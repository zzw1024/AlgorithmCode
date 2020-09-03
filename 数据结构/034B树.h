#include "000库函数.h"


#define MAXSIZE 100//存储空间

#define m 3//B树的阶
#define N 17//数据元素的个数
#define MAX 5//字符串的最大长度

struct BTree
{
	int keynum;//节点中关键字的个数 即节点大小
	BTree *parent;//指向双亲的指针
	struct Node//节点向量类型
	{
		int key;//关键字向量
		BTree *ptr;//子树指针向量
		int recptr;//记录指针向量
	};
	Node node[m + 1];//0号单元未使用
};


struct Result{
	BTree *pt;//指向找到的节点
	int i;//在节点中的关键字序号
	int tag;//查找成功与否
};

int Search(BTree *p, int elem) {//p.node[i].key<=elem<p.node[i+1].key
	int j;
	for (int i = 1; i < p->keynum; ++i)
		if (p->node[i].key <= elem)
			j = i;
	return j;
}

//查找B树中是否存在该数
/*关键字应该插在指针pt所指节点中的第i和第i+1个关键字之间*/
Result* SearchBTree(BTree *T, int elem) {
	BTree *p, *q;
	p = T;
	q = NULL;
	int find = false;
	Result *r = new Result;
	int i = 0;
	while (p && !find) {
		i = Search(p, elem);//p.node[i].key<=elem<p.node[i+1].key
		if (i > 0 && p->node[i].key == elem)//查找到了关键字
			find = true;
		else {
			q = p;
			p = p->node[i].ptr;
		}
	}
	r->i = i;
	if(find){//查找成功
		r->pt = p;
		r->tag = 1;
	}
	else {//查找不成功，返回elem的插入位置的信息
		r->pt = q;
		r->tag = 0;
	}
	return r;
}

/* 将r->key、r和ap分别插入到q->key[i+1]、q->recptr[i+1]和q->ptr[i+1]中 */
int Insert(BTree* &pt, int n, int rx, BTree *ap) {
	for (int i = pt->keynum; i > n; --i)//空出pt->node[n+1]
		pt->node[i + 1] = pt->node[i];//向后挪，腾出位置来
	pt->node[n + 1].key = rx;
	pt->node[n + 1].ptr = ap;
	pt->node[n + 1].recptr = rx;
	pt->keynum++;
	return true;
}

/* 将结点q分裂成两个结点，前一半保留，后一半移入新生结点ap */
int split(BTree* &pt, BTree* &ap) {
	int s = (m + 1) / 2;
	ap = new BTree;//生成新的节点ap
	ap->node[0].ptr = pt->node[s].ptr;//后一半移入ap中
	for (int i = s + 1; i < m; ++i) {
		ap->node[i - s] = pt->node[i];
		if (ap->node[i - s].ptr)
			ap->node[i - s].ptr->parent = ap;
	}
	ap->keynum = m - s;
	ap->parent = pt->parent;
	pt->keynum = s - 1;/*  q的前一半保留，修改keynum */ 

	return true;
}

/* 生成含信息(T,r,ap)的新的根结点&T，原T和ap为子树指针 */
int NewRoot(BTree *T, int key, BTree *ap) {
	BTree *p = new BTree;
	p->node[0].ptr = T;
	T = p;
	if (T->node[0].ptr)
		T->node[0].ptr->parent = T;
	T->parent = NULL;
	T->keynum = 1;
	T->node[1].key = key;
	T->node[1].recptr = key;
	T->node[1].ptr = ap;
	if (T->node[1].ptr)
		T->node[1].ptr->parent = T;

	return true;
}

/*  在m阶B树T上结点*q的key[i]与key[i+1]之间插入关键字K的指针r。若引起 */
/*  结点过大,则沿双亲链进行必要的结点分裂调整,使T仍是m阶B树。 */
int InsertBTree(BTree* &T, int elem, BTree *pt, int n) {
	BTree *ap;
	ap = new BTree;
	bool finished = false;
	int s, rx;
	rx = elem;
	while (pt && !finished) {
		Insert(pt, n, rx, ap);// 将r->key、r和ap分别插入到q->key[i+1]、q->recptr[n+1]和q->ptr[n+1]中  */
		if (pt->keynum < m)
			finished = true;//插入成功
		else {//对节点进行分裂
			s = (m + 1) / 2;
			rx = pt->node[s].recptr;
			split(pt, ap);/*  将q->key[s+1..m],q->ptr[s..m]和q->recptr[s+1..m]移入新结点*ap  */
			pt = pt->parent;
			if (pt)
				n = Search(pt, elem);//在双亲结点中*q中查找rx->key的插入位置
		}
	}
	if (!finished)/*  T是空树(参数q初值为NULL)或根结点已分裂为结点*q和*ap */
		NewRoot(T, rx, ap);/*  生成含信息(T,rx,ap)的新的根结点*T，原T和ap为子树指针 */

	return true;
}
		

int T034()
{
	int r[N] = { 22,16,41,58,8,11,12,16,17,22,23,31,41,52,58,59,61 };
	BTree *T = new BTree;
	T = NULL;
	Result *s;
	for (int i = 0; i < N; i++)
	{
		s = SearchBTree(T, r[i]);
		if (!s->tag)
			InsertBTree(T, r[i], s->pt, s->i);
	}
	printf("\n请输入待查找记录的关键字: ");
	int a;
	scanf("%d", &a);
	s = SearchBTree(T, a);
	if (s->tag)
		printf("(%d)", (s->pt)->node[a].key);
	else
		printf("没找到");
	printf("\n");

	return 0;
}
