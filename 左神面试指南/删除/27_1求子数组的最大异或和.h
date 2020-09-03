#pragma once
#include <iostream>
#include <vector>

using namespace std;


//【题目】
//	给定一个数组，求子数组的最大异或和。
//	一个数组的异或和为，数组中所有的数异或起来的结果。
//
//【题解】
//	必须以i结尾的最大异或和的最长数组
//	暴力解为O(N3)，就是每个数都暴力循环一遍
//
//	异或运算的性质：
//	e1 ^ e2 = e3
//	e1 = e2 ^ e3;
//	e2 = e3 ^ e1;
//
//	使用前缀树：
//	将0~i的异或和计算出来，换算成二进制数据
//	然后将二进制数据组成一颗二叉树
//
//	然后怎么找到最大异或和？
//	就是除了首位希望为0，因为首位为1是负数
//	然后后面的数尽量走1的这条路，然后那条路就是最大的异或和
//	主要难点就是使用移位将所位的二进制各个位置上的数提取出来
//

class TreeNode
{

public:
	struct Node
	{
		int val;
		vector<Node*>nexts;
		Node(int a) :val(a), nexts({ nullptr,nullptr }) {}
	};

	void add(int num)
	{
		Node* cur = head;
		for (int i = 31; i >= 0; --i)
		{
			int k = ((num >> i) & 1);//取出每一位数字
			cur->nexts[k] = cur->nexts[k] == nullptr ? new Node(-1) : cur->nexts[k];
			cur = cur->nexts[k];
		}
	}

	int maxXor(int num)
	{
		Node* cur = head;
		int s = 0;
		for (int i = 31; i >= 0; --i)
		{
			int k = (num >> i) & 1;//从最高位一位一位取出数据
			int b = i == 31 ? k : (k ^ 1);
			b = cur->nexts[b] != nullptr ? b : (b ^ 1);
			s |= (k^b) << i;
			cur = cur->nexts[b];
		}
		return s;
	}
public:
	Node* head = new Node(-1);
};


int getMaxXOR(vector<int>num)
{
	if (num.size() == 0)
		return 0;
	int xors = 0;
	int res = INT_MIN;
	TreeNode numTree;
	numTree.add(0);
	for (auto a : num)
	{
		xors ^= a;
		res = res > numTree.maxXor(xors) ? res : numTree.maxXor(xors);
		numTree.add(xors);
	}
	return res;		
}


void Test()
{
	vector<int>v;
	v = { 1,2,3,4,5 };
	cout << getMaxXOR(v) << endl;
}