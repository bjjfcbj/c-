#ifndef THREAD_POOP_D
#define THREAD_POOP_D

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <queue>
#include <mutex>
#include <future>
#include <functional>
#include <condition_variable>

/**
 * @brief namespace of drw \n
 * DRW专用空间 
 */
namespace drw
{

#define NORMAL_THREAD_NUM 128
#define EXTRA_THREAD_NUM 128

/**
 * @brief thread pool built by drw. \n
 * 一个可以接收多参数任务的线程池
 */
class thread_pool
{

    using Task = std::function<void()>;

    std::vector<std::thread> normal_pool;
    std::vector<std::thread> extra_pool;
    std::queue<Task> task_que;
    std::atomic<bool> stop;
    std::atomic<unsigned int> available_num;
    std::condition_variable cv_task;
    std::mutex g_lock;

  public:
    explicit thread_pool(unsigned int size = 4) : stop(false), available_num(size > 0 ? (size < NORMAL_THREAD_NUM ? size : NORMAL_THREAD_NUM) : 1)
    {
        while (size--)
        {
            normal_pool.emplace_back([this] {
                while (!this->stop)
                {
                    Task task;
                    {
                        std::unique_lock<std::mutex> lock{this->g_lock};
                        this->cv_task.wait(lock, [this] {
                            return this->stop.load() || !this->task_que.empty();
                        });
                        if (this->stop.load())
                        {
                            return;
                        }
                        task = std::move(this->task_que.front());
                        this->task_que.pop();
                    }
                    --this->available_num;
                    task();
                    ++this->available_num;
                }
            });
        }
    }

    thread_pool(thread_pool &tp) = delete;
    thread_pool &operator=(const thread_pool &) = delete;

    ~thread_pool()
    {
        stop.store(true);
        cv_task.notify_all();
        for (auto &th : normal_pool)
        {
            if (th.joinable())
            {
                th.join();
            }
        }
    }

    /**
 * @brief future版本 
 */
    template <class F, class... Args>
    auto commit(F &&f, Args &&... args) -> std::future<decltype(f(args...))>
    {
        if (this->stop.load())
        {
            throw std::runtime_error("this thread_pool has already closed");
        }
        using Ret_type = decltype(f(args...));
        auto task = std::make_shared<std::packaged_task<Ret_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        std::future<Ret_type> future = task->get_future();
        {
            std::lock_guard<std::mutex> lock{g_lock};
            task_que.emplace([task] { (*task)(); });
        }
        cv_task.notify_one();

        return future;
    }

    unsigned int available()
    {
        return available_num;
    }
};

} // namespace drw

#endif