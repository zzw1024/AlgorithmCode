#pragma once
#include <iostream>
#include <string>

using namespace std;

//
//Promblem:
//	��������������T1��T2������T1��ĳ�������ṹ�Ƿ���T2�Ľṹ��ȡ�
//
//Solution:
//	���ཫ�������������л����мǼ��Ϸָ���Ϳսڵ��ǡ���
//	Ȼ��ʹ��KMP�㷨���������ַ���ƥ�䣬�ж��������Ƿ�����ԭ��������
//

struct Node
{
	char c;
	Node* lchild;
	Node* rchild;
	Node(char a) :c(a), lchild(nullptr), rchild(nullptr) {}
};

void getSequence(string &str, Node* root)
{
	if (root == nullptr)
		str += "#_";
	else
	{
		str = str + root->c + "_";
		getSequence(str, root->lchild);
		getSequence(str, root->rchild);
	}
}

void getIndex(int*& index, string str)
{
	for (int i = 0, p = 0; i < str.length(); ++i)
	{
		if (0 == i)
			index[0] = -1;
		else if (1 == i)
			index[i] = 0;
		else
		{
			if (str[i - 1] == str[p])
				index[i] = ++p;
			else if (p > 0)
				p = index[p];
			else
				index[i] = 0;
		}
	}
}

bool isSubTree(Node* root1, Node* root2)
{
	string str1, str2;
	str1 = str2 = "";
	//���л�
	getSequence(str1, root1);
	getSequence(str2, root2);
	//��ȡ������ǰ��׺����
	int* index = new int[str2.length()];
	getIndex(index, str2);
	
	//ʹ��KMP�����ж�
	int i, j;
	i = j = 0;
	while (i < str1.length() && j < str2.length())
	{
		if (str1[i] == str2[j])
		{
			++i;
			++j;
		}
		else if (-1 == index[j])
		{
			j = 0;
			++i;
		}
		else
			j = index[j];
	}
	delete[] index;
	return (i <= str1.length() && j >= str2.length());
}

void Test()
{
	Node *root1, *root2;
	root1 = new Node('5');

	root1->lchild = new Node('4');
	root1->rchild = new Node('3');
	root1->lchild->lchild = new Node('2');
	root1->lchild->rchild = new Node('1');
	root1->rchild->rchild = new Node('1');

	root2 = new Node('3');
	root2->rchild = new Node('1');
	cout << isSubTree(root1, root2) << endl;

	root2 = nullptr;
	root2 = new Node('4');
	root2->lchild = new Node('2');
	cout << isSubTree(root1, root2) << endl;
}