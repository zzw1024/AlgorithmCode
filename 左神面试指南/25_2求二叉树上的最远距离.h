#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//����Ŀ��
//	�������У�һ���ڵ���������ߺ������ߣ���ô�ӽڵ�A�����ߵ��ڵ�B��
//	�ڵ�A�ߵ��ڵ�B�ľ���Ϊ��A�ߵ�B���·����ÿ���ڵ�ֻ��һ�Σ������ظ��ߡ��ϵĽڵ������
//	��һ�ö������ϵ���Զ����
//	����A��B�����ж���·�������·��
//����⡿
//	ʹ�õݹ飬��ÿһ���ڵ�Ϊͷ�����������������룬���������
//	������һ��
//	������������������
//	�����Զ���
//	������������������
//	����������
//	������������������������


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

//��һ�ֵݹ�
returnType* findMaxDis1(Node* head)
{
	if (head == nullptr)
		return new returnType(0, 0);
	//�ݹ������������Ĵ�С
	returnType *lres, *rres;
	lres = findMaxDis1(head->l);
	rres = findMaxDis1(head->r);

	//�ж�
	int maxDis = max(max(lres->maxDis, rres->maxDis), lres->h + 1 + rres->h);//����������Ƚ����ж�
	int h = max(lres->h, rres->h) + 1;//Խ��������̽������������ȼ�1
	return new returnType(h, maxDis);
}


//�ڶ��ֵݹ�
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