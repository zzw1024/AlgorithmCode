#pragma once
#include <iostream>
#include <vector>

using namespace std;

//【题目】
//	一个公司的上下节关系是一棵多叉树，这个公司要举办晚会，你作为组织者已经摸清了大家的心理：
//	一个员工的直接上级如果到场，这个员工肯定不会来。
//	每个员工都有一个活跃度的值，决定谁来你会给这个员工发邀请函，怎么让舞会的气氛最活跃？
//	返回最大的活跃值。
//	举例：
//	给定一个矩阵来表述这种关系
//		matrix =
//		{
//		1,6
//		1,5
//		1,4
//		}
//	这个矩阵的含义是：
//	matrix[0] = { 1 , 6 }，表示0这个员工的直接上级为1, 0这个员工自己的活跃度为6
//	matrix[1] = { 1 , 5 }，表示1这个员工的直接上级为1（他自己是这个公司的最大boss）, 1这个员工自己的活跃度为5
//	matrix[2] = { 1 , 4 }，表示2这个员工的直接上级为1, 2这个员工自己的活跃度为4
//	为了让晚会活跃度最大，应该让1不来，0和2来。最后返回活跃度为10
//
//【题解】
//	使用动态规划
//	每个节点保存其活跃度
//	然后嘛整棵树按照等级进行展开
//	x1来的活跃度为：x1的活跃度 + x1所有子节点不来的活跃度
//	x1不来的活跃度：x1不来 + x1所有子节点的每个节点中的max(来，不来)
//


///使用递归求解
void process(vector<vector<int>>data, vector<vector<int>>&dp, vector<bool>isVist, int& root)
{
	isVist[root] = true;//遍历过
	dp[root][1] = data[root][1];//获取活跃值
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i][0] == root && !isVist[i])
		{
			process(data, dp, isVist, i);
			dp[root][1] += dp[i][0];
			dp[root][0] += dp[i][0] > dp[i][1] ? dp[i][0] : dp[i][1];
		}
	}
}



//使用动态规划解题
int getMaxHappy(vector<vector<int>>data)
{
	vector<vector<int>>dp(data.size(), vector<int>(data[0].size(), 0));
	vector<bool>isVist(data.size(), false);
	int root = 0;//找到boss
	for (int i = 0; i < data.size(); ++i)
		if (data[i][0] == i)//自己是自己的 上司，则此人为boss
		{
			root = i;
			break;
		}
	process(data, dp, isVist, root);
	return dp[root][0] > dp[root][1] ? dp[root][0] : dp[root][1];
}


///使用二叉树的递归来求解
struct Node
{
	int val;//活跃度
	vector<Node*>child;//下属，是1:n的关系
	Node(int a) :val(a) {}
};

Node* Create(const vector<vector<int>>data)
{
	Node* head = nullptr;
	vector<Node*>node(data.size());
	int root = 0;
	for (int i = 0; i < data.size(); ++i)
		if (data[i][0] == i)
		{
			root = i;
			break;
		}
	node[root] = new Node(data[root][1]);
	for (int i=0;i<data.size();++i)
	{
		if (data[i][0] != i)//不是大boss
		{
			node[i] = new Node(data[i][1]);
			node[data[i][0]]->child.push_back(node[i]);
		}
		else
			head = node[i];
	}
	return head;
}


struct returnType
{
	int c;//来的活跃度
	int nc;//不来的活跃度
	returnType(int a, int b) :c(a), nc(b) {}
};

returnType* calMaxHappy(Node* head)
{
	int cvalue, ncvalue;
	cvalue = head->val;//head去的活跃度
	ncvalue = 0;//head不去的活跃度
	for (int i = 0; i != head->child.size(); ++i)
	{
		returnType* res = calMaxHappy(head->child[i]);
		cvalue += res->nc;
		//上司去的活跃度 = 上司的活跃度 + 下属不去的活跃度；因为上司去，下属不会去
		ncvalue += res->c > res->nc ? res->c : res->nc;
		//上司不去的活跃 = 上司不去的活跃度 + 下属去或者不去的最大值，因为上司不去，下属可以去，亦可以不去
	}
	return new returnType(cvalue, ncvalue);
}

void Test()
{
	vector<vector<int>>data;
	data = { {1,6},{1,5},{1,4} };
	cout << getMaxHappy(data) << endl;

	Node* head = Create(data);
	returnType* p = calMaxHappy(head);
	cout << (p->c > p->nc ? p->c : p->nc) << endl;
}