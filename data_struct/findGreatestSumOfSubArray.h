#include<vector>
using namespace std;

int findGreatestSumOfSubArray(vector<int> nums)
{
	
	int max = INT_MIN;
	
	for(int i=0,j,k;i<nums.size();i++)
	{ 
		
		for ( j = i; j < nums.size(); j++)
		{
		   int sum = 0;
			for (k = i; k <=j; k++)
			{
				sum = sum + nums[k];
			}
		   if (sum > max)
			max = sum;
		}
		
	}
	return max;
}

void findGreatestSumOfSubArrayTest()
{
	vector<int> nums1 = { 1,-5,4,7 };
	int t = findGreatestSumOfSubArray(nums1);
	int s = 0;
}
