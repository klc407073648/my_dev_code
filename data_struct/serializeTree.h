#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
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

//
//class serializeTree {
//public:
//	string result;
//	string preOrderTraversal(TreeNode * root) {
//		// write your code here
//		if (root == NULL)
//		{
//			result.insert(result.size(), "#");
//			result.insert(result.size(), "_");
//           return result;
//		}
//			
//		result.insert(result.size(), std::to_string(root->val));
//		result.insert(result.size(), "_");
//		preOrderTraversal(root->left);
//		preOrderTraversal(root->right);
//		return result;
//	}
//
//};

class serializeTree {
public:
	
	string serialByPre(TreeNode * root) {
		// write your code here
		if (root == NULL)
		{
			return "#!";
		}
		string res = to_string(root->val) + "!";
		res += serialByPre(root->left);
		res += serialByPre(root->right);
		return res;
	}
	TreeNode* reconByPreString(string preStr) {
		queue<string> queue1;
		for (int i = 0; i < preStr.size(); i++)
		{
			string str="";
			while (preStr[i] != '!')
			{
				str = str + preStr[i++];
			}
			queue1.push(str);
		}
		
		return reconPreOrder(queue1);
	}

	//反序列化输出
	TreeNode*  reconPreOrder(queue<string> &s) {
		string value = s.front();
		s.pop();
		if (value=="#") {
			return NULL;
		}
		TreeNode *node = new TreeNode(std::stoi(value));
		node->left  = reconPreOrder(s);
		node->right = reconPreOrder(s);
		return node;
	}

};



	


void serializeTreeTest()
{
	TreeNode *head = new TreeNode(23);
	head->left = new TreeNode(14);
	head->right = new TreeNode(15);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(6);
	head->right->left = new TreeNode(7);
	head->right->right = new TreeNode(5);
	vector<int> nums1, nums2, nums3;
	serializeTree s;
	string str = s.serialByPre(head);
	/*for (int i = 0; i < str.size(); i++)
		cout << str[i] ;*/
	TreeNode* t=s.reconByPreString(str);
	int tt = 0;


	
}
