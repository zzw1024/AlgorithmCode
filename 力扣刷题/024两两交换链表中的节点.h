#include "000库函数.h"




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//注意，该链表是无头结点,为了不乱，自己加了一个头结点
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || head->next == NULL)return head;
		ListNode* p = new ListNode(0);
		p->next = head;
		head = p;
		while (1) {
			ListNode *i, *j;
			i = p->next;
			j = i->next;
			i->next = j->next;
			j->next = i;
			p->next = j;
			if (!(p->next))
				return head->next;
			p = p->next->next;
			if (!(p->next) || !(p->next->next))
				return head->next;
		}
		return head->next;
	}

	
};

//使用递归，比自己更耗时，但节约内存
//实际上利用了回溯的思想，递归遍历到链表末尾，然后先交换末尾两个，然后依次往前交换：
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)	return head;
		ListNode* p = head;
		head = head->next;
		p->next = head->next;
		head->next = p;
		p->next = swapPairs(p->next);
		return head;
	}
};


void T024() {
	ListNode* L = new ListNode(0);
	ListNode*p = L;
	for (int i = 0; i < 6; ++i) {
		ListNode*q = new ListNode(0);
		q->val = i + 1;
		p->next = q;
		p = q;
	} 
	p->next = NULL;
	p = L->next;
	while (p) {
		cout << p->val << '\t';
		p = p->next;
	}
	cout << endl;

	Solution S;
	p = S.swapPairs(L->next);
	while (p) {
		cout << p->val << '\t';
		p = p->next;
	}
	cout << endl;
	
}
