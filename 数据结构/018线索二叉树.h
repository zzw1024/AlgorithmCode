//#include "000库函数.h"
#if 0
struct BiTree {
	char data;
	struct BiTree *lchild, *rchild;
	int ltag;//0表示有孩子
	int rtag;//表示无孩子，可用来指向前驱后继的线索
};
BiTree *pre;
Status CreateBiThrTree(BiTree **T) {
	char c;
	c = cin.get();
	if ('0' == c)
		*T = NULL;
	else {
		*T = new BiTree;
		(*T)->data = c;
		(*T)->ltag = 0;
		(*T)->rtag = 0;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
	return OK;
}
//中序遍历
void InThreading(BiTree *T) {
	if (T) {
		InThreading(T->lchild);
		if (!T->lchild) {
			T->ltag = 1;
			T->lchild = pre;
		}
		if (!pre->rchild) {
			pre->rtag = 1;
			pre->rchild = T;
		}
		pre = T;
		InThreading(T->rchild);
	}
}

Status InOrderThreading(BiTree **P, BiTree *T) {
	*P = new BiTree;
	(*P)->ltag = 0;
	(*P)->rtag = 1;
	(*P)->rchild = *P;//右孩子结点为空，指向父母
	if (!T)
		(*P)->lchild = *P;
	else {
		(*P)->lchild = T;
		pre = *P;
		InThreading(T);
		pre->rchild = *P;
		pre->rtag = 1;
		(*P)->rchild = pre;
	}
	return OK;

}
//中序遍历二叉树
Status InOrderTraverse(BiTree *T) {
	BiTree *p;
	p = T->lchild;
	while (p != T) {
		while (p->ltag == 0)
			p = p->lchild;
		cout << p->data << endl;

		while (p->rtag == 1 && p->rchild != T) {
			p = p->rchild;
			cout << p->data << endl;
		}
		p = p->rchild;
	}
	return OK;
}
int T018()
{
	BiTree *P, *T = NULL;

	CreateBiThrTree(&T);

	InOrderThreading(&P, T);

	printf("中序遍历输出结果为: ");

	InOrderTraverse(P);

	printf("\n");

	return 0;
}
#endif

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

// 线索存储标志位
// Link(0)：表示指向左右孩子的指针
// Thread(1)：表示指向前驱后继的线索
typedef enum { Link, Thread } PointerTag;

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
} BiThrNode, *BiThrTree;

// 全局变量，始终指向刚刚访问过的结点
BiThrTree pre;

// 创建一棵二叉树，约定用户遵照前序遍历的方式输入数据
void CreateBiThrTree(BiThrTree *T)
{
	char c;

	scanf("%c", &c);
	if (' ' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiThrNode *)malloc(sizeof(BiThrNode));
		(*T)->data = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}

// 中序遍历线索化
void InThreading(BiThrTree T)
{
	if (T)
	{
		InThreading(T->lchild);		// 递归左孩子线索化

		if (!T->lchild)	// 如果该结点没有左孩子，设置ltag为Thread，并把lchild指向刚刚访问的结点。
		{
			T->ltag = Thread;
			T->lchild = pre;
		}

		if (!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}

		pre = T;

		InThreading(T->rchild);		// 递归右孩子线索化
	}
}

void InOrderThreading(BiThrTree *p, BiThrTree T)
{
	*p = (BiThrTree)malloc(sizeof(BiThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if (!T)
	{
		(*p)->lchild = *p;
	}
	else
	{
		(*p)->lchild = T;
		pre = *p;
		InThreading(T);
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}

void visit(char c)
{
	printf("%c", c);
}

// 中序遍历二叉树，非递归
void InOrderTraverse(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;

	while (p != T)
	{
		while (p->ltag == Link)
		{
			p = p->lchild;
		}
		visit(p->data);

		while (p->rtag == Thread && p->rchild != T)
		{
			p = p->rchild;
			visit(p->data);
		}

		p = p->rchild;
	}
}

int T018()
{
	BiThrTree P, T = NULL;

	CreateBiThrTree(&T);

	InOrderThreading(&P, T);

	printf("中序遍历输出结果为: ");

	InOrderTraverse(P);

	printf("\n");

	return 0;
}