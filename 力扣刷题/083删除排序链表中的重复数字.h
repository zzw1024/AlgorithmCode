#include "_000�⺯��.h"

//�����������Ĳ�֮ͬ�������ظ������ֲ���ȫ��ɾ��������һ��

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//���ͷŵ�ɾ������
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		//����һ��ͷ���
		ListNode *p = new ListNode(0);
		p->next = head;
		head = p;
		ListNode *q = p;
		while (q && p) {
			q = q->next;
			while (q && q->next && q->val == q->next->val) {
				//һ���ļǵ��ͷ�ɾ��������
				ListNode *ptr = q;
				p->next = q->next;
				delete(ptr);
				ptr = NULL;
				q = p->next;
			}
			p = p->next;
		}
		return head->next;
	}
};


//���ͷŵ�ɾ���ڵ�
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		//����һ��ͷ���
		ListNode *p = new ListNode(0);
		p->next = head;
		head = p;
		ListNode *q = p;
		while (p->next) {
			q = p->next;
			while (q->next && q->val == q->next->val)
				q = q->next;
			if (p->next != q)
				p->next = q;
			p = p->next;
		}
		return head->next;
	}
};


//ʹ�õݹ�
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		head->next = deleteDuplicates(head->next);
		return (head->val == head->next->val) ? head->next : head;
	}
};

void T083() {
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	vector<int>v = { 1,2,3,4,4, 5, 5 };
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
	Solution s;
	p = s.deleteDuplicates(head->next);
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
}