#pragma once
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;



struct Node
{
	int val;
	Node* lchild;
	Node* rchild;
	Node(int a = -1) :val(a), lchild(NULL), rchild(NULL) {}
};
//直观地打印一颗树，即打印一横向的树，每个节点的左上角节点为其父节点

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

bool isBST01(Node* root)
{
	if (root == NULL)
		return true;
	Node* pre = NULL;
	Node* cur1 = root;
	Node* cur2 = NULL;
	bool res = true;

	while (cur1)
	{
		cur2 = cur1->lchild;
		if (cur2)
		{
			while (cur2->rchild != NULL && cur2->rchild != cur1)
				cur2 = cur2->rchild;
			if (cur2->rchild == NULL)
			{
				cur2->rchild = cur1;
				cur1 = cur1->lchild;
				continue;
			}
			else
				cur2->rchild = NULL;
		}
		if (pre != NULL && pre->val > cur1->val)
			res = false;
		pre = cur1;
		cur1 = cur1->rchild;
	}
	return res;
}


//判断是否为搜索二叉树可以使用中序遍历，即判断中序遍历是否为升序即可
void inOrd(Node* root, vector<int>&v)
{
	if (root == NULL)
		return;
	inOrd(root->lchild, v);
	v.push_back(root->val);
	cout << root->val << "  ";
	inOrd(root->rchild, v);
}

bool isBST02(Node* root)//使用中序遍历
{
	vector<int>v;
	inOrd(root, v);
	cout << endl;
	for (int i = 0; i < v.size() - 1; ++i)
		if (v[i] >= v[i + 1])
			return false;
	return true;
}


void Test()
{
	PrintTree print;
	bool res = true;
	Node* root = new Node(1);
	root->lchild = new Node(2);
	root->rchild = new Node(3);
	root->lchild->lchild = new Node(4);
	root->lchild->rchild = new Node(5);
	root->rchild->lchild = new Node(6);
	root->rchild->rchild = new Node(7);
	root->lchild->lchild->lchild = new Node(8);
	print.Print(root);

	res = isBST01(root);
	if (res)
		cout << "This is a BST!" << endl;
	else
		cout << "This is not a BST!" << endl;

	root = NULL;
	root = new Node(10);
	root->lchild = new Node(6);
	root->rchild = new Node(14);
	root->lchild->lchild = new Node(4);
	root->lchild->rchild = new Node(8);
	root->rchild->lchild = new Node(13);
	root->rchild->rchild = new Node(15);
	root->lchild->lchild->lchild = new Node(3);
	root->lchild->lchild->rchild = new Node(5);
	root->lchild->rchild->lchild = new Node(7);
	root->lchild->rchild->rchild = new Node(9);
	print.Print(root);
	res = isBST01(root);
	if (res)
		cout << "This is a BST!" << endl;
	else
		cout << "This is not a BST!" << endl;


}
