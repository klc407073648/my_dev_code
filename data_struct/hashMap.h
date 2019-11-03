#include<map>
#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;

//set的各成员函数列表如下:
//1. begin()--返回指向第一个元素的迭代器
//2. clear()--清除所有元素
//3. count()--返回某个值元素的个数
//4. empty()--如果集合为空，返回true
//5. end()--返回指向最后一个元素的迭代器
//6. equal_range()--返回集合中与给定值相等的上下限的两个迭代器
//7. erase()--删除集合中的元素
//8. find()--返回一个指向被查找到元素的迭代器
//9. get_allocator()--返回集合的分配器
//10. insert()--在集合中插入元素
//11. lower_bound()--返回指向大于（或等于）某值的第一个元素的迭代器
//12. key_comp()--返回一个用于元素间值比较的函数
//13. max_size()--返回集合能容纳的元素的最大限值
//14. rbegin()--返回指向集合中最后一个元素的反向迭代器
//15. rend()--返回指向集合中第一个元素的反向迭代器
//16. size()--集合中元素的数目
//17. swap()--交换两个集合变量
//18. upper_bound()--返回大于某个值元素的迭代器
//19. value_comp()--返回一个用于比较元素间的值的函数


//C++ maps是一种关联式容器，包含“关键字 / 值”对
//begin()         返回指向map头部的迭代器
//clear(）        删除所有元素
//count()         返回指定元素出现的次数
//empty()         如果map为空则返回true
//end()           返回指向map末尾的迭代器
//equal_range()   返回特殊条目的迭代器对
//erase()         删除一个元素
//find()          查找一个元素
//get_allocator() 返回map的配置器
//insert()        插入元素
//key_comp()      返回比较元素key的函数
//lower_bound()   返回键值 >= 给定元素的第一个位置
//max_size()      返回可以容纳的最大元素个数
//rbegin()        返回一个指向map尾部的逆向迭代器
//rend()          返回一个指向map头部的逆向迭代器
//size()          返回map中元素的个数
//swap()           交换两个map
//upper_bound()    返回键值>给定元素的第一个位置
//value_comp()     返回比较元素value的函数
//void mapTest()
//{
//	
//	map<string, int>  myStudent;
//	myStudent.insert(pair<string, int>("klc", 1));
//	myStudent.insert(pair<string, int>("gsc", 2));
//	myStudent.insert(pair<string, int>("lz", 3));
//	//myStudent.insert(pair<string, int>("klc", 5));
//	myStudent["klc"] = 5;//数组可以覆盖，插入操作具有唯一性，不能覆盖已经存在的词条
//
//
//
//	map<string, int>::iterator iter;
//     myStudent.erase("klc");
//	iter = myStudent.find("klc");
//	if (iter != myStudent.end())
//
//		cout << "Find, the value is " << iter->second << endl;
//
//	else
//
//		cout << "Do not Find" << endl;
//
//
//}
void  hashMapTest()
{
	std::unordered_map<std::string, int> mymap = { { "Mars", 3000 },{ "Saturn", 60000 },{ "Jupiter", 70000 } };
	

	// 对元素进行计算
	mymap["Mars"] = 3396;
	mymap.at("Saturn") += 272;
	mymap.at("Jupiter") = mymap.at("Saturn") + 9638;

	// auto：自动判断类型
	// 基于范围的 for 循环，遍历 mymap
	for (auto& x : mymap) {
		std::cout << x.first << ": " << x.second << std::endl;
	}
	std::cout << "mymap.size() is " << mymap.size() << std::endl << std::endl;

	//============================
	//   2. iterator, 迭代器遍历
	//============================
	// 定义第二个 unordered_map
	std::unordered_map<std::string, std::string> mymap2 = { { "Australia", "Canberra" },{ "U.S.", "Washington" },{ "France", "Paris" } };
	std::cout << "mymap2 contains:" << std::endl;

	// 遍历 mymap2
	for (auto it = mymap2.begin(); it != mymap2.end(); ++it)
		std::cout << " " << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;

	// mymap2 分配的各桶中的元素
	std::cout << "mymap2's buckets contain:\n";
	for (unsigned i = 0; i < mymap2.bucket_count(); ++i) {
		std::cout << "bucket #" << i << " contains:";
		for (auto local_it = mymap2.begin(i); local_it != mymap2.end(i); ++local_it)
			std::cout << " " << local_it->first << ":" << local_it->second;
		std::cout << std::endl;
	}

	//============================
	//   3. bucker, 桶操作
	//============================
	// 定义第三个 unordered_map
	std::unordered_map<std::string, std::string> mymap3 = {
		{ "us", "United States" },
		{ "uk", "United Kingdom" },
		{ "fr", "France" },
		{ "de", "Germany" }
	};

	// 遍历 mymap3
	for (auto& x : mymap3) {
		std::cout << "Element [" << x.first << ":" << x.second << "]";
		// 返回元素所在桶号
		std::cout << " is in bucket #" << mymap3.bucket(x.first) << std::endl;
	}

	//============================
	//   4. count ，判断元素是否在容器中
	//============================
	// 定义第四个 unordered_map
	std::unordered_map<std::string, double> mymap4 = {
		{ "Burger", 2.99 },
		{ "Fries", 1.99 },
		{ "Soda", 1.50 } };

	// 遍历 mymap4
	for (auto& x : { "Burger", "Pizza", "Salad", "Soda" })
	{
		// 判断 x 是否在容器中
		if (mymap4.count(x)>0)
			std::cout << "mymap4 has " << x << std::endl;
		else
			std::cout << "mymap4 has no " << x << std::endl;
	}

	//============================
	//   5. erase ，删除操作
	//============================
	// 定义第五个 unordered_map
	std::unordered_map<std::string, std::string> mymap5;
	mymap5["U.S."] = "Washington";
	mymap5["U.K."] = "London";
	mymap5["France"] = "Paris";
	mymap5["Russia"] = "Moscow";
	mymap5["China"] = "Beijing";
	mymap5["Germany"] = "Berlin";
	mymap5["Japan"] = "Tokyo";

	// 通过迭代器删除
	mymap5.erase(mymap5.begin());
	// 通过 Key 值删除
	mymap5.erase("France");
	// 通过迭代器范围删除
	mymap5.erase(mymap5.find("China"), mymap5.end());

	// 基于范围的 for 循环，遍历展示删除后的 mymap
	for (auto& x : mymap5)
		std::cout << x.first << ": " << x.second << std::endl;

	//============================
	//   6. find ，搜索操作
	//============================
	// 定义第六个 unordered_map
	std::unordered_map<std::string, double> mymap6 = {
		{ "mom", 5.4 },
		{ "dad", 6.1 },
		{ "bro", 5.9 } };

	std::string input;
	std::cout << "who? ";
	// 输入 mom, dad, bro 中的一个，否则搜索失败返回 Not Found
	getline(std::cin, input);

	// 根据输入参数 Key 值进行搜索，返回一个迭代器
	std::unordered_map<std::string, double>::const_iterator got = mymap6.find(input);

	// find 返回值若为 unordered_map 的尾部，则没有在容器中找到
	if (got == mymap6.end())
		std::cout << "not found";
	else
		std::cout << got->first << " is " << got->second;
	std::cout << std::endl;

	//============================
	//   6. insert ，插入操作
	//============================
	// 定义第七、八个 unordered_map
	std::unordered_map<std::string, double>
		myrecipe,
		mypantry = { { "milk", 2.0 },{ "flour", 1.5 } };

	// 定义插入元素，类型为 pair 的对象
	std::pair<std::string, double> myshopping("baking powder", 0.3);

	// 复制插入
	myrecipe.insert(myshopping);
	// 移动插入
	myrecipe.insert(std::make_pair<std::string, double>("eggs", 6.0));
	// 范围插入
	myrecipe.insert(mypantry.begin(), mypantry.end());  // range insertion
														// 初始化列表插入
	myrecipe.insert({ { "sugar", 0.8 },{ "salt", 0.1 } });    // initializer list insertion

	std::cout << "myrecipe contains:" << std::endl;
	for (auto& x : myrecipe)
		std::cout << x.first << ": " << x.second << std::endl;

	std::cout << std::endl;

	int t = 0;
}


int  mapTest1()//返回MoreThanHalfNum_Solution
{
	vector<int> nums = { 1,2,3,2,2,2,6,4,2 };
	map<int, int>  result;
	map<int, int>::iterator it;
	for (int i = 0; i < nums.size(); i++)
	{
		it=result.find(nums[i]);
		if (it != result.end())
			it->second++;
		result.insert(pair<int, int>(nums[i], 1));
	}
	int max= 0;
	int maxIndex = 0;
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] > max)
		{
			max = result[i];
			maxIndex = i;
		}
	}
	if (max > nums.size() / 2)
	{
		return maxIndex;
	}
	
	return 0;
	

}

int  mapTest2()//查找矩阵中相同数
{
	vector<vector<int>> nums = { {2,5,3},{3,2,1},{1,3,5} };
	int row = nums.size();
	int col = nums[0].size();
	vector<map<int, int>>  result;
	for (int i = 0; i < row; i++)
	{
		map<int, int> tmpMap;
		for (int j = 0; j < col; j++)
		{
			tmpMap.insert(pair<int, int>(nums[i][j],j));//2 0
		}
		result.push_back(tmpMap);
	}
	map<int, int>::iterator it= result[0].begin();
	for (;it!= result[0].end(); it++)
	{
		for (int i = 1; i < row; i++)
		{
			/*map<int, int>::iterator it1;
			it1= result[i].find(it->first);*/
			if (result[i].count(it->first))
			{
				if (i == row - 1)
				{
					cout<< it->first;
					return  it->first;
				}
				continue;
			}
			else
				break;
		}
	
	}

	//map<int, int>::iterator it1;
	//it1 = result[i].find(it->first);
	//if (it1 != result[i].end())
	//{
	//	if (i == row - 1)
	//	{
	//		return  it->first;
	//	}
	//	continue;
	//}
	//else
	//	break;

	

	return 0;
}


//给一个字符串 str1 = This is an example, 给出另一个字符串 str2 = is example
//返回["This", "an"]
bool CmpByValue(pair<string, int> &it1, pair<string, int> &it2)
{
	return it1.second < it2.second;
}
int mapTest3()
{
	string str1 = "This is an example";
	string str2 = " ";
	
	queue<string> q1, q2;
	string str = "";
	for (int i = 0; i <str1.size(); i++)
	{
		if (str1[i] != ' ')
		{
			str = str + str1[i];
		}
		 if(str1[i] == ' '||i==str1.size()-1)
		{
			q1.push(str);
			str = "";
		}
	}
	str = "";
	for (int i = 0; i <str2.size(); i++)
	{
		if (str2[i] != ' ')
		{
			str = str + str2[i];
		}
		if (str2[i] == ' ' || i == str2.size() - 1)
		{
			q2.push(str);
			str = "";
		}
	}
	map<string, int> map1,map2;
	int num1 = 0,num2=0;
	while (!q1.empty())
	{
		map1.insert(pair<string, int>(q1.front(), num1++));
		q1.pop();
	}

	while (!q2.empty())
	{
		map2.insert(pair<string, int>(q2.front(), num2++));
		q2.pop();
	}
	map<string, int>::iterator it1,it2;
	for (it2 = map2.begin(); it2 != map2.end(); it2++)
	{
		map1.erase(it2->first);
	}

	vector<pair<string, int>> map_value(map1.begin(), map1.end());
	sort(map_value.begin(), map_value.end(), CmpByValue);
	
	for (int i=0; i < map_value.size(); ++i)
	{
		cout << map_value[i].first<<" ";
	}

	return 0;
}

vector<string> split(const string& src, string separate_character)
{
	vector<string> strs;
	int separate_characterLen = separate_character.size();//分割字符串的长度,这样就可以支持如“,,”多字符串的分隔符
	int lastPosition = 0, index = -1;
	while (-1 != (index = src.find(separate_character, lastPosition)))
	{
		strs.push_back(src.substr(lastPosition, index - lastPosition));
		lastPosition = index + separate_characterLen;
	}
	string lastString = src.substr(lastPosition);//截取最后一个分隔符后的内容
	if (!lastString.empty())
		strs.push_back(lastString);//如果最后一个分隔符后还有内容就入队
	return strs;

}

vector<vector<int>> fanzhuanMatrix(vector<vector<int>> &nums)
{
	int row = nums.size();
	int col = nums[0].size();
	vector<vector<int>>  result;
	for (int j = 0; j < col; j++)
	{
		vector<int> temp;
		for (int i = 0; i < row; i++)
		{
			temp.push_back(nums[i][j]);
		}
		result.push_back(temp);
	}
	return result;
}

void printMatrix111(vector<vector<int>> &nums)
{
	int row = nums.size();
	int col = nums[0].size();
	for (int i = 0; i < row; i++)
	{
		vector<int> temp;
		for (int j = 0; j < col; j++)
		{
			cout<<nums[i][j]<<" ";
		}
		cout << endl;
		
	}
}

void setTest()
{
	
	set<int> s;
	set<int>::iterator it;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	cout << "set 的 size 值为 ：" << s.size() << endl;
	cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;
	cout << "set 中的第一个元素是 ：" << *s.begin() << endl;
	//cout << "set 中的最后一个元素是:" << *s.end() << endl;
	s.clear();
	 if (s.empty())
	{
	   cout << "set 为空 ！！！" << endl;
	 }
	cout << "set 的 size 值为 ：" << s.size() << endl;
	cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;
	

}
int firstNotRepeatingChar(string str)
{
	if (str.size() == 0)
		return -1;
	map<char, int>  mymap;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (mymap.count(str[i]) == 0)//如果我没有插入过这条记录
		{
			mymap.insert(pair<char, int>(str[i], 1));
		}
		else
		{
			mymap[str[i]]++;
		}
		
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (mymap[str[i]] == 1)
			return i;
	}
	return -1;

	
}

string reverseString(string &str)
{
	string res = "";
	for (int i = str.size() - 1; i >= 0; )
	{
		if (str[i] == ' ')
		{
			res = res + str[i];
			i--;
		}
		else if (i >= 0&&str[i] != ' ')
		{
			stack<char> mystr;
			while (i >= 0 && str[i] != ' ')
			{
				mystr.push(str[i]);
				i --;
			}
			string tmpstr;
			while (!mystr.empty())
			{
				tmpstr = tmpstr+mystr.top();
				mystr.pop();
			}
			res = res + tmpstr;
		}

	}
	return res;
}


