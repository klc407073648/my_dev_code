#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_


#include<vector>
#include"helpFunction.h"
using namespace std;


void bubbleSort(vector<int> &nums)
{
	if (nums.size() <2)
		return;
	int size = nums.size()-1;
	for (int i = size,j; i>0; i--)
	{
		for (j = 0; j < i; j++)
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
	}
}

#endif // !_BUBBLESORT_H_
