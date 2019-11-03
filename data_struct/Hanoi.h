#include<iostream>
#include<string>
using namespace std;
//���ڴ�ͳ�ĺ�ŵ����Ϸ������һ����չ�������дӴ�С���õ�n��Բ�̣�
//��ʼʱ����Բ�̶�������ߵ������ϣ����պ�ŵ����Ϸ��Ҫ������Ҫ������
//��Բ�̶��Ƶ��ұߵ������ϣ���ʵ��һ��������ӡ�����ƶ��켣��
//����һ��int n����ʾ��n��Բ�̡��뷵��һ��string���飬
//���е�Ԫ������Ϊÿ���ƶ���������������ʽΪ��
//move from[left / mid / right] to[left / mid / right]��

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