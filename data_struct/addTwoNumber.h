#ifndef _ADDTWONUMBER_H_
#define _ADDTWONUMBER_H_

#include<iostream>
#include<stack>

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

 class Solution {
 public:
	 /**
	 * @param l1: The first list.
	 * @param l2: The second list.
	 * @return: the sum list of l1 and l2.
	 */

	 ListNode * addLists2(ListNode * l1, ListNode * l2) {
		 // write your code here
		 stack<ListNode *> s1;
		 stack<ListNode *> s2;
		 stack<ListNode *> result;

		 int jinwei = 0;//进位值
		 int tmp = 0;//result压入值
		 ListNode *tmp1 = l1, *tmp2 = l2;


		 //依次把链表压入栈
		 while (tmp1 != NULL)
		 {
			 s1.push(tmp1);
			 tmp1 = tmp1->next;
		 }
		 while (tmp2 != NULL)
		 {
			 s2.push(tmp2);
			 tmp2 = tmp2->next;
		 }


		 while (!s1.empty() || !s2.empty())
		 {
			 if (!s1.empty() && !s2.empty())//s1,s2均非空 取出头部节点值相加
			 {

				 tmp = s1.top()->val + s2.top()->val + jinwei;
				 s1.pop();
				 s2.pop();
				 if (tmp >= 10)
				 {
					 jinwei = 1;
					 tmp = tmp % 10;
				 }
				 else
				 {
					 jinwei = 0;
				 }
				 result.push(new ListNode(tmp));

			 }
			 else if (!s1.empty() && s2.empty())//s1非空,s2空 依次压入s1
			 {
				 while (!s1.empty())
				 {
					 tmp = s1.top()->val + jinwei;
					 if (tmp >= 10)
					 {
						 jinwei = 1;
						 tmp = tmp % 10;
					 }
					 else
					 {
						 jinwei = 0;
					 }
					 s1.pop();
					 result.push(new ListNode(tmp));
				 }
				 break;
			 }
			 else if (s1.empty() && !s2.empty())//s1空,s2非空 依次压入s2
			 {
				 while (!s2.empty())
				 {
					 tmp = s2.top()->val + jinwei;
					 if (tmp >= 10)
					 {
						 jinwei = 1;
						 tmp = tmp % 10;
					 }
					 else
					 {
						 jinwei = 0;
					 }
					 s2.pop();
					 result.push(new ListNode(tmp));
				 }
				 break;
			 }


		 }
		 if (jinwei == 1)//如果最终还有进位，则再压入1
		 {
			 result.push(new ListNode(1));
		 }

		 ListNode * answer = new ListNode(0);
		 ListNode * t = answer;
		 while (!result.empty())
		 {
			 ListNode *temp = new ListNode(result.top()->val);
			 answer->next = temp;
			 answer = answer->next;
			 result.pop();
		 }

		 return t->next;


	 }
 };

void  addLists2Test()
{
	ListNode *N1 = new ListNode(2);
	ListNode *N2 = new ListNode(1);
	ListNode *N3 = new ListNode(2);
	ListNode *N4 = new ListNode(4);
	ListNode *N5 = new ListNode(2);
	ListNode *N6 = new ListNode(3);
	ListNode *N7 = new ListNode(3);
	N1->next = N2;
	N2->next = N3;
	N4->next = N5;
	N5->next = N6;
	N6->next = N7;
	Solution S;

	ListNode * result=S.addLists2(N1, N4);
	int t = 0;
}

#endif // !_ADDTWONUMBER_H_