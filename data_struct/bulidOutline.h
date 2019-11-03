#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
class Point
{
  public:
	  int pos;
	  int height;
	  Point(int p, int h)
	  {
		  pos = p;
		  height = h;
	  }
};
bool cmp1(Point &p1, Point &p2)
{
	return p1.pos < p2.pos;
}
//可以用一个三元组表示(start, end, height)，
//  [1, 3, 3],
//  [2, 4, 4],
//  [5, 6, 1]
vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
	// write your code here
	int row = buildings.size();
	int col = buildings[0].size();
	map<int, int> mymap;
	map<int, int>::iterator it;
	vector<Point> res;
	vector<vector<int>> res1;

	vector<int> position;
	vector<int> height;;
	for (int i = 0; i < row; i++)
	{
		res.push_back(Point(buildings[i][0], buildings[i][2]));
		res.push_back(Point(buildings[i][1], buildings[i][2]));
	}
	sort(res.begin(), res.end(), cmp1);
	for (int i = 0; i < res.size(); i++)
	{
		if (mymap.empty())//情况1;当map中没有元素，插入值，并记录
		{
			mymap.insert(pair<int, int>(res[i].height, res[i].pos));
			position.push_back(res[i].pos);
			height.push_back(res[i].height);
		}
		
		else if (mymap.count(res[i].height))//如果有值,且已经出现过
		{
			
			if (mymap.size() == 1)
			{
				position.push_back(mymap[res[i].height]);
				height.push_back(res[i].height);
				mymap.erase(res[i].height);
			}
			else
			    mymap.erase(res[i].height);
		}
		else if(mymap.count(res[i].height)==0&& !mymap.empty())//如果没有出现过，且原来map中有元素
		{
			it = mymap.end(); 
			it--;//指向最大的元素
			if (res[i].height > it->first)
			{

				mymap.insert(pair<int, int>(res[i].height, res[i].pos));
				position.push_back(res[i].pos);
				height.push_back(res[i].height);
			}
			else
			{
				mymap.insert(pair<int, int>(res[i].height, res[i].pos));
			}
		}
	}
	for (int i = 0; i < position.size(); i++)
	{

	}
	int t = 0;

	return res1;


}
