//#include "000�⺯��.h"
//
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
////ֻ�뵽����ķ��������Ƿ�ת���ÿһ���ͷ�ڵ㱣��
//class Solution1 {
//public:
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		ListNode *pre = nullptr, *cur = head, *next = nullptr;
//		vector<ListNode *>v;
//		int cnt = 0, n = 0;
//		while (cur)
//		{
//			cur = cur->next;
//			++n;
//		}
//		cur = head;
//		while (cur)
//		{
//			next = cur->next;
//			cur->next = pre;
//			pre = cur;
//			cur = next;
//			++cnt;
//			if (cnt%k == 0)
//			{
//				v.push_back(pre);
//				pre = nullptr;
//			}
//			if (cur && n - cnt <= n % k)
//			{
//				v.push_back(cur);
//				break;
//			}
//		}
//		cur = v[0];
//		for (int i=0;i<v.size();++i)
//		{
//			pre = v[i];
//			while (pre->next)pre = pre->next;
//			if (i < v.size() - 1)
//				pre->next = v[i + 1];
//		}
//		return cur;
//	}
//};
//
//
////���з��鷴ת
//class Solution11 {
//public:
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		ListNode *q = new ListNode(0), *pre = q, *cur = head;
//		q->next = head;
//		for (int i = 1; cur; ++i)
//		{
//			if (i%k == 0)
//			{
//				pre = reverseOneGroup(pre, cur->next);
//				cur = pre->next;
//			}
//			else
//				cur = cur->next;
//		}
//		return q->next;
//	}
//	ListNode* reverseOneGroup(ListNode* pre, ListNode* next)//ͷ�ڵ����һ��ͷ�ڵ�
//	{
//		ListNode *last = pre->next, *cur = last->next;
//		while (cur != next) {
//			last->next = cur->next;
//			cur->next = pre->next;
//			pre->next = cur;
//			cur = last->next;
//		}
//		return last;
//	}
//};
//
//class Solution {
//public:
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = pre;
//		dummy->next = head;
//		int num = 0;
//		while (cur = cur->next) ++num;//ͳ��������
//		while (num >= k) {
//			cur = pre->next;
//			for (int i = 1; i < k; ++i) {//�����Ǿ��裬�೤����������ԷŶ��ٴΣ�
//				ListNode *next = cur->next;
//				cur->next = next->next;
//				next->next = pre->next;
//				pre->next = next;
//			}
//			pre = cur;
//			num -= k;
//		}
//		return dummy->next;
//	}
//};
//
//int main()
//{
//	ListNode* p = new ListNode(1);
//	p->next = new ListNode(2);
//	p->next->next = new ListNode(3);
//	p->next->next->next = new ListNode(4);
//	p->next->next->next->next = new ListNode(5);
//	Solution s;
//	p = s.reverseKGroup(p, 3);
//	while (p)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//
//	return 0;
//}
//
//
//
//
//
