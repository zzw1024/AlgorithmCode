#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int theGenDis(string src, string exp)
{
	vector<vector<int>>dp(src.length() + 1, vector<int>(exp.length() + 1, 0));
	//初始化动态表
	for (int i = 0; i <= src.length(); ++i)//当第二个串为0时，则需要i个操作
		dp[i][0] = i;
	for (int j = 0; j <= exp.length(); ++j)//当第一个串为0时， 则需要j个操作
		dp[0][j] = j;

	for (int i = 1; i <= src.length(); ++i)
	{
		for (int j = 1; j <= exp.length(); ++j)
		{
			int f = 0;
			if (src[i - 1] != exp[j - 1])
				f = 1;
			dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + f);
		}
	}
	return dp[src.length()][exp.length()];
}

void Test()
{
	string a, b;
	a = "family";
	b = "frame";
	cout << theGenDis(a, b) << endl;
}
