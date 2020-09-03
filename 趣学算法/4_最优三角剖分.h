#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



///错咯
int theLessWeight(vector<vector<int>>w)
{
	if (w.size() < 4)//0除外
		return 0;
	vector<vector<int>>dp(w.size(), vector<int>(w[0].size(), 0));
	for (int i = 1; i < w.size(); ++i)
	{
		for (int j = i + 1; j < w.size(); ++j)
		{
			dp[i][j] = dp[i][j-1] + w[i][j-1] + w[i][j] + w[j - 1][j];
			for (int k = i + 1; k < j; ++k)
			{				
				int temp = dp[i][k] + dp[k + 1][j] + w[i - 1][k] + w[k][j] + w[i - 1][j];
				dp[i][j] = temp < dp[i][j] ? temp : dp[i][j];				
			}
		}
	}
	return dp[1][w.size() - 1];

}


int theLessWeight2(vector<vector<int>>w)
{
	vector<vector<int>>dp(w.size(), vector<int>(w[0].size(), 0));
	for (int d = 2; d < w.size(); ++d)
	{
		for (int i = 1; i < w.size() - d + 1; ++i)
		{
			int j = d + i - 1;//
			dp[i][j] = dp[i + 1][j] + w[i - 1][i] + w[i][j] + w[i - 1][j];//我i-j的代价为i+1,
			for (int k = i + 1; k < j; ++k)
			{
				int temp = dp[i][k] + dp[k + 1][j] + w[i - 1][k] + w[k][j] + w[i - 1][j];
				dp[i][j] = temp < dp[i][j] ? temp : dp[i][j];
			}
		}
	}
	return dp[1][w.size() - 1];
}

void Test()
{
	vector<vector<int>>w;
	w.push_back({ 0,2,3,1,5,6 });
	w.push_back({ 2,0,3,4,8,6 });
	w.push_back({ 3,3,0,10,13,7 });
	w.push_back({ 1,4,10,0,12,5 });
	w.push_back({ 5,8,13,12,0,3 });
	w.push_back({ 6,6,7,5,3,0 });
	cout << theLessWeight(w) << endl;
	cout << theLessWeight2(w) << endl;
}