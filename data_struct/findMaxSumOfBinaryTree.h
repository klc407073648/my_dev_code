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

//���ɹ�ϣ��map��map�������Ǽ�¼��head��ʼ��һ��·���ϵ��ۼӺͣ�����keyֵ��ʾĳ���ۼӺͣ�value��ʾ�ۼӺͳ��ֵ����������
//���磬����ĳ��·���ϵĽڵ�ֵΪ[1, 2, 3, -3, 5]����ômap�еļ�¼Ϊ[1:1, 3 : 2, 6 : 3, 3 : 2, 8 : 5]��ע��value��ʾ�ۼӺ�
//���ֵ��������������map�еĵ��ĸ���¼�͵ڶ�����¼��ͬ�����Ե�������¼��ʵ����Ҫ���룬map�ļ�¼Ӧ��Ϊ[1:1, 3 : 2, 6 : 3, 8 : 5]��
//
//��map����ӣ�0�� 0����¼����ʾ�ۼӺ� 0 �����κνڵ�Ϳ��Եõ����������������������������ĵ�ǰλ����cur������Ϊlevel��
//��ʱ���ۼӺ�ӦΪcur�ĸ��ڵ���ۼӺ�presum����cur�ڵ��ֵ����cursum = presum + cur.val�������presum + cur.val, level��
//�����¼�Ѿ�������map�У�����Ҫ�ٴβ��롣������������Ҫ���Ĺ����ǣ��ж��Ƿ�����cur��β��·�����ۼӺ� ������Ŀ������
//ָ��ֵsum��ֻ��Ҫ��map��Ѱ���Ƿ���cursum - sum�����¼���ɣ�������������¼�Ļ� level - map[cursum - sum]������������
//��һ��·�����ȣ�ʹ��ȫ�ֱ�������·�������ֵ��
//
//��Ҫע����ǣ��ڱ����������������Ҫ���ص�cur�ĸ��ڵ��ǣ���Ҫ��map�иýڵ�ļ�¼ɾȥ�����֮ǰ����Ļ�����
//������ܳ���·�������Զ����µ������



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

