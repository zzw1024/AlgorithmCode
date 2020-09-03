#include "_000库函数.h"


// 第一想法就是当成排列组合来做
// 产生初始数组，向右为1，向下为2
// 方案可行，但超出时间限制了
class solution {
public:
	int uniquepaths(int m, int n) {
		vector<int>v(m-1,1);//m-1个向右
		v.insert(v.end(), n - 1, 2);//n-1个向下
		int nums = 1;
		while (next_permutation(v.begin(), v.end()))nums++;
		return nums;
	}
};

//看过博客后，才发现，带重复数字的全排列组合数就是较小的数的取法数目
class solution {
public:
	int uniquepaths(int m, int n) {
		int min = m > n ? n : m;
		double res = 1, denom = 1;
		for (int i = 1; i <= min - 1; ++i) {
			res *= m + n - 1 - i;
			denom *= i;
		}
		return (int) (res / denom);
	}
};

//用递归不知道会不会快一点
// 超时了

class solution {
public:
	int uniquepaths(int m, int n) {
		return combin(1, 1, m, n);
	}
	int combin(int row, int col, int m, int n) {
		if (row == m && col == n)//到达右下角
			return 1;
		if (row > m || col > n)//不满足要求
			return 0;
		return combin(row + 1, col, m, n) + combin(row, col + 1, m, n);
	}

};

//使用动态规划
//那么跟爬梯子问题一样，我们需要用动态规划Dynamic Programming来解，
//我们可以维护一个二维数组dp，其中dp[i][j]表示到当前位置不同的走法的个数，
//然后可以得到递推式为: dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，
//这里为了节省空间，我们使用一维数组dp，一行一行的刷新也可以，代码如下：
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> dp(n, 1);
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				dp[j] += dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};

void T062() {
	Solution s;
	cout << s.uniquePaths(7, 3) << endl;
}