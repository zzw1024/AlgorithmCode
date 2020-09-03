#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Problem:
//	在二叉树中找到一个节点的后继节点
//	【题目】 现在有一种新的二叉树节点类型如下：
//	public class Node { 
//		public int value; 
//		public Node left; 
//		public Node right; 
//		public Node parent; 
//		public Node(int data) { this.value = data; }
//	}
//	该结构比普通二叉树节点结构多了一个指向父节点的parent指针。
//	假设有一 棵Node类型的节点组成的二叉树，
//	树中每个节点的parent指针都正确地指向自己的父节点，
//	头节点的parent指向null。只给一个在二叉树中的某个节点 node，
//	请实现返回node的后继节点的函数。在二叉树的中序遍历的序列中， 
//	node的下一个节点叫作node的后继节
//
//
//Solution:
//		在中序遍历的顺序中，每一个节点的后一个节点即为该节点的后继节点，
//		先驱节点即为中序顺序的前面节点。
//
//		节点x的后继节点为：
//		【若有右子树】即为该节点的右子树最左的节点
//		【若无右子树】：
//		通过前驱指针，向上回溯父节点，并判断该节点是否为该父节点的左子树，
//		若是，则该父节点为该节点的后继节点。不是，父节点继续向上回溯其父。
//		若一直找不到，则该节点的后继节点为空。



struct Node
{
	int val;
	Node* lchild;
	Node* rchild;
	Node* parent;
	Node(int a = -1) :val(a), lchild(NULL), rchild(NULL),parent(NULL) {}
};

void Create(Node*& root, vector<int>num)//层序构造树
{
	queue<Node*>q;
	root = new Node(num[0]);
	q.push(root);
	int i = 1;
	while (i < num.size() && !q.empty())
	{
		Node* p = q.front();
		q.pop();
		if (!p)//空节点p
			break;
		if (num[i] > 0)
		{
			p->lchild = new Node(num[i++]);
			p->lchild->parent = p;
		}
		if (num[i] > 0)
		{
			p->rchild = new Node(num[i++]);
			p->rchild->parent = p;
		}
		q.push(p->lchild);
		q.push(p->rchild);
	}
}

void MidTravel(Node *root)
{
	if (!root)
		return;
	MidTravel(root->lchild);
	cout << root->val << "  ";
	MidTravel(root->rchild);
}

Node* FindNode(Node* node)
{
	if (node->rchild)//有右子树，那么后继节点即为右子树的最左的节点
	{
		Node* p = node->rchild;
		while (p->lchild)
			p = p->lchild;
		return p;		
	}
	//无右子树
	//后继节点为该节点为某个父节点的左子树
	Node *f;//父亲指针
	f = node->parent;
	while (!f)
	{
		if (node == f->lchild)
			return f;
		node = f;
		f = node->parent;
	}
	//该节点为最右节点，故无后继节点
	return NULL;
}

void Test()
{
	Node* root = NULL;
	vector<int>num = { 1,2,3,4,5,6,7,8,9,10,11,12,-1,-1,-1 };
	Create(root, num);//层序构造树

	cout << "=============查看中序遍历==============" << endl;
	MidTravel(root);
	cout << endl << endl;

	Node* p = NULL;
	p = root->rchild;		 
	cout << "节点 " << p->val << " 的后继节点为：";
	p = FindNode(p);
	if (p)
		cout << p->val << endl;
	else
		cout << "空。" << endl;

	p = root->lchild->rchild;
	cout << "节点 " << p->val << " 的后继节点为：";
	p = FindNode(p);
	if (p)
		cout << p->val << endl;
	else
		cout << "空。" << endl;

	p = root->rchild->rchild;
	cout << "节点 " << p->val << " 的后继节点为：";
	p = FindNode(p);
	if (p)
		cout << p->val << endl;
	else
		cout << "空。" << endl;

}
		