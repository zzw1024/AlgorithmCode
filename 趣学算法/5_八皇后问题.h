#pragma once
#include <iostream>
#include <vector>

using namespace std;

bool isOK(vector<int>v, int t)
{
	for (int i = 1; i < t; ++i)//只需要判断前面t-1个位置即可
		if(v[t]==v[i] || (t - i) == fabs(v[i] - v[t]))
			return false;
	return true;
}
//t表示的是行
void GoBack(int t, vector<vector<int>>&res, vector<int>v)
{
	if (t >= v.size())
	{
		res.push_back(v);
		return;
	}	
	for (int i = 1; i < v.size(); ++i)//i表示为列
	{
		v[t] = i;
		if (isOK(v, t))
			GoBack(t + 1, res, v);
	}
}

void Test()
{
	int n = 4;
	vector<vector<int>>res;
	vector<int>v(n+1, 0);
	GoBack(1, res, v);


	for (auto &a : res)
	{
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl;
}