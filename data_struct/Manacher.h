#include<vector>
#include<string>
using namespace std;

string getManacherStr(string str)
{
	string res;
	if (str.size() == 0)
		return 0;
	int size = 2 * str.size() + 1;//#个数为原字符串个数+1
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		res = res + ((i&1)== 0 ? '#': str[index++]);
	}
	return  res;
}

int  maxLcpsLength(string str)
{
	if (str.size() == 0)
		return 0;
	string mStr = getManacherStr(str);
	vector<int>  pArr(mStr.size());
	int index = -1;
	int pR = -1;
	int maxValue = INT_MIN;
	for (int i = 0; i != mStr.size(); i++) {
		pArr[i] = pR > i ? min(pArr[2 * index - i], pR - i) : 1;
		while (i + pArr[i] < mStr.size() && i - pArr[i] > -1) {
			if (mStr[i + pArr[i]] == mStr[i - pArr[i]])
				pArr[i]++;
			else {
				break;
			}
		}
		if (i + pArr[i] > pR) {
			pR = i + pArr[i];
			index = i;
		}
		maxValue = max(maxValue, pArr[i]);
	}
	return maxValue - 1;
}

void getManacherStrTest()
{
	string str = "KLC";
	getManacherStr(str);
	int t = 0;
}
