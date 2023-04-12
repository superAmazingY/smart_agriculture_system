#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <curl/curl.h>
#include <json-c/json.h>

#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyUSB0"
#define _POSIX_SOURCE 1

#define QUERY_DELAY 1000000
#define MAX_QUERY_COUNT 10

int main() {
    int fd, res, query_count = 0;
    struct termios oldtio, newtio;
    unsigned char query[8] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x03, 0x65, 0xCD};
    unsigned char response[8];
    unsigned short nitrogen, phosphorus, potassium;

    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror(MODEMDEVICE);
        exit(1);
    }

    tcgetattr(fd, &oldtio);

    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;

    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &newtio);

    while (1) {
        if (query_count == MAX_QUERY_COUNT) {
            printf("Reached maximum query count, exiting program.\n");
            break;
        }

        res = write(fd, query, sizeof(query));
        if (res != sizeof(query)) {
            perror("write");
            exit(1);
        }

        usleep(QUERY_DELAY);

        res = read(fd, response, sizeof(response));
        if (res != sizeof(response)) {
            perror("read");
            query_count++;
            continue;
        }

        nitrogen = (response[3] << 8) | response[4];
        phosphorus = (response[5] << 8) | response[6];
        potassium = (response[7] << 8) | response[8];

        printf("Nitrogen: %d mg/kg\n", nitrogen);
        printf("Phosphorus: %d mg/kg\n", phosphorus);
        printf("Potassium: %d mg/kg\n", potassium);
        printf("\n");

        // 将传感器数据转换为JSON格式
        json_object *json_data = json_object_new_object();
        json_object_object_add(json_data, "nitrogen", json_object_new_int(nitrogen));
        json_object_object_add(json_data, "phosphorus", json_object_new_int(phosphorus));
        json_object_object_add(json_data, "potassium", json_object_new_int(potassium));
        const char *json_str = json_object_to_json_string(json_data);

        //发送JSON数据到服务器
        CURL *curl;
        CURLcode res_curl;

        curl = curl_easy_init();
        if (curl) {
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json"); // set the content type to JSON
            curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/data"); // set the URL of the server
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str); // set the data to be sent
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            // perform the request
            res_curl = curl_easy_perform(curl);
            if (res_curl != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res_curl));
            }

            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }

        json_object_put(json_data);

        query_count++;
    }

    tcsetattr(fd, TCSANOW, &oldtio);
    close(fd);

    return 0;
}