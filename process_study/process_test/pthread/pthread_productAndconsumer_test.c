#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>


struct m_list{
	int num;
	struct m_list *next;
};

struct m_list *head = NULL;
struct m_list *nlist = NULL;


pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *consumer_fun(void *p)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		while( head == NULL)
		{
			pthread_cond_wait(&has_product,&mutex);
		}
		nlist = head;
		head = nlist->next;
		pthread_mutex_unlock(&mutex);
		
		printf("——————————consumer:%d\n",nlist->num);
		free(nlist);
		nlist = NULL;
		sleep(rand()%3);

	}
     return NULL;
}

void *product_fun(void *p)
{
	while(1)
	{
		nlist = malloc(sizeof(struct m_list));
		nlist->num = rand()%1000+1;
		printf("——————————product:%d\n",nlist->num);
		
	    pthread_mutex_lock(&mutex);
		nlist->next = head ;
		head = nlist;
		pthread_mutex_unlock(&mutex);

		pthread_cond_signal(&has_product);
		sleep(rand()%3);
	}
	return NULL;
}


int main()
{
    pthread_t pid,cid;
	
	srand(time(NULL));
	
	pthread_create(&pid,NULL,product_fun,NULL);
	pthread_create(&cid,NULL,consumer_fun,NULL);
	
	pthread_join(pid,NULL);
	pthread_join(cid,NULL);
	
	return 0;
}
