#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	vector<string> result;
	while (t--)
	{
		long n;
		cin >> n;
		vector<string> res;
		while(n--)
		{
			string str;
			cin >> str;
			res.push_back(str);
        }
		int flag = 0;
		string firstStr = res[0];
		int size = firstStr.size();
		for (int i = 1; i < res.size(); i++)
		{
			if (res[i].size() != size)
				break;
			int pos=res[i].find_first_of[firstStr[0]];
			string sunStr,niStr;

			for (int i = pos; i < size; i++)
				sunStr = sunStr + res[i];
			for(int i=0;i<pos;i++)
				sunStr = sunStr + res[i];

			for (int i = pos; i >=0; i--)
				niStr = niStr + res[i];
			for (int i = size-1; i>pos; i--)
				niStr = niStr + res[i];

			if (firstStr == sunStr || firstStr == niStr)
			{
				if (i == size - 1)
					flag = 1;
				continue;
			}
			else
				break;
		}
		if (flag == 1)
		{
			result.push_back("Yeah");
		}
		else
		{
			result.push_back("Sad");
		}
	}
	
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}


	return 0;
}
