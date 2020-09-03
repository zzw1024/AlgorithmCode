#include "000库函数.h"

struct LinkList{
	ElemType data;
	LinkList *next;
};

//链表初始化
Status InitList(LinkList** L) {
	* L = new LinkList;
	if (!(*L))
		return ERROR;
	(*L)->data = 0;
	(*L)->next = NULL;
	return OK;
}
//计算链表的长度
int ListLength(LinkList* L) {
	int n = 0;
	L = L->next;
	while (L) {
		++n;
		L = L->next;
	}
	return n;
}
//进行链表插入，头插法
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
//遍历输出元素
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
//判断是否为空
Status ListEmpty(LinkList *L) {
	if (!(L->next))
		return OK;
	else
		return NO;
}
//清空链表
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

//获取元素
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
//获取元素位置
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
//删除数据
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
//头插法
void CreateListHead(LinkList** L, int i) {
	LinkList* q = *L;
	LinkList* p = new LinkList;
	p->data = i;
	p->next = q->next;
	q->next = p;
}

//尾插法
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
	printf("初始化L后：ListLength(L)=%d\n", ListLength(L));
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("在L的表头依次插入1～5后：L.data=");
	ListTraverse(L);

	printf("ListLength(L)=%d \n", ListLength(L));
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	i = ClearList(&L);
	printf("清空L后：ListLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("在L的表尾依次插入1～10后：L.data=");
	ListTraverse(L);

	printf("ListLength(L)=%d \n", ListLength(L));

	ListInsert(&L, 1, 0);
	printf("在L的表头插入0后：L.data=");
	ListTraverse(L);
	printf("ListLength(L)=%d \n", ListLength(L));

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

	i = ClearList(&L);
	printf("\n清空L后：ListLength(L)=%d\n", ListLength(L));
	CreateListHead(&L, 20);
	printf("整体创建L的元素(头插法)：");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\n删除L后：ListLength(L)=%d\n", ListLength(L));
	CreateListTail(&L, 20);
	printf("整体创建L的元素(尾插法)：");
	ListTraverse(L);
			
}

