#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Node
{
	double cp, rp, rw;
	int id;//已选价值、未选价值、剩余重量、树的层次
	vector<int>x;//当前选择结果
	Node(double a = 0, double b = 0, double c = 0, int d = 0, vector<int>v = {})
		:cp(a), rp(b), rw(c), id(d), x(v) {}
};

void Ordinary() // 普通队列
{
	vector<int>w, v, res;
	w = { 0,2,5,4,2 };
	v = { 0,6,3,5,4 };
	int W = 10;
	int bestp = 0;
	list<Node*>q;

	int sumw, sumv;
	sumw = sumv = 0;
	//初始化第一个节点
	for (int i = 0; i < v.size(); ++i)
	{
		sumw += w[i];
		sumv += v[i];
	}
	if (sumw <= W)
	{
		cout << "best value is：" << sumv << endl;
		return;
	}

	Node* A = new Node(0, sumv, W, 1, { 0,0,0,0,0 });
	q.push_back(A);

	//进行使用广度优先搜索
	while (!q.empty())
	{
		Node* t = q.front();
		q.pop_front();

		if (t->id >= v.size() || t->rw == 0)//剪枝
		{
			if (t->cp > bestp)
			{
				bestp = t->cp;
				res = t->x;
			}
			continue;//进行剪枝，此节点无需再扩展
		}
		if (t->rp + t->cp < bestp)//进行剪枝
			continue;
		int k = t->id;
		if (t->rw >= w[k])//可以加入该物品
		{
			Node* B = new Node(t->cp + v[k], t->rp - v[k],
				t->rw - w[k], t->id + 1, t->x);
			B->x[k] = 1;//加入该点
			if (B->cp > bestp)
			{
				bestp = B->cp;//及时更新最优解
				res = B->x;
			}
			q.push_back(B);//压入
		}
		if ((t->cp + t->rp - v[k]) >= bestp)//不选择该节点是否有优解？
		{
			Node* C = new Node(t->cp, t->rp - v[k], t->rw, t->id + 1, t->x);
			C->x[k] = 0;//不选择
			q.push_back(C);//压入
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
	sort(good.begin(), good.end(), [=](GNode* a, GNode* b) {return (a->v / a->w) > (b->v / b->w); });//进行排序

	int W = 10;
	int bestp = 0;
	int n = 4;

	priority_queue<Node*>q;//创建优先队列，会自己排序的

	int sumw, sumv;
	sumw = sumv = 0;
	//初始化第一个节点
	for (int i = 0; i <n; ++i)
	{
		sumw += good[i]->w;
		sumv += good[i]->v;
	}
	if (sumw <= W)
	{
		cout << "best value is：" << sumv << endl;
		return;
	}

	Node* A = new Node(0, sumv, W, 1, { 0,0,0,0,0 });
	q.push(A);

	//进行使用广度优先搜索
	while (!q.empty())
	{
		Node* t = q.top();
		q.pop();
		int k = t->id - 1;
		if (k >= n || t->rw == 0)//到了界限
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
		if (t->rw >= good[k]->w)//容量还足够
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
		if (t->cp + t->rp - good[k]->v >= bestp)//还有更优解
		{
			Node* R = new Node(t->cp, t->rp - good[k]->v, t->rw, t->id + 1, t->x);
			R->x[k+1] = 0;//不选择
			q.push(R);//压入
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


