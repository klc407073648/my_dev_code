#include"randomArray.h"
#include"sort.h"

using namespace algorithm::sort;

randomArray::randomArray()
{

}
randomArray::~randomArray()
{

}

vector<int> randomArray::generateRandomArray(int size, int value)
{
	vector<int>  b;
	//srand((unsigned)time(int(rand()));
	int length = (int)((size + 1)*((rand() % 100)*0.01));
	for (int i = 0; i < length; i++)
	{
		//b.push_back((int)(rand() % value)- (int)(rand() % value));
		b.push_back((int)(rand() % value));
	}
	return b;
}

//��ȷ�������㷨
void randomArray::rightMethod(vector<int> &a)
{
	Sort mySort;
	mySort.quickSort(0,a.size()-1,a);
}

//����д���㷨����ȷ��
int randomArray::myTest(int m_testCount, int m_size , int m_maxValue , bool m_succeed )
{
	testCount = m_testCount;//���Դ���
	size = m_size;//�����С
	maxValue = m_maxValue;//�������ֵ
	succeed = m_succeed;//�㷨������ȷ��־
	srand((unsigned)time(NULL));
	for (int i = 0; i < testCount; i++)
	{
		vector<int> array, array1, array2;//ԭ���飬��������1����������2
		array = generateRandomArray(size, maxValue);
		array1 = array;//
		array2 = array;
		Sort mySort;
		rightMethod(array1);//��ȷ�㷨����							
		mySort.bucketSort(array2);//Ͱ����
	
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
