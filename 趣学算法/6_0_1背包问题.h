#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Node
{
	double cp, rp, rw;
	int id;//��ѡ��ֵ��δѡ��ֵ��ʣ�����������Ĳ��
	vector<int>x;//��ǰѡ����
	Node(double a = 0, double b = 0, double c = 0, int d = 0, vector<int>v = {})
		:cp(a), rp(b), rw(c), id(d), x(v) {}
};

void Ordinary() // ��ͨ����
{
	vector<int>w, v, res;
	w = { 0,2,5,4,2 };
	v = { 0,6,3,5,4 };
	int W = 10;
	int bestp = 0;
	list<Node*>q;

	int sumw, sumv;
	sumw = sumv = 0;
	//��ʼ����һ���ڵ�
	for (int i = 0; i < v.size(); ++i)
	{
		sumw += w[i];
		sumv += v[i];
	}
	if (sumw <= W)
	{
		cout << "best value is��" << sumv << endl;
		return;
	}

	Node* A = new Node(0, sumv, W, 1, { 0,0,0,0,0 });
	q.push_back(A);

	//����ʹ�ù����������
	while (!q.empty())
	{
		Node* t = q.front();
		q.pop_front();

		if (t->id >= v.size() || t->rw == 0)//��֦
		{
			if (t->cp > bestp)
			{
				bestp = t->cp;
				res = t->x;
			}
			continue;//���м�֦���˽ڵ���������չ
		}
		if (t->rp + t->cp < bestp)//���м�֦
			continue;
		int k = t->id;
		if (t->rw >= w[k])//���Լ������Ʒ
		{
			Node* B = new Node(t->cp + v[k], t->rp - v[k],
				t->rw - w[k], t->id + 1, t->x);
			B->x[k] = 1;//����õ�
			if (B->cp > bestp)
			{
				bestp = B->cp;//��ʱ�������Ž�
				res = B->x;
			}
			q.push_back(B);//ѹ��
		}
		if ((t->cp + t->rp - v[k]) >= bestp)//��ѡ��ýڵ��Ƿ����Ž⣿
		{
			Node* C = new Node(t->cp, t->rp - v[k], t->rw, t->id + 1, t->x);
			C->x[k] = 0;//��ѡ��
			q.push_back(C);//ѹ��
		}
	}

	for (int i = 1; i < v.size(); ++i)
		if (res[i])
			cout << i << "  ";
	cout << endl << bestp << endl;
}


struct GNode
{
	double w;
	double v;
	int i;
	GNode(double a, double b, int c) :w(a), v(b), i(c) {}
};

void Priority()
{
	vector<GNode*>good;
	vector<int>res;
	good.push_back(new GNode(2, 6, 1));
	good.push_back(new GNode(5, 3, 2));
	good.push_back(new GNode(4, 5, 3));
	good.push_back(new GNode(2, 4, 4));
	sort(good.begin(), good.end(), [=](GNode* a, GNode* b) {return (a->v / a->w) > (b->v / b->w); });//��������

	int W = 10;
	int bestp = 0;
	int n = 4;

	priority_queue<Node*>q;//�������ȶ��У����Լ������

	int sumw, sumv;
	sumw = sumv = 0;
	//��ʼ����һ���ڵ�
	for (int i = 0; i <n; ++i)
	{
		sumw += good[i]->w;
		sumv += good[i]->v;
	}
	if (sumw <= W)
	{
		cout << "best value is��" << sumv << endl;
		return;
	}

	Node* A = new Node(0, sumv, W, 1, { 0,0,0,0,0 });
	q.push(A);

	//����ʹ�ù����������
	while (!q.empty())
	{
		Node* t = q.top();
		q.pop();
		int k = t->id - 1;
		if (k >= n || t->rw == 0)//���˽���
		{
			if (t->cp > bestp)
			{
				bestp = t->cp;
				res = t->x;
			}
			continue;
		}

		if (t->cp + t->rp < bestp)
			continue;
		if (t->rw >= good[k]->w)//�������㹻
		{
			Node* L = new Node(t->cp + good[k]->v, t->rp - good[k]->v,
				t->rw - good[k]->w, t->id + 1, t->x);
			L->x[k + 1] = 1;
			if (L->cp > bestp)
			{
				bestp = L->cp;
				res = L->x;
			}
			q.push(L);
		}
		if (t->cp + t->rp - good[k]->v >= bestp)//���и��Ž�
		{
			Node* R = new Node(t->cp, t->rp - good[k]->v, t->rw, t->id + 1, t->x);
			R->x[k+1] = 0;//��ѡ��
			q.push(R);//ѹ��
		}
	}
	for (int i = 1; i < res.size(); ++i)
		if (res[i])
			cout << good[i-1]->i << "  ";
	cout << endl << bestp << endl;
}

void Test()
{
	//Ordinary();
	Priority();
	

}


