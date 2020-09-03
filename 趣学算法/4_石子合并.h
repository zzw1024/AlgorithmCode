#pragma once
#include <iostream>
#include <vector>

using namespace std;


int lessStoneCost(vector<int>v)
{
	if (v.empty())
		return 0;
	vector<vector<int>>dp(v.size(), vector<int>(v.size(), 0));
	vector<int>sum(v.size(), 0);
	for (int i = 1; i < v.size(); ++i)
		sum[i] = sum[i - 1] + v[i];

	for (int d = 2; d < v.size(); ++d)
	{
		for (int i = 1; i < v.size() - d + 1; ++i)
		{
			int j = i + d - 1;
			dp[i][j] = INT_MAX;
			for (int k = i ; k < j; ++k)
			{
				int temp = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];//这后面就是i-j代价                             
				dp[i][j] = dp[i][j] < temp ? dp[i][j] : temp;
			}
		}
	}
	return dp[1][v.size() - 1];
}


void Test()
{
	vector<int>v;
	v = { 0,3,4,6,5,4,2 };
	cout << lessStoneCost(v) << endl;
}