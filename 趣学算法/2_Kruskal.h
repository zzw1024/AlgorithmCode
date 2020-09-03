#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Edge
{
	int nu;//集合编号
	int u;//点
	int vn;//集合编号
	int v;//点
	int w;//权重
};

void Test()
{
	int N = 7;//节点数目
	int M = 12;//边数目

	vector<int>nodes(N + 1);//节点编号
	map<int, pair<int, int>>data;//用来存储权值和连接顶点
	vector<pair<int, int>>res;//存储结果
	int sum = 0;
	vector<int>d;
	for (int i = 0; i <= N; ++i)
		nodes[i] = i;
	d = { 1,2,23,1,6,28,1,7,36,2,7,1,6,7,25,2,3,20,6,5,17,7,3,4,7,5,16,7,4,9,3,4,15,5,4,3 };
	for (int i = 0; i < d.size(); i += 3)//存入数据并自动排序
		data[d[i + 2]] = make_pair(d[i], d[i + 1]);
	
	for (auto ptr = data.begin();ptr!=data.end();++ptr)
	{
		int a = ptr->second.first;
		int b = ptr->second.second;
		if (nodes[a] != nodes[b])//不属于同一个集合
		{
			sum += ptr->first;
			res.push_back(make_pair(a, b));
			int n = nodes[a] < nodes[b] ? nodes[a] : nodes[b];//合并
			int a1 = nodes[a];
			int a2 = nodes[b];
			for (int i = 0; i < nodes.size(); ++i)
			{
				if (nodes[i] == a1 || nodes[i] == a2)
					nodes[i] = n;
			}
		}

	}
	for (auto a : res)
		cout << a.first << "->" << a.second << endl;
	cout << sum << endl;
}