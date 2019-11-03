#ifndef _GENERATERANDOMARRAR_H_
#define _GENERATERANDOMARRAR_H_



#include<math.h>
#include <iostream>
#include <ctime>
#include<vector>
#include<stack>
#include<algorithm>
#include"bubbleSort.h"
#include"selectionSort.h"
#include"insertionSort.h"
#include"mergeSort.h"
#include"heapSort.h"
#include"bucketSort.h"
//随机数组生成器：生成一个数组大小在[0,size]之间，值小于value的数组
vector<int> generateRandomArray(int size,int value)
{
	vector<int>  b;
	//srand((unsigned)time(int(rand()));
	int length = (int)((size+1)*((rand() % 100)*0.01));
	for (int i = 0; i < length; i++)
	{
		//b.push_back((int)(rand() % value)- (int)(rand() % value));
		b.push_back((int)(rand() % value));
	}
	return b;
}

//正确的排序算法
void rightMethod(vector<int> &a)
{
	sort(a.begin(), a.end());
}

//算法测试
int myTest()
{
	int testTime = 20;//测试次数
	int size = 20;//数组大小
	int value = 100;//数组最大值
	bool succeed = true;//算法测试正确标志
	srand((unsigned)time(NULL));
	for (int i = 0; i < testTime; i++)
	{
		vector<int> array, array1, array2;//原数组，待排数组1，待排数组2
		array = generateRandomArray(size, value);
		array1 = array;//
		array2 = array;
		rightMethod(array1);//正确算法排序
		//quickSort(0, array2.size() - 1, array2);//编写算法的排序
		bucketSort(array2);
		//mergeSort(0, array2.size() - 1, array2);
		//selectionSort(array2);
		//insertionSort(array2);
		//bubbleSort(array2);
		//heapSort(array2);
		cout << "原序列：        ";
		for (int i = 0; i<array.size(); i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
		cout << "正确方法排序：  ";
		for (int i = 0; i<array1.size(); i++)
		{
			cout << array1[i] << " ";
		}
		cout << endl;
		cout << "我写的算法排序：";

		for (int i = 0; i<array2.size(); i++)
		{
			cout << array2[i] << " ";
		}
		cout << endl;
		if (array1 != array2)//比较两种算法结果是否一致
		{
			succeed = false;
			cout << "出错时的原序列：      ";
			for (int i = 0; i<array.size(); i++)
			{
				cout << array[i] << " ";
			}
			break;
		}
	}
	succeed == true ? cout << "算法正确" << endl : cout << "算法错误" << endl;

	return 0;
}



#endif // !_GENERATERANDOMARRAR_H_