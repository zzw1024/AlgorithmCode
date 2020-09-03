//#include "head.h"
//
//
//class Solution {
//public:
//	int cutRope(int number) {
//		if (number <= 1)return 0;
//		if (number < 5)return (number / 2)*(number - number / 2);//因为至少要分为2段
//		vector<int>dp(number + 1, 0);
//		dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3;
//		int maxN = 0;
//		for (int i = 4; i <= number; ++i)
//		{
//			maxN = 0;
//			for (int j = 1; j <= i / 2; ++j)
//			{
//				int temp = dp[j] * dp[i - j];
//				maxN = maxN > temp ? maxN : temp;
//				dp[i] = maxN;
//			}
//		}
//		return dp[number];
//	}
//};
//
//class Solution {
//public:
//	int cutRope(int number) {
//		if (number <= 1)return 0;
//		if (number < 5)return (number / 2)*(number - number / 2);//因为至少要分为2段
//		int n3 = number / 3;//3的个数
//		if (number % 3 == 1)//最后剪的一段为4时，不要剪成3-1，要剪成2-2
//			n3--;
//		int n2 = (number - 3 * n3) / 2;//2的个数
//		return pow(3, n3)*pow(2, n2);
//	}
//};
//
//
