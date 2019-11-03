#include<vector>
#include<iostream>

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

void morrisTraveal(TreeNode *head)
{
	if (head == NULL)
		return;
	TreeNode *cur = head;
	while (cur != NULL)
	{
		if (cur->left == NULL)
		{
			cout << cur->val << " ";
			cur = cur->right;
		}
		else if (cur->left != NULL)
		{
			TreeNode *mostRight = cur->left;
			while (mostRight->right != NULL&&mostRight->right!=cur)
			{
				mostRight = mostRight->right;
			}
			if (mostRight->right == NULL)
			{
				mostRight->right = cur;
				cout << cur->val << " ";
				cur = cur->left;
			}
			else
			{
				mostRight->right = NULL;
				
				cur = cur->right;
			}
		}
	}
}
void morrisTravealTest()
{
	TreeNode *head = new TreeNode(5);
	head->left = new TreeNode(3);
	head->right = new TreeNode(7);
	head->left->left = new TreeNode(2);
	head->left->right = new TreeNode(4);
	head->right->left = new TreeNode(6);
	head->right->right = new TreeNode(8);
	 morrisTraveal(head);
	int s = 0;
}