#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_




#include<vector>
#include<stdlib.h>
using namespace std;
int partition(int L, int R, vector<int> &nums);
//随机快排,是最常用的随机排序。
void quickSort(int L, int R, vector<int> &nums)
{
	if (L >= R)
		return ;
	int mid = partition(L, R, nums);
	quickSort(L, mid - 1, nums);
	quickSort(mid + 1, R, nums);
}
int partition(int L, int R, vector<int> &nums)
{
	swap(nums[L + (int)(rand() % (R - L + 1))], nums[L]);
	int less = L + 1;
	int more = R ;
	while (L<more)
	{
		if (nums[less] <=nums[L])
			swap(nums[less++], nums[L++]);
		else
			swap(nums[less], nums[more--]);
	}
	
	return L;
}


//int partition(int L, int R, vector<int> &nums)
//{
//	swap( nums[L+(int)(rand()%(R-L+1))],nums[L]);
//	int tmp = nums[L];
//	while (L<R)
//	{
//		while (L<R&&tmp<=nums[R])
//		{
//			R--;
//		}
//		if (L < R)
//			nums[L++] = nums[R];
//		while (L<R&&tmp>nums[L])
//		{
//			L++;
//		}
//		if (L<R)
//			nums[R--]=nums[L];
//	}
//	nums[L] = tmp;
//	return L;
//} 
//



//public static void quickSort(int[] arr, int l, int r) {
//	if (l < r) {
//		swap(arr, l + (int)(Math.random() * (r - l + 1)), r);
//		int[] p = partition(arr, l, r);
//		quickSort(arr, l, p[0] - 1);
//		quickSort(arr, p[1] + 1, r);
//	}
//}
//
//public static int[] partition(int[] arr, int l, int r) {
//	int less = l - 1;
//	int more = r;
//	while (l < more) {
//		if (arr[l] < arr[r]) {
//			swap(arr, ++less, l++);
//		}
//		else if (arr[l] > arr[r]) {
//			swap(arr, --more, l);
//		}
//		else {
//			l++;
//		}
//	}
//	swap(arr, more, r);
//	return new int[] { less + 1, more };
//}


#endif // !_QUICKSORT_H_