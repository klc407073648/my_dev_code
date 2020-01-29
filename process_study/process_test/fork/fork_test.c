#include<unistd.h>
#include<iostream>

using namespace std;

int main()
{
 cout<<"Test Func begin!"<<endl;
 pid_t m_pid;
 m_pid= fork();

 if(m_pid == -1)
{
  perror("fork fail.");
}
 else if(m_pid == 0)
{
  cout<<"I'm child "<<"id:"<<getpid()<<" ppid:"<<getppid()<<endl;
  //while(1)
  //{
	  //cout<<"I'm child "<<"id:"<<getpid()<<" ppid:"<<getppid()<<endl;
  //}
}
 else if(m_pid > 0)
{
  cout<<"I'm parent "<<"id:"<<getpid()<<" ppid:"<<getppid()<<" childID:"<<m_pid<<endl;
  sleep(2);
  while(1)
  {
	  
  }
}

 cout<<"fork end"<<endl;

 return 0;
}