//
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
//class Solution {
//public:
//	ListNode* ReverseList(ListNode* pHead) {
//		if (pHead == nullptr || pHead->next == nullptr)return pHead;
//		ListNode *newHead = nullptr, *pre = nullptr, *cur = nullptr, *next = nullptr;
//		cur = pHead;
//		while (cur != nullptr)
//		{
//			next = cur->next;
//			cur->next = pre;
//			pre = cur;
//			cur = next;
//		}
//		return pre;
//	}
//};
//ÿ��ֻ��תһ�Σ��ȼ�סnext, Ȼ��pre->cur������
//
