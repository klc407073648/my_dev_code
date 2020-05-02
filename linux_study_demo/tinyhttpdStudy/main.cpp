#include"HttpServer.h"
#include <sys/socket.h>
#include <unistd.h>
using namespace klc::http;



int main(void)
{
 HttpServer* m_http;
 int len,i;
 char buf[BUFSIZ]; 
 int server_sock = -1;
 u_short port = 10000;
 int client_sock = -1;
 struct sockaddr_in client_name;
 socklen_t client_name_len = sizeof(client_name);
 //socklen_t client_name_len = sizeof(client_name);
 server_sock = m_http->startup(&port);
 printf("httpd running on port %d\n", port);

 while (1)
 {
  //阻塞等待客户端连接
  client_sock = accept(server_sock,
                       (struct sockaddr *)&client_name,
                       &client_name_len);
  if (client_sock == -1)
	m_http->error_die("accept");
  m_http->accept_request(client_sock); 
 
 }

 close(server_sock);

 return(0);
}
	
