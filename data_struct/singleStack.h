#include<stack>
#include<iostream>
#include<vector>

using namespace std;
class mStack
{
public:
	int num;
	int value;
	
	mStack(int n, int v)
	{
		num = n;
		value = v;
	};
};



class singleStack
{
   public:
	   int L;//左边界
	   int cur;//当前位置
	   int R;//右边界
	   vector<int>  curPos;
	   vector<int>  leftPos;
	   vector<int>  rightPos;
	   stack<mStack>  s1;//[2 1 5 6 2 3]  单调增栈
	   void push(int t)
	   {
		   cur++;
		   if (s1.empty())
		   {
			   s1.push(mStack(cur, t));
		   }
		   else if (s1.top().value < t)
		   {
			   s1.push(mStack(cur, t));
		   }
		   else
		   {
			   while (!s1.empty() && s1.top().value >= t)
			   {
				   curPos.push_back(s1.top().value);
				   s1.pop();
				   if (!s1.empty())
				   {
					   L = s1.top().num;
				   }
				   else
					   L = -1;
				   saveInfo();
			   }
			   s1.push(mStack(cur, t));
		   }
	   }
	   void pop()
	   {
		   if(cur!=R-1)
		     s1.pop();
		   else
		   {
			   curPos.push_back(s1.top().value);
			   s1.pop();
			   if (!s1.empty())
			   {
				   L = s1.top().num;
			   }
			   else
				   L = -1;
			   leftPos.push_back(L);
			   rightPos.push_back(R);
		   }
	   }
	   int top()
	   {
		   return s1.top().value;
	   }

	   void saveInfo()
	   {

		   leftPos.push_back(L);
		   rightPos.push_back(cur);
		  
	   }
	   singleStack(int r)
	   {
		   L = -1;
		   cur = -1;
		   R = r;
	   }

};


int largestRectangleArea(vector<int> &nums) {
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	singleStack mystack(nums.size());
	for (int i = 0; i < nums.size(); i++)
	{
		mystack.push(nums[i]);
	}
	while (!mystack.s1.empty())
	{
		mystack.pop();
	}
	vector<int> result;
	for (int i = 0; i < nums.size(); i++)
	{
		result.push_back(mystack.curPos[i] * (mystack.rightPos[i] - mystack.leftPos[i] - 1));
	}
	int max = 0;
	for (int i = 0; i < result.size(); i++)
	{
		if (max < result[i])
			max = result[i];
	}
	return max;
	return 0;
	

}

int badHairDay(vector<int> &nums)
{
	int sum = 0;
	if (nums.size() == 0)
		return sum;
	stack<int>  s;
	s.push(nums[0]);
	for(int i=1;i<nums.size();i++)
	{

		while (!s.empty()&&s.top() <= nums[i])  
			s.pop();
		sum = sum + s.size();
		s.push(nums[i]);

	}
	return sum;
}

//[2 1 5 6 2 3]  单调增栈
int largestRectangleAreaTest(vector<int> &nums) 
{
	
	if (nums.size() == 0)
		return 0;
	int maxArea = 0;
	stack<int> s;
	for (int i = 1; i < nums.size(); i++)
	{
		while (!s.empty() && nums[s.top()] >= nums[i])
		{
			int j = s.top();//要弹出的数
			s.pop();
			int L = s.empty() ? -1 : s.top();
			int R = i;
			maxArea = max(maxArea, nums[j] * (R - L - 1));
		}
		s.push(i);
	}

	while (!s.empty())
	{
		int j = s.top();//要弹出的数
		s.pop();
		int L = s.empty() ? -1 : s.top();
		int R = nums.size();
		maxArea = max(maxArea, nums[j]* (R - L - 1));
	}
	return maxArea;
}