#include<iostream>
#include<vector>
using namespace std;






void printMatrix(vector<vector<int>> &nums)
{

	int row = nums.size()-1;
	int col = nums[0].size()-1;
	int top=0,left=0, bottom=row,right=col;
	int i = 0, j = 0;
	while (i <= bottom &&j <= right)
	{
		if (i == bottom)
		{
			while (j <= right )
			{
				cout << nums[i][j++] << " ";
			}
			break;
		}
		else if (j == right)
		{
			while (i <= bottom)
			{
				cout << nums[i++][j] << " ";
				break;
			}
		}
		else
		{
			while (j <= right - 1)
			{
				cout << nums[i][j++]<< " ";
			}
			while (i <= bottom - 1)
			{
				cout << nums[i++][j] << " ";
			}
			while (j >= left+1)
			{
				cout << nums[i][j--] << " ";
			}
			while (i >= top+1)
			{
				cout << nums[i--][j] << " ";
			}
			left++; right--; top++; bottom--;
			i++; j++;
		}
	}
	

}

void myPrintMatrix()
{
	vector<vector<int>> nums = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<vector<int>> nums1 = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
	vector<vector<int>> nums2= { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
	printMatrix(nums2);
}


