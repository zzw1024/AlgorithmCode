#include "000库函数.h"

#define MAXSIZE 200


//结构
struct SqList
{
	int data[MAXSIZE];
	int length;
};

//建立初始表
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
//返回位置
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
	printf("初始化L后：L.length=%d\n", L.length);
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("在L的表头依次插入1～5后：L.data=");
	ListTraverse(L);

	printf("L.length=%d \n", L.length);
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	i = ClearList(&L);
	printf("清空L后：L.length=%d\n", L.length);
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("在L的表尾依次插入1～10后：L.data=");
	ListTraverse(L);

	printf("L.length=%d \n", L.length);

	ListInsert(&L, 1, 0);
	printf("在L的表头插入0后：L.data=");
	ListTraverse(L);
	printf("L.length=%d \n", L.length);

	GetElem(L, 5, &e);
	printf("第5个元素的值为：%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("第%d个元素的值为%d\n", k, j);
		else
			printf("没有值为%d的元素\n", j);
	}


	k = ListLength(L); /* k为表长 */
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e); /* 删除第j个数据 */
		if (i == ERROR)
			printf("删除第%d个数据失败\n", j);
		else
			printf("删除第%d个的元素值为：%d\n", j, e);
	}
	printf("依次输出L的元素：");
	ListTraverse(L);

	j = 5;
	ListDelete(&L, j, &e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n", j, e);

	printf("依次输出L的元素：");
	ListTraverse(L);

	//构造一个有10个数的Lb
	i = InitList(&Lb);
	for (j = 6; j <= 15; j++)
		i = ListInsert(&Lb, 1, j);

	unionL(&L, Lb);

	printf("依次输出合并了Lb的L的元素：");
	ListTraverse(L);

	

}