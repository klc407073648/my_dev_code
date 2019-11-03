#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;


class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

class ReturnData
{
public:
	int size;
	int  max;
	int  min;
	TreeNode *head;
	ReturnData(int m_size,int m_max,int m_min, TreeNode* m_head)
	{
		size = m_size;
		max = m_max;
		min = m_min;
		head = m_head;
	}
};

ReturnData* process(TreeNode * head)
{
	if (head == NULL)
		return new ReturnData(0, INT_MIN, INT_MAX, NULL);

	ReturnData* leftTree = process(head->left);
	ReturnData* rightTree = process(head->right);
	int midSize = 0;
	if (leftTree->head == head->left&&rightTree->head == head->right&&leftTree->max < head->val&&head->val < rightTree->min)
	{
		midSize = leftTree->size + rightTree->size + 1;
	}
	
	/*int maxSize = max(max(leftTree->size, rightTree->size), midSize);
	TreeNode *maxHead = leftTree->size > rightTree->size ? leftTree->head : rightTree->head;
	if (maxSize == midSize)
	{
		maxHead = head;
	}
	return new ReturnData(maxSize,
		max(max(leftTree->max, rightTree->max), head->val),
		min(min(leftTree->min, rightTree->min), head->val),
		maxHead);*/
	if(midSize>0)
		return new ReturnData(midSize, max(head->val,rightTree->max), min(leftTree->min, head->val), head);
	else if (leftTree->size > rightTree->size)
	{
	   return new ReturnData(leftTree->size, leftTree->max, leftTree->min, leftTree->head);
	}
	else
	{
		return new ReturnData(rightTree->size, rightTree->max, rightTree->min, rightTree->head);
	}

}
ReturnData* process1(TreeNode * head)
{
if (head == NULL) {
	return new ReturnData(0, INT_MIN, INT_MAX, NULL);
}
TreeNode * left = head->left;
ReturnData* leftSubTressInfo = process1(left);
TreeNode * right = head->right;
ReturnData* rightSubTressInfo = process1(right);

int includeItSelf = 0;
if (leftSubTressInfo->head == left
	&&rightSubTressInfo->head == right
	&& head->val> leftSubTressInfo->max
	&& head->val < rightSubTressInfo->min
	) {
	includeItSelf = leftSubTressInfo->size + 1 + rightSubTressInfo->size;
}
int p1 = leftSubTressInfo->size;
int p2 = rightSubTressInfo->size;
int maxSize = max(max(p1, p2), includeItSelf);

TreeNode * maxHead = p1 > p2 ? leftSubTressInfo->head : rightSubTressInfo->head;
if (maxSize == includeItSelf) {
	maxHead = head;
}

return new ReturnData(maxSize,
	max(max(leftSubTressInfo->max, rightSubTressInfo->max), head->val),
	min(min(leftSubTressInfo->min, rightSubTressInfo->min), head->val),
	maxHead);

}


int maxSearchSubTree(TreeNode * head)
{
	return process(head)->size;
}

void  maxSearchSubTreeTest()
{
	
	TreeNode *head = new TreeNode(6);
	head->left = new TreeNode(5);
	head->right = new TreeNode(10);
	head->left->left = new TreeNode(2);
	head->left->right = new TreeNode(4);
	head->right->left = new TreeNode(7);
	head->right->right = new TreeNode(9);
	cout << maxSearchSubTree(head);
}
