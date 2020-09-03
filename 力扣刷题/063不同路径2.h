#include "_000�⺯��.h"


//�����ö�̬�滮Dynamic Programming���⣬����ʹ��һ����ά��dp���飬��СΪ(m + 1) x(n + 1)��
//�����dp[i][j] ��ʾ����(i - 1, j - 1) λ�õĲ�ͬ·��������,
//��ôi��j��Ҫ���µķ�Χ����[1, m] ��[1, n]��״̬ת�Ʒ��̸�֮ǰ�ǵ�����һ���ģ�
//��Ϊÿ��λ��ֻ����������������λ���ƶ�����,
//����Ҳ�������������ߵ�dpֵ��������µ�ǰ��dpֵ������
//
//dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
//
//������ܿ��������ǳ�ʼ��dp����Ĵ�СΪ(m + 1) x(n + 1)��
//��Ϊ��handle��Ե�������i��jΪ0ʱ����1���ܻ����
//��ĳ��λ�����ϰ���ʱ����dpֵΪ0������ֱ��������λ�ü��ɡ�
//���ǻ���Ҫ��ʼ��dp�����ĳ��ֵ��ʹ�����������ۼӡ�����㲻���ϰ���ʱ��
//��dpֵӦ��Ϊֵ����dp[1][1] = 1������������ dp[0][1] + dp[1][0] ���¶�����
//���Զ���������һ����ʼ��Ϊ1���ɡ�����֮��LeetCode������������test case��
//ʹ��ʹ��int�͵�dp�����������Ĵ����������Ǹ�Ϊʹ��long�͵�����������overflow���������£�

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
		dp[0][1] = 1;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (obstacleGrid[i - 1][j - 1] != 0) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m][n];
	}
};

void T063() {
	Solution s;
	vector<vector<int>>v;
	v = { {0, 0, 0},
		  {0, 1, 0},
		  {0, 0, 0} };
	cout << s.uniquePathsWithObstacles(v) << endl;
}