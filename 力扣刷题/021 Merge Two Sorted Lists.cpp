//#include "000¿âº¯Êý.h"
//
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//		if (l1 == nullptr || l2 == nullptr)return l1 == nullptr ? l2 : l1;
//		ListNode* p = l1;
//		while (p->next != nullptr)
//			p = p->next;
//		p->next = l2;
//		return mergeSort(l1);
//	}
//	ListNode* mergeSort(ListNode*head)
//	{
//		if (head == nullptr || head->next == nullptr)return head;
//		ListNode* slow = head, *fast = head, *pre = head;
//		while (fast != nullptr && fast->next != nullptr)
//		{
//			pre = slow;
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		pre->next = nullptr;
//		return merge(mergeSort(head), mergeSort(slow));
//	}
//	ListNode* merge(ListNode* l1, ListNode*l2)
//	{
//		if (l1 == nullptr || l2 == nullptr)return l1 == nullptr ? l2 : l1;
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