#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


pthread_mutex_t mutex; 


void *my_pthread_fun(void *arg)
{
	
	while(1)
	{
		pthread_mutex_lock(&mutex);
		printf("hello");
		printf("world\n");
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}



int main()
{
	pthread_t tid;
	int ret;
	pthread_mutex_init(&mutex,NULL);
	
	ret = pthread_create(&tid,NULL,my_pthread_fun,NULL);
	if( ret != 0)
	{
	  printf("pthread_create fail");
	  exit(1);
	}

	while(1)
	{
		pthread_mutex_lock(&mutex);
		printf("HELLO");
		printf("WORLD\n");
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_cancel(tid);
    pthread_join(tid, NULL);
	
	pthread_mutex_destroy(&mutex);
	
	return 0;
	
}