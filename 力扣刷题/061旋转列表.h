#include "_000库函数.h"


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 //感觉应该用双向指针更方便
 //含空头结点
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !k)return head;
		ListNode* s = head->next;//抓住头
		ListNode* e  = head->next;//抓住头尾
		int size = 1;//计算链表长度
		while (e->next) {
			e = e->next;
			++size;
		}
		k = k % size;//不用重复倍数次
		if (!k)return head;
		k = size - k;//移动次数，表示尾指针向右移动k次
		e->next = head->next;//形成一个环形列表
		while (k--) {
			s = s->next;//链表向右移，头指针向右移
			e = e->next;
		}
		head->next =  s;//确定头结点
		e->next = NULL;//确定尾结点
		return head;
	}
};

//不含空头结点【题目中往往不含空头节点】
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !k)return head;
		ListNode* s = head;//抓住头
		ListNode* e = head;//抓住头尾
		int size = 1;//计算链表长度
		while (e->next) {
			e = e->next;
			++size;
		}
		k = k % size;//不用重复倍数次
		if (!k)return head;
		k = size - k;//移动次数，表示尾指针向右移动k次
		e->next = head;//形成一个环形列表
		while (k--) {
			s = s->next;//链表向右移，头指针向右移
			e = e->next;
		}
		head = s;//确定头结点
		e->next = NULL;//确定尾结点
		return head;
	}
};

 //直接在单链表上操作

 class Solution {
 public:
	 ListNode* rotateRight(ListNode* head, int k) {
		 if (!head || !k)return head;
		 ListNode* e = head->next;//抓住头尾
		 int size = 1;//计算链表长度
		 while (e->next) {
			 e = e->next;
			 ++size;
		 }
		 k = k % size;//不用重复倍数次
		 if (!k)return head;
		 k = size - k;//移动次数，表示尾指针向右移动k次
		 e->next = head->next;
		 while (k--) head = head->next;//链表向右移，头指针向右移		 
		 e = head;
		 head->next = e->next;
		 e->next = NULL;
		 return head;
	 }
 };
void T061() {
	Solution s;
	ListNode* head = new ListNode(0);
	ListNode* p = head;
	for (int i = 1; i <= 5; ++i) {
		ListNode* q = new ListNode(i);
		p->next = q;
		p = q;
	}
	p->next = NULL;
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
	head = s.rotateRight(head,1);
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl << "****************" << endl;


	p = head;
	for (int i = 0; i <= 2; ++i) {
		ListNode* q = new ListNode(i);
		p->next = q;
		p = q;
	}
	p->next = NULL;
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
	head = s.rotateRight(head, 4);
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl << "****************" << endl;
}