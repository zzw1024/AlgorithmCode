#include "_000库函数.h"


//使用动态规划思想

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0')return 0;
		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;
		for (int i = 1; i < dp.size(); ++i) {
			if (s[i - 1] != '0') dp[i] += dp[i - 1];//防止一位"0"出现
			if (i >= 2 && s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10") {//防止出现“01”这种组合
				dp[i] += dp[i - 2];
			}
		}
		return dp.back();
	}
};

	//另一种解法
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;
		int c1 = 1, c2 = 1;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == '0') c1 = 0;
			if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
				c1 = c1 + c2;
				c2 = c1 - c2;
			}
			else {
				c2 = c1;
			}
		}
		return c1;
	}
};


