#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int counter=0;

pthread_rwlock_t rwlock;

void *my_read_fun(void *arg)
{
	int i = (int)arg;
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);
		printf("-----------------read %d , pthread id:%lu counter:%d\n",i,pthread_self(),counter);
		usleep(100);
		pthread_rwlock_unlock(&rwlock);
		usleep(100);
	}
	
}

void *my_write_fun(void *arg)
{
	int i = (int)arg;
	while(1)
	{
		pthread_rwlock_wrlock(&rwlock);
		printf("-----------------write %d , pthread id:%lu counter:%d\n",i,pthread_self(),++counter);
		usleep(100);
		pthread_rwlock_unlock(&rwlock);
		usleep(100);
	}
	
}

int main()
{
	pthread_t tid[5];
	int i;
	
	pthread_rwlock_init(&rwlock,NULL);
	
	for(i=0;i<3;i++)
	{
		pthread_create(&tid[i],NULL,my_read_fun,(void *)i);
	}
	for(i=0;i<2;i++)
	{
		pthread_create(&tid[3+i],NULL,my_write_fun,(void *)i);
	}
	for(i=0;i<5;i++)
	{
		pthread_join(tid[i],NULL);
	}

	pthread_rwlock_destroy(&rwlock);
	
	return 0;
}
