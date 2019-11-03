#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
	if (length<0)
		return false;
	unordered_map<int, int> mymap;
	for (int i = 0; i<length; i++)
	{
		if (numbers[i]<length)
		{
			continue;
		}
		else
		{
			return false;
		}
		if (mymap.count(numbers[i]) == 1)
		{
			*duplication = numbers[i];
			return true;
		}
		else
		{
			mymap.insert(pair<int, int>(numbers[i], 1));
		}
	}
	return false;
}


void multimapTest()
{
	map<int, int>  a;
	map<int, int>::reverse_iterator it;
	a.insert(pair<int, int>(1, 11));
	a.insert(pair<int, int>(2, 12));
	a.insert(pair<int, int>(3, 13));
	a.insert(pair<int, int>(4, 21));
	a.insert(pair<int, int>(5, 22));
	for (it = a.rbegin(); it != a.rend(); it++)
	{
		cout << it->first << " ";
	}
	cout << a.rend()->first;
	/*multimap<int, int> a;
	a.insert(pair<int, int>(1, 11));
	a.insert(pair<int, int>(1, 12));
	a.insert(pair<int, int>(1, 13));
	a.insert(pair<int, int>(2, 21));
	a.insert(pair<int, int>(2, 22));
	a.insert(pair<int, int>(3, 31));
	a.insert(pair<int, int>(3, 32));
	multimap<int, int>::iterator p_map;
	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> ret;
	for (p_map = a.begin(); p_map != a.end();)
	{
		cout << p_map->first << " =>";
		ret = a.equal_range(p_map->first);
		for (p_map = ret.first; p_map != ret.second; ++p_map)
			cout << "" << (*p_map).second;
		cout << endl;
	}*/
}
