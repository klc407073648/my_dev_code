#include<map>
#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;

//set�ĸ���Ա�����б�����:
//1. begin()--����ָ���һ��Ԫ�صĵ�����
//2. clear()--�������Ԫ��
//3. count()--����ĳ��ֵԪ�صĸ���
//4. empty()--�������Ϊ�գ�����true
//5. end()--����ָ�����һ��Ԫ�صĵ�����
//6. equal_range()--���ؼ����������ֵ��ȵ������޵�����������
//7. erase()--ɾ�������е�Ԫ��
//8. find()--����һ��ָ�򱻲��ҵ�Ԫ�صĵ�����
//9. get_allocator()--���ؼ��ϵķ�����
//10. insert()--�ڼ����в���Ԫ��
//11. lower_bound()--����ָ����ڣ�����ڣ�ĳֵ�ĵ�һ��Ԫ�صĵ�����
//12. key_comp()--����һ������Ԫ�ؼ�ֵ�Ƚϵĺ���
//13. max_size()--���ؼ��������ɵ�Ԫ�ص������ֵ
//14. rbegin()--����ָ�򼯺������һ��Ԫ�صķ��������
//15. rend()--����ָ�򼯺��е�һ��Ԫ�صķ��������
//16. size()--������Ԫ�ص���Ŀ
//17. swap()--�����������ϱ���
//18. upper_bound()--���ش���ĳ��ֵԪ�صĵ�����
//19. value_comp()--����һ�����ڱȽ�Ԫ�ؼ��ֵ�ĺ���


//C++ maps��һ�ֹ���ʽ�������������ؼ��� / ֵ����
//begin()         ����ָ��mapͷ���ĵ�����
//clear(��        ɾ������Ԫ��
//count()         ����ָ��Ԫ�س��ֵĴ���
//empty()         ���mapΪ���򷵻�true
//end()           ����ָ��mapĩβ�ĵ�����
//equal_range()   ����������Ŀ�ĵ�������
//erase()         ɾ��һ��Ԫ��
//find()          ����һ��Ԫ��
//get_allocator() ����map��������
//insert()        ����Ԫ��
//key_comp()      ���رȽ�Ԫ��key�ĺ���
//lower_bound()   ���ؼ�ֵ >= ����Ԫ�صĵ�һ��λ��
//max_size()      ���ؿ������ɵ����Ԫ�ظ���
//rbegin()        ����һ��ָ��mapβ�������������
//rend()          ����һ��ָ��mapͷ�������������
//size()          ����map��Ԫ�صĸ���
//swap()           ��������map
//upper_bound()    ���ؼ�ֵ>����Ԫ�صĵ�һ��λ��
//value_comp()     ���رȽ�Ԫ��value�ĺ���
//void mapTest()
//{
//	
//	map<string, int>  myStudent;
//	myStudent.insert(pair<string, int>("klc", 1));
//	myStudent.insert(pair<string, int>("gsc", 2));
//	myStudent.insert(pair<string, int>("lz", 3));
//	//myStudent.insert(pair<string, int>("klc", 5));
//	myStudent["klc"] = 5;//������Ը��ǣ������������Ψһ�ԣ����ܸ����Ѿ����ڵĴ���
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
	

	// ��Ԫ�ؽ��м���
	mymap["Mars"] = 3396;
	mymap.at("Saturn") += 272;
	mymap.at("Jupiter") = mymap.at("Saturn") + 9638;

	// auto���Զ��ж�����
	// ���ڷ�Χ�� for ѭ�������� mymap
	for (auto& x : mymap) {
		std::cout << x.first << ": " << x.second << std::endl;
	}
	std::cout << "mymap.size() is " << mymap.size() << std::endl << std::endl;

	//============================
	//   2. iterator, ����������
	//============================
	// ����ڶ��� unordered_map
	std::unordered_map<std::string, std::string> mymap2 = { { "Australia", "Canberra" },{ "U.S.", "Washington" },{ "France", "Paris" } };
	std::cout << "mymap2 contains:" << std::endl;

	// ���� mymap2
	for (auto it = mymap2.begin(); it != mymap2.end(); ++it)
		std::cout << " " << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;

	// mymap2 ����ĸ�Ͱ�е�Ԫ��
	std::cout << "mymap2's buckets contain:\n";
	for (unsigned i = 0; i < mymap2.bucket_count(); ++i) {
		std::cout << "bucket #" << i << " contains:";
		for (auto local_it = mymap2.begin(i); local_it != mymap2.end(i); ++local_it)
			std::cout << " " << local_it->first << ":" << local_it->second;
		std::cout << std::endl;
	}

	//============================
	//   3. bucker, Ͱ����
	//============================
	// ��������� unordered_map
	std::unordered_map<std::string, std::string> mymap3 = {
		{ "us", "United States" },
		{ "uk", "United Kingdom" },
		{ "fr", "France" },
		{ "de", "Germany" }
	};

	// ���� mymap3
	for (auto& x : mymap3) {
		std::cout << "Element [" << x.first << ":" << x.second << "]";
		// ����Ԫ������Ͱ��
		std::cout << " is in bucket #" << mymap3.bucket(x.first) << std::endl;
	}

	//============================
	//   4. count ���ж�Ԫ���Ƿ���������
	//============================
	// ������ĸ� unordered_map
	std::unordered_map<std::string, double> mymap4 = {
		{ "Burger", 2.99 },
		{ "Fries", 1.99 },
		{ "Soda", 1.50 } };

	// ���� mymap4
	for (auto& x : { "Burger", "Pizza", "Salad", "Soda" })
	{
		// �ж� x �Ƿ���������
		if (mymap4.count(x)>0)
			std::cout << "mymap4 has " << x << std::endl;
		else
			std::cout << "mymap4 has no " << x << std::endl;
	}

	//============================
	//   5. erase ��ɾ������
	//============================
	// �������� unordered_map
	std::unordered_map<std::string, std::string> mymap5;
	mymap5["U.S."] = "Washington";
	mymap5["U.K."] = "London";
	mymap5["France"] = "Paris";
	mymap5["Russia"] = "Moscow";
	mymap5["China"] = "Beijing";
	mymap5["Germany"] = "Berlin";
	mymap5["Japan"] = "Tokyo";

	// ͨ��������ɾ��
	mymap5.erase(mymap5.begin());
	// ͨ�� Key ֵɾ��
	mymap5.erase("France");
	// ͨ����������Χɾ��
	mymap5.erase(mymap5.find("China"), mymap5.end());

	// ���ڷ�Χ�� for ѭ��������չʾɾ����� mymap
	for (auto& x : mymap5)
		std::cout << x.first << ": " << x.second << std::endl;

	//============================
	//   6. find ����������
	//============================
	// ��������� unordered_map
	std::unordered_map<std::string, double> mymap6 = {
		{ "mom", 5.4 },
		{ "dad", 6.1 },
		{ "bro", 5.9 } };

	std::string input;
	std::cout << "who? ";
	// ���� mom, dad, bro �е�һ������������ʧ�ܷ��� Not Found
	getline(std::cin, input);

	// ����������� Key ֵ��������������һ��������
	std::unordered_map<std::string, double>::const_iterator got = mymap6.find(input);

	// find ����ֵ��Ϊ unordered_map ��β������û�����������ҵ�
	if (got == mymap6.end())
		std::cout << "not found";
	else
		std::cout << got->first << " is " << got->second;
	std::cout << std::endl;

	//============================
	//   6. insert ���������
	//============================
	// ������ߡ��˸� unordered_map
	std::unordered_map<std::string, double>
		myrecipe,
		mypantry = { { "milk", 2.0 },{ "flour", 1.5 } };

	// �������Ԫ�أ�����Ϊ pair �Ķ���
	std::pair<std::string, double> myshopping("baking powder", 0.3);

	// ���Ʋ���
	myrecipe.insert(myshopping);
	// �ƶ�����
	myrecipe.insert(std::make_pair<std::string, double>("eggs", 6.0));
	// ��Χ����
	myrecipe.insert(mypantry.begin(), mypantry.end());  // range insertion
														// ��ʼ���б����
	myrecipe.insert({ { "sugar", 0.8 },{ "salt", 0.1 } });    // initializer list insertion

	std::cout << "myrecipe contains:" << std::endl;
	for (auto& x : myrecipe)
		std::cout << x.first << ": " << x.second << std::endl;

	std::cout << std::endl;

	int t = 0;
}


int  mapTest1()//����MoreThanHalfNum_Solution
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

int  mapTest2()//���Ҿ�������ͬ��
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


//��һ���ַ��� str1 = This is an example, ������һ���ַ��� str2 = is example
//����["This", "an"]
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
	int separate_characterLen = separate_character.size();//�ָ��ַ����ĳ���,�����Ϳ���֧���硰,,�����ַ����ķָ���
	int lastPosition = 0, index = -1;
	while (-1 != (index = src.find(separate_character, lastPosition)))
	{
		strs.push_back(src.substr(lastPosition, index - lastPosition));
		lastPosition = index + separate_characterLen;
	}
	string lastString = src.substr(lastPosition);//��ȡ���һ���ָ����������
	if (!lastString.empty())
		strs.push_back(lastString);//������һ���ָ����������ݾ����
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
	cout << "set �� size ֵΪ ��" << s.size() << endl;
	cout << "set �� maxsize��ֵΪ ��" << s.max_size() << endl;
	cout << "set �еĵ�һ��Ԫ���� ��" << *s.begin() << endl;
	//cout << "set �е����һ��Ԫ����:" << *s.end() << endl;
	s.clear();
	 if (s.empty())
	{
	   cout << "set Ϊ�� ������" << endl;
	 }
	cout << "set �� size ֵΪ ��" << s.size() << endl;
	cout << "set �� maxsize��ֵΪ ��" << s.max_size() << endl;
	

}
int firstNotRepeatingChar(string str)
{
	if (str.size() == 0)
		return -1;
	map<char, int>  mymap;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (mymap.count(str[i]) == 0)//�����û�в����������¼
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


