//#include "000库函数.h"
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//
////题目很简单，直接相加就行
//
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode *result = new ListNode(0);//记住，这是带头节点的
//		ListNode *p = result, *p1 = l1, *p2 = l2;
//		int c = 0;//进位
//		while (p1 || p2)
//		{
//			int sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + c;
//			p->next = new ListNode(sum % 10);
//			p = p->next;
//			c = sum / 10;
//			p1 = p1 ? p1->next : nullptr;
//			p2 = p2 ? p2->next : nullptr;
//		}		
//		if (c > 0)
//			p->next = new ListNode(c);
//		return result->next;
//	}
//};
//
//int main()
//{
//	ListNode *L1 = new ListNode(2);
//	L1->next  = new ListNode(4);
//	L1->next->next = new ListNode(3);
//
//	ListNode *L2 = new ListNode(5);
//	L2->next = new ListNode(6);
//	L2->next->next = new ListNode(4);
//	L2->next->next->next = new ListNode(9);
//
//	Solution s;
//	ListNode* p = s.addTwoNumbers(L1, L2);
//	while (p)
//	{
//		cout << p->val << " ";
//		p = p->next;
//	}
//	return 0;
//
//
//
//}