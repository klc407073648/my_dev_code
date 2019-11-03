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
//��ӡ�ַ�����ȫ����
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




//�ظ���ĸ�İ��ֵ��� ȫ�������
vector<string> result;

void findAllSort(string str1, int n, string str)//�ҵ�����ȫ���򣨺��ظ��ģ�
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
bool cmp(string &str1, string &str2)//С��
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