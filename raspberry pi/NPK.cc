#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <cstdlib>
#include <ctime>
#include <curl/curl.h>
#include <json/json.h>

using namespace std;

int main()
{
    // 打开串口
   int fd = open("/dev/ttyUSB1", O_RDWR | O_NOCTTY);
    if (fd < 0)
    {
        cerr << "Failed to open serial port" << endl;
        return -1;
    }

    // 配置串口参数
    struct termios tty;
    memset(&tty, 0, sizeof(tty));
    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;
    tcsetattr(fd, TCSANOW, &tty);

    while (true)
    {
        // 发送问询帧
        unsigned char buf[8] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x03, 0x65, 0xCD};
        write(fd, buf, sizeof(buf));

        // 读取应答帧
        unsigned char recv_buf[10] = {0};
        int n = read(fd, recv_buf, sizeof(recv_buf));
        if (n < 0)
        {
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
        int nitrogen = (recv_buf[3] << 8) | recv_buf[4];
        int phosphorus = (recv_buf[5] << 8) | recv_buf[6];
        int potassium = (recv_buf[7] << 8) | recv_buf[8];

        // 打印数据
        cout << "nitrogen: " << nitrogen <<"mg/kg" <<endl;
        cout << "phosphorus: " << phosphorus<<"mg/kg" << endl;
        cout << "potassium: " << potassium<<"mg/kg" << endl;

        // 创建JSON对象并添加数据
        Json::Value root;
        root["nitrogen"] = nitrogen;
        root["phosphorus"] = phosphorus;
        root["potassium"] = potassium;
        // 将JSON对象转换为字符串
        Json::StreamWriterBuilder builder;
        std::string body = Json::writeString(builder, root);

        // 发送HTTP请求，将数据传输给服务器
        CURL *curl;
        CURLcode res;
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "http://8.130.45.241:8099/user/getNPK");
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());
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
        std::cout<<std::endl;

        // 休眠1秒钟
        sleep(1);
    }

    // 关闭串口
    close(fd);

    return 0;
}
