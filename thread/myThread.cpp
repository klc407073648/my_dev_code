#include"myThread.h"
#include <iostream>
#include <thread>
#include<mutex>
#include <Windows.h>
using namespace std;

mutex mu;
int currentNum = 0;


void myThread1()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Thread 01 is working ！" << endl;
		Sleep(100);
	}
}
void myThread2()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Thread 02 is working ！" << endl;
		Sleep(100);
	}
}

void myThread5()
{
	while (currentNum < 10)
	{
		mu.lock(); //同步数据锁
		currentNum++;
		cout << "Thread 05 is working ！" <<" currentNum="<< currentNum<< endl;
		Sleep(100);
		mu.unlock();  //解除锁定
	}
}
void myThread6()
{
	while(currentNum < 10)
	{
		mu.lock(); //同步数据锁
		currentNum++;
		cout << "Thread 06 is working ！" << " currentNum=" << currentNum << endl;
		Sleep(100);
		mu.unlock();  //解除锁定
	}
}

void myThread3(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Thread 03 is working ！" << endl;
		Sleep(100);
	}
}
void myThread4(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Thread 04 is working ！" << endl;
		Sleep(100);
	}
}

//主进程等待子线程
void myTest1()
{
	thread task01(myThread1);
	thread task02(myThread2);

	task01.join();
	task02.join();

	for (int i = 0; i < 5; i++)
	{
		cout << "Main thread is working ！" << endl;
		Sleep(200);
	}
	system("pause");
}

//主进程和子进程互不干扰
void myTest2()
{
	thread task01(myThread1);
	thread task02(myThread2);

	task01.detach();
	task02.detach();

	for (int i = 0; i < 5; i++)
	{
		cout << "Main thread is working ！" << endl;
		Sleep(200);
	}
	system("pause");
}

//主进程和子进程互不干扰,且带参数的子线程
void myTest3()
{
	thread task01(myThread3,3);
	thread task02(myThread4,3);

	task01.detach();
	task02.detach();

	for (int i = 0; i < 5; i++)
	{
		cout << "Main thread is working ！" << endl;
		Sleep(200);
	}
	system("pause");
}

//多线程竞争的情况
void myTest4()
{
	thread task01(myThread5);
	thread task02(myThread6);
	task01.detach();
	task02.detach();
	system("pause");
}
/*
在类中使用子线程的一个问题
当我们再类中使用子线程我们会发现，我们不能把初始函数设置为类的成员函数，必须要把成员函数设置成static类型的才可以，
但是这有设计到一个问题，就是static的类成员函数不能调用非static的变量成员，下面是一个两全其美的方法：

thread sendtask(bind(&client::sendata, this));//其中client是类的名字
这样就可以解决我们的问题。

*/
