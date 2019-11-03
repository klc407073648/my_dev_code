#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_



#include<vector>
#include<iostream>
using namespace std;
//�Ѿ�����ȫ��������������κ�һ�����������ֵ����ͷ����С�����κ�һ����������Сֵ����ͷ��
//��N��������λ���������ѣ�һ�������һ��С����
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
	swap(nums[0], nums[--size]);//�����ֵ����
	while (size > 0) {
		heapify(nums, 0,size);//[0,size)�ϵ���nums[0]ʹ���Ϊ�����
		swap(nums[0], nums[--size]);
	}
}


//��������
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