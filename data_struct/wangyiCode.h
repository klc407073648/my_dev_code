#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
set<string> myset;
//������ϣ�n��'a'��m��'z'��ֻ�����$C_{ n + m }^n$����Ϊcount(n + m, n) �����ʡ�
//˼·��
//�����һ���ַ�Ϊa����ʣ��n - 1��'a'��m��'z'��ɵ�������ֻ�ܹ���count(n - 1 + m, n - 1)�����ʣ�
//�����ֵ���ǰcount(n - 1 + m, n - 1)�����ʡ�
//�Ƚ�k��count(n - 1 + m, n - 1)����kС��˵��k��ǰcount(n - 1 + m, n - 1)�����ʣ����һ���ַ���Ϊ'a'��
//�����⻯Ϊ��������(n - 1��'a'��m��'z')�ҵ���k������
//��k����˵����һ���ַ���Ϊ'z', ��������'z'��ͷ�ĵ����еĵ�k - count(n - 1 + m, n - 1)����
//�����⻯Ϊ��������(n��'a'��m - 1��'z')�ҵ���k - count(n + m - 1, m - 1)�����ʡ�
//eg : n = 2, m = 2, k = 5
//	�����һ���ַ�Ϊa, ��ʣ��1��a, 2��zֻ�ܹ���3�����ʣ������ֵ���ǰ3������(aamm, amam, amma)
//	k>3�����һ���ַ���Ϊz��ԭ���⻯Ϊ��n = 2, m = 1, k = 2������ʣ��2��a��1��z���ҵ���2������


void generateString(string str, int n, string aimstr)
{
	if (n == 0)
	{
		if (myset.count(aimstr) == 0)
		{
			myset.insert(aimstr);
		}

		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			string s = str;
			char myStr = s[i];
			s.erase(s.begin() + i);
			generateString(s, n - 1, aimstr + myStr);
		}

	}

}

int  myTestCode1()
{
	int n, m;
	long k;
	cin >> n;
	cin >> m;
	cin >> k;
	string str1(n,'a');
	string str2(m,'z');
	string str = str1 + str2;
	generateString(str, n + m,"");
	if (myset.size() < k)
		return -1;
	set<string>::iterator it1;
	int i = 1;
	for (it1 = myset.begin(); i <= k; i++,it1++)
	{
		if(i==k)
		 cout << *it1;
	}
	int s = 0;
	return 0;

}
