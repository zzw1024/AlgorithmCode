#include "000�⺯��.h"


#define MAXSIZE 100//�洢�ռ�

#define m 3//B���Ľ�
#define N 17//����Ԫ�صĸ���
#define MAX 5//�ַ�������󳤶�

struct BTree
{
	int keynum;//�ڵ��йؼ��ֵĸ��� ���ڵ��С
	BTree *parent;//ָ��˫�׵�ָ��
	struct Node//�ڵ���������
	{
		int key;//�ؼ�������
		BTree *ptr;//����ָ������
		int recptr;//��¼ָ������
	};
	Node node[m + 1];//0�ŵ�Ԫδʹ��
};


struct Result{
	BTree *pt;//ָ���ҵ��Ľڵ�
	int i;//�ڽڵ��еĹؼ������
	int tag;//���ҳɹ����
};

int Search(BTree *p, int elem) {//p.node[i].key<=elem<p.node[i+1].key
	int j;
	for (int i = 1; i < p->keynum; ++i)
		if (p->node[i].key <= elem)
			j = i;
	return j;
}

//����B�����Ƿ���ڸ���
/*�ؼ���Ӧ�ò���ָ��pt��ָ�ڵ��еĵ�i�͵�i+1���ؼ���֮��*/
Result* SearchBTree(BTree *T, int elem) {
	BTree *p, *q;
	p = T;
	q = NULL;
	int find = false;
	Result *r = new Result;
	int i = 0;
	while (p && !find) {
		i = Search(p, elem);//p.node[i].key<=elem<p.node[i+1].key
		if (i > 0 && p->node[i].key == elem)//���ҵ��˹ؼ���
			find = true;
		else {
			q = p;
			p = p->node[i].ptr;
		}
	}
	r->i = i;
	if(find){//���ҳɹ�
		r->pt = p;
		r->tag = 1;
	}
	else {//���Ҳ��ɹ�������elem�Ĳ���λ�õ���Ϣ
		r->pt = q;
		r->tag = 0;
	}
	return r;
}

/* ��r->key��r��ap�ֱ���뵽q->key[i+1]��q->recptr[i+1]��q->ptr[i+1]�� */
int Insert(BTree* &pt, int n, int rx, BTree *ap) {
	for (int i = pt->keynum; i > n; --i)//�ճ�pt->node[n+1]
		pt->node[i + 1] = pt->node[i];//���Ų���ڳ�λ����
	pt->node[n + 1].key = rx;
	pt->node[n + 1].ptr = ap;
	pt->node[n + 1].recptr = rx;
	pt->keynum++;
	return true;
}

/* �����q���ѳ�������㣬ǰһ�뱣������һ�������������ap */
int split(BTree* &pt, BTree* &ap) {
	int s = (m + 1) / 2;
	ap = new BTree;//�����µĽڵ�ap
	ap->node[0].ptr = pt->node[s].ptr;//��һ������ap��
	for (int i = s + 1; i < m; ++i) {
		ap->node[i - s] = pt->node[i];
		if (ap->node[i - s].ptr)
			ap->node[i - s].ptr->parent = ap;
	}
	ap->keynum = m - s;
	ap->parent = pt->parent;
	pt->keynum = s - 1;/*  q��ǰһ�뱣�����޸�keynum */ 

	return true;
}

/* ���ɺ���Ϣ(T,r,ap)���µĸ����&T��ԭT��apΪ����ָ�� */
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

/*  ��m��B��T�Ͻ��*q��key[i]��key[i+1]֮�����ؼ���K��ָ��r�������� */
/*  ������,����˫�������б�Ҫ�Ľ����ѵ���,ʹT����m��B���� */
int InsertBTree(BTree* &T, int elem, BTree *pt, int n) {
	BTree *ap;
	ap = new BTree;
	bool finished = false;
	int s, rx;
	rx = elem;
	while (pt && !finished) {
		Insert(pt, n, rx, ap);// ��r->key��r��ap�ֱ���뵽q->key[i+1]��q->recptr[n+1]��q->ptr[n+1]��  */
		if (pt->keynum < m)
			finished = true;//����ɹ�
		else {//�Խڵ���з���
			s = (m + 1) / 2;
			rx = pt->node[s].recptr;
			split(pt, ap);/*  ��q->key[s+1..m],q->ptr[s..m]��q->recptr[s+1..m]�����½��*ap  */
			pt = pt->parent;
			if (pt)
				n = Search(pt, elem);//��˫�׽����*q�в���rx->key�Ĳ���λ��
		}
	}
	if (!finished)/*  T�ǿ���(����q��ֵΪNULL)�������ѷ���Ϊ���*q��*ap */
		NewRoot(T, rx, ap);/*  ���ɺ���Ϣ(T,rx,ap)���µĸ����*T��ԭT��apΪ����ָ�� */

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
	printf("\n����������Ҽ�¼�Ĺؼ���: ");
	int a;
	scanf("%d", &a);
	s = SearchBTree(T, a);
	if (s->tag)
		printf("(%d)", (s->pt)->node[a].key);
	else
		printf("û�ҵ�");
	printf("\n");

	return 0;
}
