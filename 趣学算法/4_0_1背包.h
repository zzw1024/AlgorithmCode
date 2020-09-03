#pragma once
#include <iostream>
#include <vector>

using namespace std;

int theBagValue(vector<int>v, vector<int>w, const int W)
{
	if (W <= 0)
		return 0;
	vector<vector<int>>dp(v.size(), vector<int>(W + 1, 0));
	for (int i = 1; i < v.size(); ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			if (j < w[i])//�������Ʒ
				dp[i][j] = dp[i - 1][j];//�ǾͲ�Ҫ����i�����Ʒ
			else
			{
				int temp = dp[i - 1][j - w[i]] + v[i];//i-1����Ʒ�� ���Ž�Ϊ��ѡ�е�i-1����Ʒ����ʱ�ݻ�Ϊj-w[i]���ݻ�
				dp[i][j] = dp[i - 1][j] > temp ? dp[i - 1][j] : temp;
			}
		}
	}
	return dp[dp.size() - 1][W];
}

void Test()
{
	vector<int>w, v;
	int W;
	w = { 0,2,5,4,2,3 };
	v = { 0,6,3,5,4,6 };
	W = 10;
	cout << theBagValue(v, w, W) << endl;
}