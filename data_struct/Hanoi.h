#include<iostream>
#include<string>
using namespace std;
//对于传统的汉诺塔游戏我们做一个拓展，我们有从大到小放置的n个圆盘，
//开始时所有圆盘都放在左边的柱子上，按照汉诺塔游戏的要求我们要把所有
//的圆盘都移到右边的柱子上，请实现一个函数打印最优移动轨迹。
//给定一个int n，表示有n个圆盘。请返回一个string数组，
//其中的元素依次为每次移动的描述。描述格式为：
//move from[left / mid / right] to[left / mid / right]。

void hanoi(int n, string from, string to, string help)
{
	if (n == 1)
		cout << "move 1 from " << from << " to " << to<<endl;
	else
	{
		hanoi(n - 1, from, help, to);
		cout << "move " << n << " from " << from << " to " << to << endl;
		hanoi(n - 1, help, to, from);
	}
}
void hanoiTest()
{
	int n = 3;
	hanoi(n, "left", "right", "mid");
}