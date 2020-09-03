#include "_000库函数.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//又是无头结点的链表！！！
//还有，哪个数字重复了，就将他全部删除！！
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		//创建一个头结点
		ListNode *p = new ListNode(0);
		p->next = head;
		head = p;
		ListNode *q = p;
		int flag = 0;//用来标记重复数字
		while (q && p) {
			q = q->next;
			while (q && q->next && q->val == q->next->val) {
				//一定的记得释放删除的数字
				ListNode *ptr = q;
				p->next = q->next;
				delete(ptr);
				ptr = NULL;
				q = p->next;
				flag = 1;
			}
			if (flag) {//删除最后一个重复了的数字
				ListNode *ptr = q;
				p->next = q->next;
				delete(ptr);
				ptr = NULL;
				q = p;
				flag = 0;
			}
			else
				p = p->next;
		}
		return head->next;
	}
};

//不释放删除的节点，我不建议，但好多博客是这样写的
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		//创建一个头结点
		ListNode *p = new ListNode(0);
		p->next = head;
		head = p;
		ListNode *q = p;
		while (p->next) {
			q = p->next;
			while (q->next && q->val == q->next->val)
				q = q->next;
			if (p->next != q)
				p->next = q->next;
			else
				p = p->next;
		}
		return head->next;
	}
};



//使用递归，不使用while

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head) return head;
		if (head->next && head->val == head->next->val) {
			while (head->next && head->val == head->next->val) {
				head = head->next;
			}
			return deleteDuplicates(head->next);
		}
		head->next = deleteDuplicates(head->next);
		return head;
	}
};
void T082() {
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	vector<int>v = { 1,2,3,4,4, 5, 5};
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