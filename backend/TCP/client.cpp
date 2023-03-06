/********************************
*
*  Created on 2022/06/28
*  Author: amazingY
*
*  An example of socket client.
*
*********************************/
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

const char kServerSocketIp[] = "172.26.57.88";
const int kServerSocketPort = 10086;  // 服务器端口
const int kMsgSize = 1024;            // 接收char[]类型数据的buf大小
int return_num;               // 声明int型数据接收recv()的返回值。

int main() {
  char send_msg[kMsgSize];
  // 创建一个server使用的socket对象，并初始化为ipv4网络地址协议
  // socket数据类型为stream，传输协议为tcp协议。
  int client_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  sockaddr_in server_addr;                                   // 创建服务端地址数据。
  memset(&server_addr, 0, sizeof(server_addr));              // 先将保存地址的server_addr置为全0
  server_addr.sin_family = AF_INET;                          // 指定地址协议为ipv4.
  server_addr.sin_port = htons(kServerSocketPort);           // 指定服务端端口。
  server_addr.sin_addr.s_addr = inet_addr(kServerSocketIp);  // 指定服务端ipv4地址。
  // 连接服务器，成功返回0，错误返回-1
  connect(client_socket,(sockaddr*)&server_addr,sizeof(server_addr));
  char recv_msg_buf[kMsgSize];  // 创建接收数据的buf.

  while (true) {
    std::cout<<"输入文本:";
    std::cin.getline(send_msg,kMsgSize);
    send(client_socket,send_msg,sizeof(send_msg),0);           // 发送数据。
    std::cout << "发送信息: " << send_msg << std::endl;
    return_num = recv(client_socket,recv_msg_buf,kMsgSize,0);  // 接收来自服务器的数据
    std::cout << "服务器回复信息: " 
              << recv_msg_buf << std::endl;
    memset(recv_msg_buf,0,kMsgSize);
    // 若在循环体内定义发送消息，可以选择将发送消息置0.
    memset(send_msg,0,sizeof(send_msg));
    sleep(1);
  }
  close(client_socket);
  return 0;
}
