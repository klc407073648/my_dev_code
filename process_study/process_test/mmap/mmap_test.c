#include<stdio.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
	char *str="hello mmap test\n";
	char *p;
	int ret1,ret2;
	int len=strlen(str);
	int fd=open("klc.txt",O_CREAT|O_RDWR,0644);
	if(fd==-1)
	{
		perror("open fail");
		exit(1);
	}
	ret1=ftruncate(fd,len);
	if(ret1==-1)
	{
		perror("ftruncate fail");
		exit(1);
	}
	
	p = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	strcpy(p,str);
	
	munmap(p,len);
	close(fd);
	
	return 0;
}