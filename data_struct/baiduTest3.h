#include<stack>
#include<string>
using namespace std;


int savePeople(char *str)
{
	//WRITE YOUR CODE HERE
	stack<char>  s;
	int num = 0;
	int size=sizeof(str);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ')'&&s.top() != '(')
			s.push(str[i]);
		else if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == ')'&&s.top() == '(')
		{
			s.pop();
			num++;
		}
	}
	if (!s.empty())
		return -1;

	return num;
}


