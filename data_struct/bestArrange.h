#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;
class bestArrange
{
public:
	int start;
	int end;
	bestArrange(int s, int e)
	{
		start = s;
		end = e;
	}
};
	
bool cmp_by_end(bestArrange &t1, bestArrange &t2)
{
		return t1.end < t2.end;
}


void bestArrage(vector<bestArrange> &s,int start)
{
	vector<bestArrange> res;
	int sum = 0;
	res = s;
	/*res.push_back(bestArrange(7, 8));
	res.push_back(bestArrange(6, 8));
	res.push_back(bestArrange(8, 11));
	res.push_back(bestArrange(8, 9));
	res.push_back(bestArrange(12, 15));
	res.push_back(bestArrange(12, 14));
	res.push_back(bestArrange(16, 20));
	res.push_back(bestArrange(15, 19));
	res.push_back(bestArrange(20, 23));
	res.push_back(bestArrange(20, 24));*/
	
	sort(res.begin(), res.end(), cmp_by_end);
	for (int i = 0; i < res.size(); i++)
	{
		if (start<=res[i].start)
		{
			start = res[i].end;
			sum++;
		}
	}
	cout << sum;

}
