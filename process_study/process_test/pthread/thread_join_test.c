#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

typedef struct {
	int var;
	char ch;
	char str[25];	
} exit_info;


void *my_thread_fun(void *arg)
{
	exit_info *info = (exit_info *)arg;
	info->var=10;
	info->ch='a';
	strcpy(info->str,"my thread\n");
	//return (void *)info;
	pthread_exit((void *)info);
}

int main()
{
	pthread_t tid;
	int ret;
	exit_info *info= malloc(sizeof(exit_info));
	
	ret = pthread_create(&tid,NULL,my_thread_fun,(void *)info);
	
	if( ret != 0 )
	{
		printf("error number %d",ret);
		exit(1);
	}
	
	ret = pthread_join(tid,(void **)&info);
	
	if( ret != 0 )
	{
		printf("error number %d",ret);
		exit(1);
	}

	printf("var=%d ch=%c str=%s",info->var,info->ch,info->str);
	
	free(info);
	
	return 0;
}