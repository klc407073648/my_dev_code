#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_



#include<vector>
#include<iostream>
using namespace std;
//堆就是完全二叉树，大根堆任何一棵子树的最大值都是头部，小根堆任何一棵子树的最小值都是头部
//找N个数的中位数，两个堆，一个大根堆一个小根堆
void heapInsert(vector<int> &nums, int index);
void heapify(vector<int> &nums, int index, int size);


void heapSort(vector<int> &nums) {
	if (nums.size() < 2) {
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		heapInsert(nums, i);
	}
	int size = nums.size();
	swap(nums[0], nums[--size]);//将最大值弹出
	while (size > 0) {
		heapify(nums, 0,size);//[0,size)上调整nums[0]使其成为大根堆
		swap(nums[0], nums[--size]);
	}
}


//构造大根堆
 void heapInsert(vector<int> &nums, int index) {
	while (nums[index] > nums[(index - 1) / 2]) {
		swap(nums[index], nums[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

void heapify(vector<int> &nums, int index, int size) {
	int left = index * 2 + 1;
	while (left < size) {
		int largest = left + 1 < size && nums[left + 1] > nums[left] ? left + 1 : left;
		largest = nums[largest] > nums[index] ? largest : index;
		if (largest == index) {
			break;
		}
		swap(nums[largest], nums[index]);
		index = largest;
		left = index * 2 + 1;
	}
}
//
//void myHeapTest()
//{
//	vector<int> a = { 9,5,4,10,15 };
//	heapSort(a);
//	for (int i = 0; i<a.size(); i++)
//	{
//		cout << a[i] << " ";
//	}
//}

#endif // !_HEAPSORT_H_