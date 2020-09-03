//#include<iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
////【题目】
////给定一个链表的头节点head，请判断该链表是否为回文结构。
////例如：
////1->2->1，返回true。
////1->2->2->1，返回true。
////15->6->15，返回true。
////1->2->3，返回false。
////进阶：
////如果链表长度为N，时间复杂度达到O（N），额外空间复杂度达到O（1）。
////【题解】
////方法一：
////遍历一遍链表，将数据压入栈中
////然后再遍历一遍链表与栈的弹出数据对比
////方法二：
////使用快慢指针，将链表的前部分压入栈，然后栈数据弹出与链表的后半部分对比
////方法三：
////使用快慢指针，将链表的后半部分反转，然后与链表前半部分对比
//
//struct Node
//{
//	int val;
//	Node* next;
//	Node(int a = 0) :val(a), next(nullptr) {}
//};
//
//bool Way1(Node* head)
//{
//	stack<int>s;
//	Node* p = head->next;
//	while (p)
//	{
//		s.push(p->val);
//		p = p->next;
//	}
//	p = head->next;
//	while (!s.empty())
//	{
//		if (p->val != s.top())
//			return false;
//		p = p->next;
//		s.pop();
//	}
//	return true;
//}
//bool Way2(Node* head)
//{
//	Node *p, *q;
//	stack<int>s;
//	p = q = head->next;
//	while (q && q->next)
//	{
//		p = p->next;
//		q = q->next->next;
//	}
//	if (q)
//		p = p->next;
//	while (p)
//	{
//		s.push(p->val);
//		p = p->next;
//	}
//	p = head->next;
//	while (!s.empty())
//	{
//		if (p->val != s.top())
//			return false;
//		p = p->next;
//		s.pop();
//	}
//	return true;
//}
//bool Way3(Node* head)
//{
//	Node *p, *q, *pre=nullptr;
//	stack<int>s;
//	p = q = head->next;
//	while (q && q->next)
//	{
//		pre = p;
//		p = p->next;
//		q = q->next->next;
//	}
//	if (q)
//	{
//		pre = p;
//		p = p->next;
//	}
//	pre->next = nullptr;
//	while (p)
//	{
//		q = p->next;
//		p->next = pre->next;
//		pre->next = p;
//		p = q;
//	}
//	p = head->next;
//	while (pre->next)
//	{
//		if (p->val != pre->next->val)
//			return false;
//		p = p->next;
//		pre = pre->next;
//	}
//	return true;	
//}
//
//int main()
//{
//	Node* head = new Node(-1);
//	Node* p = head;
//	vector<int>v;
//	v = { 1,2,2,1 };
//	for (auto a : v)
//	{
//		Node* q = new Node(a);
//		p->next = q;
//		p = q;
//	}
//	cout << Way1(head) << endl;
//	cout << Way2(head) << endl;
//	cout << Way3(head) << endl;
//	
//	return 0;
//}