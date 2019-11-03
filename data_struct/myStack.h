#ifndef _MYSTACK_H_
#define _MYSTACK_H_



#include<iostream>
#include<stack>
#include<queue>
//实现一个特殊的栈， 在实现栈的基本功能的基础上， 再实现返
//回栈中最小元素的操作。
//【要求】
//1． pop、 push、 getMin操作的时间复杂度都是O(1)。
//2． 设计的栈类型可以使用现成的栈结构。
using namespace std;
//最小值栈
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
			cout << "栈已经空了" << endl;
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

//一遇到出栈，就把stack1栈内的数值依次弹出给stack2,然后最后一个数出栈
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

//准备两个队列，一遇到出栈就把对头依次进另外一个队列删除队尾
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
	