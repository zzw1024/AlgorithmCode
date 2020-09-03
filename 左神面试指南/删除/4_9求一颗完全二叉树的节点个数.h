#pragma once
#include <iostream>

using namespace std;

//Problem:
//	��֪һ����ȫ������������ڵ�ĸ���
//	Ҫ��ʱ�临�Ӷȵ���O(N)��NΪ������Ľڵ����
//
//Solution:
//   ֻҪ������ڵ��������+�Ǹ����ҽ����ڵ����

struct Node
{
	int val;
	Node* lchild;
	Node* rchild;
	Node(int a = -1) :val(a), lchild(NULL), rchild(NULL) {}
};


int NodeNum(Node* root)
{
	if (root == NULL)
		return 0;
	return bs(root, 1, mostLeftLevel(root, 1));//��ڵ�������
}

int bs(Node* root, int w, int h)
{
	if (w == h)
		return 1;
	if (mostLeftLevel(root->rchild, w + 1) == h)//����ڵ�������Ⱦ�������ڵ㣬��������Ϊ����
		return ((1 << (h - w)) + bs(root->rchild, w + 1, h));
	else 
		return ((1 << (h - w - 1)) + bs(root->lchild, w + 1, h));
}

int mostLeftLevel(Node* root, int level)
{
	while (root)
	{
		++level;
		root = root->lchild;
	}
	return level - 1;
}