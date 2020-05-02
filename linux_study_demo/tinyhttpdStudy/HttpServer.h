/**
 * @file HttpServer.h
 * @brief http服务器
 * @author klc
 * @date 2020-03-01
 * @copyright Copyright (c) 2020年 klc
 */


#ifndef __HTTP_HTTPSERVER_H__
#define __HTTP_HTTPSERVER_H__

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>

#define ISspace(x) isspace((int)(x))

#define SERVER_STRING "Server: jdbhttpd/0.1.0\r\n"

using namespace std;

namespace klc {
namespace http {

/**
 * @brief HTTP服务器类
 */
class HttpServer 
{
public:
    HttpServer(){}
	~HttpServer() {}
	void accept_request(int);
	void bad_request(int);
	void cat(int, FILE *);
	void cannot_execute(int);
	void error_die(const char *);
	void execute_cgi(int, const char *, const char *, const char *);
	int get_line(int, char *, int);
	void headers(int, const char *);
	void not_found(int);
	void serve_file(int, const char *);
	int startup(u_short *);
	void unimplemented(int);
};
}
}
#endif //__HTTP_HTTPSERVER_H__
