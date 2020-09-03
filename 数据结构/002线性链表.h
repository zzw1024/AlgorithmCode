#include "000�⺯��.h"

struct LinkList{
	ElemType data;
	LinkList *next;
};

//�����ʼ��
Status InitList(LinkList** L) {
	* L = new LinkList;
	if (!(*L))
		return ERROR;
	(*L)->data = 0;
	(*L)->next = NULL;
	return OK;
}
//��������ĳ���
int ListLength(LinkList* L) {
	int n = 0;
	L = L->next;
	while (L) {
		++n;
		L = L->next;
	}
	return n;
}
//����������룬ͷ�巨
Status ListInsert(LinkList** L, int pot, ElemType elem) {
	LinkList* q = *L;
	for (int i = 1; i < pot; ++i) {
		if (!(q->next)) {
			return ERROR;
			break;
		}
		q = q->next;
	}		
	LinkList* p = new LinkList;
	p->data = elem;
	p->next = q->next;
	q->next = p;
	return OK;
}
//�������Ԫ��
void ListTraverse(LinkList *L) {
	LinkList* p = L->next;
	if (!p)
		cout << "printf ERROR!" << endl;
	while (p) {
		cout << p->data << '\t' ;
		p = p->next;
	}
	cout << endl;
}
//�ж��Ƿ�Ϊ��
Status ListEmpty(LinkList *L) {
	if (!(L->next))
		return OK;
	else
		return NO;
}
//�������
Status ClearList(LinkList **L) {
	if (!((*L)->next))
		return OK;
	LinkList *p = (*L)->next;
	while (p) {
		LinkList *q = p->next;
		delete(p);
		p = q;
	}
	(*L)->next = NULL;
	
}

//��ȡԪ��
Status GetElem(LinkList *L, int pot, int *e) {
	for (int i = 0; i < pot; ++i) {
		if (!L) {
			return ERROR;
			break;
		}
		L = L->next;
	}
	*e = L->data;
	return OK;
}
//��ȡԪ��λ��
int LocateElem(LinkList *L, int elem) {
	int i = 0;
	while (L->data != elem) {
		if (!L) {
			return ERROR;
			break;
		}
		L = L->next;
		++i;
	}
	return i;

}
//ɾ������
Status ListDelete(LinkList** L, int pot, int* e) {
	LinkList* p = *L;
	for (int i = 1; i < pot; ++i) {
		if (!(p->next)) {
			return ERROR;
			break;
		}
		p = p->next;
	}
	if (!(p->next)) {
		return ERROR;
	}
	LinkList*q = p->next;
	p->next = q->next;
	*e = q->data;
	delete(q);

	return OK;
}
//ͷ�巨
void CreateListHead(LinkList** L, int i) {
	LinkList* q = *L;
	LinkList* p = new LinkList;
	p->data = i;
	p->next = q->next;
	q->next = p;
}

//β�巨
void CreateListTail(LinkList** L, int i) {
	LinkList* p = *L;
	while (p->next) {
		p = p->next;
	}
	LinkList* q = new LinkList;
	q->data = i;
	q->next = NULL;
	p->next = q;
}

void T002(){

	LinkList* L;
	ElemType e;
	Status i;
	int j, k;
	i = InitList(&L);
	printf("��ʼ��L��ListLength(L)=%d\n", ListLength(L));
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("��L�ı�ͷ���β���1��5��L.data=");
	ListTraverse(L);

	printf("ListLength(L)=%d \n", ListLength(L));
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	i = ClearList(&L);
	printf("���L��ListLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("��L�ı�β���β���1��10��L.data=");
	ListTraverse(L);

	printf("ListLength(L)=%d \n", ListLength(L));

	ListInsert(&L, 1, 0);
	printf("��L�ı�ͷ����0��L.data=");
	ListTraverse(L);
	printf("ListLength(L)=%d \n", ListLength(L));

	GetElem(L, 5, &e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
		else
			printf("û��ֵΪ%d��Ԫ��\n", j);
	}


	k = ListLength(L); /* kΪ�� */
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e); /* ɾ����j������ */
		if (i == ERROR)
			printf("ɾ����%d������ʧ��\n", j);
		else
			printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
	}
	printf("�������L��Ԫ�أ�");
	ListTraverse(L);

	j = 5;
	ListDelete(&L, j, &e); /* ɾ����5������ */
	printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);

	printf("�������L��Ԫ�أ�");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\n���L��ListLength(L)=%d\n", ListLength(L));
	CreateListHead(&L, 20);
	printf("���崴��L��Ԫ��(ͷ�巨)��");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\nɾ��L��ListLength(L)=%d\n", ListLength(L));
	CreateListTail(&L, 20);
	printf("���崴��L��Ԫ��(β�巨)��");
	ListTraverse(L);
			
}

