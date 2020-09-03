#include "000库函数.h"

#define MAXSIZE 100


//二叉树的结构
struct BiTree
{
	int data;
	BiTree *lchild, *rchild;
};

//创建二叉树
void InsertBST(BiTree* &T, int elem) {
	BiTree *p = new  BiTree;
	p->data = elem;
	p->lchild = NULL;
	p->rchild = NULL;
	if (!T) {
		T = p;//为空树		
		return;
	}

	if (T->data == elem)
		return;//此数已经存在

	while (true) {
		if (elem > T->data) {
			if (T->rchild != NULL)
				T = T->rchild;//走到最右端
			else {
				T->rchild = p;//添加为右子树
				return;
			}
		}
		else {
			if (T->lchild != NULL)
				T = T->lchild;//走到最左端
			else {
				T->lchild = p;//添加为左子树
				return;
			}
		}
	}

}

void ShowTree(BiTree *T) {
	//进行中序浏览
	if (T) {
		ShowTree(T->lchild);
		cout << T->data << "—>";
		ShowTree(T->rchild);
	}
}

//对二叉树进行查找工作
int SearchData(BiTree *T, int num) {
	if (!T)return 0;
	if (T->data == num)return 1;
	if (num > T->data)SearchData(T->rchild,num);
	else SearchData(T->lchild, num);
}


//进行删除
//重点，也是难点
int Delete(BiTree* &T) {
	BiTree *p, *q;
	if (T->rchild == NULL) {//若该结点没有右子树，则将该节点的左子树代替其，并删除
		p = T;
		T = T->lchild;
		delete(p);
	}
	else if (T->lchild == NULL) {//若该结点没有左子树，则将该节点的右子树代替其，并删除
		p = T;
		T = T->rchild;
		delete(p);
	}
	else {//左右子树都存在
		p = T;
		q = T->lchild;
		while (q->rchild) {//走到T左支的末端，此时他是左边最大的数
			p = q;//记住前端点
			q = q->rchild;
		}
		T->data = q->data;//前驱的数字用最右端数字代替
		if (p != T)//将末端的左孩子连接，因为此时他是左端最大的数字
			p->rchild = q->lchild;
		else
			p->lchild = q->lchild;//重接左子树
		delete(q);//释放左端最大值
	}
	return 1;
}


//对二叉树进行删除操作
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
			p = T;//记住头结点的位置
		T = p;//仍然返回头结点，从头结点开始重新遍历
	}
	ShowTree(T);
	cout << endl;
	cout << "找到没？" << endl << SearchData(T, 99) << endl;
	p = T;//记住头结点
	DeleteBST(T, 93);
	T = p;
	ShowTree(T);
	cout << endl;
	p = T;//记住头结点
	DeleteBST(T, 37);
	T = p;
	ShowTree(T);
	cout << endl;
	return 0;
}
