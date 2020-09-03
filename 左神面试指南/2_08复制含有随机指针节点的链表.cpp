//#pragma once
//#include <iostream>
//#include <hash_map>
//
//using namespace std;
////
////
////Problem:
////	复制含有随机指针节点的链表
////	【题目】 一种特殊的链表节点类描述如下：
////	public class Node {
////		public int value; 
////      public Node next; 
////		public Node rand;
////		public Node(int data) { this.value = data; }
////	}
////	Node类中的value是节点值，next指针和正常单链表中next指针的意义
////	一 样，都指向下一个节点，rand指针是Node类中新增的指针，这个指
////	针可 能指向链表中的任意一个节点，也可能指向null。 给定一个由
////	Node节点类型组成的无环单链表的头节点head，请实现一个 函数完成
////	这个链表中所有结构的复制，并返回复制的新链表的头节点。 进阶：
////	不使用额外的数据结构，只用有限几个变量，且在时间复杂度为 O(N)
////	内完成原问题要实现的函数。
////
////Solution 
////	一：
////		使用hash_map来进行存放原链表
////		key=原链表，  value=新建链表的节点
////		然后根据原链表的结构将新链表进行结构构造
////	二：
////		将原链表数组原地复制两份：
////					head 1 2 3 4 5 6 NULL
////		复制成： head head' 1 1' 2 2' 3 3' 4 4' 5 5' 6' 6' NULL
////		然后Copy则取带'的节点就行
////
//
//
//
//
//
//struct Node
//{
//	int val;
//	Node *rand;
//	Node *next;
//	Node(int a = -1) :val(a), rand(NULL), next(NULL) {}
//};
//
//
//Node* CopeListDeep(Node* head)
//{
//	hash_map<Node*, Node*>map;
//	Node* p = head;
//	while (p)//新建链表的结构
//	{
//		map[p] = new Node(-1);
//		p = p->next;
//	}
//
//	p = head;
//	while (p)//重构新链表的结构
//	{
//		map[p]->val = p->val;
//		map[p]->next = map[p->next];
//		map[p]->rand = map[p->rand];
//		p = p->next;
//	}
//	return map[head];
//}
//
//Node* CopeListDeep2(Node* head)
//{
//	Node* cur = head;
//	Node* next = NULL;
//	while (cur)//将原链表复制两份
//	{
//		next = cur->next;
//		cur->next = new Node(cur->val);
//		cur->next->next = next;//此处为复制两份的代码
//		cur = next;
//	}
//
//	cur = head;
//	Node* copyHead = NULL;//为了区分原链
//	//先复制rand节点
//	while (cur)//将新建的节点的结构进行重构
//	{
//		next = cur->next->next;//原链表的遍历
//		copyHead = cur->next;
//		copyHead->rand = ((cur->rand) == NULL ? NULL : (cur->rand)->next);
//		cur = next;
//	}
//	//copyHead已经是链表的末尾NULL
//	cur = head;
//	Node* res = head->next;
//	while (cur)
//	{
//		next = cur->next->next;
//		copyHead = cur->next;
//		cur->next = next;
//		copyHead->next = (next == NULL) ? NULL : next->next;
//		cur = next;
//	}
//
//	//为什么不一次性将原链表进行还原和复制链表进行重构？
//	//因为一旦原链表前半部分还原，而后半部分一旦有rand指向前半部分，原链表是能找到所指向
//	//的节点，但由于前半部分原链表已经还原了，所以复制链表的rand无法依据原链表的位置找到自己rand所指向的节点，
//	//故得先将rand  copy出来。
//	return res;
//
//}
//
//
//void Test()
//{
//	Node *head = new Node(-1);
//	head->next = new Node(1);
//	head->next->next = new Node(2);
//	head->next->next->next = new Node(3);
//	head->next->next->next->next = new Node(4);
//	head->next->next->next->next->next = new Node(5);
//	head->next->next->next->next->next->next = new Node(6);
//	head->next->next->next->next->next->next->next = NULL;
//
//
//	head->rand = NULL;
//	head->next->rand = head->next->next->next->next->next->next;
//	head->next->next->rand = head->next->next->next->next->next->next;
//	head->next->next->next->rand = head->next->next->next->next->next;
//	head->next->next->next->next->rand = head->next->next->next;
//	head->next->next->next->next->next->rand = NULL;
//	head->next->next->next->next->next->next->rand = head->next->next->next->next;
//
//
//	cout << "打印原链表:" << endl;
//	Node*p = head->next;
//	while (p)
//	{
//		cout << "next: " << p->val << "   rand: " << ((p->rand) ? p->rand->val : -1) << endl;
//		p = p->next;
//	}
//
//	cout << endl << "打印新链表:" << endl;
//	p = CopeListDeep2(head)->next;
//	while (p)
//	{
//		cout << "next: " << p->val << "   rand: " << ((p->rand) ? p->rand->val : -1) << endl;
//		p = p->next;
//	}
//
//
//}
//
//
