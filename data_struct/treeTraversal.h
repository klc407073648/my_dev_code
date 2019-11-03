#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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


class treeTraversal {
public:
	vector<int> result;
	vector<int> preOrderTraversal(TreeNode * root) {
		// write your code here
		if (root == NULL)
			return result;
		result.push_back(root->val);
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
		return result;
	}

	vector<int> inOrderTraversal(TreeNode * root) {
		// write your code here
		if (root == NULL)
			return result;
		inOrderTraversal(root->left);
		result.push_back(root->val);
		inOrderTraversal(root->right);
		return result;
	}

	vector<int> postOrderTraversal(TreeNode * root) {
		// write your code here
		if (root == NULL)
			return result;
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		result.push_back(root->val);
		return result;
	}
};


class treeNoRecurTraversal {
public:
	vector<int> result;
	vector<int> preOrderTraversal(TreeNode * root) {
		// write your code here
		if (root == NULL)
			return result;
		stack<TreeNode *> stack;
		stack.push(root);
		while(!stack.empty())
		{ 
			TreeNode *top = stack.top();
			result.push_back(top->val);
			stack.pop();
			if (top->right != NULL)
				stack.push(top->right);
			if (top->left != NULL)
				stack.push(top->left);
			
		}
	}

	vector<int> inOrderTraversal(TreeNode * root) {
		// write your code here
		{
			if (root == NULL)
				return result;
			stack<TreeNode *> stack;
			//当前节点为空，从栈拿一个，打印,当前节点往右跑;
			//当前节点不为空，当前节点压入栈，当前节点往左
			while (!stack.empty() || root != NULL) {
				if (root != NULL) {
					stack.push(root);
					root = root->left;
				}
				else {
					root = stack.top();
					stack.pop();
					result.push_back(root->val);
					root = root->right;
				}
			}
			return result;
		}
	}

	vector<int> postorderTraversal(TreeNode * root) {
		// write your code here
		if (root == NULL)
			return result;
		stack<TreeNode *> stack1;
		stack<TreeNode *> stack2;
		stack1.push(root);
		while (!stack1.empty())//先中右左，压入栈，最后弹出 左右中
		{
			TreeNode *top = stack1.top();
			stack2.push(top);
			stack1.pop();
			if (top->left != NULL)
				stack1.push(top->left);
			if (top->right != NULL)
				stack1.push(top->right);
		}
		while (!stack2.empty())
		{
			result.push_back(stack2.top()->val);
			stack2.pop();
		}
		return result;
	}
};

void treeTraversalTest()
{
	 TreeNode *head = new TreeNode(2);
	head->left= new TreeNode(1);
	head->right = new TreeNode(3);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(6);
	head->right->left = new TreeNode(7);
	head->right->right = new TreeNode(5);
	vector<int> nums1, nums2, nums3;
	treeTraversal s;
	nums1 = s.preOrderTraversal(head);
	for (int i = 0; i < nums1.size(); i++)
		cout << nums1[i] << " ";
		cout << endl;
	s.result = {};
	nums2 = s.inOrderTraversal(head);
	for (int i = 0; i < nums2.size(); i++)
		cout << nums2[i] << " ";
	cout << endl;
	s.result = {};
	nums3 = s.postOrderTraversal(head);
	for (int i = 0; i < nums3.size(); i++)
		cout << nums3[i] << " ";
	cout << endl;
}