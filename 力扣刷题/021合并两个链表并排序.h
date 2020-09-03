#pragma once
#include"000库函数.h"


//此题所谓的排序，并不是要把合并后的数字排序，而是将l1,l2的数字合并

struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}//构造函数
   
};
 

//使用小学生插队思想，多次遍历链表进行排序，不推荐
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l2 == NULL) return l1;
	if (l1 == NULL) return l2;
	ListNode *p1 = l1;
	ListNode *p2 = l2;
	ListNode *start = l1->val < l2->val ? l1 : l2;
	do {
		if (p2->val <= p1->val) {
			while (p2->next != NULL && p2->next->val <= p1->val) {
				p2 = p2->next;
			}
			l2 = p2->next;
			p2->next = p1;
		}
		else {
			while (p1->next != NULL && p1->next->val < p2->val) {
				p1 = p1->next;
			}
			l2 = p2->next;
			p2->next = p1->next;
			p1->next = p2;
		}
		p2 = l2;
	} while (p2 != NULL);
	return start;


}

//自己答案
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* Res=new ListNode(0), *p = Res;
	if (l2 == NULL) return l1;
	if (l1 == NULL) return l2;
	while (l1 && l2) {
		if (l1->val > l2->val) {
			p->next = l2;
			l2 = l2->next;
		}
		else {
			p->next = l1;
			l1 = l1->next;
		}
		p = p->next;

	}
	p->next = l1 ? l1 : l2;//将比较长的链表数据补充上来
	return Res->next;//去除头结点；

}

//递归思想
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l2 == NULL) return l1;
	if (l1 == NULL) return l2;
	ListNode*Res = l1->val <= l2->val ? l1 : l2;//取小
	ListNode*p = l1->val > l2->val ? l1 : l2;//取大
	Res->next = mergeTwoLists(Res->next, p);
	return Res;
}

//算法加递归
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (!l1 || (l2 && l1->val > l2->val))swap(l1, l2);//每次将小者给l1
	if (l1)l1->next = mergeTwoLists(l1->next, l2);
	return l1;
	
}


void T21() {
	ListNode *l1,*l2;
	ListNode *p, *q;
	l1 = new ListNode(0);
	l2 = new ListNode(0);


	p = l1;//带头结点
	q = new ListNode(0);
	q->val = 8;
	p->next = q;
	p = q;


	q = new ListNode(0);
	q->val = 3;
	p->next = q;
	p = q;

	q = new ListNode(0);
	q->val = 1;
	p->next = q;
	p = q;
	p->next = NULL;

	p = l2;/**************************/
	q = new ListNode(0);
	q->val = 4;
	p->next = q;
	p = q;
	q = new ListNode(0);
	q->val = 9;
	p->next = q;
	p = q;

	q = new ListNode(0);
	q->val =6;
	p->next = q;
	p = q;

	q = new ListNode(0);
	q->val = 6;
	p->next = q;
	p = q;
	p->next = NULL;
	

	ListNode* Res = l1;
	Res = mergeTwoLists(l1,l2);
	while (Res) {
		cout << Res->val << "\t";
		Res = Res->next;
	}
	cout << endl;

}


