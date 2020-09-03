//#include <iostream>
//
//using namespace std;
//
////Problem：
////	两个单链表相交的一系列问题
////	【题目】 在本题中，单链表可能有环，也可能无环。给定两个
////	单链表的头节点 head1和head2，这两个链表可能相交，也可能
////	不相交。请实现一个函数， 如果两个链表相交，请返回相交的
////	第一个节点；如果不相交，返回null 即可。 
////	要求：如果链表1	的长度为N，链表2的长度为M，时间复杂度请达到 O(N + M)，额外
////	空间复杂度请达到O(1)
////
////Solution：
////	对于判断单链表是否有环，则使用快慢指针即可知道，两指针相交，则有环
////	对于判断双链表是否相交，则判断遍历链表的最后指针的地址是否相同，相同则有公共部分
////	然后在从头遍历，长的链表先遍历长的部分，然后一起遍历，当指针相同时，则为相交的部位。
//
//
//
//struct Node
//{
//	int val;
//	Node* next;
//	Node(int a = 0) :val(a), next(NULL) {}
//};
//
//void FindNode(Node* head1, Node* head2)
//{
//	if (head1->next == NULL || head2->next == NULL)
//		return;
//	Node *p1, *p2;
//	p1 = head1->next;
//	p2 = head2->next;
//	int size1, size2;//计算链表长度
//	size1 = size2 = 1;
//	while (p1->next || p2->next)
//	{
//		if (p1->next)
//		{
//			p1 = p1->next;
//			size1++;
//		}
//		if (p2->next)
//		{
//			p2 = p2->next;
//			size2++;
//		}
//	}
//	if (p1 != p2)
//	{
//		cout << "List1 and List2 have no commmon part!" << endl;
//		return;
//	}
//	cout << "List1 and List2 have commmon part!" << endl;
//	//重新遍历，找到交点
//	p1 = head1->next;
//	p2 = head2->next;
//	for (int i = 0; i < (size1 > size2 ? size1 - size2 : size2 - size1); ++i)//长的先遍历
//	{
//		if (size1 > size2)
//			p1 = p1->next;
//		else
//			p2 = p2->next;
//	}
//	while (p1 != p2)
//	{
//		p1 = p1->next;
//		p2 = p2->next;
//	}
//	cout << "相交部位为：addr：" << p1 << "  val:" << p1->val << endl;
//
//}
//
//void Test()
//{
//	int a[] = { 1,2,3,4,5,6 };
//	int b[] = { 4,5,6 };
//	int c[] = { 7,8,9,10 };
//	Node* head1 = new Node(-1);
//	Node* head2 = new Node(-1);
//	Node* p1 = head1;
//	Node* p2 = head2;
//
//	for (auto n : a)
//	{
//		Node* q = new Node(n);
//		p1->next = q;
//		p1 = q;
//	}
//	p1->next = NULL;
//	for (auto n : b)
//	{
//		Node* q = new Node(n);
//		p2->next = q;
//		p2 = q;
//	}
//	p2->next = NULL;
//
//	cout << "相交之前判断：" << endl;
//	FindNode(head1, head2);
//	cout << "***********************" << endl;
//	for (auto n : c)
//	{
//		Node* q = new Node(n);
//		p1->next = q;
//		p1 = q;
//		p2->next = q;
//		p2 = q;
//	}
//	p1->next = NULL;
//	p2->next = NULL;
//
//	cout << "相交之后判断：" << endl;
//	FindNode(head1, head2);
//	cout << "***********************" << endl;
//}
//
