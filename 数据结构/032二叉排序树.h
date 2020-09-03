#include "000�⺯��.h"

#define MAXSIZE 100


//�������Ľṹ
struct BiTree
{
	int data;
	BiTree *lchild, *rchild;
};

//����������
void InsertBST(BiTree* &T, int elem) {
	BiTree *p = new  BiTree;
	p->data = elem;
	p->lchild = NULL;
	p->rchild = NULL;
	if (!T) {
		T = p;//Ϊ����		
		return;
	}

	if (T->data == elem)
		return;//�����Ѿ�����

	while (true) {
		if (elem > T->data) {
			if (T->rchild != NULL)
				T = T->rchild;//�ߵ����Ҷ�
			else {
				T->rchild = p;//���Ϊ������
				return;
			}
		}
		else {
			if (T->lchild != NULL)
				T = T->lchild;//�ߵ������
			else {
				T->lchild = p;//���Ϊ������
				return;
			}
		}
	}

}

void ShowTree(BiTree *T) {
	//�����������
	if (T) {
		ShowTree(T->lchild);
		cout << T->data << "��>";
		ShowTree(T->rchild);
	}
}

//�Զ��������в��ҹ���
int SearchData(BiTree *T, int num) {
	if (!T)return 0;
	if (T->data == num)return 1;
	if (num > T->data)SearchData(T->rchild,num);
	else SearchData(T->lchild, num);
}


//����ɾ��
//�ص㣬Ҳ���ѵ�
int Delete(BiTree* &T) {
	BiTree *p, *q;
	if (T->rchild == NULL) {//���ý��û�����������򽫸ýڵ�������������䣬��ɾ��
		p = T;
		T = T->lchild;
		delete(p);
	}
	else if (T->lchild == NULL) {//���ý��û�����������򽫸ýڵ�������������䣬��ɾ��
		p = T;
		T = T->rchild;
		delete(p);
	}
	else {//��������������
		p = T;
		q = T->lchild;
		while (q->rchild) {//�ߵ�T��֧��ĩ�ˣ���ʱ�������������
			p = q;//��סǰ�˵�
			q = q->rchild;
		}
		T->data = q->data;//ǰ�������������Ҷ����ִ���
		if (p != T)//��ĩ�˵��������ӣ���Ϊ��ʱ���������������
			p->rchild = q->lchild;
		else
			p->lchild = q->lchild;//�ؽ�������
		delete(q);//�ͷ�������ֵ
	}
	return 1;
}


//�Զ���������ɾ������
int DeleteBST(BiTree* &T, int num) {
	if (!T)return false;
	if (num == T->data) {
		Delete(T);
		return true;
	}
	else if (num > T->data)DeleteBST(T->rchild, num);
	DeleteBST(T->lchild, num);
}

int T032(void)
{
	int i;
	int a[10] = { 62,88,58,47,35,73,51,99,37,93 };
	BiTree *T = new BiTree;
	T = NULL;
	BiTree *p;
	for (i = 0; i < 10; i++) {
		InsertBST(T, a[i]);
		if (i == 0)
			p = T;//��סͷ����λ��
		T = p;//��Ȼ����ͷ��㣬��ͷ��㿪ʼ���±���
	}
	ShowTree(T);
	cout << endl;
	cout << "�ҵ�û��" << endl << SearchData(T, 99) << endl;
	p = T;//��סͷ���
	DeleteBST(T, 93);
	T = p;
	ShowTree(T);
	cout << endl;
	p = T;//��סͷ���
	DeleteBST(T, 37);
	T = p;
	ShowTree(T);
	cout << endl;
	return 0;
}
