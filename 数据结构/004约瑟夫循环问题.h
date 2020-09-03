#pragma once
#include "000库函数.h"

struct Cril
{
	int nums;
	struct Cril *next;
};



Cril * Create(int nums) {
	Cril *head = new Cril;
	Cril *p = head;
	for (int i = 0; i < nums; ++i) {
		Cril *q = new Cril;
		q->nums = i + 1;
		p->next = q;
		p = q;
	}
	p->next = head->next;
	return head->next;
}

void ShowSave(Cril *L) {
	int i = L->nums;
	while (L->next->nums != i) {
		cout << L->nums << '\t';
		L = L->next;
	}
	cout << L->nums << '\t';
	cout << endl;

}
void Paly(Cril *L, int n) {
	Cril *p = L;//无头结点
	Cril *q;
	int t = 1;
	while (p->next != p) {
		q = p;
		p = p->next;
		++t;
		if (t == n) {
			cout << "the nums " << p->nums << " out !" << endl;
			cout << "the save nums is:" << endl;			
			q->next = p->next;
			free(p);
			p = q;
			ShowSave(p);
			t = 0;
		}
	}
}

void T004() {
	cout << "welcome to play the Cril Game!" << endl;
	cout << "please tell me how many people play the game : ";
	int nums;
	cin >> nums;
	cout << "yuou want which number to dead ：";
	int n;
	cin >> n;
	if (nums < n) {
		cout << "the number more than people! game over!" << endl;
		return;
	}
	Cril *L = Create(nums);
	ShowSave(L);
	cout << "****************************" << endl;
	Paly(L, n);

}