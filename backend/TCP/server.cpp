/********************************
*
*  Created on 2023/02/20
*  Author: amazingY
*
*  An example of socket server.
*
*********************************/
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <string>
 
const int kServerSocketPort = 10086;  // 服务器端口
const int kMsgSize = 1024;            // 接收char[]类型数据的buf大小
int return_num;                   // 声明int型数据接收recv()的返回值。
 
int main() {
  // 创建一个server使用的socket对象，并初始化为ipv4网络地址协议
  // socket数据类型为stream，传输协议为tcp协议。
  int server_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  sockaddr_in server_addr;                             // 创建服务端地址数据。
  server_addr.sin_family = AF_INET;                    // 指定地址协议为ipv4.
  server_addr.sin_port = htons(kServerSocketPort);     // 指定socket服务的端口号。
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);     // 指定为"0.0.0.0"，表示监听本机所有网卡的端口
  // 如果想要监听某块网卡的端口，请指定为该网卡ip,如下：
  //server_addr.sin_addr.s_addr = inet_addr("172.26.113.206/20");
  // 将socket对象与地址信息绑定，成功返回非负值，失败返回-1
  bind(server_socket,(sockaddr*)&server_addr,sizeof(server_addr));
  // ServerSocket开始监听，最大连接数指定为5,成功返回非负值，失败返回-1
  listen(server_socket,5);
  std::cout << "等待客户端接入......." << std::endl;
 
  // 创建一个新的socket对象来和连接客户端的socket对象（sever的socket还要继续听！）
  sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int sub_server_socket = accept(server_socket,          // 从指定sever取得连接信息
                               (sockaddr*)&client_addr,  // 获得客户端的地址
                               &client_addr_len);
  std::cout << inet_ntoa(client_addr.sin_addr) << ":"
            << ntohs(client_addr.sin_port)
            << "接入成功" << std::endl;
  char receive_data_buf[kMsgSize];  // 创建接收数据的buf.

  char check_msg[] = "消息接收成功！";
  while (true) {
    memset(receive_data_buf,0,sizeof(receive_data_buf));
    // recv()函数会等待sockfd的发送缓冲区中的数据被协议传送完毕，
    // 当协议把数据接收完毕后，recv函数就把sockfd的接收缓冲区中的数据copy到buf中，
    // recv函数返回其实际copy的字节数,返回0说明传输时网络中断
    // 如果协议在传送数据时出现网络错误，或copy时出错返回SOCKET_ERROR
    // 该函数的第一个参数指定接收端套接字描述符；
    // 第二个参数指明一个缓冲区，该缓冲区用来存放recv函数接收到的数据；
    // 第三个参数指明buf的长度；
    // 第四个参数一般置0;
    return_num = recv(sub_server_socket,receive_data_buf,kMsgSize,0);
    std::cout << "客户端的信息: "
              << receive_data_buf << std::endl;
    send(sub_server_socket,check_msg,sizeof(check_msg),0);  // 向客户端发送确认信息
  }
  close(sub_server_socket);
  close(server_socket);
  return 0;
}
