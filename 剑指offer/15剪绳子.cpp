//#include "head.h"
//
//
//class Solution {
//public:
//	int cutRope(int number) {
//		if (number <= 1)return 0;
//		if (number < 5)return (number / 2)*(number - number / 2);//��Ϊ����Ҫ��Ϊ2��
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
//		if (number < 5)return (number / 2)*(number - number / 2);//��Ϊ����Ҫ��Ϊ2��
//		int n3 = number / 3;//3�ĸ���
//		if (number % 3 == 1)//������һ��Ϊ4ʱ����Ҫ����3-1��Ҫ����2-2
//			n3--;
//		int n2 = (number - 3 * n3) / 2;//2�ĸ���
//		return pow(3, n3)*pow(2, n2);
//	}
//};
//
//
