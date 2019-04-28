#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345
#define BUFFER_SIZE 1024
const char *SERVER_IP = "127.0.0.1";

using namespace std;

void filerecv(int sock);

int main()
{
    int client_fd = socket(AF_INET, SOCK_STREAM, 0); //定义socketfd

    struct sockaddr_in server_addr; //定义socketaddress
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    { //连接
        cout << "connect error" << endl;
        exit(1);
    }

    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    while (fgets(send_buffer, sizeof(send_buffer), stdin) != NULL)
    {
        send(client_fd, send_buffer, strlen(send_buffer), 0);
        if (strcmp(send_buffer, "exit\n") == 0)
        {
            break;
        }
        //recv(client_fd, recv_buffer, sizeof(recv_buffer), 0);
        //cout << recv_buffer << endl;
        if (strcmp(send_buffer, "down\n") == 0)
        {
            filerecv(client_fd);
        }
        memset(send_buffer, 0, sizeof(send_buffer));
        memset(recv_buffer, 0, sizeof(recv_buffer));
    }

    close(client_fd);
    cout << "client quit" << endl;
    return 0;
}

//filerecv
void filerecv(int sock)
{
    int len = 0;
    char buffer[20];
    memset(buffer, 0, sizeof(buffer));
    fstream out("name.json", ios::binary | ios::app | ios::out);
    cout << "file created" << endl;
    while ((len = recv(sock, buffer, sizeof(buffer), MSG_DONTWAIT)) > 0) //问题大大的
    {
        cout << "p1" << endl;
        out.write(buffer, len);
        if (len < sizeof(buffer))
            break;
        memset(buffer, 0, sizeof(buffer));
        cout << "p2" << endl;
    }
    out.close();
    cout << "recv end" << endl;
}