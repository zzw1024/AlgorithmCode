#include "000库函数.h"

/********************************普通树*************************/
/*
struct PTNode
{
	ElemType data;//结点数据
	int parent;//双亲的位置
};

struct PTree {
	PTNode nodes[MAXSIZE];
	int r; //根节点
	int n; // 结点数目
};
*/
/****************************带孩子结点的树***************************/
/*
struct ChildPtr {
	int child;   //孩子结点的下标
	struct ChildPtr *next;//指向下一个孩子结点的指针
};
//结点的结构
struct CTBox {
	ElemType data;//存放树中结点的数据
	int parent; //存放双亲的下标
	struct ChildPtr firstchild;//指向大儿子的指针
};
//树的结构
struct CTree {
	CTBox nodes[MAXSIZE];
	int r;//根节点坐标
	int n;//结点的数目
};
*/

/***************************二叉树************************/
struct BiTree {
	char data;//存放节点数据
	struct BiTree *lchild, *rchild;//存放左孩子和右孩子	
};
//初始化二叉树
Status CreateBiTree(BiTree **T,string s,int i) {	
	if (i == s.size())return OK;
	if (s[i] == '0') {//输入的是空节点
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
//前序遍历二叉树
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
	cout << "请按前序顺序输入你的树的数据！空节点请用0代替" << endl;
	cin >> s;
	CreateBiTree(&T,s,0);
	PreOrderTraverse(T);
}

