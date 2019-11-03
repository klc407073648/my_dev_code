#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int idTest()
{
	string str;
	cin >> str;
	if (str.size() != 6)
	{
		cout << "error";
		return 0;
	}
	vector<int> v1, v2;
	int firstSum = 0, secondSum = 0;
	for (int i = 0; i<6; i++)
	{
		if (i >= 0 && i<3)
		{
			v1.push_back(str[i] - '0');
			firstSum = str[i] - '0' + firstSum;
		}
		else
		{
			v2.push_back(str[i] - '0');
			secondSum = str[i] - '0' + secondSum;
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	if (firstSum == secondSum)
	{
		cout << 0;
		return 0;
	}
	else if (firstSum > secondSum)
	{
		int chazhi = firstSum - secondSum;
		if (9 - v2[0] >= chazhi)
		{
			cout << 1;
			return 0;
		}
		else if (9 - v2[0] < chazhi)
		{
			chazhi = chazhi - (9 - v2[0]);
		}

		if (9 - v2[1] >= chazhi)
		{
			cout << 2;
			return 0;
		}
		else if (9 - v2[1] < chazhi)
		{
			cout << 3;
			return 0;
		}
	}
	else if (firstSum <secondSum)
	{
		int chazhi = secondSum - firstSum;
		if (9 - v1[0] >= chazhi)
		{
			cout << 1;
			return 0;
		}
		else if (9 - v1[0] < chazhi)
		{
			chazhi = chazhi - (9 - v1[0]);
		}

		if (9 - v1[1] >= chazhi)
		{
			cout << 2;
			return 0;
		}
		else if (9 - v1[1] < chazhi)
		{
			cout << 3;
			return 0;
		}
	}


	return 0;
}



