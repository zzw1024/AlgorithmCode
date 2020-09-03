#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <queue>

#define INF 9999999
using namespace std;

struct Node
{
	int id;
	int dis;
	vector<int>x;
	Node(int a = 0, int b = 0, vector<int>v = {}) :id(a), dis(b), x(v) {}
};





void Test()
{
	vector<vector<int>>Edge;
	Edge.push_back({ 0,0,0,0,0 });
	Edge.push_back({ 0,INF,15,30,5 });
	Edge.push_back({ 0,15,INF,6,12 });
	Edge.push_back({ 0,30,6,INF,3 });
	Edge.push_back({ 0,5,12,3,INF });
	vector<int>res;
	int bestDis = INT_MAX;

	//在分治定界中，最好使用有优先次序的队列
	priority_queue<Node*>q;

	//初始化
	Node* root = new Node(2, 0, { 0,1,2,3,4 });//从第二个开始遍历
	q.push(root);

	while (!q.empty())
	{
		Node* t = q.top();
		q.pop();
		int k = t->id;
		if (k == Edge.size() - 1)//到达最后一个点
		{
			int Dis = t->dis + Edge[t->x[Edge.size() - 2]][Edge.size() - 1] + Edge[t->x[Edge.size() - 1]][1];
			if (Edge[t->x[Edge.size() - 1]][1] != INF && Edge[t->x[Edge.size() - 2]][Edge.size() - 1] != INF &&
				t->dis + Edge[t->x[Edge.size() - 1]][1] < bestDis)//此路不通
			{
				bestDis = Dis;
				res = t->x;
				res.push_back(1);
			}
			continue;
		}
		
		if (t->dis >= bestDis)
			continue;//距离已经不是最优
		for (int j = k; j < Edge.size(); ++j)//开始遍历
		{
			if (Edge[t->x[k - 1]][t->x[j]] != INF)//就是k-1与j是有路可行的，则进行交换
			{
				int Dis = t->dis + Edge[t->x[k - 1]][t->x[j]];
				if (Dis < bestDis)
				{
					Node* child = new Node(k + 1, Dis, t->x);
					swap(child->x[k], child->x[j]);
					q.push(child);
				}
			}
		}
	}	
	for (auto a : res)
		cout << a << "->";
	cout << endl << bestDis << endl;
}