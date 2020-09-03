//#include "000�⺯��.h"
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
////ʹ����ķ��������ǣ�ÿ���ҳ���С������ͷ��Ȼ��ʹ��һ������������������
//class Solution1 {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		ListNode* res = new ListNode(0);
//		ListNode* p = res;
//		int min = INT32_MAX, index = -1;
//		do 
//		{
//			min = INT32_MAX, index = -1;
//			for (int i = 0; i < lists.size(); ++i)//�ҳ���С������ͷ
//			{
//				if (lists[i] && lists[i]->val < min)//�ж��ǲ��ǿ�����
//				{
//					min = lists[i]->val;
//					index = i;
//				}
//			}
//			if (index == -1)return res->next;
//			p->next = lists[index];//��������
//			p = p->next;
//			lists[index] = p->next;//ȥ��ѡ���˵�ͷ�ڵ�
//		} while (index != -1);
//		return res->next;
//	}
//};
//
////ʹ�������鲢�ķ���
////n=5,0-3,1-4,2,ÿ�Թ鲢����һ��������
//class Solution {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		if (lists.empty())return nullptr;
//		int n = lists.size();
//		while (n > 1)
//		{
//			int k = (n + 1) / 2;
//			for (int i = 0; i < n / 2; ++i)
//				lists[i] = helper(lists[i], lists[i + k]);
//			n = k;
//		}
//		return lists[0];
//	}
//	ListNode *helper(ListNode* pL, ListNode *pR) {
//		ListNode *temp = new ListNode(0);
//		ListNode *p = temp;
//		while (pL && pR)
//		{
//			if (pL->val <= pR->val)
//			{
//				p->next = pL;		
//				pL = pL->next;
//			}
//			else
//			{
//				p->next = pR;				
//				pR = pR->next;
//			}
//			p = p->next;
//		}
//		if (pL)p->next = pL;
//		if (pR)p->next = pR;
//		return temp->next;		
//	}
//};
//int main()
//{
//	Solution s;
//	ListNode* l1 = new ListNode(1);
//	l1->next = new ListNode(4);
//	l1->next->next = new ListNode(5);
//	ListNode* l2 = new ListNode(1);
//	l2->next = new ListNode(3);
//	l2->next->next = new ListNode(4);
//	ListNode* l3 = new ListNode(2);
//	l3->next = new ListNode(6);
//	vector<ListNode*>l = { l1,l2,l3 };
//	ListNode* res = s.mergeKLists(l);
//	while (res)
//	{
//		cout << res->val << "->";
//		res = res->next;
//	}
//	return 0;
//}