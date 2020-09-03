#pragma once
#include "000库函数.h"
struct Cril
{
	int nums;
	struct Cril *next;
};


void T005() {
	Cril *head = new Cril;
	Cril *p = head;
	for (int i = 0; i < 7; ++i) {
		Cril *q = new Cril;
		q->nums = i + 1;
		p->next = q;
		p = q;
	}
	p->next = NULL;
	p = head->next;
	while (p) {
		cout << p->nums << '\t';
		p = p->next;
	}
	Cril *q = head;
	p = head;
	while (q){
		p = p->next;
		q = q->next->next;
	}
	cout << "中间数为" << p->nums << endl;

	

}