#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minMulNum(vector<int>matrix)
{
	if (matrix.size() < 3)
	{
		return 0;
	}

	vector<vector<int>>dp(matrix.size(), vector<int>(matrix.size(), 0));

	for (int k = 2; k < matrix.size(); ++k)//就是选取多大的矩阵？
	{
		for (int i = 1; i < matrix.size() - k + 1; ++i)
		{
			int j = i + k - 1;
			dp[i][j] = dp[i + 1][j] + matrix[i - 1] * matrix[i] * matrix[j];
			for (int t = i + 1; t < j; ++t)//遍历中间矩阵
			{
				int n = dp[i][t] + dp[t + 1][j] + matrix[i - 1] * matrix[t] * matrix[j];
				if (dp[i][j] > n)
					dp[i][j] = n;

			}
		}
	}

	return dp[1][matrix.size() - 1];

}

int minMulNum2(vector<int>m)
{
	if (m.size() < 3)
	{
		return 0;
	}
	vector<vector<int>>dp(m.size(), vector<int>(m.size(), 0));
	for (int i = 1; i < m.size(); ++i)
	{
		for (int j = i+1; j < m.size(); ++j)
		{
			dp[i][j] = dp[i][j - 1] + m[i - 1] * m[j - 1] * m[j];
		}
	}

	for (int i = 1; i < m.size(); ++i)
	{
		for (int j = i+1; j < m.size(); ++j)
		{
			for (int k = i + 1; k < j; ++k)
			{
				if (dp[i][j] > (dp[i][k] + dp[k + 1][j] + m[i - 1] * m[k] * m[j]))
					dp[i][j] = (dp[i][k] + dp[k + 1][j] + m[i - 1] * m[k] * m[j]);
			}
		}
	}

	return dp[1][m.size() - 1];


}

void Test()
{
	vector<int>v;
	v = { 3,5,10,8,2,4 };
	cout << minMulNum2(v) << endl;
}