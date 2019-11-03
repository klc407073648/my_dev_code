#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_



#include<vector>
using namespace std;

void insertionSort(vector<int> &nums)
{
	if (nums.size() < 2)
		return;
	int size = nums.size() - 1;
	for (int i = 1, j; i <= size; i++)
	{
		int tmp = nums[i];
		for (j = i; j > 0 && tmp < nums[j - 1]; j--)
			nums[j] = nums[j - 1];
		nums[j] = tmp;
	}
}

#endif // !_INSERTIONSORT_H_