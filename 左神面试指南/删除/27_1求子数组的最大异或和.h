#pragma once
#include <iostream>
#include <vector>

using namespace std;


//����Ŀ��
//	����һ�����飬���������������͡�
//	һ�����������Ϊ�����������е�����������Ľ����
//
//����⡿
//	������i��β��������͵������
//	������ΪO(N3)������ÿ����������ѭ��һ��
//
//	�����������ʣ�
//	e1 ^ e2 = e3
//	e1 = e2 ^ e3;
//	e2 = e3 ^ e1;
//
//	ʹ��ǰ׺����
//	��0~i�����ͼ������������ɶ���������
//	Ȼ�󽫶������������һ�Ŷ�����
//
//	Ȼ����ô�ҵ�������ͣ�
//	���ǳ�����λϣ��Ϊ0����Ϊ��λΪ1�Ǹ���
//	Ȼ��������������1������·��Ȼ������·������������
//	��Ҫ�ѵ����ʹ����λ����λ�Ķ����Ƹ���λ���ϵ�����ȡ����
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
			int k = ((num >> i) & 1);//ȡ��ÿһλ����
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
			int k = (num >> i) & 1;//�����λһλһλȡ������
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