#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 10086

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char* hello = "确认收到数据";

    // 创建TCP套接字
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 设置套接字选项
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // 绑定到端口并监听连接
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 1) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    std::cout << "等待客户端连接..." << std::endl;

    while (true) {
        // 接受连接
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        std::cout << "连接来自: " << inet_ntoa(address.sin_addr) << ":" << ntohs(address.sin_port) << std::endl;

        // 读取数据
        valread = read(new_socket, buffer, 1024);
        if (valread > 0) {
            std::cout << "接收到的数据: " << buffer << std::endl;
        }

        // 发送响应
        send(new_socket, hello, strlen(hello), 0);
        std::cout << "响应已发送" << std::endl;

        close(new_socket);
    }

    return 0;
}
