#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


///��ʵ�ܼ򵥣�����ʹ��Dijkstra˼�뼴�ɣ��ҵ��̵�·���͸���

int theBestPlan(vector<vector<int>>r)
{
	vector<int>dp = r[1];
	vector<int>f(dp.size(), 1);
	for (int i = 3; i < r.size(); ++i)//�ӵ�3��վ�㿪ʼ����Ҫ����Ѱ����Сֵ����ΪdpĬ�Ϸ����ǵ�����
	{
		for(int j = 2;j<i;++j)//j���ܴ���i����Ϊֻ�ܴ������ߵ����Σ����ܷ���
			if (dp[i] > (dp[j] + r[j][i]))//1��i�ķ���������j�᲻����٣�
			{
				dp[i] = dp[j] + r[j][i];
				f[i] = j;
			}
	}

	stack<int>s;
	s.push(f.size() - 1);
	for (int i = f.size() - 1; i != 1;)
	{
		i = f[i];
		s.push(i);
	}
	cout << "theBestPath: ";
	while (!s.empty())
	{
		cout << s.top() << "  ";
		s.pop();
	}
	cout << endl;
	return dp[dp.size() - 1];

}

void Test()
{
	vector<vector<int>>v;
	v.push_back({ 0,0,0,0,0,0,0 });
	v.push_back({ 0,0,2,5,9,15,20 });
	v.push_back({ 0,0,0,3,5,11,18 });
	v.push_back({ 0,0,0,0,3,6,12 });
	v.push_back({ 0,0,0,0,0,5,8 });
	v.push_back({ 0,0,0,0,0,0,6 });
	v.push_back({ 0,0,0,0,0,0,0 });
	cout << "theMinCost: " << theBestPlan(v) << endl;
}