//#include "head.h"
//
//
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};
//class Solution {
//public:
//	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//		if (pHead1 == nullptr || pHead2 == nullptr)return nullptr;
//		int L1 = 1, L2 = 1;
//		ListNode *p1 = pHead1, *p2 = pHead2;
//		while (p1->next != nullptr)
//		{
//			p1 = p1->next;
//			++L1;
//		}
//		while (p2->next != nullptr)
//		{
//			p2 = p2->next;
//			++L2;
//		}
//		if (p1 != p2)return nullptr;//最后一个节点不相同，则没有相交点
//		p1 = pHead1;
//		p2 = pHead2;
//		if (L1 >= L2)
//			for (int i = 0; i < L1 - L2; ++i)p1 = p1->next;
//		else
//			for (int i = 0; i < L2 - L1; ++i)p2 = p2->next;
//		while (p1 != p2)
//		{
//			p1 = p1->next;
//			p2 = p2->next;
//		}
//		return p1;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	ListNode *L1 = new ListNode(1);
//	L1->next = new ListNode(2);
//	L1->next->next = new ListNode(3);
//	ListNode *L2 = new ListNode(4);
//	L2->next = new ListNode(5);
//	L2->next->next = L1->next->next;
//	ListNode *p = s.FindFirstCommonNode(L1, L2);
//	cout << (p == nullptr ? -1 : p->val) << endl;
//	return 0;
//
//
//}