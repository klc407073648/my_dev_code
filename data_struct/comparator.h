#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_


#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//比较器的使用

//template <class RandomAccessIterator>
//void sort(RandomAccessIterator first, RandomAccessIterator last);
//
//template <class RandomAccessIterator, class Compare>
//void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
//STL内的sort函数有以下特征：
//1. 要求输入一个范围[first, last)
//2. 随机迭代器，能用此算法的容器是支持随机访问的容器：vector, deque, string。
//3.第一个版本使用operator<进行比较，默认升序排序，第二个版本使用comp做比较.
//	关于参数comp，comp带两个同类型的参数，如果第一个参数排在第二个参数前面，返回true，否则返回false


class Student
{
public:
	int id;
	int age;
	string name;
	//bool CompAge(const Student& s1, const Student& s2);
	bool operator < (const Student& right) const
	{
		return age < right.age;
	}//asscend
	 //降序需要的操作符函数
	bool operator >(const Student& right) const
	{
		return age > right.age;
	}//asscend
	Student() {};
	Student(int m_id, int m_age, string m_name) :id(m_id), age(m_age),name(m_name)
	{}
	~Student() {};

};


bool CompAge(const Student& s1, const Student& s2)
{
	return s1.age < s2.age;//从小到大
}

bool CompId(const Student& s1, const Student& s2)
{
	return s1.id > s2.id;
}

#endif

void studentTest()
{
	vector<Student> student;
	Student stu[3] = { Student(10001,20,"klc"),Student(10002,15,"gsc"),Student(10003,40,"lz") };
	for (int i = 0; i < 3; i++)
		student.push_back(stu[i]);
	for (int i = 0; i < 3; i++)
		cout << student[i].id << " " << student[i].age << " " << student[i].name << endl;
	sort(student.begin(), student.end()); //CompAge  ，  less<Student>()
	for (int i = 0; i < 3; i++)
		cout << student[i].id << " " << student[i].age << " " << student[i].name << endl;
}
