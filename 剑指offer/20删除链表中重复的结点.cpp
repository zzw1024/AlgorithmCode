//#include "head.h"
//
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//};
//
//
//class Solution {
//public:
//	ListNode* deleteDuplication(ListNode* pHead)	{
//		if (pHead == nullptr || pHead->next == nullptr)return pHead;
//		ListNode *newHead = new ListNode(0);
//		newHead->next = pHead;
//		ListNode *pre = newHead, *p = newHead->next;
//		int sameNum = 0;
//		while (p!= nullptr && p->next != nullptr)
//		{
//			if (p->val == p->next->val)
//			{
//				sameNum = p->val;
//				while (pre->next != nullptr && pre->next->val == sameNum)
//					pre->next = pre->next->next;
//				p = pre->next;
//			}
//			else
//			{
//				pre = p;
//				p = p->next;
//			}
//		}
//		return newHead->next;
//	}
//};
//
//int main()
//{
//	Solution S;
//	ListNode *head = new ListNode(2);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(1);
//	ListNode *p = S.deleteDuplication(head);
//	//head->next->next->next = new ListNode(3);
//	//head->next->next->next->next = new ListNode(4);
//	//head->next->next->next->next->next = new ListNode(5);
//	
//	while (p!=nullptr)
//	{
//		cout << p->val << "->";
//		p = p->next;
//
//	}
//	while (1);
//}