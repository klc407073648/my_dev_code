#ifndef _TRIE_  
#define _TRIE_  

#include <iostream>  
#include <fstream>  
#include <string>  
#include <algorithm>  
#include <assert.h>  
using namespace std;
const int MaxBranchNum = 26;//������ִ�Сд��������չ��52  

							/*����trie�����*/
class TrieNode
{
public:
	char* word; //�ڵ��ʾ�ĵ���  
	int count;  //���ʳ��ֵĴ���  
	TrieNode* nextBranch[MaxBranchNum];//ָ��26���ַ��ڵ��ָ��  
public:
	TrieNode() : word(NULL), count(0)
	{
		memset(nextBranch, NULL, sizeof(TrieNode*) * MaxBranchNum);
	}
	//Node *next[26];//26��
	//Node()
	//{
	//	isWord = false;
	//	for (int i = 0; i != 26; ++i)
	//	{
	//		next[i] = NULL;//���26��
	//	}
	//}

};

/*������Trie*/
class Trie
{
public:
	Trie();
	~Trie();
	void Insert(const char* str);//�����ַ���str  
	bool Search(const char* str, int& count);//�����ַ���str�������س��ֵĴ���  
	bool Remove(const char* str);//ɾ���ַ���str  
	void PrintALL();//��ӡtrie�������еĽ��  
	void PrintPre(const char* str);//��ӡ��strΪǰ׺�ĵ���  
private:
	TrieNode* pRoot;
private:
	void Destory(TrieNode* pRoot);
	void Print(TrieNode* pRoot);
};

#endif //_TRIE_  

Trie::Trie()
{
	pRoot = new TrieNode();//ע���ֵ����ĸ�������ַ�  
}

Trie::~Trie()
{
	Destory(pRoot);
}

/*����һ������*/
void Trie::Insert(const char* str)
{
	assert(NULL != str);
	int index;
	TrieNode* pLoc = pRoot;
	for (int i = 0; str[i]; i++)
	{
		index = str[i] - 'a';//������ִ�Сд��������չ  

		if (index < 0 || index > MaxBranchNum)//��ִ�в���  
		{
			return;
		}

		if (NULL == pLoc->nextBranch[index])//�õ��ʵ�ǰ׺�����ڣ�Ҫ���ɸý��  
		{
			pLoc->nextBranch[index] = new TrieNode();
		}
		pLoc = pLoc->nextBranch[index];
	}
	if (NULL != pLoc->word)//�����Ѿ����ֹ�  
	{
		pLoc->count++;
		return;
	}
	else    //����û�г��ֹ���Ӧ�ò��뵥��  
	{
		pLoc->count++;
		pLoc->word = new char[strlen(str) + 1];
		assert(NULL != pLoc->word);
		strcpy(pLoc->word, str);
	}
}

/*����һ�����ʣ�������ڸõ��ʣ��򷵻�����ִ���*/
bool Trie::Search(const char* str, int& count)
{
	assert(str != NULL);
	int i = 0;
	int index = -1;;
	TrieNode* pLoc = pRoot;
	while (pLoc && *str)
	{
		index = *str - 'a';//������ִ�Сд��������չ  

		if (index < 0 || index > MaxBranchNum)//����һ�����ʣ���ִ�в���  
		{
			return false;
		}

		pLoc = pLoc->nextBranch[index];
		str++;
	}
	if (pLoc && pLoc->word)//�����������ҵ��õ���  
	{
		count = pLoc->count;
		return true;
	}
	return false;
}

bool Trie::Remove(const char* str)
{
	assert(NULL != str);
	int index = -1;;
	TrieNode* pLoc = pRoot;
	while (pLoc && *str)
	{
		index = *str - 'a';//������ִ�Сд��������չ  

		if (index < 0 || index > MaxBranchNum)//����һ�����ʣ���ִ�в���  
		{
			return false;
		}

		pLoc = pLoc->nextBranch[index];
		str++;
	}
	if (pLoc && pLoc->word)//�����������ҵ��õ���  
	{
		delete[] pLoc->word;
		pLoc->word = NULL;
		return true;
	}
	return false;
}

void Trie::PrintALL()
{
	Print(pRoot);
}

void Trie::PrintPre(const char* str)
{
	assert(str != NULL);
	int i = 0;
	int index = -1;;
	TrieNode* pLoc = pRoot;
	while (pLoc && *str)
	{
		index = *str - 'a';//������ִ�Сд��������չ  

		if (index < 0 || index > MaxBranchNum)//����һ�����ʣ���ִ�в���  
		{
			return;
		}

		pLoc = pLoc->nextBranch[index];
		str++;
	}
	if (pLoc)//�����������ҵ��õ���  
	{
		Print(pLoc);
	}
}

/*�����ֵ�˳�������pRootΪ�������еĵ���*/
void Trie::Print(TrieNode* pRoot)
{
	if (NULL == pRoot)
	{
		return;
	}
	//�������  
	if (NULL != pRoot->word)
	{
		cout << pRoot->word << " " << pRoot->count << endl;
	}
	//�ݹ鴦���֧  
	for (int i = 0; i < MaxBranchNum; i++)
	{
		Print(pRoot->nextBranch[i]);
	}
}

/*����trie��*/
void Trie::Destory(TrieNode* pRoot)
{
	if (NULL == pRoot)
	{
		return;
	}
	for (int i = 0; i < MaxBranchNum; i++)
	{
		Destory(pRoot->nextBranch[i]);
	}
	//���ٵ���ռ�ÿռ�  
	if (NULL != pRoot->word)
	{
		delete[]pRoot->word;
		pRoot->word = NULL;
	}
	delete pRoot;//���ٽ��  
	pRoot = NULL;
}

int main()
{
	Trie t;
	string str;
	int count = -1;
	ifstream in("word.txt");
	//�ѵ��������ֵ���  
	while (in >> str)
	{
		transform(str.begin(), str.end(), str.begin(), tolower);//��д��Сд  
		t.Insert(str.c_str());
	}
	//����  
	bool isFind = t.Search("the", count);
	if (isFind)
	{
		cout << "����the,���ִ�����" << count << endl;
	}
	else
	{
		cout << "������the!" << endl;
	}
	//���  
	t.PrintALL();
	//ɾ��  
	bool isDel = t.Remove("the");
	if (isDel)
	{
		cout << "ɾ���ɹ�!" << endl;
	}
	else
	{
		cout << "ɾ��ʧ��!" << endl;
	}
	//�����w��ͷ�ĵ���  
	t.PrintPre("w");
	cout << endl;
	system("pause");
}
