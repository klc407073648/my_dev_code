#ifndef _HOLLAND_H_
#define _HOLLAND_H_



#include<vector>
#include"helpFunction.h"
//#include"generateRandomArray.h"
using namespace std;
//给定一个数组arr， 和一个数num， 请把小于等于num的数放在数
//组的左边， 大于num的数放在数组的右边。
//要求额外空间复杂度O(1)， 时间复杂度O(N)

void codeTest1(int num,vector<int> &nums)
{
	if (nums.size() < 2)
		return;
	int size = nums.size() - 1;
	int less = 0;
	int more = size;
	while(less<more)
	{
		while (less<more&&nums[less] <= num)
		{
			less++; 
		}
		while(less<more&&nums[more]>num)
		{
			more--;
		}
		if (less < more)
			swap(nums[less++], nums[more--]);
	}
}

//问题二（荷兰国旗问题）
//给定一个数组arr， 和一个数num， 请把小于num的数放在数组的
//左边， 等于num的数放在数组的中间， 大于num的数放在数组的
//右边。
//要求额外空间复杂度O(1)， 时间复杂度O(N)
void holland(int num, vector<int> &nums)
{
	if (nums.size() < 2)
		return;
	int size = nums.size() - 1;
	int less = -1;
	int more = size+1;
	int i = 0;
	while (i<more)
	{
		if (i < more&&nums[i] < num)
		{
			swap(nums[++less],nums[i++]);
		}
		else if (i<more&&nums[i] >num)
		{
			swap(nums[i], nums[--more]);
		}
		else
			i++;
	}
}



int codeTest11()
{
	int testTime = 20;//测试次数
	int size = 20;//数组大小
	int value = 100;//数组最大值
	bool succeed = true;//算法测试正确标志
	srand((unsigned)time(NULL));
	for (int i = 0; i <testTime; i++)
	{
		vector<int> array;//原数组
		array = generateRandomArray(size, value);
		cout << "原序列：";
		for (int i = 0; i < array.size(); i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
		holland(30, array);
		cout << "排序后：";
		for (int i = 0; i < array.size(); i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
		

	}
	return 0;
}




#endif // !_HOLLAND_H_