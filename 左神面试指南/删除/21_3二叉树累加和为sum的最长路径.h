#pragma once
#include <iostream>
#include <vector>
#include <hash_map>
#include <algorithm>
using namespace std;

//����һ�ö�������ͷ�ڵ�head����һ������sum��������ÿ���ڵ��϶�
//�����֣����ǹ涨·�������Ǵ������µģ�����������ۼӺ�Ϊsum��
//�·�����ȡ�

///��ʹ�õݹ�

struct Node
{
	int val;
	Node* l;
	Node* r;
	Node(int a) :val(a), r(nullptr), l(nullptr) {}
};

int PreOrder(Node* root, int sum, int preSum, int level, int maxLen, hash_map<int, int>sumMap)
{
	if (root == nullptr)
		return maxLen;
	int curSum = preSum + root->val;
	if (sumMap.find(curSum) == sumMap.end())
		sumMap[curSum] = level;
	if (sumMap.find(curSum - sum) != sumMap.end())//����֮����ڣ���ֱ�Ӽ��㼴��
		maxLen = max(level - sumMap[curSum - sum], maxLen);

	maxLen = PreOrder(root->l, sum, curSum, level + 1, maxLen, sumMap);
	maxLen = PreOrder(root->r, sum, curSum, level + 1, maxLen, sumMap);
	if (level == sumMap[curSum])
		sumMap.erase(curSum);
	return maxLen;
}

int theNumTree(Node* root, int sum)
{
	hash_map<int, int>sumMap;
	sumMap[0] = 0;//����ͷ�ڵ�
	return PreOrder(root, sum, 0, 1, 0, sumMap);
}



void Test()
{
	Node* root = new Node(-3);
	root->l = new Node(4);
	root->r = new Node(5);
	root->l->l = new Node(7);
	root->l->r = new Node(8);
	root->r->l = new Node(5);
	root->r->r = new Node(7);
	root->l->l->l = new Node(6);
	root->l->l->r = new Node(4);
	root->l->r->l = new Node(3);
	root->l->r->r = new Node(1);
	root->r->l->l = new Node(9);
	root->r->l->r = new Node(10);
	root->r->r->l = new Node(1);
	root->r->r->r = new Node(2);

	cout << theNumTree(root, 10) << endl;
	cout << theNumTree(root, 14) << endl;
	cout << theNumTree(root, 100) << endl;


}