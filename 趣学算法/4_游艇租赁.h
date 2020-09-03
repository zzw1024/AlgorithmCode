#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


///其实很简单，就是使用Dijkstra思想即可，找到短的路径就更新

int theBestPlan(vector<vector<int>>r)
{
	vector<int>dp = r[1];
	vector<int>f(dp.size(), 1);
	for (int i = 3; i < r.size(); ++i)//从第3个站点开始，不要遍历寻找最小值，因为dp默认费用是递增的
	{
		for(int j = 2;j<i;++j)//j不能大于i是因为只能从上游走到下游，不能返回
			if (dp[i] > (dp[j] + r[j][i]))//1到i的费用若借助j会不会变少？
			{
				dp[i] = dp[j] + r[j][i];
				f[i] = j;
			}
	}

	stack<int>s;
	s.push(f.size() - 1);
	for (int i = f.size() - 1; i != 1;)
	{
		i = f[i];
		s.push(i);
	}
	cout << "theBestPath: ";
	while (!s.empty())
	{
		cout << s.top() << "  ";
		s.pop();
	}
	cout << endl;
	return dp[dp.size() - 1];

}

void Test()
{
	vector<vector<int>>v;
	v.push_back({ 0,0,0,0,0,0,0 });
	v.push_back({ 0,0,2,5,9,15,20 });
	v.push_back({ 0,0,0,3,5,11,18 });
	v.push_back({ 0,0,0,0,3,6,12 });
	v.push_back({ 0,0,0,0,0,5,8 });
	v.push_back({ 0,0,0,0,0,0,6 });
	v.push_back({ 0,0,0,0,0,0,0 });
	cout << "theMinCost: " << theBestPlan(v) << endl;
}