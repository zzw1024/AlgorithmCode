//#pragma once
//
//#include <iostream>
//
//using namespace std;
//
////Problem:
////	��ת�����˫������
////	����Ŀ�� �ֱ�ʵ�ַ�ת��������ͷ�ת˫������ĺ�����
////	��Ҫ�� ���������ΪN��ʱ�临�Ӷ�Ҫ��ΪO(N)������ռ�
////	���Ӷ�Ҫ��ΪO(1)
////
////Solution:
////	ѧ��ʹ��ָ��
//
//struct Node
//{
//	int val;
//	Node* next;
//	Node(int a = 0) :val(a), next(NULL) {}
//};
//
//void ReverSingleList(Node*& head)//��ת��������
//{
//	if (head->next == NULL || head->next->next == NULL)
//		return;
//	Node *p1, *p2, *p3;
//	p1 = head->next;
//	p2 = p1->next;
//	p3 = p2->next;
//	p1->next = NULL;
//	while (p3)
//	{
//		p2->next = p1;
//		p1 = p2;
//		p2 = p3;
//		p3 = p3->next;
//	}
//	p2->next = p1;
//	head->next = p2;
//}
//
//
//struct DNode
//{
//	int val;
//	DNode* next;
//	DNode* pre;
//	DNode(int a = 0) :val(a), next(NULL), pre(NULL) {}
//};
//
//void ReverDoubleList(DNode*& head)//��ת˫�����������뵥������һ��
//{
//	if (head->next == NULL || head->next->next == NULL)
//		return;
//	DNode *p1, *p2, *p3;
//	p1 = head->next;
//	p2 = p1->next;
//	p3 = p2->next;
//	p1->next = NULL;
//	p1->pre = p2;
//	while (p3)
//	{
//		p2->next = p1;
//		p1->pre = p2;
//		p2->pre = p3;
//		p1 = p2;
//		p2 = p3;
//		p3 = p3->next;
//	}
//	p2->next = p1;
//	p2->pre = head;
//	head->next = p2;
//}
//
//void Test()
//{
//	int a[6] = { 1,2,3,4,5,6 };
//	Node* head = new Node(-1);
//	Node* p = head;
//	for (auto n : a)
//	{
//		Node* q = new Node(n);
//		p->next = q;
//		p = q;
//	}
//	p->next = NULL;
//
//	p = head->next;
//	cout << "ԭ����Ϊ�� ";
//	while (p)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//
//	ReverSingleList(head);
//	p = head->next;
//	cout << endl << "*******************" << endl << "��ת�������Ϊ�� ";
//	while (p)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//	cout << endl << "=============================" << endl;
//	cout << "=============================" << endl;
//	cout << "=============================" << endl;
//
//
//	int b[6] = { 1,2,3,4,5,6 };
//	DNode* head2 = new DNode(-1);
//	DNode* p2 = head2;
//	for (auto n : b)
//	{
//		DNode* q2 = new DNode(n);
//		p2->next = q2;
//		q2->pre = p2;
//		p2 = q2;
//	}
//	p2->next = NULL;
//
//	p2 = head2->next;
//	cout << "ԭ����Ϊ��˳Ϊ�� ";
//	while (p2->next)
//	{
//		cout << p2->val << "->";
//		p2 = p2->next;
//	}
//	cout << p2->val << "->";
//	cout << endl << "*******************" << endl << "ԭ����Ϊ����Ϊ�� ";
//	while (p2->pre)
//	{
//		cout << p2->val << "->";
//		p2 = p2->pre;
//	}
//
//	ReverDoubleList(head2);
//	p2 = head2->next;
//	cout << endl << "*******************" << endl << "��ת���˫�������˳Ϊ�� ";
//	while (p2->next)
//	{
//		cout << p2->val << "->";
//		p2 = p2->next;
//	}
//	cout << p2->val << "->";
//	cout << endl << "*******************" << endl << "��ת���˫���������Ϊ�� ";
//	while (p2->pre)
//	{
//		cout << p2->val << "->";
//		p2 = p2->pre;
//	}
//	cout << endl << "=============================" << endl;
//}
