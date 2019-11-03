#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getNextArray(string str);

int getIndexOf(string s1, string s2)
{
	if (s1.empty() || s2.empty() || s2.size() < 1 || s1.size() < s2.size())
	{
		return -1;
	}
	string str1 = s1;
	string str2 = s2;
	int i1 = 0; 
	int i2 = 0;
	vector<int> next = getNextArray(str2);
	while (i1 < str1.size() && i2 < str2.size())
	{
		if (str1[i1] == str2[i2])
		{
			i1++;
			i2++;
		}
		else if (next[i2] == -1)
		{
			i1++;
		}
		else {
			i2 = next[i2];
		}
	}
	return i2 == str2.size() ? i1 - i2 : -1;
}


vector<int> getNextArray(string str)
{
	
	vector<int> nextArr(str.size());
	if (str.size() == 1)
	{
		nextArr[0] = -1;
		return  nextArr;
	}
	nextArr[0] = -1;
	nextArr[1] = 0;
	int i = 2;
	int cn = 0;
	while (i<str.size())
	{
		if (str[i - 1] == str[cn])
		{
			nextArr[i++] = ++cn;
		}
		else if (cn > 0)
		{ 
			cn = nextArr[cn];
		}
		else
		{ 
			nextArr[i++] = 0;
		}
	}
	return nextArr;
}

void getNextArrTest()
{
	vector<int> t= getNextArray("abcabcd");
	int ss1=getIndexOf("abcabcd", "ccab");
	int ss2 = getIndexOf("abcabcd", "abc");
	int ss3 = getIndexOf("abcabcd", "cd");
	int s = 0;
}
