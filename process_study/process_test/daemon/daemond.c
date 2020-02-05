#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<time.h>
#include<errno.h>

int main()
{
	pid_t pid,sid;
	
	pid = fork();
	
	if( pid == -1 )
	{
		perror("fork error");
		exit(1);
	}
	else if( pid > 0)
	{
		return 0;
	}
	
	sid = setsid();
	if( sid == -1 )
	{
		perror("setsid error");
		exit(1);
	}
	
	int ret = chdir("/home/test/");
    if (ret == -1) {
        perror("chdir error");  
        exit(1);
    }
	
	umask(0022);
	
	close(STDIN_FILENO);
    open("/dev/null", O_RDWR);
    dup2(0, STDOUT_FILENO);
    dup2(0, STDERR_FILENO);
	
	
	
	while(1)
	{
		int fd = open("time.txt",O_CREAT|O_RDWR|O_APPEND);
		
		//获取时间
		time_t now ;
		char timebuf[25];
        struct tm *tm_now ;

        time(&now) ;

        tm_now = localtime(&now) ;
        
        sprintf(timebuf,"%d-%d-%d %d:%d:%d\n",tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec) ;
		//获取时间
	
		write(fd, timebuf, sizeof(timebuf));
		sleep(2);
	}
		
	return 0;
}