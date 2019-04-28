#include "thread_pool.h"
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;
using namespace drw;

void fun1()
{
    char buffer[128];
    getcwd(buffer, sizeof(buffer));
    string s{buffer};
    cout << s << endl;
    chdir("/");
    cout << "change dir to /" << endl;
}

void fun2()
{
    sleep(2);
    char buffer[128];
    getcwd(buffer, sizeof(buffer));
    cout << buffer << endl;
}

int main()
{
    thread a{fun1};
    thread b{fun2};
    a.join();
    b.join();
    return 0;
}