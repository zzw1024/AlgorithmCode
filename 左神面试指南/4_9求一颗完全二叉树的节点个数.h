#pragma once
#include <iostream>

using namespace std;

//Problem:
//	已知一棵完全二叉树，求其节点的个数
//	要求：时间复杂度低于O(N)，N为这棵树的节点个数
//
//Solution:
//   只要求到最左节点的最大深度+那个最右结束节点就行

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
	return bs(root, 1, mostLeftLevel(root, 1));//左节点最大深度
}

int bs(Node* root, int w, int h)
{
	if (w == h)
		return 1;
	if (mostLeftLevel(root->rchild, w + 1) == h)//若左节点的最大深度就是最深节点，则左子树为满树
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