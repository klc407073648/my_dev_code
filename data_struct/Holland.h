#ifndef _HOLLAND_H_
#define _HOLLAND_H_



#include<vector>
#include"helpFunction.h"
//#include"generateRandomArray.h"
using namespace std;
//����һ������arr�� ��һ����num�� ���С�ڵ���num����������
//�����ߣ� ����num��������������ұߡ�
//Ҫ�����ռ临�Ӷ�O(1)�� ʱ�临�Ӷ�O(N)

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

//������������������⣩
//����һ������arr�� ��һ����num�� ���С��num�������������
//��ߣ� ����num��������������м䣬 ����num�������������
//�ұߡ�
//Ҫ�����ռ临�Ӷ�O(1)�� ʱ�临�Ӷ�O(N)
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
	int testTime = 20;//���Դ���
	int size = 20;//�����С
	int value = 100;//�������ֵ
	bool succeed = true;//�㷨������ȷ��־
	srand((unsigned)time(NULL));
	for (int i = 0; i <testTime; i++)
	{
		vector<int> array;//ԭ����
		array = generateRandomArray(size, value);
		cout << "ԭ���У�";
		for (int i = 0; i < array.size(); i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
		holland(30, array);
		cout << "�����";
		for (int i = 0; i < array.size(); i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
		

	}
	return 0;
}




#endif // !_HOLLAND_H_