#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Problem��
//	����һ����ά���飬��ά�����е�ÿ��������������Ҫ�������
//	���ߵ����½ǣ�ÿһ��ֻ�����һ������¡���;����������Ҫ��
//	��������������С��·���͡�
//
//Solution��
//	ʹ�ö�̬�滮��˼�룬
//	��[i][j]ֻ���ɸõ���Ϸ������߹�����Ȼ������·����


int MinCost01(vector<vector<int>>v,int i,int j)//ʹ�õݹ飬���յ㵽���
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