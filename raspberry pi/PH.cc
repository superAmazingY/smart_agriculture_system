#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <curl/curl.h>
#include <json/json.h>

using namespace std;

int main() {
    // 打开串口
    int fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    if (fd < 0) {
        cerr << "Failed to open serial port" << endl;
        return -1;
    }

    // 配置串口参数
    struct termios tty;
    memset(&tty, 0, sizeof(tty));
    cfsetospeed(&tty, B4800); // 设置波特率为4800
    cfsetispeed(&tty, B4800);
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;
    tcsetattr(fd, TCSANOW, &tty);

    // 循环读取并打印数据
    while (true) {
        // 发送问询帧
        unsigned char buf[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x03, 0xC5, 0xC8};
        write(fd, buf, sizeof(buf));

        // 读取应答帧
        unsigned char recv_buf[8] = {0};
        int n = read(fd, recv_buf, sizeof(recv_buf));
        if (n < 0) {
            cerr << "Failed to read from serial port" << endl;
            return -1;
        }

        cout << "Received response frame: ";
        for (int i = 0; i < sizeof(recv_buf); i++)
        {
            printf("%02X ", recv_buf[i]);
        }
        cout << endl;


        // 解析应答帧
        float moisture = (recv_buf[3] << 8) | recv_buf[4]; // 水分，应答帧中水分值所在位置为第4、5个字节
        float temperature = (recv_buf[5] << 8) | recv_buf[6]; // 温度，应答帧中温度值所在位置为第6、7个字节
        float ph = (recv_buf[7] << 8) | recv_buf[8]; // PH，应答帧中PH值所在位置为第8、9个字节

        // 打印数据
        cout << "Moisture: " << moisture / 10 << "%" << endl;
        cout << "Temperature: " << temperature / 10 << "°C" << endl;
        cout << "PH: " << ph / 10 << endl;

        // 创建JSON对象并添加数据
        Json::Value root;
        root["moisture"] = moisture;
        root["temperature"] = temperature;
        root["ph"] = ph;

        // 将JSON对象转换为字符串
        std::string body = root.toStyledString();

        // 发送HTTP请求，将数据传输给服务器
        CURL *curl;
        CURLcode res;
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "http://8.130.45.241:8099/user/getPH");
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, -1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json"); // 设置HTTP请求头部为JSON格式
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK)
                cerr << "Failed to send data to server" << endl;
            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
        }
        // 休眠1秒钟
        sleep(3);
    }
    // 关闭串口
    close(fd);

    return 0;
}
