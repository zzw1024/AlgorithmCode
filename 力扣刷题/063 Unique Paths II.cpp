//#include "000�⺯��.h"
//
//
////������һ��ľ��飬��ֻ֪���϶�̬�滮
//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//		int n = obstacleGrid.size(), m = obstacleGrid[0].size();
//		if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
//			return 0;//��ֹ����·
//		vector<vector<long long int>>dp(n, vector<long long int>(m, 0));//���壬�ᳬ��int��ȡֵ��Χ
//		dp[0][0] = 1;
//		for (int i = 1; i < n; ++i)//��1��
//			if (obstacleGrid[i][0] == 0)//Ϊ����·��
//				dp[i][0] = dp[i - 1][0];
//		for (int j = 1; j < m; ++j)//��һ��
//			if (obstacleGrid[0][j] == 0)//Ϊ����·��
//				dp[0][j] = dp[0][j - 1];
//		for (int i = 1; i < n; ++i)
//			for (int j = 1; j < m; ++j)
//				if (obstacleGrid[i][j] == 0)//Ϊ����·��
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