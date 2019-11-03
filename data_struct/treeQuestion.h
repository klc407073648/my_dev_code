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
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* Mirror(TreeNode *pRoot) {
	if (pRoot == NULL)
		return;
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



TreeNode* copyTreeFun
(TreeNode* root) {
	if (root == NULL)
		return NULL;
	TreeNode *t = new TreeNode(root->val);
	t->left = copyTreeFun(root->left);
	t->right = copyTreeFun(root->right);
	return t;

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
		else if ((top1->right != NULL&&top2->right == NULL) || (top1->right == NULL&&top2->right != NULL) || (top1->right != NULL&&top2->right != NULL&&top1->right->val != top2->right->val))
			return false;
		else if (top1->left != NULL&&top2->left != NULL&&top1->left->val == top2->left->val)
		{
			s1.push(top1->left);
			s2.push(top2->left);
		}
		else  if ((top1->left != NULL&&top2->left == NULL) || (top1->left == NULL&&top2->left != NULL) || (top1->left != NULL&&top2->left != NULL&&top1->left->val != top2->left->val))
			return false;
	}
	return true;
}


