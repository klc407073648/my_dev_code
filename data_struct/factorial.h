#include<iostream>
using namespace std;

int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n*factorial(n - 1);
}

void factorialTest()
{
	cout << factorial(5) << endl;
	cout << factorial(6) << endl;
}


