 #ifndef _MERGESORT_H_
#define _MERGESORT_H_



#include<vector>
using namespace std;
void merge(int l1, int r1, int l2, int r2, vector<int> &nums);
void mergeSort(int left, int right, vector<int> &nums)
{
	if (left >= right)
		return;
	int mid = (left + right) >> 1;
	mergeSort(left, mid, nums);
	mergeSort(mid+1, right, nums);
	merge(left, mid, mid + 1, right, nums);

}


void merge(int l1, int r1, int l2, int r2, vector<int> &nums)
{
	int i = l1;
	int j = l2;
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);
	int k = 0;
	vector<int> tmp(n);

	while (i <= r1&&j <= r2)
	{
		tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
	}
	while(i<=r1)
		tmp[k++] = nums[i++];
	while (j <= r2)
		tmp[k++] = nums[j++];
	for (int i = 0; i < n; i++)
		nums[l1 + i] = tmp[i];
}


#endif // !_MERGESORT_H_