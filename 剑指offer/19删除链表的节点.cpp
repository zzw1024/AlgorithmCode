//#include "head.h"
////
////��Ŀһ����O��1��ʱ����ɾ������ڵ㡣
////�������������ͷָ���һ���ڵ�ָ�룬����һ��������O��1��ʱ����ɾ���ýڵ㡣
//
//struct ListNode{
//	int val;
//	ListNode *next;
//};
//
//class Solution {
//	void DeleteNode(ListNode **listHead, ListNode *toDeleteNode) {
//		if (listHead == nullptr || toDeleteNode == nullptr)return;	
//		if (*listHead == toDeleteNode)
//			*listHead = (*listHead)->next;
//		else
//		{
//			ListNode* p = *listHead;
//			while (p->next != nullptr)
//			{
//				if (p->next == toDeleteNode)
//				{
//					p->next = toDeleteNode->next;
//					break;
//				}
//				p = p->next;
//			}
//		}
//	}
//};
