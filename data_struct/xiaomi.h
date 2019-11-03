#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int xiaomiTest()
{
	vector<string> res;
	string str;
	vector<string> jinzhi;
	vector<string> shuzhi;
	vector<int>  result;
	map<int, int> mymap;
	map<int, int>::iterator it;
	while (cin >> str)
	{
		if (str != "END")
			res.push_back(str);
		else
			break;
	}
	for (int i = 0; i < res.size(); i++)
	{
		int pos = res[i].find('#');
		jinzhi.push_back(res[i].substr(0, pos));
		shuzhi.push_back(res[i].substr(pos + 1, res[i].size() - 1));
	}
	for (int i = 0; i < res.size(); i++)
	{
		int jinzhiF;
		int sum = 0;
		if (jinzhi[i].size() == 2)
		{
			int h = (jinzhi[i].at(0) - '0') * 10;
			int l = (jinzhi[i].at(1) - '0') * 1;
			jinzhiF = h + l;
		}
		else
		{
			jinzhiF = jinzhi[i].at(0) - '0';
		}
		int k = 0;
		for (int j = shuzhi[i].size() - 1; j >= 0; j--)
		{
			if (shuzhi[i].at(j) >= 'a'&&shuzhi[i].at(j) <= 'z')
			{
				sum = sum + (shuzhi[i].at(j) - 'a' + 10)*pow(jinzhiF, k);
			}
			else
			{
				sum = sum + (shuzhi[i].at(j) - '0')*pow(jinzhiF, k);
			}
			k++;
		}
		result.push_back(sum);

	}
	for (int i = 0; i < result.size(); i++)
	{
		if (mymap.count(result[i]) == 1)
		{
			mymap[result[i]]++;
		}
		else
		{
			mymap.insert(pair<int, int>(result[i], 1));
		}
	}
	if (mymap.size() == result.size())
	{
		cout << "None";
		return 0;
	}
	int tmp;
	for (it = mymap.begin(); it != mymap.end(); it++)
	{
		if (it->second == 1)
		{
			tmp = it->first;
			break;
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] == tmp)
		{
			cout << res[i];
		}

	}
	return 0;
}
