#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
//int longTest()
//{
//	long input;
//	cin >> input;
//	cout << hex << input;
//	long sum = 0;
//	
//	while (input != 0)//ÕýÊý
//	{
//		long yushu = input % 2;
//		input = input / 2;
//		sum = sum + yushu;
//		
//	}
//	cout << sum;
//	return 0;
//}
//class myClass
//{
//public:
//	long start;
//	long end;
//	myClass() {};
//	myClass(long s, long e)
//	{
//		start = s;
//		end = e;
//	}
//};
//int myTest222()
//{
//	int record;
//	long time,number,startTime,endTime;
//	cin >> record;
//	cin >> time;
//	map<long, myClass>  mymap;
//	map<long, myClass>::iterator it;
//	for (int i = 1; i <= record; i++)
//	{
//		cin >> number;
//		cin >> startTime;
//		cin >> endTime;
//		mymap[number] = myClass(startTime, endTime);
//	}
//	int flag = 0;
//
//	for (it = mymap.begin(); it != mymap.end(); it++)
//	{
//		if (it->second.start <= time&&it->second.end >= time)
//		{
//			cout << it->first << endl;
//			flag = 1;
//		}
//
//	}
//	if (flag = 0)
//		cout << "null";
//
//	int s = 0;
//	return 0;
//}

class LRU
{
public:
	
	map<int,int> mymap;
	int curSize;
	int maxSize;
	int get(int key)
	{
		if (mymap.count(key) == 1)
			cout << mymap[key];
		else
			return -1;
	}
	void put(int key,int value)
	{
		if (curSize == maxSize)
		{
			;
		}
	    if (mymap.count(key) == 1)
		{
				mymap[key] = value;
		}
		else 
		{
			mymap.insert(pair<int, int>(key, value));
			curSize++;
		}
	}
	LRU() {};
	LRU(int s)
	{
		curSize = 0;
		maxSize = s;
	}
};

int myTest333()
{
	int n;
	cin >> n;
	return 0;
}

int myTest44()
{
	int n;
	cin >> n;
	int count = 0;
    while (n != 0) {
	  count++;
	  n = n & (n - 1);
}
return count;
}

int myTest555()
{
	int n;
	cin >> n;
	unsigned int s = 1;
	int count = 0;
	while (s)
	{
		if (n&s) {
			count++;
		}
		s = s << 1;
	}

	return count;
}
