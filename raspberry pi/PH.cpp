#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define BAUDRATE B4800
#define MODEMDEVICE "/dev/ttyUSB0"
#define _POSIX_SOURCE 1

int main()
{
    int fd, res;
    struct termios oldtio, newtio;
    unsigned char query[8] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x03, 0x65, 0xCD};
    unsigned char response[8];
    unsigned short nitrogen, phosphorus, potassium;

    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY);
    if (fd < 0)
    {
        perror(MODEMDEVICE);
        exit(1);
    }

    tcgetattr(fd, &oldtio); // 保存当前串口配置

    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;

    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &newtio); // 应用新的串口配置

    res = write(fd, query, sizeof(query));
    if (res != sizeof(query))
    {
        perror("write");
        exit(1);
    }

    usleep(50000); // 等待传感器响应

    res = read(fd, response, sizeof(response));
    if (res != sizeof(response))
    {
        perror("read");
        exit(1);
    }

// 读取传感器数据并转换为实际值
    unsigned short raw_moisture = (response[3] << 8) | response[4];
    float moisture = raw_moisture / 100.0;
    unsigned short raw_temperature = (response[5] << 8) | response[6];
    float temperature = raw_temperature / 100.0;
    unsigned short raw_conductivity = (response[7] << 8) | response[8];
    float conductivity = raw_conductivity / 10.0;
    unsigned short raw_phvalue = (response[9] << 8) | response[10];
    float phvalue = raw_phvalue / 100.0;

// 输出传感器数据
    printf("Moisture: %.2f\n", moisture);
    printf("Temperature: %.2f\n", temperature);
    printf("Conductivity: %.1f\n", conductivity);
    printf("PH Value: %.2f\n", phvalue);

    tcsetattr(fd, TCSANOW, &oldtio); // 恢复原来的串口配置
// 关闭串口
    close(fd);
    return 0;
}