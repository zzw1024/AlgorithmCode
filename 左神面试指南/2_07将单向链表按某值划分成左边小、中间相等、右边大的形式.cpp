//#pragma once
//
//#include <iostream>
//
//using namespace std;
//
////Problem：
////【题目】 给定一个单向链表的头节点head，节点的值类型是整型，再给定一个整数pivot。
////	实现一个调整链表的函数，将链表调整为左部分都是值小于 pivot的节点，
////	中间部分都是值等于pivot的节点，右部分都是值大于 pivot的节点。
////	除这个要求外，对调整后的节点顺序没有更多的要求。
////	例如：链表9->0->4->5->1，pivot = 3。 
////	调整后链表可以是1->0->4->9->5，
////	可以是0->1->9->5->4。
////	总之，	满足左部分都是小于3的节点，
////	中间部分都是等于3的节点（本例中这个部分为空），
////	右部分都是大于3的节点即可。对某部分内部的节点顺序不做要求。
////进阶：
////	在原问题的要求之上再增加如下两个要求。在左、中、右三个部分的内部也做顺序要求
////	要求每部分里的节点从左 到右的顺序与原链表中节点的先后次序一致。 
////	例如：链表9->0->4->5->1，pivot = 3。调整后的链表是0->1->9->4->5。 
////	在满足原问题要求的同时，左部分节点从左到右为0、1。在原链表中也 是先出现0，后出现1；
////	中间部分在本例中为空，不再讨论；右部分节点 从左到右为9、4、5。在原链表中也是先出现9，然后出现4，最后出现5。
////	
////	如果链表长度为N，时间复杂度请达到O(N)，额外空间复杂度请达到O(1）
////	
////		
////Solution:
////	使用两个指针，pr后插数来存放小数，pr前插数来存放相等的数，p为遍历游动指针
//
//struct Node
//{
//	int val;
//	Node* next;
//	Node(int a = 0) :val(a), next(NULL) {}
//};
//
//void Partition(Node*& head, const int num)
//{
//	Node *pr, *p;
//	p = pr = head;
//	while (p->next)
//	{
//		if (p->next->val < num)
//		{
//			Node* q;
//			q = pr->next;
//			pr->next = p->next;
//			p->next = p->next->next;
//			pr = pr->next;
//			pr->next = q;
//		}
//		else if (p->next->val == num)
//		{
//			Node* q;
//			q = pr->next;
//			pr->next = p->next;
//			p->next = p->next->next;
//			pr->next->next = q;
//		}
//		else
//			p = p->next;
//	}
//
//}
//
//
//void Test()
//{
//	int a[] = { 7,2,8,1,4,5,4,6 };
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
//	cout << "原链表为： ";
//	while (p)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//
//	Partition(head, 4);
//	p = head->next;
//	cout << endl << "*******************" << endl << "分部分后的链表为： ";
//	while (p)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//	cout << endl << "=============================" << endl;
//}