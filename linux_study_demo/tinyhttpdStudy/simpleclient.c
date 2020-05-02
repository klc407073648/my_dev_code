#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
 int sockfd;
 int len;
 //char buf[BUFSIZ];
 struct sockaddr_in address;
 int result;

 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 address.sin_family = AF_INET;
 address.sin_addr.s_addr = inet_addr("127.0.0.1");
 
 char buf[] = "GET / HTTP/1.1\n\n\n";
 //char buf[] = "  klc \n";
 char get[1024] = {0};
 
 address.sin_port = htons(10000);
 len = sizeof(address);
 result = connect(sockfd, (struct sockaddr *)&address, len);

 if (result == -1)
 {
  perror("oops: client1");
  exit(1);
 }

 write(sockfd,buf, sizeof(buf));/*发送请求*/
 read(sockfd,get, sizeof(get));/*接收返回数据*/
 /*打印返回数据*/
 printf("-----------------------------show buffer -----------------------------\n");
 printf("%s",get);
 printf("----------------------------------------------------------------------\n");


//  while (1) 
// {
        /*从标准输入获取数据*/
//        fgets(buf, sizeof(buf), stdin);
        /*将数据写给服务器*/
//        write(sockfd, buf, strlen(buf));       //写个服务器
        /*从服务器读回转换后数据*/
//        len = read(sockfd, buf, sizeof(buf));
        /*写至标准输出*/
//        write(STDOUT_FILENO, buf, len);
// }
 
 close(sockfd);
 exit(0);
}
