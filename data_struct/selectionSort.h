#ifndef _SELECTIONSORT_H_
#define _SELECTIONSORT_H_



#include<vector>
#include"helpFunction.h"
using namespace std;

void selectionSort(vector<int> &nums)
{
	if (nums.size() < 2)
		return;
	int size = nums.size() - 1;
	for(int i=0,j,least;i<=size;i++)
	{ 
		for(j=i+1,least=i;j<=size;j++)
		{
			if (nums[j] < nums[least])
				least = j;
		}
		if (i != least)
			swap(nums[i], nums[least]);
	}
}


#endif // !_SELECTIONSORT_H_