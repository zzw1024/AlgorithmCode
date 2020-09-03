#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//【题目】
//	二叉树中，一个节点可以往上走和往下走，那么从节点A总能走到节点B。
//	节点A走到节点B的距离为：A走到B最短路径【每个节点只走一次，不能重复走】上的节点个数。
//	求一棵二叉树上的最远距离
//	即，A到B可能有多条路径，求最长路径
//【题解】
//	使用递归，求每一个节点为头的整棵子树的最大距离，则答案在其中
//	可能性一：
//	就是左子树的最大距离
//	可能性二：
//	就是右子树的最大距离
//	可能性三：
//	从左子树到右子树的最大距离


struct Node
{
	int val;
	Node* l;
	Node* r;
	Node(int a) :val(a), l(nullptr), r(nullptr) {}
};

struct returnType
{
	int h;
	int maxDis;
	returnType(int a, int b) :h(a), maxDis(b) {}
};

//第一种递归
returnType* findMaxDis1(Node* head)
{
	if (head == nullptr)
		return new returnType(0, 0);
	//递归获得左右子树的大小
	returnType *lres, *rres;
	lres = findMaxDis1(head->l);
	rres = findMaxDis1(head->r);

	//判断
	int maxDis = max(max(lres->maxDis, rres->maxDis), lres->h + 1 + rres->h);//根据树的深度进行判断
	int h = max(lres->h, rres->h) + 1;//越向下深入探索，则树的深度加1
	return new returnType(h, maxDis);
}


//第二种递归
vector<int> findMaxDis2(Node* head)
{
	if (head == nullptr)
		return { 0, 0 };

	vector<int>lv, rv;
	lv = findMaxDis2(head->l);
	rv = findMaxDis2(head->r);
	int maxDis = max(max(lv[1], rv[1]), lv[0] + 1 + rv[0]);
	int h = max(lv[0], lv[0]) + 1;
	return { h,maxDis };
}


void Test()
{

	Node* root = new Node(9);
	root->l = new Node(8);
	root->r = new Node(1);
	root->l->l = new Node(5);
	root->l->r = new Node(9);
	root->l->l->l = new Node(4);
	root->l->l->r = new Node(6);
	root->r->l = new Node(5);
	root->r->r = new Node(3);
	returnType* p = findMaxDis1(root);
	cout << p->maxDis << endl;

	root = nullptr;
	root = new Node(5);
	root->l = new Node(2);
	root->r = new Node(6);
	root->l->l = new Node(1);
	root->l->r = new Node(3);
	p = findMaxDis1(root);
	cout << p->maxDis << endl;

	vector<int>v;
	root = nullptr;
	root = new Node(9);
	root->l = new Node(8);
	root->r = new Node(1);
	root->l->l = new Node(5);
	root->l->r = new Node(9);
	root->l->l->l = new Node(4);
	root->l->l->r = new Node(6);
	root->r->l = new Node(5);
	root->r->r = new Node(3);
	v = findMaxDis2(root);
	cout << v[1] << endl;

	root = nullptr;
	root = new Node(5);
	root->l = new Node(2);
	root->r = new Node(6);
	root->l->l = new Node(1);
	root->l->r = new Node(3);
	v = findMaxDis2(root);
	cout << v[1] << endl;

	
}