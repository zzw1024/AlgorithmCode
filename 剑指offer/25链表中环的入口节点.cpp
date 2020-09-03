//#include "head.h"
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//};
//
//class Solution {
//public:
//	ListNode* EntryNodeOfLoop(ListNode* pHead)
//	{
//		if (pHead == nullptr || pHead->next == nullptr)return nullptr;
//		ListNode *slowPtr, *fastPtr;
//		slowPtr = fastPtr = pHead;
//		while (fastPtr != nullptr && fastPtr->next != nullptr)
//		{
//			slowPtr = slowPtr->next;
//			fastPtr = fastPtr->next->next;
//			if (slowPtr == fastPtr)break;
//		} 
//		if (fastPtr != slowPtr)return nullptr;
//		slowPtr = pHead;
//		while (slowPtr!=fastPtr)
//		{
//			slowPtr = slowPtr->next;
//			fastPtr = fastPtr->next;
//		}
//		return fastPtr;
//	}
//};
//
