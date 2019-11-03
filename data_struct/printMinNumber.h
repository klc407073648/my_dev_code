#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool cmp1(string &s1, string &s2)
{
	return s1 + s2 < s2 + s1;
}
string PrintMinNumber(vector<int> nums) {

	string str="";
	if (nums.size() == 0)
		return str;
	vector<string> result;
	for (int i = 0; i < nums.size(); i++)
	{
		result.push_back(to_string(nums[i]));
	}
	sort(result.begin(), result.end(), cmp1);

	string str;
	for (int i = 0; i < result.size(); i++)
	{
		str=str+result[i];
	}
	return str;

}
