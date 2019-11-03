#ifndef _DIVIDELIST_H_
#define _DIVIDELIST_H_



#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* divideList(int k,ListNode *head)
{
	queue<ListNode *> left,mid,right;//用6个节点分别表示小于头，尾；等于头，尾；大于头尾
	ListNode *tmp = head;
	ListNode *result = new ListNode(0);
	ListNode *t = result;
	if (head == NULL || head->next == NULL)
		return head;
	while (tmp != NULL)
	{
		if (tmp->val < k)
		{
			left.push(tmp);
		}
		else if (tmp->val == k)
		{
			mid.push(tmp);
		}
		else
			right.push(tmp);
		tmp = tmp->next;
	}
	while (!left.empty())
	{
		result->next = left.front();
		result = result->next;
		left.pop();
	}
	while (!mid.empty())
	{
		result->next = mid.front();
		result = result->next;
		mid.pop();
	}
	while (!right.empty())
	{
		result->next = right.front();
		result = result->next;
		right.pop();
	}
	result->next = NULL;
	return t->next;


}

void divideListTest()
{
	ListNode *N1 = new ListNode(9);
	ListNode *N2 = new ListNode(0);
	ListNode *N3 = new ListNode(4);
	ListNode *N4 = new ListNode(5);
	ListNode *N5 = new ListNode(1);

	N1->next = N2;
	N2->next = N3;
	N3->next = N4;
	N4->next = N5;

	ListNode *t=divideList(3, N1);
	int s = 0;
	while (t != NULL)
	{
		cout << t->val << " ";
		t = t->next;
	}

}


#endif // !_DIVIDELIST_H_