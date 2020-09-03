////#include "000库函数.h"
////
////
////struct ListNode {
////    int val;
////    ListNode *next;
////    ListNode(int x) : val(x), next(NULL) {}
////};
////
//class Solution {
//public:
//	ListNode* sortList(ListNode* head) {
//		if (head == nullptr || head->next == nullptr)return head;
//		ListNode *slow = head, *fast = head, *pre = head;
//		while (fast != nullptr && fast->next != nullptr)
//		{
//			pre = slow;
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		pre->next = nullptr;//将链表分为两段
//		return merge(sortList(head), sortList(slow));
//	}
//	ListNode* merge0(ListNode* l1, ListNode* l2)
//	{
//		if (l1 == nullptr || l2 == nullptr)return l1 == nullptr ? l2 : l1;
//		if (l1->val < l2->val)
//		{
//			l1->next = merge(l1->next, l2);
//			return l1;
//		}
//		else
//		{
//			l2->next = merge(l1, l2->next);
//			return l2;
//		}
//	}
//	ListNode* merge(ListNode* l1, ListNode* l2)
//	{
//		ListNode* ptr = new ListNode(-1);
//		ListNode* p = ptr;
//		while (l1 != nullptr && l2 != nullptr)
//		{
//			if (l1->val < l2->val)
//			{
//				p->next = l1;
//				l1 = l1->next;
//			}
//			else
//			{
//				p->next = l2;
//				l2 = l2->next;
//			}
//			p = p->next;
//		}
//		if (l1 == nullptr)p->next = l2;
//		if (l2 == nullptr)p->next = l1;
//		return ptr->next;
//	}
//};