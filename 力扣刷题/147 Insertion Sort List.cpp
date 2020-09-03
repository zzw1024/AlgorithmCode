//#include "000¿âº¯Êý.h"
//
//
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
//	ListNode *insertionSortList(ListNode *head) {
//		if (head == nullptr || head->next == nullptr)return head;
//		ListNode *durry, *p, *pre, *cur, *next;
//		durry = new ListNode(-1);
//		durry->next = head;
//		p = pre = cur = next = head;
//		next = cur->next;
//		while (next != nullptr)
//		{		
//			cur = next;
//			next = cur->next;
//			p = durry;
//			while (p != cur)
//			{
//				if (p->next->val > cur->val)
//				{
//					pre->next = next;
//					cur->next = p->next;
//					p->next = cur;
//					break;
//				}
//				p = p->next;
//			}
//			if (pre->next == cur)//Î´ÒÆ¶¯¹ý
//				pre = cur;
//		}
//		return durry->next;
//	}
//};
//
//int main()
//{
//	ListNode * p = new ListNode(6);
//	p->next = new ListNode(5);
//	p->next->next = new ListNode(3);
//	p->next->next->next = new ListNode(1);
//	p->next->next->next->next = new ListNode(8);
//	p->next->next->next->next->next = new ListNode(7);
//	p->next->next->next->next->next->next = new ListNode(2);
//	p->next->next->next->next->next->next->next = new ListNode(4);
//	Solution s;
//	ListNode* ptr = s.insertionSortList(p);
//	while (ptr != nullptr)
//	{
//		cout << ptr->val << "->";
//		ptr = ptr->next;
//	}
//	while (1);
//}