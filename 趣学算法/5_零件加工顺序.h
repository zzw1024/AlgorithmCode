#pragma once
#include <iostream>
#include <vector>

using namespace std;


void Goback(int t, vector<vector<int>>data, vector<int>& res, vector<int>v, int& bestf, int f1, int f2)
{
	if (t >= data.size())
	{
		bestf = f2;
		res.assign(v.begin(), v.end());
		return;
	}
	for (int i = t; i < data.size(); ++i)//重难点，怎么使得不重复加工工件
	{
		int temp = f2;//用来回溯
		f1 += data[v[i]][0];  //利用前面已经加过的时间
		f2 = (f1 > f2 ? f1 : f2) + data[v[i]][1];//是否该工件第一步加工完，是的话直接进入第二道工序
		if (f2 < bestf)//因为不能使用重复工件，所以使用交换的方法
		{
			swap(v[i], v[t]);
			Goback(t + 1, data, res, v, bestf, f1, f2);
			swap(v[i], v[t]);//复位
		}
		f1 -= data[v[i]][0];//复位
		f2 = temp;
	}
}

void Test()
{
	vector<vector<int>>data;
	data.push_back({ 0,0 });
	data.push_back({ 5,7 });
	data.push_back({ 1,2 });
	data.push_back({ 8,2 });
	data.push_back({ 5,4 });
	data.push_back({ 3,7 });
	data.push_back({ 4,4 });

	vector<int>res;
	vector<int>v = { 0,1,2,3,4,5,6 };//先给出一个初始顺序，后续在此基础上进行交换遍历
	int bestf = INT_MAX;
	int f1 = 0;
	int f2 = 0;
	Goback(1, data, res, v, bestf, f1, f2);

	for (auto a : res)
		cout << a << "  ";
	cout << endl << bestf << endl;
}
