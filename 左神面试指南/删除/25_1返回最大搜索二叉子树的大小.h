#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//【题目】
//	给定一棵二叉树的头节点head，请返回最大搜索二叉子树的大小
//
//【题解】
//简化问题，想到该问题的解答应该有几种情形
//第一种可能：
//	最大搜索二叉子树在head的左子树
//第二种可能：
//	最大搜索二叉子树在head的右子树
//第三种可能：
//	最大搜索二叉子树为自己；利用左子树的最大值与右子树的最小值
//递归左子树，再递归右子树
//	信息1：左子树中最大搜索二叉树的大小
//	信息2：右子树中最大搜索二叉树的大小
//	信息3：左子树最大搜索二叉树的头结点
//	信息4：右子树最大搜索二叉树的头结点
//	信息5：左子树上的最大值
//	信息6：右子树上的最小值
//使用递归，求每一个结点所包含的最大搜索二叉树


struct Node
{
	int val;
	Node* l;
	Node* r;
	Node(int a) :val(a), l(nullptr), r(nullptr) {}
};

//递归方式一
struct returnType
{
	int size;
	Node* head;
	int min;
	int max;
	returnType(int s, Node* h, int mi, int ma) :size(s), head(h), min(mi), max(ma) {}
};

returnType* findSTree1(Node* head)
{
	if (head == nullptr)
		return new returnType(0, nullptr, INT_MAX, INT_MIN);
	returnType* lInfo = findSTree1(head->l);//得到左子树的最大搜索二叉树
	returnType* rInfo = findSTree1(head->r);//得到右子树的最大搜索二叉树

	int selfSize = 0;//判断包含该头节点的整棵树是否为搜索二次树
	if (lInfo->head == head->l &&
		rInfo->head == head->r &&
		lInfo->max < head->val &&
		rInfo->min > head->val
		)
		selfSize = lInfo->size + 1 + rInfo->size;

	int maxSize = max(max(lInfo->size, rInfo->size), selfSize);//求得最大的搜索二叉树的大小
	Node* maxHead = nullptr;//选择最大的子树的头结点
	if (maxSize == selfSize)
		maxHead = head;
	else if (maxSize == lInfo->size)
		maxHead = lInfo->head;
	else
		maxHead = rInfo->head;

	//这时返回的是包含head的整颗子树
	return new returnType(maxSize, maxHead,
		min(min(lInfo->min, rInfo->min), head->val),
		max(max(lInfo->max, rInfo->max), head->val));
}


//使用第二种递归

Node* findSTree2(Node* head, vector<int>&info)
{
	if (head == nullptr)
	{
		info[0] = 0;
		info[1] = INT_MIN;
		info[2] = INT_MAX;
		return nullptr;
	}
	vector<int>hv = info;
	//得到左右子树的信息
	Node* lNode = findSTree2(head->l, info);
	vector<int>lv = info;
	Node* rNode = findSTree2(head->r, info);
	vector<int>rv = info;
	//更新信息
	info[1] = max(max(lv[1], rv[1]), head->val);
	info[2] = min(min(lv[2], rv[2]), head->val);
	//判断
	if (lNode == head->l && rNode == head->r && lv[1] < head->val && rv[2] > head->val)
	{
		info[0] = lv[0] + rv[0] + 1;
		return head;
	}
	info[0] = max(lv[0], rv[0]);
	return lv[0] > rv[0] ? lNode : rNode;
}


int maxSTree(Node* head)
{
	vector<int>info(3,0);//储存字数的大小、最大值、最小值
	findSTree2(head, info);
	return info[0];
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
	returnType* p = findSTree1(root);
	cout << p->size << endl;
	
	root = nullptr;
	root = new Node(5);
	root->l = new Node(2);
	root->r = new Node(6);
	root->l->l = new Node(1);
	root->l->r = new Node(3);
	p = findSTree1(root);
	cout << p->size << endl;

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
	cout << maxSTree(root) << endl;

	root = nullptr;
	root = new Node(5);
	root->l = new Node(2);
	root->r = new Node(6);
	root->l->l = new Node(1);
	root->l->r = new Node(3);
	cout << maxSTree(root) << endl;



}