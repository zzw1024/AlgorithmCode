//
//#include "head.h"
//
//class Solution01 {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		if (array.size() == 0)return 0;
//		int sum = 0, maxS = array[0];
//		for (int i = 0; i < array.size(); ++i)
//		{
//			if (sum < 0)//sum累加和为负的，还不如从我自己加起
//				sum = array[i];
//			else
//				sum += array[i];
//			maxS = maxS > sum ? maxS : sum;
//		}
//		return maxS;
//	}
//};
//
//class Solution02 {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		if (array.size() == 0)return 0;
//		vector<int>dp(array.size(), 0);
//		dp[0] = array[0];
//		for (int i = 1; i < array.size(); ++i)
//			dp[i] = max(array[i], array[i] + dp[i - 1]);//加上前面数字的和会不会使和变大
//		return dp.back();
//	}
//};