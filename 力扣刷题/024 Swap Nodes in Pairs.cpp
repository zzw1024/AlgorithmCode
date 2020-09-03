//#include "000库函数.h"
//
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
////直接两两交换就行
//
//class Solution {
//public:
//	ListNode* swapPairs(ListNode* head) {
//		ListNode *L = new ListNode(0);
//		ListNode *p = L;
//		L->next = head;
//		while (p->next && p->next->next)
//		{
//			ListNode* q = p->next;
//			p->next = q->next;
//			p = p->next;
//			q->next = p->next;
//			p->next = q;
//			p = p->next;
//		}
//		return L->next;
//	}
//};
//
////使用递归
//class Solution {
//public:
//	ListNode* swapPairs(ListNode* head) {
//		if (!head || !head->next)return head;
//		ListNode *p = head->next;
//		head->next = swapPairs(head->next->next);
//		p->next = head;
//		return p;
//	}
//};
//
//
//
//int main()
//{
//	ListNode* p = new ListNode(1);
//	//p->next = new ListNode(2);
//	//p->next->next = new ListNode(3);
//	//p->next->next->next = new ListNode(4);
//	Solution s;
//	p = s.swapPairs(p);
//	while (p)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//	return 0;
//}