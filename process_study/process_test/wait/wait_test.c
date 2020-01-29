#include<unistd.h>
#include<iostream>
#include <sys/wait.h>

using namespace std;

int main()
{
	cout<<"Wait Func begin!"<<endl;
	pid_t m_pid,wait_pid;
	int status;
	m_pid= fork();

	 if(m_pid == -1)
	{
	  perror("fork fail.");
	}
	 else if(m_pid == 0)
	{
	  sleep(20);
	  cout<<"I'm child "<<"id:"<<getpid()<<" ppid:"<<getppid()<<endl;
	}
	 else if(m_pid > 0)
	{
	  wait_pid=wait(&status);
	  if(WIFEXITED(status))
	  {
		  cout<<"I'm parent, child:"<<wait_pid<<" exit normally"<<" status:"<<WEXITSTATUS(status)<<endl;
	  }
	  if(WIFSIGNALED(status))
	  {
		  cout<<"I'm parent, child exit abnormally "<<"kill by signal "<<WTERMSIG(status)<<endl;
	  }
	  cout<<"I'm parent "<<"id:"<<getpid()<<" ppid:"<<getppid()<<endl;
	  sleep(2);
	}

	 cout<<"Wait Func end"<<endl;

 return 0;
}

