#include "_000库函数.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//只能扫描一遍
//将中间要反转的数取出来在放入链表中
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head || m <= 0 || n <= 0 || n <= m)return head;
		//加头
		ListNode*p = new ListNode(-1);
		p->next = head;
		head = p;

		stack<int>s;
		ListNode*pre = new ListNode(0);
		while (p && n >0) {
			--m;
			if (m == 0)pre = p;			
			p = p->next;
			if (p && m <= 0)
				s.push(p->val);
			--n;
		}
		if (p == NULL)return head->next;//m,n超过了链表长度
		pre->next = p->next;
		while (!s.empty()) {
			ListNode*q = new ListNode(0);
			q->val = s.top();
			q->next = pre->next;			
			pre->next = q;
			pre = q;
			s.pop();
		}
		return head->next;
	}
};

//走一步反转一个数据
//不用对m,n的大小进行判断
class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		ListNode *dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;
		for (int i = 0; i < m - 1; ++i) pre = pre->next;
		ListNode *cur = pre->next;
		for (int i = m; i < n; ++i) {//用交换法
			ListNode *t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
		}
		return dummy->next;
	}
};


void T092() {
	Solution s;
	vector<int>v;
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	v = { 1,2,3,4,5 };
	for (auto a : v) {
		ListNode *q = new ListNode(0);
		q->val = a;
		p->next = q;
		p = q;
	}
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;


	p = s.reverseBetween(head->next, 2, 6);
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
}