#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <curl/curl.h>
#include <json-c/json.h>

#define BAUDRATE B4800
#define MODEMDEVICE "/dev/ttyUSB0"
#define _POSIX_SOURCE 1

int main() {

    int fd, res;
    struct termios oldtio, newtio;
    unsigned char query[8] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x03, 0x65, 0xCD};
    unsigned char response[8];
    unsigned short nitrogen, phosphorus, potassium;

    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY);
    if (fd < 0) {
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

    while (1) // 循环打印数据
    {
        res = write(fd, query, sizeof(query));
        if (res != sizeof(query)) {
            perror("write");
            exit(1);
        }

        usleep(50000); // 等待传感器响应

        res = read(fd, response, sizeof(response));
        if (res != sizeof(response)) {
            perror("read");
            exit(1);
        }
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

    // 将传感器数据转换为JSON格式
    struct json_object *jobj = json_object_new_object();
    json_object_object_add(jobj, "moisture", json_object_new_double((double) moisture));
    json_object_object_add(jobj, "temperature", json_object_new_double((double) temperature));
    json_object_object_add(jobj, "conductivity", json_object_new_double((double) conductivity));
    json_object_object_add(jobj, "phvalue", json_object_new_double((double) phvalue));
    const char *json_str = json_object_to_json_string(jobj);

    // 发送JSON数据到服务器
    CURL *curl;
    CURLcode res_curl;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/data");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, "Content-Type: application/json");
        res_curl = curl_easy_perform(curl);
        if (res_curl != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res_curl));
        }

        curl_easy_cleanup(curl);
        json_object_put(jobj);
        tcsetattr(fd, TCSANOW, &oldtio); // 恢复原来的串口配置
        close(fd);

        return 0;
    }
}