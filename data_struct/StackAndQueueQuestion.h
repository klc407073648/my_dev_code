#include<iostream>
#include<vector>
using namespace std;

class ArrayStack
{
public:
	vector<int> value;
	int  size;
	void push(int input) {
		if (value.size() < size)
			value.push_back(input);
		else
			cout << "数组已满";
	}
	void pop()
	{
		if(value.size()>0)
			value.pop_back();
		else
			cout << "数组已空";
	}

	int top()
	{
		if (value.size() > 0)

		{
			cout << (value[value.size() - 1]);
			return  (value[value.size() - 1]);
		}
		else
		{
			cout << "数组已空";
			return 0;
		}
	}
	ArrayStack(int n,vector<int> &nums):size(n) {
		
		for (int i = 0; i <size; i++)
			value.push_back(nums[i]);
	};
	ArrayStack();
};


void ArrayStackTest()
{
	vector<int> nums = { 5,4,6,3,1 };
	ArrayStack s(5, nums);
	s.push(5);
	s.pop();
	s.top();
	s.push(4);
	s.push(4);



}