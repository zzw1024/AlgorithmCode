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
//	void reorderList(ListNode* head) {
//		if (head == nullptr || head->next == nullptr)return;
//		ListNode* slow = head, *fast = head;
//		while (fast && fast->next)
//		{
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		fast = slow->next;
//		slow->next = nullptr;
//		stack<ListNode*>s;
//		while (fast)
//		{
//			s.push(fast);
//			fast = fast->next;
//		}
//		slow = head;
//		while (!s.empty())
//		{
//			ListNode* p = slow->next;
//			slow->next = s.top();
//			s.pop();
//			slow->next->next = p;
//			slow = p;
//		}
//		return;
//	}
//};
//
//int main()
//{
//	ListNode* root = new ListNode(1);
//	root->next = new ListNode(2);
//	root->next->next = new ListNode(3);
//	root->next->next->next = new ListNode(4);
//	root->next->next->next->next = new ListNode(5);
//	Solution s;
//	s.reorderList(root);
//}
