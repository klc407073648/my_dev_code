#include<iostream>
#include<string>
#include<stdio.h>
#include<stdio.h>
#include<assert.h>
using namespace std;
vector<string>  res;


int myStringTest1(string str)
{
	int a[128] = {0};
	for (int i = 0; i < str.size(); i++)
	{
		a[str[i]]++;
	}
	for (int i = 0; i < 128; i++)
	{
		if (a[i] != 0)
			printf("%c,%d\n", i, a[i]);
	       /*cout <<  (char)i << " "<< a[i] << endl;*/
	}
	return 0;
}

int myStringTest2(string str)
{
	for (int i = 1,j; i <= str.size(); i++)
	{
		for (j = 0; j+i<= str.size(); j++)
		{
			res.push_back(str.substr(j, i));
		}
	}
	res.erase(unique(res.begin(), res.end()), res.end());

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}

	return 0;
}


int myStringTest3(string str)
{
	const string str11 = "aabbcc";
	string str1 = "abc";
	string str2(5,'a');
	string str3(str11,4);
	string str4(str1, 1, 2);
	string str22("Hello"), str33("Wide World");

	const char *ptr1 = 0;
	ptr1 = str22.data();
	for(;*ptr1!='\0';ptr1++)
	cout << *ptr1;
	cout << str22.append(str33,0,3) << " ";
	cout << str1 << " " << str2 << " " << str3 << " " << str4 << " ";

	return 0;
}

char *strcpy11(char *strDest,const char *strSrc)
{
	 assert((strDest != NULL) && (strSrc != NULL));
     char    *address = strDest;
      while ((*strDest++ = *strSrc++) != '\0')//直到strSrc字符结尾，神一样的语句，美到流眼泪！
                       NULL;
           return address;
}

char *strcpy1(char *strDest, const char *strSrc)
{
	//assert((strDest != NULL) && (strSrc != NULL));
	char    *address = strDest;
	for (; *strSrc != '\0'; strSrc++, strDest++)
	{
		*strDest = *strSrc;
	}
	*strDest = '\0';
	return address;
}