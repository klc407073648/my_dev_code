#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *my_thread_fun(void *arg)
{
	int i = (int)arg;
	sleep(i);
	printf("%dth child thread was created, pthread id:%lu\n",i+1,pthread_self());
	return NULL;
}

int main()
{
	pthread_t tid;
	
	int ret,i;
	
	printf("main process begin , pthread id:%lu\n",pthread_self());
	
	for(i=0;i<5;i++)
	{
		pthread_create(&tid,NULL,my_thread_fun,(void *)i);
	}
	
	sleep(i);
	printf("main process end\n");
		
	return 0;
}