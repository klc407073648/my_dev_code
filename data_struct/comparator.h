#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_


#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//�Ƚ�����ʹ��

//template <class RandomAccessIterator>
//void sort(RandomAccessIterator first, RandomAccessIterator last);
//
//template <class RandomAccessIterator, class Compare>
//void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
//STL�ڵ�sort����������������
//1. Ҫ������һ����Χ[first, last)
//2. ��������������ô��㷨��������֧��������ʵ�������vector, deque, string��
//3.��һ���汾ʹ��operator<���бȽϣ�Ĭ���������򣬵ڶ����汾ʹ��comp���Ƚ�.
//	���ڲ���comp��comp������ͬ���͵Ĳ����������һ���������ڵڶ�������ǰ�棬����true�����򷵻�false


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
	 //������Ҫ�Ĳ���������
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
	return s1.age < s2.age;//��С����
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
	sort(student.begin(), student.end()); //CompAge  ��  less<Student>()
	for (int i = 0; i < 3; i++)
		cout << student[i].id << " " << student[i].age << " " << student[i].name << endl;
}
