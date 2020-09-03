#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Problem:
//	�ڶ��������ҵ�һ���ڵ�ĺ�̽ڵ�
//	����Ŀ�� ������һ���µĶ������ڵ��������£�
//	public class Node { 
//		public int value; 
//		public Node left; 
//		public Node right; 
//		public Node parent; 
//		public Node(int data) { this.value = data; }
//	}
//	�ýṹ����ͨ�������ڵ�ṹ����һ��ָ�򸸽ڵ��parentָ�롣
//	������һ ��Node���͵Ľڵ���ɵĶ�������
//	����ÿ���ڵ��parentָ�붼��ȷ��ָ���Լ��ĸ��ڵ㣬
//	ͷ�ڵ��parentָ��null��ֻ��һ���ڶ������е�ĳ���ڵ� node��
//	��ʵ�ַ���node�ĺ�̽ڵ�ĺ������ڶ���������������������У� 
//	node����һ���ڵ����node�ĺ�̽�
//
//
//Solution:
//		�����������˳���У�ÿһ���ڵ�ĺ�һ���ڵ㼴Ϊ�ýڵ�ĺ�̽ڵ㣬
//		�����ڵ㼴Ϊ����˳���ǰ��ڵ㡣
//
//		�ڵ�x�ĺ�̽ڵ�Ϊ��
//		����������������Ϊ�ýڵ������������Ľڵ�
//		����������������
//		ͨ��ǰ��ָ�룬���ϻ��ݸ��ڵ㣬���жϸýڵ��Ƿ�Ϊ�ø��ڵ����������
//		���ǣ���ø��ڵ�Ϊ�ýڵ�ĺ�̽ڵ㡣���ǣ����ڵ�������ϻ����丸��
//		��һֱ�Ҳ�������ýڵ�ĺ�̽ڵ�Ϊ�ա�



struct Node
{
	int val;
	Node* lchild;
	Node* rchild;
	Node* parent;
	Node(int a = -1) :val(a), lchild(NULL), rchild(NULL),parent(NULL) {}
};

void Create(Node*& root, vector<int>num)//��������
{
	queue<Node*>q;
	root = new Node(num[0]);
	q.push(root);
	int i = 1;
	while (i < num.size() && !q.empty())
	{
		Node* p = q.front();
		q.pop();
		if (!p)//�սڵ�p
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
	if (node->rchild)//������������ô��̽ڵ㼴Ϊ������������Ľڵ�
	{
		Node* p = node->rchild;
		while (p->lchild)
			p = p->lchild;
		return p;		
	}
	//��������
	//��̽ڵ�Ϊ�ýڵ�Ϊĳ�����ڵ��������
	Node *f;//����ָ��
	f = node->parent;
	while (!f)
	{
		if (node == f->lchild)
			return f;
		node = f;
		f = node->parent;
	}
	//�ýڵ�Ϊ���ҽڵ㣬���޺�̽ڵ�
	return NULL;
}

void Test()
{
	Node* root = NULL;
	vector<int>num = { 1,2,3,4,5,6,7,8,9,10,11,12,-1,-1,-1 };
	Create(root, num);//��������

	cout << "=============�鿴�������==============" << endl;
	MidTravel(root);
	cout << endl << endl;

	Node* p = NULL;
	p = root->rchild;		 
	cout << "�ڵ� " << p->val << " �ĺ�̽ڵ�Ϊ��";
	p = FindNode(p);
	if (p)
		cout << p->val << endl;
	else
		cout << "�ա�" << endl;

	p = root->lchild->rchild;
	cout << "�ڵ� " << p->val << " �ĺ�̽ڵ�Ϊ��";
	p = FindNode(p);
	if (p)
		cout << p->val << endl;
	else
		cout << "�ա�" << endl;

	p = root->rchild->rchild;
	cout << "�ڵ� " << p->val << " �ĺ�̽ڵ�Ϊ��";
	p = FindNode(p);
	if (p)
		cout << p->val << endl;
	else
		cout << "�ա�" << endl;

}
		