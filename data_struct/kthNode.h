#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

 bool cmp111(TreeNode *t1, TreeNode *t2)
{
	return  t1->val<t2->val;
}
TreeNode* KthNode(TreeNode* pRoot, int k)
{
	stack<TreeNode*> s;
	s.push(pRoot);
	vector<TreeNode*> result;
	while (!s.empty())
	{
		TreeNode  *cur = s.top();
		result.push_back(cur);
		s.pop();
		if (cur->right != NULL)
			s.push(cur->right);
		if (cur->left != NULL)
			s.push(cur->left);
	}
	sort(result.begin(), result.end(), cmp111);
	return result[k - 1];

}
TreeNode* Mirror(TreeNode *pRoot) {
	if (pRoot == NULL)
		return NULL;
	queue<TreeNode *> s;
	s.push(pRoot);
	while (!s.empty())
	{
		TreeNode *top = s.front();
		TreeNode *temp = top->left;
		top->left = top->right;
		top->right = temp;
		s.pop();
		if (top->right != NULL)
		{
			s.push(top->right);
		}
		if (top->left != NULL)
		{
			s.push(top->left);
		}
	}
	return pRoot;
}
TreeNode* copyTreeFun(TreeNode *pRoot) {
	if (pRoot == NULL)
		return NULL;
	TreeNode *copyTree = new TreeNode(pRoot->val);
	queue<TreeNode *> s, s1;
	s.push(pRoot);
	s1.push(copyTree);
	while (!s.empty() && !s1.empty())
	{
		TreeNode *top = s.front();
		TreeNode *top1 = s1.front();
		s.pop();
		s1.pop();
		if (top->right != NULL)
		{
			top1->right = new TreeNode(top->right->val);
			s.push(top->right);
			s1.push(top1->right);
		}
		if (top->left != NULL)
		{
			top1->left = new TreeNode(top->left->val);
			s.push(top->left);
			s1.push(top1->left);
		}
	}
	return copyTree;
}
bool isSymmetrical(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return true;
	TreeNode *copyTree = copyTreeFun(pRoot);
	TreeNode *symTree = Mirror(pRoot);
	queue<TreeNode *> s1, s2;
	s1.push(copyTree);
	s2.push(symTree);
	while (!s1.empty() && !s2.empty())
	{
		TreeNode *top1 = s1.front();
		TreeNode *top2 = s2.front();
		s1.pop();
		s2.pop();
		if (top1->right != NULL&&top2->right != NULL&&top1->right->val == top2->right->val)
		{
			s1.push(top1->right);
			s2.push(top2->right);
		}
		else if ((top1->right != NULL&&top2->right == NULL) || (top1->right == NULL&&top2->right != NULL)&& (top1->right != NULL&&top2->right != NULL&&top1->right->val != top2->right->val))
			return false;
		else if (top1->left != NULL&&top2->left != NULL&&top1->left->val == top2->left->val)
		{
			s1.push(top1->left);
			s2.push(top2->left);
		}
		else  if ((top1->left != NULL&&top2->left == NULL) || (top1->left == NULL&&top2->left != NULL)&& (top1->left != NULL&&top2->left != NULL&&top1->left->val != top2->left->val))
			return false;
	}
	return true;

}

void KthNodeTest()
{
	TreeNode *head = new TreeNode(5);
	head->left = new TreeNode(6);
	head->right = new TreeNode(9);
	head->left->left = new TreeNode(5);
	head->left->right = new TreeNode(7);
	head->right->left = new TreeNode(7);
	head->right->right = new TreeNode(5);
	TreeNode *t=KthNode(head,3);
	bool t1= isSymmetrical(head);
	int s = 0;
}


//
//class Solution {
//public:
//
//	static bool cmp111(TreeNode *t1, TreeNode *t2)
//	{
//		return  t1->val<t2->val;
//	}
//	TreeNode* KthNode(TreeNode* pRoot, int k)
//	{
//		if (pRoot == NULL || k == 0)
//			return NULL;
//
//		stack<TreeNode*> s;
//		s.push(pRoot);
//		vector<TreeNode*> result;
//		while (!s.empty())
//		{
//			TreeNode  *cur = s.top();
//			result.push_back(cur);
//			s.pop();
//			if (cur->right != NULL)
//				s.push(cur->right);
//			if (cur->left != NULL)
//				s.push(cur->left);
//		}
//		if (result.size()<k)
//			return NULL;
//		sort(result.begin(), result.end(), cmp111);
//
//		return result[k - 1];
//
//	}
//
//
//};