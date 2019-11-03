#ifndef _MYSTACK_H_
#define _MYSTACK_H_



#include<iostream>
#include<stack>
#include<queue>
//ʵ��һ�������ջ�� ��ʵ��ջ�Ļ������ܵĻ����ϣ� ��ʵ�ַ�
//��ջ����СԪ�صĲ�����
//��Ҫ��
//1�� pop�� push�� getMin������ʱ�临�Ӷȶ���O(1)��
//2�� ��Ƶ�ջ���Ϳ���ʹ���ֳɵ�ջ�ṹ��
using namespace std;
//��Сֵջ
class myStack
{
public:
	stack<int> dataStack;
	stack<int> minStack;
	int min;
  
	void push(int t)
	{
		
		dataStack.push(t);
		if (minStack.empty())
		{
			minStack.push(t);
			min = t;
		}
		else if (min>t && !minStack.empty())
		{
			minStack.push(t);
		}
		else
		{
			minStack.push(min);
		}
	}
	void pop()
	{
		if (dataStack.empty() && minStack.empty())
		{
			cout << "ջ�Ѿ�����" << endl;
			return;
		}
		dataStack.pop();
		minStack.pop();
	}

	int getMin()
	{
		return minStack.top();
	}
	

};

void myStackTest()
{
	myStack stack;
	stack.push(3);
	cout << stack.getMin() << endl;
	stack.push(4);
	cout << stack.getMin() << endl;
	stack.push(1);
	cout << stack.getMin() << endl;
	stack.pop();
	cout << stack.getMin() << endl;
	stack.push(5);
	cout << stack.getMin() << endl;
	stack.push(2);
	cout << stack.getMin() << endl;
	stack.push(0);
	cout << stack.getMin() << endl;
}

//һ������ջ���Ͱ�stack1ջ�ڵ���ֵ���ε�����stack2,Ȼ�����һ������ջ
class myQueue
{
public:
	stack<int> stack1;
	stack<int> stack2;

	void push(int t)
	{
		stack1.push(t);
	}
	void pop()
	{
		if (stack1.empty() && stack2.empty())
			cout << "Queue is empty!" << endl;
		else if(stack2.empty())
		{ 
			while(!stack1.empty())
		   {
			stack2.push(stack1.top());
			stack1.pop();
		   }
			stack2.pop();
	    }
		else 
			stack2.pop();
		
	}

	int front()
	{
		if (!stack2.empty())
			return  stack2.top();
		else if(stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			return  stack2.top();
		}
	}

};

void myQueueTest()
{
	myQueue queue;
	queue.push(4);
	queue.push(3);
	queue.push(2);
	queue.push(1);
	cout << queue.front() << endl;
	queue.pop();
	cout << queue.front() << endl;
	queue.pop();
	cout << queue.front() << endl;
	queue.pop();
	cout << queue.front() << endl;
	queue.pop();
	int t = 0;
}

//׼���������У�һ������ջ�ͰѶ�ͷ���ν�����һ������ɾ����β
class myQueueStack
{
public:
	queue<int> dataQueue;
	queue<int> helpQueue;

	void push(int t)
	{
		dataQueue.push(t);
	}

	void pop()
	{
		if (dataQueue.empty())
			cout << "stack is empty!" << endl;
		else
		{
			while(dataQueue.size()!=1)
			{
				helpQueue.push(dataQueue.front());
				dataQueue.pop();
			}
			dataQueue.pop();
			queue<int> tmp=helpQueue;
			helpQueue = dataQueue;
			dataQueue = tmp;
		}
	
}
	int top()
	{
		return dataQueue.back();
	}
};

void myQueueStackTest()
{
	myQueueStack s;
	s.push(4);
	s.push(5);
	cout << s.top() << endl;
	s.push(3);
	cout << s.top() << endl;
	s.push(2);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	s.pop();

}
#endif // !_MYSTACK_H_
	