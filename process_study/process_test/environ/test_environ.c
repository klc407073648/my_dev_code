#include<iostream>

using namespace std;
extern char** environ;

int main()
{
 int i=0;
 //输出环境变量
 while(environ[i])
{
 cout<<environ[i]<<endl;
 i++;
}
 return 0;
}

