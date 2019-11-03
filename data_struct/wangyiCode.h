#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
set<string> myset;
//排列组合，n个'a'和m个'z'，只能组成$C_{ n + m }^n$，记为count(n + m, n) 个单词。
//思路：
//假设第一个字符为a，则剩下n - 1个'a'和m个'z'组成的子序列只能构成count(n - 1 + m, n - 1)个单词，
//且是字典中前count(n - 1 + m, n - 1)个单词。
//比较k和count(n - 1 + m, n - 1)，若k小，说明k是前count(n - 1 + m, n - 1)个单词，则第一个字符必为'a'。
//子问题化为在子序列(n - 1个'a'和m个'z')找到第k个单词
//若k大，则说明第一个字符必为'z', 单词是以'z'开头的单词中的第k - count(n - 1 + m, n - 1)个。
//子问题化为在子序列(n个'a'和m - 1个'z')找到第k - count(n + m - 1, m - 1)个单词。
//eg : n = 2, m = 2, k = 5
//	假设第一个字符为a, 则剩下1个a, 2个z只能构成3个单词，且是字典中前3个单词(aamm, amam, amma)
//	k>3，则第一个字符必为z。原问题化为在n = 2, m = 1, k = 2，即在剩下2个a，1个z中找到第2个单词


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
