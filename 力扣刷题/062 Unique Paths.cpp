//#include "000�⺯��.h"
//
////�����뵽����ʹ�ݹ�
////���ǵݹ�ᳬʱ
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		vector<vector<bool>>visit(n, vector<bool>(m, false));//һ��Ҫ����Ѿ���������·��
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
//			visit[i][j] = false;//����
//		}
//	}
//};
////Ȼ���Ƕ�̬�滮
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		vector<vector<int>>dp(n, vector<int>(m, 0));
//		dp[0][0] = 1;
//		for (int i = 1; i < n; ++i)//��һ�е�·��ֻ��Ϊ������������·��
//			dp[i][0] = dp[i - 1][0];
//		for (int j = 1; j < m; ++j)//��һ�е�·��ֻ��Ϊ����߹�����·��
//			dp[0][j] = dp[0][j-1];
//		for (int i = 1; i < n; ++i)
//			for (int j = 1; j < m; ++j)
//				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//�м��·��ֻ��Ϊ��߻�������������·��
//		return dp[n - 1][m - 1];
//	}
//};
////ʹ��һ�пռ䣬���ֻ��Ҫ������ǰ������һ�е����� 
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
