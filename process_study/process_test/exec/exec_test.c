#include<unistd.h>
#include<iostream>

using namespace std;

int main()
{
  
  //execlp("ls","ls","-al",NULL);
  //execl("/bin/ls","ls","-al",NULL);
  char *args[]={"ls","-al",NULL};
  //execvp("ls",args);
  //execvp("/bin/ls",args);
  char *args1[]={"ps","-ef",NULL};
  execvp("ps",args1);
  return 0;

}
