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
	for (int i = t + 1; i < v.size(); ++i)//�жϸõ��ǲ�������ŵ�
	{
		if (Edge[t][i] == 0)//һ���������㲻������ɾ��
			flag = false;
	}	

	if (flag)//��Ҫ
	{
		v[t] = 1;
		n++;
		GoBack(t + 1, Edge, bv, v, bestn, n);
		n--;//����
	}
	
	if ((n + v.size() - t - 1) > bestn)//�����������������֧
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


