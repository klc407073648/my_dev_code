#ifndef _LISTQUESTION_H_
#define _LISTQUESTION_H_


#include<iostream>
#include<stack>
//»ØÎÄÁ´±í
using namespace std;

class ListNode
{
public:
	int value;
	ListNode *next;

	ListNode(int data) {
		value = data;
		next = NULL;
	};


};

bool isPalindromeList(ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	ListNode *fPtr=head, *sPtr=head,*nextPtr=head;
	while (sPtr->next!=NULL&&sPtr->next->next != NULL)
	{
		fPtr=fPtr->next;  //1 2 1    1 2 3 3 2 1
		sPtr = sPtr->next->next;
	}
	stack<ListNode *>  s;
	while (fPtr->next != NULL)
	{
		s.push(fPtr->next);
		fPtr = fPtr->next;
	}

	while (!s.empty())
	{
		ListNode *tmp = s.top();
		s.pop();
		int tmpValue = tmp->value;
		if (tmpValue != nextPtr->value)
			return false;
		nextPtr = nextPtr->next;
	}
	return true;

}

void isPalindromeListTest()
{
	ListNode *head = new ListNode(5);
	ListNode *h1 = new ListNode(1);
	ListNode *h2 = new ListNode(1);
	ListNode *h3 = new ListNode(3);
	ListNode *h4 = new ListNode(5);
	head->next = h1;
	h1->next = h2;
	h2->next = h3;
	h3->next = h4;
	
	cout<<isPalindromeList(head)<<endl;
}

#endif // !_LISTQUESTION_H_