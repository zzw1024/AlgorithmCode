//#include "000库函数.h"
//
//
////根据上一题的经验，可知只能上动态规划
//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//		int n = obstacleGrid.size(), m = obstacleGrid[0].size();
//		if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
//			return 0;//防止是死路
//		vector<vector<long long int>>dp(n, vector<long long int>(m, 0));//陷阱，会超出int的取值范围
//		dp[0][0] = 1;
//		for (int i = 1; i < n; ++i)//第1列
//			if (obstacleGrid[i][0] == 0)//为可行路径
//				dp[i][0] = dp[i - 1][0];
//		for (int j = 1; j < m; ++j)//第一行
//			if (obstacleGrid[0][j] == 0)//为可行路径
//				dp[0][j] = dp[0][j - 1];
//		for (int i = 1; i < n; ++i)
//			for (int j = 1; j < m; ++j)
//				if (obstacleGrid[i][j] == 0)//为可行路径
//					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//		return dp[n - 1][m - 1];
//	}
//};
//
//int main()
//{
//	vector<vector<int>>v = { {1,0} };//;, 0}, { 0,0,0 } };
//	Solution s;
//	cout << s.uniquePathsWithObstacles(v);
//	return 0;;
//}