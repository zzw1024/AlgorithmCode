//
//
//
//#include "head.h"
//
//vector<vector<int>>v;
//int Dijkstra()
//{
//	int x = v.size(), y = v[0].size();
//	vector<bool>visit(x*y, false);
//	vector<int>value(x*y, 0);
//	value[0] = v[0][0];
//	for (int i = 0; i < x*y; ++i)
//	{
//		int index = -1, maxV = -1;
//		for (int j = 0; j < value.size(); ++j)
//		{
//			if (visit[j] == false && maxV < value[j])
//			{
//				maxV = value[j];
//				index = j;
//			}
//		}
//		if (index == -1)break;
//		visit[index] = true;
//		for (int j = index + 1; j < x*y; ++j)//不能向回走
//		{
//			int ax = index / y, ay = index % y;
//			int bx = j / y, by = j % y;
//			if (visit[j] == false && abs((ax + ay) - (bx + by)) == 1)
//			{
//				if (value[j] < value[index] + v[bx][by])
//					value[j] = value[index] + v[bx][by];
//			}
//		}
//	}
//	return value.back();
//}
//
//int DP()
//{
//	vector<vector<int>>dp(v.size(), vector<int>(v[0].size(), 0));
//	dp[0][0] = v[0][0];
//	for (int i = 1; i < v[0].size(); ++i)
//		dp[0][i] = dp[0][i-1] + v[0][i];
//	for (int i = 1; i < v.size(); ++i)
//		dp[i][0] = dp[i-1][0] + v[i][0];
//	for (int i = 1; i < v.size(); ++i)
//		for (int j = 1; j < v[0].size(); ++j)
//			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + v[i][j];
//	return dp[v.size() - 1][v[0].size() - 1];
//}
//
//int DFS(int i, int j)
//{
//	if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size())
//		return 0;
//	if (i == v.size() - 1 && j == v[0].size() - 1)
//		return v[i][j];
//	return max(DFS(i, j + 1), DFS(i + 1, j));
//}
//
//int main()
//{
//	v = { {1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5} };
//	cout << Dijkstra() << endl;
//	cout << DP() << endl;
//	cout << DFS(0, 0) << endl;
//	return 0;
//}