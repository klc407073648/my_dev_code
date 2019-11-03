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

//class ReturnData
//{
//   public:
//	   int maxLength;
//	   int curSum;
//	   ReturnData(int length,int sum)
//	   {
//		   maxLength = length;
//		   curSum = sum;
//	   }
//};
//ReturnData* process(TreeNode *head,int sum)
//{
//	if (head == NULL)
//	{
//		return  new ReturnData(0,0);
//	}
//	if (head->val == 0)
//	{
//		return  new ReturnData(1,0);
//	}
//	ReturnData* leftTree = process(head->left, sum- head->val);
//	ReturnData* rightTree = process(head->right, sum - head->val);
//
//	
//	return new ReturnData(leftTree->maxLength>rightTree->maxLength? leftTree->maxLength : rightTree->maxLength,max(leftTree->maxLength, rightTree->maxLength));
//}
//
//int findMaxLengthOfBinaryTree(TreeNode *head,int sum)
//{
//	if (head == NULL)
//		return 0;
//	return process(head, sum)->maxLength;
//}

//生成哈希表map，map的作用是记录从head开始的一条路径上的累加和，其中key值表示某个累加和，value表示累加和出现的最早层数。
//例如，假设某个路径上的节点值为[1, 2, 3, -3, 5]，那么map中的记录为[1:1, 3 : 2, 6 : 3, 3 : 2, 8 : 5]，注意value表示累加和
//出现的最早层数，所以map中的第四个记录和第二个记录相同，所以第四条记录其实不必要插入，map的记录应该为[1:1, 3 : 2, 6 : 3, 8 : 5]。
//
//在map中添加（0， 0）记录，表示累加和 0 不用任何节点就可以得到。先序遍历二叉树，假设遍历到的当前位置是cur，层数为level，
//此时的累加和应为cur的父节点的累加和presum加上cur节点的值，即cursum = presum + cur.val。如果（presum + cur.val, level）
//这个记录已经存在于map中，则不需要再次插入。接下来，我们要做的工作是，判断是否有以cur结尾的路径的累加和 等于题目所给的
//指定值sum。只需要在map中寻找是否有cursum - sum这个记录即可，如果存在这个记录的话 level - map[cursum - sum]就是满足条件
//的一个路径长度，使用全局变量更新路径的最大值。
//
//需要注意的是，在遍历完二叉树的子树要返回到cur的父节点是，需要将map中该节点的记录删去（如果之前插入的话），
//否则可能出现路径不是自顶向下的情况。



int  preOrder(TreeNode *head, int sum, int preSum,int level, int maxLen, map<int, int> sumMap)
{
	if (head == NULL)
		return maxLen;
	int curSum = preSum + head->val;
	if (sumMap.count(curSum) == 0)
	{
		sumMap.insert(pair<int, int>(curSum, level));
	}
	if (sumMap.count(curSum - sum) == 1)
	{
		maxLen = max(maxLen, level - sumMap[curSum - sum]);
	}

	maxLen=preOrder(head->left, sum, curSum, level + 1, maxLen, sumMap);
	maxLen=preOrder(head->right, sum, curSum, level + 1, maxLen, sumMap);

	if (level == sumMap[curSum]) {
		sumMap.erase(curSum);
	}
	return maxLen;
}

int findMaxLengthOfBinaryTree(TreeNode *head, int sum)
{
	map<int, int> sumMap;
	sumMap.insert(pair<int, int>(0, 0));
	return preOrder(head, sum, 0, 1, 0, sumMap);
}

void myTestTree()
{
	TreeNode *head = new TreeNode(-3);
	head->left = new TreeNode(3);
	head->right = new TreeNode(9);
	head->left->left = new TreeNode(1);
	head->left->right = new TreeNode(0);
	head->right->left = new TreeNode(2);
	head->right->right = new TreeNode(1);
	head->left->right->left = new TreeNode(1);
	head->left->right->right = new TreeNode(6);
   
	cout << findMaxLengthOfBinaryTree(head, 6)<<endl;
	cout << findMaxLengthOfBinaryTree(head, -9);

}

