#include "_000库函数.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//感觉用两条链表可能会更简单点，但内存会大点,
//的确，内存多了点
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* p1 = new ListNode(-1);//用来存放小于x的数
		ListNode* p2 = new ListNode(-1);//用来存放其他数字
		ListNode* q1 = p1;
		ListNode* q2 = p2;
		while (head) {//无头结点
			ListNode* q = new ListNode(0);
			q->val = head->val;
			if (head->val < x) {
				q1->next = q;
				q1 = q;
			}
			else {
				q2->next = q;
				q2 = q;
			}
			head = head->next;
		}
		q1->next = p2->next;//组合为一个链表
		return p1->next;//不需要头结点
	}
};

//用插入法，在原链表上操作
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* p = new ListNode(-1);
		p->next = head;
		head = p;//加一个头结点
		ListNode* pro, *cur;
		pro = p;//要插入的位置
		cur = p;//移动的位置
		p = p->next;
		while (p) {
			if (p->val < x) {
				ListNode* q = new ListNode(0);
				q->val = p->val;
				cur->next = p->next;//删除该数				
				p = cur->next;
				q->next = pro->next;//插入
				pro->next = q;
				if (cur == pro)
					cur = cur->next;
				pro = q;
			}
			else {
				p = p->next;
				cur = cur->next;
			}
		}
		return head->next;
	}
};

void T086() {
	Solution s;
	vector<int>v;
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	v = { 1,4,3,2,5,2 };
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
	p = s.partition(head->next,3);
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
}