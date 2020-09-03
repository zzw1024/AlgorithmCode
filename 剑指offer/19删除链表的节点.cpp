//#include "head.h"
////
////题目一：在O（1）时间内删除链表节点。
////给定单向链表的头指针和一个节点指针，定义一个函数在O（1）时间内删除该节点。
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
