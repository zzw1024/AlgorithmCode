#include "000�⺯��.h"

/********************************��ͨ��*************************/
/*
struct PTNode
{
	ElemType data;//�������
	int parent;//˫�׵�λ��
};

struct PTree {
	PTNode nodes[MAXSIZE];
	int r; //���ڵ�
	int n; // �����Ŀ
};
*/
/****************************�����ӽ�����***************************/
/*
struct ChildPtr {
	int child;   //���ӽ����±�
	struct ChildPtr *next;//ָ����һ�����ӽ���ָ��
};
//���Ľṹ
struct CTBox {
	ElemType data;//������н�������
	int parent; //���˫�׵��±�
	struct ChildPtr firstchild;//ָ�����ӵ�ָ��
};
//���Ľṹ
struct CTree {
	CTBox nodes[MAXSIZE];
	int r;//���ڵ�����
	int n;//������Ŀ
};
*/

/***************************������************************/
struct BiTree {
	char data;//��Žڵ�����
	struct BiTree *lchild, *rchild;//������Ӻ��Һ���	
};
//��ʼ��������
Status CreateBiTree(BiTree **T,string s,int i) {	
	if (i == s.size())return OK;
	if (s[i] == '0') {//������ǿսڵ�
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	}
	else {
		*T = new BiTree;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		(*T)->data = s[i];
		CreateBiTree(&(*T)->lchild, s, i + 1);
		CreateBiTree(&(*T)->rchild, s, i + 1);
	}
}
//ǰ�����������
Status PreOrderTraverse(BiTree *T) {
	if (T) {
		cout << T->data << '\t';
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	else
		return OK;
}



void T017() {
	BiTree *T ;
	T = new BiTree;
	string s;
	cout << "�밴ǰ��˳����������������ݣ��սڵ�����0����" << endl;
	cin >> s;
	CreateBiTree(&T,s,0);
	PreOrderTraverse(T);
}

