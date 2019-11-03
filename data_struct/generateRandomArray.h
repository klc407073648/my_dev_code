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
//�������������������һ�������С��[0,size]֮�䣬ֵС��value������
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

//��ȷ�������㷨
void rightMethod(vector<int> &a)
{
	sort(a.begin(), a.end());
}

//�㷨����
int myTest()
{
	int testTime = 20;//���Դ���
	int size = 20;//�����С
	int value = 100;//�������ֵ
	bool succeed = true;//�㷨������ȷ��־
	srand((unsigned)time(NULL));
	for (int i = 0; i < testTime; i++)
	{
		vector<int> array, array1, array2;//ԭ���飬��������1����������2
		array = generateRandomArray(size, value);
		array1 = array;//
		array2 = array;
		rightMethod(array1);//��ȷ�㷨����
		//quickSort(0, array2.size() - 1, array2);//��д�㷨������
		bucketSort(array2);
		//mergeSort(0, array2.size() - 1, array2);
		//selectionSort(array2);
		//insertionSort(array2);
		//bubbleSort(array2);
		//heapSort(array2);
		cout << "ԭ���У�        ";
		for (int i = 0; i<array.size(); i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
		cout << "��ȷ��������  ";
		for (int i = 0; i<array1.size(); i++)
		{
			cout << array1[i] << " ";
		}
		cout << endl;
		cout << "��д���㷨����";

		for (int i = 0; i<array2.size(); i++)
		{
			cout << array2[i] << " ";
		}
		cout << endl;
		if (array1 != array2)//�Ƚ������㷨����Ƿ�һ��
		{
			succeed = false;
			cout << "����ʱ��ԭ���У�      ";
			for (int i = 0; i<array.size(); i++)
			{
				cout << array[i] << " ";
			}
			break;
		}
	}
	succeed == true ? cout << "�㷨��ȷ" << endl : cout << "�㷨����" << endl;

	return 0;
}



#endif // !_GENERATERANDOMARRAR_H_