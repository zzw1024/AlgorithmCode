//#include "000库函数.h"
//
////首先想到的是使递归
////但是递归会超时
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		vector<vector<bool>>visit(n, vector<bool>(m, false));//一定要标记已经遍历过的路径
//		int res = 0;
//		helper(visit, res, m, n, 0, 0);
//		return res;
//	}
//	void helper(vector<vector<bool>>&visit, int &res, int m, int n, int i, int j)
//	{
//		if (i == n - 1 && j == m - 1)
//		{
//			++res;
//			return;
//		}
//		if (i >= 0 && i < n && j >= 0 && j < m && !visit[i][j])
//		{
//			visit[i][j] = true;
//			helper(visit, res, m, n, i + 1, j);
//			helper(visit, res, m, n, i, j + 1);
//			visit[i][j] = false;//回溯
//		}
//	}
//};
////然后是动态规划
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		vector<vector<int>>dp(n, vector<int>(m, 0));
//		dp[0][0] = 1;
//		for (int i = 1; i < n; ++i)//第一列的路径只能为上面走下来的路径
//			dp[i][0] = dp[i - 1][0];
//		for (int j = 1; j < m; ++j)//第一行的路径只能为左边走过来的路径
//			dp[0][j] = dp[0][j-1];
//		for (int i = 1; i < n; ++i)
//			for (int j = 1; j < m; ++j)
//				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//中间的路径只能为左边或者上面走来的路径
//		return dp[n - 1][m - 1];
//	}
//};
////使用一行空间，因此只需要保留当前行与上一行的数据 
//class Solution2 {
//public:
//	int uniquePaths(int m, int n) {
//		vector<int> dp(n, 1);
//		for (int i = 1; i < m; ++i) {
//			for (int j = 1; j < n; ++j) {
//				dp[j] += dp[j - 1];
//			}
//		}
//		return dp[n - 1];
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	cout << s.uniquePaths(7, 3);
//	return 0;
//}
//
