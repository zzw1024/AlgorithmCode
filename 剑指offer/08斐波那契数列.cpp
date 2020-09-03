//#include "head.h"
//
//class Solution01 {
//public:
//	int Fibonacci(int n) {
//		int a = 0, b = 1, c;
//		for (int i = 2; i <= n; ++i)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		return n == 0 ? 0 : b;
//	}
//};
//
//class Solution02 {
//public:
//	int Fibonacci(int n) {
//		if (n <= 1)
//			return n;
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//};
//
//class Solution03 {
//public:
//	int Fibonacci(int n) {
//		if (n <= 1)
//			return n;
//		vector<int>dp(n + 1);
//		dp[0] = 0, dp[1] = 1;
//		for (int i = 2; i <= n; ++i)
//			dp[i] = dp[i - 1] + dp[i - 2];
//		return dp[n];
//	}
//};
//
