#include "000�⺯��.h"

#define MAXSIZE 100//
#define EH 0
#define LH +1  //���
#define RH -1  //�Ҹ�  

//�������Ľṹ
struct BiTree
{
	int data;
	int bf;//AVL��ƽ������
	BiTree *lchild, *rchild;
};

bool L_Rotate(BiTree* &T) {//��T��������������ƽ�⴦��
	BiTree *R;
	R = T->rchild;
	T->rchild = R->lchild;//R���������ҽ�ΪT��������
	R->lchild = T;
	T = R;
	return true;
}

bool R_Rotate(BiTree* &T) {//��T����������
	BiTree *L;
	L = T->lchild;
	T->lchild = L->rchild;
	L->rchild = T;
	T = L;
	return true;
}




//�ж��ټ����������᲻�����ƽ��
bool LeftBalace(BiTree* &T) {//�������ӽ���߾�Ӧ����Ӻ��ж��Ƿ������ƽ��
	BiTree *L, *Lr;
	L = T->lchild;
	switch (L->bf)//�ж���������ƽ������
	{
	case LH://ԭΪ�������������Ӿʹ���ƽ����,����Ҫ����������
		T->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH://ԭ�ڵ�Ϊ��������������ڵ㣨���+1�����ʹ���ƽ���ˣ�����˫������
		Lr = L->rchild;
		switch (Lr->bf)
		{
		case LH:
			T->bf = RH;
			L->bf = EH;
			break;
		case EH:
			T->bf = L->bf = EH;
			break;
		case RH:
			T->bf = EH;
			L->bf = LH;
			break;
		default:
			break;
		}
		Lr->bf = EH;
		L_Rotate(T->lchild);//��T��������������ƽ�⴦��
		R_Rotate(T);//��T����������
		break;
	default:
		break;
	}
	return true;
}

//�ж��ټ����������᲻�����ƽ��
bool RightBalace(BiTree* &T) {//�������ӽ��ұ߾�Ӧ����Ӻ��ж��Ƿ������ƽ��
	BiTree *R, *Rl;
	R = T->rchild;
	switch (R->bf)//�ж���������ƽ������
	{
	case LH://ԭ�ڵ�Ϊ�������������ҽڵ㣨���+1�����ʹ���ƽ���ˣ�����˫������		
		Rl = R->lchild;
		switch (Rl->bf)
		{
		case LH:
			T->bf = EH;
			R->bf = RH;
			break;
		case EH:
			T->bf = R->bf = EH;
			break;
		case RH:
			T->bf = LH;
			R->bf = EH;
			break;
		default:
			break;
		}
		Rl->bf = EH;
		R_Rotate(T->rchild);//��T��������������ƽ�⴦��
		L_Rotate(T);//��T����������
		break;
	case RH://ԭΪ�������������Ӿʹ���ƽ����,����Ҫ����������		
		T->bf = R->bf = EH;
		L_Rotate(T);
		break; 		
	default:
		break;
	}
	return true;
}

//AVL����
/*  ����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ�� */
/*  ����Ԫ��Ϊe���½�㣬������1�����򷵻�0����������ʹ���������� */
/*  ʧȥƽ�⣬����ƽ����ת������������taller��ӳT������� */
bool InsertAVL(BiTree * &T, int elem, bool &n) {
	if (T == NULL) {
		BiTree *p;
		p = new BiTree;
		p->data = elem;
		p->bf = EH;
		p->lchild = NULL;
		p->rchild = NULL;
		T = p;
		n = true;
		return true;
	}
	if (T->data == elem) {//�����Ѵ��ڣ�����Ҫ�����
		n = false;
		return false;
	}
	if (elem < T->data) {
		if (!(InsertAVL(T->lchild, elem, n)))//Ӧ���������������м�������
			return false;//���ʧ��
		if (n) {//��ӳɹ�
			switch (T->bf)//���AVL��ƽ������
			{
			case LH://ԭ����߸�
				LeftBalace(T);//�������ӽ���߾�Ӧ����Ӻ��ж��Ƿ������ƽ��
				n = false;
				break;
			case EH://ԭ����ȸ߶�,�Ǿͼ�������ߣ���������
				T->bf = LH;
				n = true;
				break;
			case RH://ԭ���Ҷ˸ߣ��Ǿͼ�����ˣ��������ұߵĸ߶�
				T->bf = EH;
				n = false;
				break;
			default:
				break;
			}
		}			
	}
	else {
		if (!(InsertAVL(T->rchild, elem, n)))//Ӧ���������������м�������
			return false;//���ʧ��
		if (n) {//��ӳɹ�
			switch (T->bf)//���AVL��ƽ������
			{
			case LH://ԭ����߸�
				T->bf = EH;//�����Ҷˣ���������ߵĸ߶�
				n = false;
				break;
			case EH://ԭ����ȸ߶�,�Ǿͼ������ұߣ���������
				T->bf = LH;
				n = true;
				break;
			case RH://ԭ���Ҷ˸�
				RightBalace(T);//�������ӽ��ұ߾�Ӧ����Ӻ��ж��Ƿ������ƽ��
				n = false;
				break;
			default:
				break;
			}
		}
	}


}
//����AVL
void ShowTree(BiTree *T) {
	//�����������
	if (T) {
		ShowTree(T->lchild);
		cout << T->data << "��>";
		ShowTree(T->rchild);
	}
}

int T033(void)
{
	int i;
	int a[10] = { 3,2,1,4,5,6,7,10,9,8 };
	BiTree *T = new BiTree;
	T = NULL;
	bool taller;//�����ж�AVL�Ƿ����������
	BiTree *p;
	for (i = 0; i < 10; i++)	{
		InsertAVL(T, a[i], taller);
		if (i == 0)p = T;//��סͷ���
	}
	ShowTree(T);
	cout << endl;
	return 0;
}