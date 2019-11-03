#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
//arr = { 7,3,2,1,1,7,7,7 }
int maxLengthSubArrayOfSum(vector<int> &nums, int aim)
{
	map<int, int>  mymap;
	mymap.insert(pair<int, int>(0, -1));
	int maxValue = 0;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum = sum + nums[i];
		if (mymap.count(sum) == 0)
		{
			mymap.insert(pair<int, int>(sum, i));
		}
		int numberToFind =sum-aim;
		if (mymap.count(numberToFind) == 1)
		{
			maxValue =max(maxValue,i - mymap[numberToFind]);
		}
	}
	return maxValue;
}

//7 1 1 1 7 -6 -1 7
//7 0 8 1 9 2 10 3 17 4 11 5 17 6 24 7
int findGreatestSumOfSubArray(vector<int> &nums)
{
	map<int, int>  mymap;
	int sum = 0;
	int max = INT_MIN;
	mymap.insert(pair<int, int>(0, -1));
	for (int i = 0; i < nums.size(); i++)
	{
		sum = sum + nums[i];
		if (mymap.count(sum)==0)
		{
			mymap.insert(pair<int, int>(sum, i));
		}
	}
	map<int, int>::iterator it1,it2;
	it1 = mymap.begin();
	it2 = mymap.end();
	it2--;
	return it2->first - it2->first;

}
