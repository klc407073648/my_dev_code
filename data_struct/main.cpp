#include<iostream>
#include"quickSort.h"
#include"generateRandomArray.h"
#include"Holland.h"
#include"heapSort.h"
#include"comparator.h"
#include<algorithm>
#include"StackAndQueueQuestion.h"
#include"myStack.h"
#include"printMatrix.h"
#include"findNumberInMatrix.h"
//#include"listQuestion.h"
#include"addTwoNumber.h"
//#include"divideList.h"
//#include"treeTraversal.h"
//#include"succeedNode.h"
//#include"serializeTree.h"
#include"hashMap.h"
//#include"factorial.h"
//#include"Hanoi.h"
#include"printAllSubsquence.h"
//#include"KMP.h"
//#include"maxInWindows.h"
//#include"priority.h"
//#include"findGreatestSumOfSubArray.h"
//#include"deleteDuplication.h"
//#include"morris.h"
//#include"kthNode.h"
//#include"BFS.h"
#include"singleStack.h"
#include"Manacher.h"
#include"bulidOutline.h"
#include"maxLengthSubArray.h"
#include"multimap.h"
#include"binSearch.h"
#include"hasPathInMatrix.h"
#include"doProjectMakeMaxMoney.h"
#include"bestArrange.h"
//#include"findMaxSumOfBinaryTree.h"
#include"maxSearchSubTree.h"
#include"tetrisGame.h"
#include"wangyiCode.h"
#include"longTest.h"
#include"meiTuan.h"
#include"baiduTest3.h"
#include"luckyID.h"
#include"foodTest.h"
#include"myString.h"
#include"xiaomi.h"

class Base
{
public:
	Base() { Print(); }
	virtual ~Base(){}
	virtual void Print()
	{
		cout << "Base" << endl;
	}
};


class Inherit:public Base
{
public:
	Inherit() {}
	virtual ~Inherit() {}
	virtual void Print()
	{
		cout << "Inherit" << endl;
	}
};


int main()
{
	/*staticTest a,b;
	a.staticFun();
	b.staticFun();*/

	//studentTest();

	/*printAllSubsquenceTest();
	printAllSortTest();*/
	/*getNextArrTest();*/
	//KthNodeTest();
	//mapTest3();
	/*vector<vector<int>> nums1 = { {1,2,3},{4,5,6 },{7,8,9}};
	vector<vector<int>> nums2 = { { 1,2,3 },{ 4,5,6 } };
	vector<vector<int>>  s1 = fanzhuanMatrix(nums1);
	printMatrix111(s1);
	vector<vector<int>>  s2 = fanzhuanMatrix(nums2);
	printMatrix111(s2);
	int t = 0;*/
	/*vector<int> nums1 = { 2,1,5,6,2,3 };
	int t=largestRectangleAreaTest(nums1);*/
	/*vector<int> nums1 = { 5,2,4,2,6,1 };
	int t=badHairDay(nums1);*/
	/*int t=maxLcpsLength("abc1234321ab");
	int s = 0;*/
	/*string str = "I am   a student";
	string s=reverseString(str);
	 cout << s;*/
	/*vector<vector<int>> nums1 = { { 2,4,4 },{ 1,3,3 },{ 5,6,1 } };
	buildingOutline(nums1);
	int t = 0;*/
	/*vector<int> nums1 = { 7,3,2,1,1,7,-6,-1,7 };
	int s=maxLengthSubArrayOfSum(nums1,7);*/
	//morrisTravealTest();
	//bfsTest();
	/*int a = 10;
	auto s = [a](int x)->int{return a + x; };
	cout << s(10);*/
	/*binSearchTest();*/
	//int a[] = { 2,1,3,1,4 };
	//int length = 5;
	//int *duplication;
	//int b = -1;
	//	duplication = &b;
	//duplicate(a,length,duplication);
	//printAllSort1Test();
	/*myMeiTuan();*/
	/*
	char str[]= "aabbc";
	char a[20];
	char *ss=strcpy1(a, str);
	cout << a;*/
	//xiaomiTest();
	//int s = 0;
	//int ss = 255;
	//string str = std::to_string(ss);
	//Inherit inherit;
	float s = 3.3*102;
	printf("%f", s );// s * 102;
	return 0;
}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n,m,t;
//	int sum = 0;
//	cin >> n;
//	vector<int>  mArray;
//	vector<int>  sumArray;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> t;
//		sum = sum + t;
//		sumArray.push_back(sum);
//	}
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> t;
//		mArray.push_back(t);
//	}
//	
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (mArray[i] <=sumArray[j])
//			{
//				cout << j + 1<<endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//#include<math.h>
//using namespace std;
//
//vector<int> findMaxAndMin(vector<int> &nums)
//{
//	int max = INT_MIN;
//	int min = INT_MAX;
//	int maxPos = 0;
//	int minPos = 0;
//	vector<int>  res;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (nums[i] > max)
//		{
//			max = nums[i];
//			maxPos = i;
//		}
//		if (nums[i] <min)
//		{
//			min = nums[i];
//			minPos = i;
//		}
//	}
//	res.push_back(minPos);
//	res.push_back(maxPos);
//
//}
//
//int main()
//{
//
//	int n, k,ai;
//	cin >> n;
//	cin >> k;
//
//	vector<int>  arr;
//	vector<int>  tmp;
//	map<int, int> mymap;
//	for (int i = 0; i<n; i++)
//	{
//		cin >> ai;
//		arr.push_back(ai);
//	}
//	vector<int>  tmp(arr); 
//	sort(tmp.begin(), tmp.end());
//	if(k>0&&tmp[0]!=tmp[tmp.size()-1])
//	{ 
//		vector<int>  s1 = findMaxAndMin(arr);
//		arr[s1[1]]--;
//		arr[s1[0]]++;
//		cout << s1[1] << " " << s1[0];
//	    
//	}
//
//	return 0;
//}
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int n, x;
//	long y;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		cin >> y;
//	}
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<functional>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	long long ai,bi,num=0;
//	vector<int>  array1, array2;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> ai;
//		array1.push_back(ai);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cin >> bi;
//		array2.push_back(bi);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		priority_queue<int, deque<int>, greater<int>> smallQueue;
//		priority_queue<int> bigQueue;
//		for (int j = i; j < n; j++)
//		{ 
//		bigQueue.push(array1[j]);
//		smallQueue.push(array2[j]);
//		if (bigQueue.top() < smallQueue.top())
//			num++;
//		else
//			break;
//		}
//	}
//	cout << num;
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<functional>
//
//using namespace std;
//
//class myClass
//{
//public:
//	int s;
//	int t;
//	myClass(int s, int t)
//	{
//		this->s = s;
//		this->t = t;
//	}
//
//};
//
//bool cmp1(myClass &m1, myClass &m2)
//{
//	return m1.t < m2.t;
//}
//
//int main()
//{
//	long N, M, num = 0;
//	cin >> N;
//	cin >> M;
//	int si, ti;
//	vector<myClass> myArr;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> si;
//		cin >> ti;
//		myArr.push_back(myClass(si, ti));
//	}
//	sort(myArr.begin(), myArr.end(), cmp1);
//	int start;
//	for (int i = 0; i < N; i++)
//	{
//		if (i = 0)
//		{
//			start = myArr[i].t;
//			num++;
//		}
//		if (myArr[i].s >= start&& myArr[i].t<M) {
//			num++;
//			start = myArr[i].t;
//		}
//	}
//	cout << num;
//
//
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	vector<string> result;
//	while (t--)
//	{
//		long n;
//		cin >> n;
//		vector<string> res;
//		while (n--)
//		{
//			string str;
//			cin >> str;
//			res.push_back(str);
//		}
//		int flag = 0;
//		string firstStr = res[0];
//		int size = firstStr.size();
//		for (int i = 1; i < res.size(); i++)
//		{
//			if (res[i].size() != size)
//				break;
//			int pos=-1;
//			for (int j = 0; j < size; j++)
//			{
//				if (res[i][j] == firstStr[0])
//				{
//					pos = j;
//				}
//			}
//			if (pos == -1)
//				break;
//			/*int pos = res[i].find_first_of[firstStr[0]];*/
//			string sunStr, niStr;
//
//			for (int j = pos; j < size; j++)
//				sunStr = sunStr + res[i][j];
//			for (int j = 0; j<pos; j++)
//				sunStr = sunStr + res[i][j];
//
//			for (int j = pos; j >= 0; j--)
//				niStr = niStr + res[i][j];
//			for (int j = size - 1; j>pos; j--)
//				niStr = niStr + res[i][j];
//
//			if (firstStr == sunStr || firstStr == niStr)
//			{
//			    flag = 1;
//				continue;
//			}
//			else
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			result.push_back("Yeah");
//		}
//		else
//		{
//			result.push_back("Sad");
//		}
//	}
//
//	for (int i = 0; i < result.size(); i++)
//	{
//		if (i ==result.size()-1)
//		{
//			cout << result[i];
//		}
//		else
//		{
//			cout << result[i]<< endl;
//		}
//	}
//
//
//	return 0;
//}