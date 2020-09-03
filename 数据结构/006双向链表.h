#include "000库函数.h"

struct DuLinkList {
	ElemType data;
	struct DuLinkList* pri;
	struct DuLinkList* next;
};

//初始化
void InitList(DuLinkList **L) {
	*L = new DuLinkList ;
	(*L)->next = *L;
	(*L)->pri = (*L);
	(*L)->data = 0;
	DuLinkList *p = (*L);
	for (int i = 0; i < 20; ++i) {
		DuLinkList *q = new DuLinkList;
		q->data = i + 5;
		p->next = q;
		q->next = (*L);
		(*L)->pri = q;
		q->pri = p;
		p = q;
	}
	
}
//寻找位置
void caser(DuLinkList **L, int pot) {
	if (pot > 0) {
		while (pot--) {
			*L = (*L)->next;
		}
	}
	else {
		while (pot++) {
			*L = (*L)->pri;
		}
	}
	
}

int T006()
{
	DuLinkList *L;
	int i, n;

	InitList(&L);
	printf("请输入一个整数:\n");
	scanf("%d", &n);
	printf("\n");

	caser(&L, n);

	for (i = 0; i < 26; i++)
	{
		L = L->next;
		printf("%4d", L->data);
	}

	printf("\n");

	return 0;
}
