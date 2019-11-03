#include<vector>
#include<iostream>

using namespace std;

int binSearch(vector<int> &nums, int k)
{
	if (nums.size() == 0)
		return -1;
	int left = 0;
	int right = nums.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) >> 1;

		if (nums[mid] < k)
		{
			left = mid + 1;
		}
		else if(nums[mid] > k)
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return -1;
}

void binSearchTest()
{
	vector<int> nums = { 0,1,2,3,7,8,9};
	binSearch(nums, 2);
	cout << binSearch(nums, 8) << " "<<binSearch(nums,9) << " "<<binSearch(nums, 3) << endl;
}
