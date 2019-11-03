#include<stack>
#include<queue>
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
void  bfs(TreeNode* head)
{
	if (head == NULL)
		return;
	queue<TreeNode*> queue;
	queue.push(head);

	while (!queue.empty())
	{
		TreeNode* cur = queue.front();
		cout << cur->val << " ";
		queue.pop();
		if (cur->left != NULL)
			queue.push(cur->left);
		if (cur->right != NULL)
			queue.push(cur->right);
		

	}
}
void dfs(TreeNode* head)
{
	if (head == NULL)
		return;
	stack<TreeNode*> stack;
	stack.push(head);
	while (!stack.empty())
	{
		TreeNode* cur = stack.top();
		cout << cur->val << " ";
		stack.pop();
		if (cur->right != NULL)
		{
			stack.push(cur->right);
		}
		if (cur->left != NULL)
		{
			stack.push(cur->left);
		}
		
	}

}

void bfsTest()
{
	TreeNode *head = new TreeNode(5);
	head->left = new TreeNode(3);
	head->right = new TreeNode(7);
	head->left->left = new TreeNode(2);
	head->left->right = new TreeNode(4);
	head->right->left = new TreeNode(6);
	head->right->right = new TreeNode(8);

	bfs(head);
	cout << endl;
	dfs(head);
}