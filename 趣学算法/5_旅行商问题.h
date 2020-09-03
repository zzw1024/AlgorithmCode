#pragma once
#include <iostream>
#include <vector>

using namespace std;


void GoBack(int t, vector<vector<int>>route, vector<int>v, vector<int>&res, int s, int &bests)
{
	if (t >= v.size() && (s + route[v[v.size() - 1]][1]) < bests)//�˴������������
	{
		res.assign(v.begin(), v.end());
		res.push_back(1);//�����������
		bests = s + route[v[v.size() - 1]][1];
		return;
	}
	for (int i = t; i < v.size(); ++i)
	{
		int temp = s+ route[v[t - 1]][i];
		if (temp < bests)//���t-1��t���еľ������
		{
			s += route[v[t - 1]][t];//����t-1��t�Ĳ��ԣ�
			swap(v[t], v[i]);
			GoBack(t + 1, route, v, res, s, bests);
			swap(v[t], v[i]);//��ԭ����
			s -= route[v[t - 1]][t];
		}		
	}
}

void Test()
{
	vector<vector<int>>route;
	route.push_back({ 0,0,0,0,0,0 });
	route.push_back({ 0,999999,3,999999,8,9 });
	route.push_back({ 0,3,9999999,3,10,5 });
	route.push_back({ 0,999999,3,9999999,4,3 });
	route.push_back({ 0,8,10,4,999999,20 });
	route.push_back({ 0,9,5,3,20,999999 });
	vector<int>v = { 0,1,2,3,4,5 };
	vector<int>res;
	int s = 0;
	int bests = INT_MAX;
	GoBack(2, route, v, res, s, bests);//��Զ��1����

	for (auto a : res)
		cout << a << "->";
	cout << endl << bests << endl;
}