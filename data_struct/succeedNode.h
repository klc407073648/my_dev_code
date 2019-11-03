#include<vector>
#include<iostream>
using namespace std;

 class Node {
 public:
	 int value;
	 Node *left, *right,*parent;
	 Node(int data) :value(data) {
		 left = NULL; 
		 right = NULL; 
		 parent = NULL;
	 }

 };

 Node* getMostLeftNode(Node *node)
 {
	 while (node->left != NULL)
	 {
		 node = node->left;
	 }

	 return node;
 }


 Node* succeedNode(Node *node)
 {
	 if (node == NULL)
		 return node;
	 else if (node->right != NULL)
	 {
		  return getMostLeftNode(node->right);
	 }
	 else
	 {
			 Node* parentNode = node->parent;
			 while (parentNode!=NULL&&node == parentNode->right)
			 {
				 node = parentNode;
				 parentNode = node->parent;
			 }
			 return  parentNode;
	 }
 }

 void succeedNodeTest()
 {
	 Node *head = new Node(6);
	 head->parent = NULL;
	 head->left = new Node(3);
	 head->left->parent = head;
	 head->left->left = new Node(1);
	 head->left->left->parent = head->left;
	 head->left->left->right = new Node(2);
	 head->left->left->right->parent = head->left->left;
	 head->left->right = new Node(4);
	 head->left->right->parent = head->left;
	 head->left->right->right = new Node(5);
	 head->left->right->right->parent = head->left->right;
	 head->right = new Node(9);
	 head->right->parent = head;
	 head->right->left = new Node(8);
	 head->right->left->parent = head->right;
	 head->right->left->left = new Node(7);
	 head->right->left->left->parent = head->right->left;
	 head->right->right = new Node(10);
	 head->right->right->parent = head->right;

	 Node *test = head->left->left;
	 cout << succeedNode(test)->value << endl;;
	 test = head->left->left->right;
	 cout << succeedNode(test)->value << endl;;
	 test = head->left;
	 cout << succeedNode(test)->value << endl;;
	 test = head->left->right;
	 cout << succeedNode(test)->value << endl;;
	 test = head->left->right->right;
	 cout << succeedNode(test)->value << endl;
	 test = head->right->right;//NULL
	 cout << succeedNode(test) << endl;;
	 
 }

