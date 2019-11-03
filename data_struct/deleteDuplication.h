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

ListNode* deleteDuplication(ListNode* pHead)
{
	

}

void deleteDuplicationTest()
{
	ListNode *N1 = new ListNode(1);
	ListNode *N2 = new ListNode(2);
	ListNode *N3 = new ListNode(2);
	ListNode *N4 = new ListNode(5);
	ListNode *N5 = new ListNode(5);

	N1->next = N2;
	N2->next = N3;
	N3->next = N4;
	N4->next = N5;

	ListNode *t = deleteDuplication(N1);
	int s = 0;
	

}
