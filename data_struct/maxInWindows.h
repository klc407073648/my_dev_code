#include<vector>
#include<list>
using namespace std;

vector<int> maxInWindows(vector<int> &nums, int size)
{
	vector<int> result;
	if (nums.size() == 0)
		return result;
	list<int> *res=new list<int>();
	int i = 0;
	while (i < nums.size())
	{
		while (res->size() > 0 && nums[res->back()] <= nums[i])
		{
			res->pop_back();
		}
		res->push_back(i);
		if (res->front() == i-size)
			res->pop_front();
		if(i>=size-1)
			result.push_back(nums[res->front()]);
		i++;
	}
	return result;

}

void  maxInWindowsTest()
{
	vector<int> tt = { 2,3,4,2,6,2,5,1 };
	vector<int> t = maxInWindows(tt, 3);
	int s = 0;

}
