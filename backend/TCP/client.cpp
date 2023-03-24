#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 10086
#define DEVICE_FILE "/dev/ttyUSB0"
#define BAUDRATE B9600

int main()
{
    int serial_fd, socket_fd;
    struct termios options;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    // 打开串口设备
    if ((serial_fd = open(DEVICE_FILE, O_RDWR | O_NOCTTY | O_SYNC)) < 0) {
        std::cerr << "无法打开串口设备" << std::endl;
        exit(EXIT_FAILURE);
    }

    // 配置串口
    tcgetattr(serial_fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 10;
    tcsetattr(serial_fd, TCSANOW, &options);

    // 创建TCP套接字
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "无法创建套接字" << std::endl;
        exit(EXIT_FAILURE);
    }

    // 连接服务器
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "8.130.45.241", &server_addr.sin_addr) <= 0) {
        std::cerr << "无效的地址" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "连接服务器失败" << std::endl;
        exit(EXIT_FAILURE);
    }

    // 读取串口数据并发送到服务器
    while (true) {
        int n = read(serial_fd, buffer, sizeof(buffer));
        if (n > 0) {
            std::cout << "读取到的数据: " << buffer << std::endl;
            send(socket_fd, buffer, n, 0);
            std::cout << "数据已发送" << std::endl;
        }
    }

    close(serial_fd);
    close(socket_fd);

    return 0;
}
