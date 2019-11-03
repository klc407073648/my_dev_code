#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;
int myTest111()
{
	long n, k;
	cin >> n;
	cin >> k;
	vector<int> interest;
	vector<int> sleep;
	
	for (int i = 0; i<n; i++)
	{
		int ai;
		cin >> ai;
		interest.push_back(ai);
	}
	for (int i = 0; i<n; i++)
	{
		int ti;
		cin >> ti;
		sleep.push_back(ti);
	}
	long mostInterest = LONG_MIN;
	long temp = 0;
	for (int i = 0; i<n; i++)
	{
		if (sleep[i] == 1)
			temp = temp + interest[i];
	}
	mostInterest = max(mostInterest, temp);
	vector<int> pos;
	{
		for (int i = 0; i<n; i++)
		{
			if (sleep[i] == 0)
				pos.push_back(i);
		}
	}
	for (int i = 0; i<pos.size(); i++)
	{
		long tmpMost = 0;
		int curPos = pos[i];
		for (int i = 0; i<curPos; i++)
		{
			if (sleep[i] == 1)
				tmpMost = tmpMost + interest[i];
		}
		if (curPos + k >= n)
		{
			for (int i = curPos; i<n; i++)
			{
				tmpMost = tmpMost + interest[i];
			}
		}
		else
		{
			for (int i = curPos; i != curPos + k; i++)
			{
				tmpMost = tmpMost + interest[i];
			}
			for (int i = curPos + k; i<n; i++)
			{
				if (sleep[i] == 1)
					tmpMost = tmpMost + interest[i];
			}
		}
		mostInterest = max(mostInterest, tmpMost);
	}
	cout << mostInterest;

	return 0;
}