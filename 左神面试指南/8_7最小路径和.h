#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Problem：
//	给你一个二维数组，二维数组中的每个数都是正数，要求从左上
//	角走到右下角，每一步只能向右或者向下。沿途经过的数字要累
//	加起来。返回最小的路径和。
//
//Solution：
//	使用动态规划的思想，
//	点[i][j]只能由该点的上方、左方走过来，然后算其路径和


int MinCost01(vector<vector<int>>v,int i,int j)//使用递归，从终点到起点
{
	int res = v[i][j];
	if (i == 0 && j == 0)
		return res;
	else if (i == 0)
		return res += MinCost01(v, i, j - 1);
	else if (j == 0)
		return res += MinCost01(v, i - 1, j);
	else
		return res += MinCost01(v, i - 1, j) < MinCost01(v, i, j - 1) ? MinCost01(v, i - 1, j) : MinCost01(v, i, j - 1);
}


int MinCost02(vector<vector<int>>v)
{

	vector<vector<int>>dp = v;
	for (int i = 0; i < v.size(); ++i) 
		for (int j = 0; j < v[0].size(); ++j)
		{
			if (i > 0 && i < v.size() && j > 0 && j < v[0].size())
				dp[i][j] += dp[i][j - 1] < dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];
			else if (i > 0 && i < v.size())
				dp[i][j] += dp[i - 1][j];
			else if (j > 0 && j < v[0].size())
				dp[i][j] += dp[i][j - 1];
		}

	return dp[v.size() - 1][v[0].size() - 1];
}

void Test()
{
	vector<vector<int>>v;
	v = { {1,2,0},
		  {0,1,2},
		  {2,3,1} };
	cout << MinCost01(v, 2, 2) << endl;
}