#include<iostream>
#include<vector>
#include<map>
using namespace std;

int myMeiTuan()
{
	int n, k, t;
	cin >> n;
	cin >> k;
	cin >> t;

	vector<int> res;
	int sum = 0;
	map<int, int> mymap;
	map<int, int>::iterator it;
	for (int i = 0; i < n; i++)
	{
		int ai;
		cin >> ai;
		res.push_back(ai);
	}

	for (int j = 0; j <= k - 1 ; j++)
	{
		if (mymap.count(res[j]) == 0)
		{
			mymap.insert(pair<int, int>(res[j], 1));
		}
		else
		{
			mymap[res[j]]++;
		}

	}


	for (int i = 0; i <= n-k; i++)
	{
		if(i==0)
		{ 
		   for (it = mymap.begin(); it != mymap.end(); it++)
		   {
			  if (it->second >= 2)
			   {
				sum++;
				break;
			  }
		  }
        }
		if (i != 0)
		{
			if (mymap[res[i-1]] == 1)
			{
				mymap.erase(res[i-1]);
			}
			else
			{
				mymap[res[i-1]]--;
			}


			if (mymap.count(res[i]) == 0)
			{
				mymap.insert(pair<int, int>(res[i], 1));
			}
			else
			{
				mymap[res[i]]++;
			}

			for (it = mymap.begin(); it != mymap.end(); it++)
			{
				if (it->second >= 2)
				{
					sum++;
					break;
				}
			}
		}

	}

	cout << sum;
	return 0;
}




//int myMeiTuan()
//{
//	int n, k, t;
//	cin >> n;
//	cin >> k;
//	cin >> t;
//
//	vector<int> res;
//	int sum = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		int ai;
//		cin >> ai;
//		res.push_back(ai);
//	}
//
	//for (int i = 0; i <= n - k; i++)
	//{
	//	map<int, int> mymap;
	//	map<int, int>::iterator it;
	//	for (int j = i; j <= k - 1 + i; j++)
	//	{
	//		if (mymap.count(res[j]) == 0)
	//		{
	//			mymap.insert(pair<int, int>(res[j], 1));
	//		}
	//		else
	//		{
	//			mymap[res[j]]++;
	//		}

	//	}
	//	for (it = mymap.begin(); it != mymap.end(); it++)
	//	{
	//		if (it->second >= 2)
	//		{
	//			sum++;
	//			break;
	//		}
	//	}


	//}
//
//	cout << sum;
//
//	return 0;
//}