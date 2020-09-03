#pragma once
#include <iostream>

#include <vector>

using namespace std;

bool isExist(vector<int>v, int i, int res, int N)
{
	if (res == N)
		return true;
	if (i >= v.size())
		return false;
	return isExist(v, i + 1, res, N) || isExist(v, i + 1, res + v[i], N);

}

bool isExist02(vector<int>v, int N)//使用动态规划
{
	vector<vector<bool>>dp(v.size()+1, vector<bool>(N + 1, false));
	for (int i = 0; i < dp.size(); ++i)
		dp[i][N] = true;
	for (int i = v.size() - 1; i >= 0; --i)
		for (int j = N - 1; j >= 0; --j)
			if (j + v[i] <= N)
				dp[i][j] = dp[i][j] || dp[i + 1][j + v[i]];

	return dp[0][0];
}

void Test()
{
	vector<int>v;
	v = { 1,2,3 };
	cout << isExist(v, 0, 0, 3) << endl;
}

