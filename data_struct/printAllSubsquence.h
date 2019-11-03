#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



void printAllSubsquence(vector<char> &chars,int n, string str)
{
	if (n == chars.size() )
	{
		cout << str << endl;
		return;
	}
	else
	{
		printAllSubsquence(chars, n + 1,str);
		printAllSubsquence(chars, n + 1, str+chars[n]);
	}
}
//打印字符串的全排列
void printAllSubsquenceTest()
{
	vector<char> chars = { 'a','c','c' };
	printAllSubsquence(chars, 0, "");
}

void printAllSort(vector<char> &chars, int n, string str)
{
	if (n == 0)
	{
		cout << str << endl;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			vector<char> s = chars;
			char myStr = s[i];
			s.erase(s.begin() + i);
			printAllSort(s, n-1, str + myStr);
		}
	
	}

}

void printAllSortTest()
{
	vector<char> chars = { 'A','A','C' };
	printAllSort(chars, 3, "");
}




//重复字母的按字典序 全排序输出
vector<string> result;

void findAllSort(string str1, int n, string str)//找到所有全排序（含重复的）
{
	if (n == 0)
	{
		result.push_back(str);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			string s = str1;
			char myStr = s[i];
			s.erase(s.begin() + i);
			findAllSort(s, n - 1, str + myStr);
		}

	}
}
//
bool cmp(string &str1, string &str2)//小于
{
	return str1 +str2<str2 + str1;
}
vector<string> Permutation(string str) {
	if (str.empty())
		return result;
	findAllSort(str, str.size(), "");
	sort(result.begin(), result.end(), cmp);
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;

}

void printAllSort1(vector<char> &chars, int n, string str)
{
	if (n == chars.size())
	{
		cout << str <<endl;
	}
	else
	{ 
	   for (int i = n; i < str.size(); i++)
	   {
			/*swap(chars[n], chars[i]);
			printAllSort1(chars, i + 1,);*/
	    }
	}
	
}

void printAllSort1Test()
{
	/*string str = "abc";
	printAllSort1(str, 0);*/
}