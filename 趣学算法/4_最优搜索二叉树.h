#pragma once
#include <iostream>
#include <vector>

using namespace std;

float theBestST(vector<float>p, vector<float>q)
{
	if (q.size() < 1)
		return 0;
	vector<vector<float>>dp(p.size()+1, vector<float>(p.size(), 0));
	vector<vector<float>>w(p.size()+1, vector<float>(p.size(), 0));
	for (int i = 1; i <= p.size(); ++i)
		w[i][i - 1] = q[i - 1];//������ڵ����ʵ�ڵ���ϵ�λ�õĸ��ʣ�
	//i��ʾ������ �Ǳ�i��һ�㣬 ��סj��ʾ���ǽڵ�ı��

	for (int d = 1; d < p.size(); ++d)//�����ģ
	{
		for (int i = 1; i < p.size() - d + 1; ++i)
		{
			int j = d + i - 1;
			w[i][j] = w[i][j - 1] + p[j] + q[j];//j��ʾ���ǽڵ�ı�ţ��ʸ��ʺ�Ϊǰ��ļ����ڵ�
			dp[i][j] = dp[i][i - 1] + dp[i + 1][j];
			for (int k = i + 1; k <= j; ++k)
				//��kΪ���ڵ�����ĳɱ�
			{
				float temp = dp[i][k - 1] + dp[k + 1][j];
				dp[i][j] = dp[i][j] < temp ? dp[i][j] : temp;
			}
			dp[i][j] += w[i][j];
		}
	}
	return dp[1][q.size() - 1];
}

void Test()
{
	vector<float>p, q;
	p = { 0,0.04,0.09,0.08,0.02,0.12,0.14 };
	q = { 0.06,0.08,0.10,0.07,0.05,0.05,0.10 };
	cout << theBestST(p, q) << endl;
}