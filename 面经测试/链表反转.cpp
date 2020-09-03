//#include "head.h"
//
//struct Node
//{
//	int val;
//	Node* next;
//	Node(int a = 0) :val(a), next(nullptr) {}
//};
//
//Node* ReverseLink(Node* head)
//{
//	Node *cur = head, *next  = head->next, *p = nullptr;
//	while (cur->next)
//	{
//		cur->next = p;
//		p = cur;
//		cur = next;
//		next = cur->next;
//	}
//	cur->next = p;
//	return cur;
//}
//int main()
//{
//	Node* head = new Node(0);
//	head->next = new Node(1);
//	head->next->next = new Node(2);
//	head->next->next->next = new Node(3);
//	head->next->next->next->next = new Node(4);
//	head->next->next->next->next->next = new Node(5);
//	head = ReverseLink(head);
//	while (head)
//	{
//		cout << head->val << "->";
//		head = head->next;
//	}
//	return 0;
//}