#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void theLongestSubStr(string str, string exp)
{
	if (str.length() == 0 || exp.length() == 0)
		return;
	vector<vector<int>>dp(str.length() + 1, vector<int>(exp.length() + 1, 0));
	vector<vector<int>>res = dp;
	for (int i = 1; i <= str.length(); ++i)
	{
		for (int j = 1; j <= exp.length(); ++j)
		{
			if (str[i - 1] == exp[i - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				res[i][j] = 1;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
				if (dp[i - 1][j] > dp[i][j - 1])
					res[i][j] = 2;
				else
					res[i][j] = 3;
			}
		}
	}
	cout << "最长公共子串长为：" << dp[dp.size() - 1][dp[0].size() - 1] << endl;
	string result = "";
	int i = str.length();
	int j = exp.length();
	while (i != 0 && j != 0)
	{
		if (res[i][j] = 1)
		{
			--i;
			--j;
			result += str[i];
		}
		else if (res[i][j] == 2)
		{
			i--;
			result += str[i];
		}
		else
		{
			j--;
			result += exp[j];
		}
	}

	
}

void Test()
{
	string a, b;
	a = "abcde";
	b = "abcde";
	theLongestSubStr(a, b);
}