#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345
#define QUEUE_SIZE 20
#define BUFFER_SIZE 1024

using namespace std;

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0); //定义socketfd

    struct sockaddr_in server_addr; //定义socketaddress
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    { //绑定端口
        cout << "bind error" << endl;
        exit(1);
    }

    if (listen(server_fd, QUEUE_SIZE) == -1)
    { //监听端口
        cout << "listen error" << endl;
        exit(1);
    }

    //客户端连接
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    int con_fd;
    while (1)
    {
        con_fd = accept(server_fd, (struct sockaddr *)&client_addr, &length); //接收连接
        if (con_fd == -1)
        {
            cout << "connect error" << endl;
            break;
        }

        while (1)
        { //循环接收
            memset(buffer, 0, sizeof(buffer));
            if (recv(con_fd, buffer, sizeof(buffer), 0) == -1)
            {
                cout << "recv error" << endl;
                close(con_fd);
                break;
            }
            if (strcmp(buffer, "exit\n") == 0)
            {
                cout << "客户连接中断" << endl;
                close(con_fd);
                break;
            }
            cout << buffer;
            send(con_fd, buffer, strlen(buffer), 0);
        }
    }
    close(server_fd);
    return 0;
}