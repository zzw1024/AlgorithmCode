//#include "head.h"
//
//
//
//struct RandomListNode {
//	int label;
//	struct RandomListNode *next, *random;
//	RandomListNode(int x) :
//			label(x), next(NULL), random(NULL) {
//	}
//};
////使用hash表将链表节点记录，其key为节点值，这样有个缺陷就是当有相同的节点值时，就不知道key对应的是哪个节点地址了
//class Solution01 {
//public:
//	RandomListNode* Clone(RandomListNode* pHead)
//	{
//		unordered_map<int, RandomListNode*>map;
//		RandomListNode *p, *q, *newHead = new RandomListNode(0);
//		p = pHead;
//		q = newHead;
//		while (p != nullptr)
//		{
//			q->next = new RandomListNode(p->label);
//			map[p->label] = q->next;
//			p = p->next;
//			q = q->next;
//		}
//		p = pHead;
//		q = newHead->next;
//		while (p != nullptr)
//		{
//			if (p->random != nullptr)
//				q->random = map[p->random->label];
//			p = p->next;
//			q = q->next;
//		}
//		return newHead->next;
//	}
//};
//
////直接将复制的节点置于原节点后面，这样找random节点时，很方便，不需要额外空间
//class Solution02 {
//public:
//	RandomListNode* Clone(RandomListNode* pHead)
//	{
//		if (pHead == nullptr)return nullptr;
//		RandomListNode *p = pHead, *q = nullptr, *newHead = new RandomListNode(0);
//		while (p != nullptr)//复制主链表
//		{
//			RandomListNode *q = new RandomListNode(p->label);
//			q->next = p->next;
//			p->next = q;
//			p = q->next;
//		}
//		p = pHead;
//		while (p != nullptr)//复制随机节点
//		{
//			if (p->random != nullptr)
//				p->next->random = p->random->next;//原链表指向哪，那么新链表就指向其后面
//			p = p->next->next;
//		}
//		p = pHead;
//		q = newHead;
//		while (p!=nullptr)//取出复制链表，并还原链表
//		{
//			q->next = p->next;//取新链表
//			p->next = p->next->next;//还原原链表
//			p = p->next;
//			q = q->next;			
//		}
//		return newHead->next;
//	}
//};
//
//
//
//
//int main()
//{
//	RandomListNode* head = new RandomListNode(1);
//	RandomListNode* p = head;
//	p->next = new RandomListNode(2);
//	p->random = head;
//	p = p->next;
//	p->next = new RandomListNode(3);
//	p = p->next;
//	p->next = new RandomListNode(4);
//	p->random = head->next->next;
//	Solution02 s;
//	p = s.Clone(head);
//	return 0;
//}
//
