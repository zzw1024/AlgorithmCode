#pragma once
#include "000�⺯��.h"

#define MAXSIZE 100

struct StaticLinkList{
	char data;
	int cur;  /* �α�(Cursor) ��Ϊ0ʱ��ʾ��ָ�� */
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

//��̬����ĳ�ʼ��
Status List::InitList( ) {
	for (int i = 0; i < MAXSIZE-1; ++i) {
		L[i].cur = i + 1;
	}
	L[MAXSIZE - 1].cur = 0;//���һ�����ݵ�λ��Ϊ��һ�������λ��
	return OK;
}
//���㾲̬����ĳ���
int List::ListLength( ){
	int num = 0;
	int i = L[MAXSIZE - 1].cur;//��ȡ��һ��������λ��
	while (i) {
		i = L[i].cur;//��i==0ʱ���������
		++num;
	}
	return num;
}
//��������
Status List::ListInsert( int pot, char c) {
	if (pot<1 || pot>this->ListLength + 1)return NO;
	int i = L[0].cur;//��ȡ���һ����λ��λ��
	L[i].data = c;	
	int j = L[MAXSIZE - 1].cur;//��ȡ��һ��λ��
	while (L[j].cur != pot) {//�ҵ�ָ��potλ�õ�����λ��
		j = L[j].cur;
	}
	L[j].cur = i;//��λ������ָ��������ݵ�λ��
	L[i].cur = 0;//��������ָ��0��λ��
	L[0].cur += 1;
	if (L[0].cur != 1)
		L[MAXSIZE - 1].cur = 1;
	return OK;
}

//�������
void List::ListTraverse( ) {
	int i = L[MAXSIZE-1].cur;
	while (i != 0) {
		cout << L[i].data << '\t';
		i = L[i].cur;
	}

}
//ɾ��λ��pot ������
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
	printf("��ʼ��L��L.length=%d\n", L.ListLength());

	i = L.ListInsert( 1, 'F');
	i = L.ListInsert( 1, 'E');
	i = L.ListInsert( 1, 'D');
	i = L.ListInsert( 1, 'B');
	i = L.ListInsert( 1, 'A');

	printf("\n��L�ı�ͷ���β���FEDBA��\nL.data=");
	L.ListTraverse();

	i = L.ListInsert( 3, 'C');
	printf("\n��L�ġ�B���롰D��֮����롰C����\nL.data=");
	L.ListTraverse( );

	i = L.ListDelete( 1);
	printf("\n��L��ɾ����A����\nL.data=");
	L.ListTraverse();

	printf("\n");


}