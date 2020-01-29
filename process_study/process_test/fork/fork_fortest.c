#include<unistd.h>
#include<iostream>

using namespace std;

int main()
{
   cout<<"Test Func begin!"<<endl;
   pid_t m_pid;
   int i;
   for(i=0;i<5;i++)
   {
	  m_pid= fork();
	  if( m_pid == 0)
		 break;
   }
    sleep(i);
	if( i < 5)
	{
	   cout<<"I'm child "<<i<<" id:"<<getpid()<<endl;
	}
	else
	{
	   cout<<"I'm parent "<<" id:"<<getpid()<<endl;
	   cout<<"Test Func end!"<<endl;
	}

 return 0;
}

