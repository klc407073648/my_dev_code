#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

using namespace std;

int main()
{
	//printf("waitpid func test!");
	pid_t pid,wpid;
	int i;
	for(i=1;i<=3;i++)
	{
		pid=fork();
		if( pid == 0 )
			break;
	}
	if(i<4)
	{	
		if(i==1)
		{
			/* if( execlp("ps","ps","-ef",NULL)== -1 ) */
			sleep(i);
			printf("child %d pid:%d\n",i,getpid());
			if( execlp("date","date",NULL)== -1 )
			{
				perror("execlp fail\n");
				exit(1);
			}
		}
		else if(i==2)
		{
			sleep(i);
			printf("child %d pid:%d\n",i,getpid());
			if( execlp("./waitpid_test_normal","waitpid_test_normal",NULL) == -1 )
			{
				perror("test waitpid_test_normal\n");
				exit(1);
			}
		}
		else if(i==3)
		{
			sleep(i);
			printf("child %d pid:%d\n",i,getpid());
			if( execlp("./waitpid_test_abnormal","waitpid_test_normal",NULL) == -1 )
			{
				perror("test waitpid_test_normal\n");
				exit(1);
			}
		}
	}
			
	else if (i==4)
	{
		do
	   {
		int stat_val;
		wpid=waitpid(-1,&stat_val,WNOHANG);
		
		if(wpid>0)
		{
			printf("I'm parent,child %d is kill\n",wpid);
			if (WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
			else if (WIFSIGNALED(stat_val))
            printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
			i--;
		}
		sleep(1);
		}while(i>1);  
	}


 return 0;
}

