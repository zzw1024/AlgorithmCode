//#include "000¿âº¯Êý.h"
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
//	bool hasCycle(ListNode *head) {
//		if (head == nullptr || head->next == nullptr)return false;
//		ListNode *slow, *fast;
//		slow = fast = head;
//		while (fast && fast->next)
//		{			
//			slow = slow->next;
//			fast = fast->next->next;
//			if (fast == slow)
//				return true;
//		}
//		return false;
//	}
//};
//
//
//int main()
//{
//	ListNode *head = new ListNode(3);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(0);
//	head->next->next->next = new ListNode(0);
//	head->next->next->next->next = new ListNode(-4);
//	head->next->next->next->next->next = head->next;
//	Solution s;
//	cout << s.detectCycle(head)->val << endl;
//	while (1);
//}