#include "_000库函数.h"
//感觉有好多种爬法
//我又想到了用全排列
//又是超时，一用到全排列就超时
class Solution {
public:
	int climbStairs(int n) {
		vector<int>v(n, 1);//开始使用一节一节的爬法
		int res = 1;
		int num1 = n, num2 = 0;//一节与二节的数量
		while (1) {
			sort(v.begin(), v.end());
			while (next_permutation(v.begin(), v.end())) ++res;
			v.clear();
			num1 -= 2;
			if (num1 < 0)break;
			++num2;//两个一节用一个二节代替
			v.insert(v.end(), num1, 1);
			v.insert(v.end(), num2, 2);
			++res;
		}
		return res;
	}
};


//使用动态规划思想
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 1) return 1;
		vector<int> dp(n);
		dp[0] = 1; dp[1] = 2;
		for (int i = 2; i < n; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp.back();
	}
};


//优化点的代码
class Solution {
public:
	int climbStairs(int n) {
		int a = 1, b = 1;
		while (n--) {
			b += a;
			a = b - a;
		}
		return a;
	}
};
void T070() {
	Solution s;
	cout << "1:	" << s.climbStairs(1) << endl;
	cout << "2:	" << s.climbStairs(2) << endl;
	cout << "3:	" << s.climbStairs(3) << endl;
	cout << "5:	" << s.climbStairs(5) << endl;
}