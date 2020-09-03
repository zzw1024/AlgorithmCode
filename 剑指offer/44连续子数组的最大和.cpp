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
//			if (sum < 0)//sum�ۼӺ�Ϊ���ģ�����������Լ�����
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
//			dp[i] = max(array[i], array[i] + dp[i - 1]);//����ǰ�����ֵĺͻ᲻��ʹ�ͱ��
//		return dp.back();
//	}
//};