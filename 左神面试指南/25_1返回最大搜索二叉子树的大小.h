#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����Ŀ��
//	����һ�ö�������ͷ�ڵ�head���뷵������������������Ĵ�С
//
//����⡿
//�����⣬�뵽������Ľ��Ӧ���м�������
//��һ�ֿ��ܣ�
//	�����������������head��������
//�ڶ��ֿ��ܣ�
//	�����������������head��������
//�����ֿ��ܣ�
//	���������������Ϊ�Լ������������������ֵ������������Сֵ
//�ݹ����������ٵݹ�������
//	��Ϣ1������������������������Ĵ�С
//	��Ϣ2������������������������Ĵ�С
//	��Ϣ3�����������������������ͷ���
//	��Ϣ4�����������������������ͷ���
//	��Ϣ5���������ϵ����ֵ
//	��Ϣ6���������ϵ���Сֵ
//ʹ�õݹ飬��ÿһ��������������������������


struct Node
{
	int val;
	Node* l;
	Node* r;
	Node(int a) :val(a), l(nullptr), r(nullptr) {}
};

//�ݹ鷽ʽһ
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
	returnType* lInfo = findSTree1(head->l);//�õ����������������������
	returnType* rInfo = findSTree1(head->r);//�õ����������������������

	int selfSize = 0;//�жϰ�����ͷ�ڵ���������Ƿ�Ϊ����������
	if (lInfo->head == head->l &&
		rInfo->head == head->r &&
		lInfo->max < head->val &&
		rInfo->min > head->val
		)
		selfSize = lInfo->size + 1 + rInfo->size;

	int maxSize = max(max(lInfo->size, rInfo->size), selfSize);//������������������Ĵ�С
	Node* maxHead = nullptr;//ѡ������������ͷ���
	if (maxSize == selfSize)
		maxHead = head;
	else if (maxSize == lInfo->size)
		maxHead = lInfo->head;
	else
		maxHead = rInfo->head;

	//��ʱ���ص��ǰ���head����������
	return new returnType(maxSize, maxHead,
		min(min(lInfo->min, rInfo->min), head->val),
		max(max(lInfo->max, rInfo->max), head->val));
}


//ʹ�õڶ��ֵݹ�

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
	//�õ�������������Ϣ
	Node* lNode = findSTree2(head->l, info);
	vector<int>lv = info;
	Node* rNode = findSTree2(head->r, info);
	vector<int>rv = info;
	//������Ϣ
	info[1] = max(max(lv[1], rv[1]), head->val);
	info[2] = min(min(lv[2], rv[2]), head->val);
	//�ж�
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
	vector<int>info(3,0);//���������Ĵ�С�����ֵ����Сֵ
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