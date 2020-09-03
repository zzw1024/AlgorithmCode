#pragma once

#include <iostream>
#include <sstream>
#include <queue>
#include <string>

using namespace std;

//Problem:
//	判断是否为完全二叉树
//
//Solution：
//	即按层添加节点，
//	必须该层的左节点先加，然后有节点添加，每一层的中间不能出现空节点！
//
//	思路：
//		使用层序遍历，若中间出现空节点，则不是一颗完全二叉树
//		当一个节点有右无左，则不是一棵完全二叉树
//		当一个节点有左无右，那么接下来的节点应都是无孩子节点

//直观地打印一颗树，即打印一横向的树，每个节点的左上角节点为其父节点

struct Node
{
	int val;
	Node* lchild;
	Node* rchild;
	Node(int a = -1) :val(a), lchild(NULL), rchild(NULL) {}
};


class PrintTree
{
public:
	void Print(Node* root)
	{
		cout << "The shape of tree is: " << endl;
		cout << "=============================================================" << endl;
		PrintShape(root, 0, "H", 17);
		cout << "=============================================================" << endl;
	}
	void PrintShape(Node* root, int h, string c, int len)
	{
		if (root)
		{
			PrintShape(root->rchild, h + 1, "v", len);
			string val;
			stringstream ss;
			ss << root->val;
			ss >> val;
			val = c + val + c;
			int lenM = val.length();
			int lenL = (len - lenM) / 2;
			int lenR = len - lenM - lenL;
			val = getSpace(lenL) + val + getSpace(lenR);
			cout << getSpace(h*len) + val << endl;
			PrintShape(root->lchild, h + 1, "^", len);
		}

	}
	string getSpace(int num)
	{
		string space = " ";
		for (int i = 0; i < num; ++i)
			space.append(" ");
		return space;
	}
};


bool isCBT(Node* root)
{
	if (root == NULL)
		return true;
	bool flag = false;
	queue<Node*>q;
	q.push(root);
	while (!q.empty())
	{
		root = q.front();
		q.pop();
		if (root == NULL)
			continue;

		if (flag)
			if (root->lchild || root->rchild)
				return false;

		if (root->lchild == NULL && root->rchild != NULL)
			return false;

		if (root->lchild == NULL)//当左孩子为空时，接下的节点的孩子必须为空
			flag = true;

		q.push(root->lchild);
		q.push(root->rchild);
	}
	return true;
}


void Test()
{
	PrintTree print;
	Node* root = new Node(1);
	root->lchild = new Node(2);
	root->rchild = new Node(3);
	root->lchild->lchild = new Node(4);
	root->lchild->rchild = new Node(5);
	root->rchild->lchild = new Node(6);
	root->rchild->rchild = new Node(7);
	root->rchild->lchild->lchild = new Node(8);
	root->rchild->lchild->rchild = new Node(9);
	print.Print(root);

	if (isCBT(root))
		cout << "This is a CBT!" << endl;
	else
		cout << "This is not a CBT!" << endl;
}