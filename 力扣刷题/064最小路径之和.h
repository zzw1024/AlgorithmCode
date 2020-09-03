#include "_000�⺯��.h"

//ʹ��Dijkstra�㷨
//����̬�滮
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();	int n = grid[0].size();
		vector<vector<int>>dp(m, vector<int>(n,0));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; ++i)dp[i][0] = grid[i][0] + dp[i - 1][0];
		for (int i = 1; i < n; ++i)dp[0][i] = grid[0][i] + dp[0][i - 1];
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);

		return dp[m - 1][n - 1];
	}
};

void T064() {
	vector<vector<int>>v;
	v = { {1,3,1},{1,5,1},{4,2,1} };
	Solution s;
	cout << s.minPathSum(v) << endl;
}
