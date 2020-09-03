//#include "head.h"
//
//class Solution01 {
//public:
//    int rectCover(int number) {
//		if(number<=2)return number<0?0:number;
//		return rectCover(number-1)+rectCover(number-2);
//    }
//};
//
//
//class Solution02 {
//public:
//    int rectCover(int number) {
//		if (number <= 2)return number < 0 ? 0 : number;
//		vector<int> dp(number + 1, 0);
//		dp[1] = 1; dp[2] = 2;
//		for (int i = 3; i <= number; ++i)
//			dp[i] = dp[i - 1] + dp[i - 2];
//		return dp[number];
//    }
//};