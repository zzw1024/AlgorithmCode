#pragma once
#include <iostream>
#include <vector>

using namespace std;

void GoBack(int t, vector<vector<int>>Edge, vector<int>&bv, vector<int>&v, int &bestn, int &n)
{
	if (t >= v.size())
	{
		bv.assign(v.begin(), v.end());
		bestn = n;
		return;
	}

	bool flag = true;
	for (int i = t + 1; i < v.size(); ++i)//判断该点是不是最大团点
	{
		if (Edge[t][i] == 0)//一旦和其他点不相连则删除
			flag = false;
	}	

	if (flag)//需要
	{
		v[t] = 1;
		n++;
		GoBack(t + 1, Edge, bv, v, bestn, n);
		n--;//回溯
	}
	
	if ((n + v.size() - t - 1) > bestn)//还需继续考虑其他分支
	{
		v[t] = 0;//
		GoBack(t + 1, Edge, bv, v, bestn, n);
	}
	
}

void Test()
{
	vector<vector<int>>Edge;
	Edge.push_back({ 0,0,0,0,0,0 });
	Edge.push_back({ 0,0,1,1,1,1 });
	Edge.push_back({ 0,1,0,1,0,0 });
	Edge.push_back({ 0,1,1,0,1,1 });
	Edge.push_back({ 0,1,0,1,0,1 });
	Edge.push_back({ 0,1,0,1,1,0 });

	int bestn = 0;
	int n = 0;
	vector<int>bv(Edge.size(),0);
	vector<int>v(Edge.size(), 0);
	GoBack(1, Edge, bv, v, bestn, n);
	cout << bestn << endl;
	for (int i = 1; i < v.size(); ++i)
		if (v[i])
			cout << i << "  ";
	cout << endl;
}


