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
////ʹ��hash������ڵ��¼����keyΪ�ڵ�ֵ�������и�ȱ�ݾ��ǵ�����ͬ�Ľڵ�ֵʱ���Ͳ�֪��key��Ӧ�����ĸ��ڵ��ַ��
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
////ֱ�ӽ����ƵĽڵ�����ԭ�ڵ���棬������random�ڵ�ʱ���ܷ��㣬����Ҫ����ռ�
//class Solution02 {
//public:
//	RandomListNode* Clone(RandomListNode* pHead)
//	{
//		if (pHead == nullptr)return nullptr;
//		RandomListNode *p = pHead, *q = nullptr, *newHead = new RandomListNode(0);
//		while (p != nullptr)//����������
//		{
//			RandomListNode *q = new RandomListNode(p->label);
//			q->next = p->next;
//			p->next = q;
//			p = q->next;
//		}
//		p = pHead;
//		while (p != nullptr)//��������ڵ�
//		{
//			if (p->random != nullptr)
//				p->next->random = p->random->next;//ԭ����ָ���ģ���ô�������ָ�������
//			p = p->next->next;
//		}
//		p = pHead;
//		q = newHead;
//		while (p!=nullptr)//ȡ��������������ԭ����
//		{
//			q->next = p->next;//ȡ������
//			p->next = p->next->next;//��ԭԭ����
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
