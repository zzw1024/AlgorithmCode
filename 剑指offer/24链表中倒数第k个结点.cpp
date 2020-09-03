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
//
////遍历两次，垃圾
//class Solution01 {
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//		if (pListHead == nullptr || k <= 0)return nullptr;
//		int listLenght = 0;
//		ListNode *res = nullptr, *p = pListHead;
//		while (p != nullptr)
//		{
//			listLenght++;
//			p = p->next;
//		}
//		if (listLenght < k)return res;
//		res = pListHead;
//		int nums = 0;
//		while (nums < (listLenght - k))
//		{
//			res = res->next;
//			nums++;
//		}
//		return res;
//	}
//};
//
////遍历一次，双指针
//class Solution02 {
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//		if (pListHead == nullptr || k <= 0)return nullptr;
//		ListNode *L, *Lk;
//		L = Lk = pListHead;
//		int i = 0;
//		for (; Lk != nullptr; ++i)
//		{
//			if (i >= k)
//				L = L->next;
//			Lk = Lk->next;
//		}
//		if (i < k)return nullptr;
//		return L;		
//	}
//};
//
//int main()
//{
//	Solution s;
//	ListNode *head = nullptr;
//	ListNode *p;
//	head = new ListNode(1);	
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(3);
//	head->next->next->next = new ListNode(4);
//	head->next->next->next->next = new ListNode(5);
//	
//	p = s.FindKthToTail(head,6);
//	while (p != nullptr)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//	while (1);
//}