#ifndef _HELPFUNCTION_H_
#define _HELPFUNCTION_H_



int max(int &a, int &b)
{
	return a > b ? a : b;
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
#endif // !1