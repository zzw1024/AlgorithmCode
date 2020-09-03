//#include "000¿âº¯Êý.h"
//
////struct RandomListNode {
////    int label;
////    RandomListNode *next, *random;
////    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
////};
//
//
//
//// Definition for a Node.
//class Node {
//public:
//	int val;
//	Node* next;
//	Node* random;
//
//	Node() {}
//
//	Node(int _val, Node* _next, Node* _random) {
//		val = _val;
//		next = _next;
//		random = _random;
//	}
//};
//
//class Solution {
//public:
//	Node* copyRandomList(Node* head) {
//		Node* p = head;
//		while (p != nullptr)
//		{
//			Node* q = new Node(p->val, nullptr,nullptr);
//			q->next = p->next;
//			p->next = q;
//			p = p->next->next;
//		}
//		p = head;
//		while (p != nullptr)
//		{
//			if (p->random != nullptr)
//				p->next->random = p->random->next;
//			p = p->next->next;
//		}
//		p = head;
//		Node *resHead = new Node(-1, nullptr, nullptr), *q;
//		q = resHead;
//		while (p != nullptr)
//		{
//			q->next = p->next;
//			q = q->next;
//			p->next = p->next->next;
//			p = p->next;
//		}
//		return resHead->next;
//	}
//};
//
//
//
//class Solution {
//public:
//	RandomListNode *copyRandomList(RandomListNode *head) {
//		RandomListNode* p = head;
//		while (p != nullptr)
//		{
//			RandomListNode* q = new RandomListNode(p->label);
//			q->next = p->next;
//			p->next = q;
//			p = p->next->next;
//		}
//		p = head;
//		while (p != nullptr)
//		{
//			if (p->random != nullptr)
//				p->next->random = p->random->next;
//			p = p->next->next;
//		}
//		p = head;
//		RandomListNode *resHead = new RandomListNode(-1), *q;
//		q = resHead;
//		while (p != nullptr)
//		{
//			q->next = p->next;
//			q = q->next;
//			p->next = p->next->next;
//			p = p->next;
//		}
//		return resHead->next;
//	}
//};
//
//
//int main()
//{
//	Node *head = new Node(1, nullptr, nullptr);
//	head->next = new Node(2, nullptr, nullptr);
//	head->next->next = new Node(3, nullptr, nullptr);
//	head->next->next->next = new Node(4, nullptr, nullptr);
//	head->next->next->next->next = new Node(5, nullptr, nullptr);
//	head->next->next->random = head->next;
//	head->next->next->next->next->random = head;
//	Solution s;
//	Node* res = s.copyRandomList(head);
//	while (1);
//
//}