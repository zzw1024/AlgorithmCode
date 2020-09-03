#pragma once
#include "000库函数.h"

#define MAXSIZE 100

struct StaticLinkList{
	char data;
	int cur;  /* 游标(Cursor) ，为0时表示无指向 */
};

class List {
private:
	StaticLinkList L[MAXSIZE];
public:
	Status InitList( );
	int ListLength( );
	Status ListInsert(int pot, char c);
	void ListTraverse( );
	Status ListDelete(int pot);
};

//静态链表的初始化
Status List::InitList( ) {
	for (int i = 0; i < MAXSIZE-1; ++i) {
		L[i].cur = i + 1;
	}
	L[MAXSIZE - 1].cur = 0;//最后一个数据的位置为第一个数组的位置
	return OK;
}
//计算静态链表的长度
int List::ListLength( ){
	int num = 0;
	int i = L[MAXSIZE - 1].cur;//获取第一个参数的位置
	while (i) {
		i = L[i].cur;//当i==0时，计算完毕
		++num;
	}
	return num;
}
//插入数据
Status List::ListInsert( int pot, char c) {
	if (pot<1 || pot>this->ListLength + 1)return NO;
	int i = L[0].cur;//获取最后一个空位的位子
	L[i].data = c;	
	int j = L[MAXSIZE - 1].cur;//获取第一个位置
	while (L[j].cur != pot) {//找到指向pot位置的数据位置
		j = L[j].cur;
	}
	L[j].cur = i;//该位置重新指向插入数据的位置
	L[i].cur = 0;//插入数据指向0的位置
	L[0].cur += 1;
	if (L[0].cur != 1)
		L[MAXSIZE - 1].cur = 1;
	return OK;
}

//遍历输出
void List::ListTraverse( ) {
	int i = L[MAXSIZE-1].cur;
	while (i != 0) {
		cout << L[i].data << '\t';
		i = L[i].cur;
	}

}
//删除位于pot 的数据
Status List::ListDelete(  int pot) {
	if (pot < 1 || pot >= MAXSIZE)return NO;
	int i = L[MAXSIZE - 1].cur;
	while (L[i].cur != pot) {
		i = L[i].cur;
	}
	L[i].cur = L[pot].cur;
	L[0].cur = pot;
}

void T003() {
	List L;	
	Status i;
	i = L.InitList();
	printf("初始化L后：L.length=%d\n", L.ListLength());

	i = L.ListInsert( 1, 'F');
	i = L.ListInsert( 1, 'E');
	i = L.ListInsert( 1, 'D');
	i = L.ListInsert( 1, 'B');
	i = L.ListInsert( 1, 'A');

	printf("\n在L的表头依次插入FEDBA后：\nL.data=");
	L.ListTraverse();

	i = L.ListInsert( 3, 'C');
	printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
	L.ListTraverse( );

	i = L.ListDelete( 1);
	printf("\n在L的删除“A”后：\nL.data=");
	L.ListTraverse();

	printf("\n");


}