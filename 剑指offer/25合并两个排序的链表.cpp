//#include "head.h"
//
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};
//
////使用普通的合并方法
//class Solution01 {
//public:
//	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//	{
//		if (pHead1 == nullptr || pHead2 == nullptr)return pHead1 == nullptr ? pHead2 : pHead1;
//		ListNode* newHead = nullptr, *p1 = nullptr, *p2 = nullptr;
//		newHead = new ListNode(0);
//		newHead->next = pHead1;
//		p1 = newHead;
//		p2 = pHead2;
//		while (p1->next != nullptr && p2 != nullptr)
//		{
//			if (p1->next->val < p2->val)
//				p1 = p1->next;
//			else
//			{
//				ListNode* temp = p1->next;
//				p1->next = p2;
//				p2 = p2->next;
//				p1->next->next = temp;
//				p1 = p1->next;
//			}
//		}
//		if (p1->next == nullptr && p2 != nullptr)
//			p1->next = p2;
//		return newHead->next;
//	}
//};
//
////使用递归
//class Solution {
//public:
//	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//	{
//		if (pHead1 == nullptr || pHead2 == nullptr)return pHead1 == nullptr ? pHead2 : pHead1;
//		ListNode* newHead = nullptr;
//		if (pHead1->val < pHead2->val)
//		{
//			newHead = pHead1;
//			newHead->next = Merge(pHead1->next, pHead2);
//		}
//		else
//		{
//			newHead = pHead2;
//			newHead->next = Merge(pHead1, pHead2->next);
//		}
//		return newHead;
//	}
//};
//
//
//void createList(ListNode*&head, vector<int>v)
//{
//	ListNode*p = head;
//	for (auto a : v)
//	{
//		p->next = new ListNode(a);
//		p = p->next;
//	}
//}
//int main()
//{
//	Solution s;
//	ListNode* pHead1 = new ListNode(0);
//	ListNode* pHead2 = new ListNode(0);
//	vector<int>v1 = {1,2,3}, v2 = { };
//	createList(pHead1, v1);
//	createList(pHead2, v2);
//	ListNode* p = s.Merge(pHead1->next, pHead2->next);
//	while (p != nullptr)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//	while (1);
//}