#include<vector>
#include<iostream>
using namespace std;


bool findNumberInMatrix(int k, vector<vector<int>> &nums)
{
	if (nums.size() == 0)
		return false;
	int row = nums.size() - 1;
	int col = nums[0].size() - 1;
	int A = 0, B = col;
	while (A <= row&&B >= 0)
	{
		if (nums[A][B] < k)
			A++;
		else if (nums[A][B] > k)
			B--;
		else
			return true;
	}
	return false;

}

void findNumberInMatrixTest()
{
	vector<vector<int>> nums = { { 1,2,3,4 },{ 5,6,7,8 },{ 9,10,11,12 },{ 13,14,15,16 } };
	bool b1=findNumberInMatrix(10, nums);
	bool b2 = findNumberInMatrix(17, nums);
	cout << b1 << " " << b2 << endl;
}
