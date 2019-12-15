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
		cout << "Thread 01 is working ��" << endl;
		Sleep(100);
	}
}
void myThread2()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Thread 02 is working ��" << endl;
		Sleep(100);
	}
}

void myThread5()
{
	while (currentNum < 10)
	{
		mu.lock(); //ͬ��������
		currentNum++;
		cout << "Thread 05 is working ��" <<" currentNum="<< currentNum<< endl;
		Sleep(100);
		mu.unlock();  //�������
	}
}
void myThread6()
{
	while(currentNum < 10)
	{
		mu.lock(); //ͬ��������
		currentNum++;
		cout << "Thread 06 is working ��" << " currentNum=" << currentNum << endl;
		Sleep(100);
		mu.unlock();  //�������
	}
}

void myThread3(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Thread 03 is working ��" << endl;
		Sleep(100);
	}
}
void myThread4(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Thread 04 is working ��" << endl;
		Sleep(100);
	}
}

//�����̵ȴ����߳�
void myTest1()
{
	thread task01(myThread1);
	thread task02(myThread2);

	task01.join();
	task02.join();

	for (int i = 0; i < 5; i++)
	{
		cout << "Main thread is working ��" << endl;
		Sleep(200);
	}
	system("pause");
}

//�����̺��ӽ��̻�������
void myTest2()
{
	thread task01(myThread1);
	thread task02(myThread2);

	task01.detach();
	task02.detach();

	for (int i = 0; i < 5; i++)
	{
		cout << "Main thread is working ��" << endl;
		Sleep(200);
	}
	system("pause");
}

//�����̺��ӽ��̻�������,�Ҵ����������߳�
void myTest3()
{
	thread task01(myThread3,3);
	thread task02(myThread4,3);

	task01.detach();
	task02.detach();

	for (int i = 0; i < 5; i++)
	{
		cout << "Main thread is working ��" << endl;
		Sleep(200);
	}
	system("pause");
}

//���߳̾��������
void myTest4()
{
	thread task01(myThread5);
	thread task02(myThread6);
	task01.detach();
	task02.detach();
	system("pause");
}
/*
������ʹ�����̵߳�һ������
������������ʹ�����߳����ǻᷢ�֣����ǲ��ܰѳ�ʼ��������Ϊ��ĳ�Ա����������Ҫ�ѳ�Ա�������ó�static���͵Ĳſ��ԣ�
����������Ƶ�һ�����⣬����static�����Ա�������ܵ��÷�static�ı�����Ա��������һ����ȫ�����ķ�����

thread sendtask(bind(&client::sendata, this));//����client���������
�����Ϳ��Խ�����ǵ����⡣

*/
