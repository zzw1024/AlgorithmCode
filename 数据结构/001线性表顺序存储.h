#include "000�⺯��.h"

#define MAXSIZE 200


//�ṹ
struct SqList
{
	int data[MAXSIZE];
	int length;
};

//������ʼ��
Status InitList(SqList *L) {
	L->length = 0;
	return OK;
}

Status ListInsert(SqList *L, int pot, int num) {
	if (L->length >= MAXSIZE || pot < 1)return NO;
	for (int i = L->length+1; i > pot; --i) {
		L->data[i ] = L->data[i-1];
	}
	L->data[pot] = num;
	L->length += 1;
	return OK;

}

void ListTraverse(SqList L) {
	for (int i = 1; i <= L.length; ++i)
		cout << L.data[i] << "\t";
	cout << endl;
}

Status ListEmpty(SqList L) {
	if (L.length == 0)return OK;
	return NO;
}

Status ClearList(SqList *L) {
	L->length = 0;
	return OK;
}
void GetElem(SqList L, int pot, ElemType *e) {
	if (L.length == 0 || pot > L.length || pot < 1) *e = NO;
	*e = L.data[pot];
}
//����λ��
int LocateElem(SqList L, ElemType j) {
	if (L.length == 0)return NO;
	int i;
	for (i = 1; i <= L.length; ++i)
		if (L.data[i] == j)
			return i;
	return NO;
}

int ListLength(SqList L) {
	return L.length;
}

Status ListDelete(SqList *L, int pot, ElemType *e) {
	if (L->length == 0 || pot<1 || pot>L->length)return NO;
	*e = L->data[pot];
	for (int i = pot; i < L->length; ++i)
		L->data[i] = L->data[i + 1];
	L->length -= 1;
	return OK;
}

void unionL(SqList *L, SqList Lb) {
	if (L->length + Lb.length > MAXSIZE)return ;
	for (int i = L->length + 1, j = 0; j < Lb.length; ++j, ++i) {
		L->data[i] = Lb.data[j + 1];
		L->length += 1;
	}
}


void T001() {
	SqList L;
	SqList Lb;

	ElemType e;
	Status i;
	int j, k;
	i = InitList(&L);
	printf("��ʼ��L��L.length=%d\n", L.length);
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("��L�ı�ͷ���β���1��5��L.data=");
	ListTraverse(L);

	printf("L.length=%d \n", L.length);
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	i = ClearList(&L);
	printf("���L��L.length=%d\n", L.length);
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("��L�ı�β���β���1��10��L.data=");
	ListTraverse(L);

	printf("L.length=%d \n", L.length);

	ListInsert(&L, 1, 0);
	printf("��L�ı�ͷ����0��L.data=");
	ListTraverse(L);
	printf("L.length=%d \n", L.length);

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

	//����һ����10������Lb
	i = InitList(&Lb);
	for (j = 6; j <= 15; j++)
		i = ListInsert(&Lb, 1, j);

	unionL(&L, Lb);

	printf("��������ϲ���Lb��L��Ԫ�أ�");
	ListTraverse(L);

	

}