//#include "head.h"
//
//
//class Solution {
//public:
//	int NumberOf1Between1AndN_Solution(int n)
//	{
//		if (n <= 0)return 0;
//		int  left = 0, right = 0, a = 1, now = 1, ans = 0;
//		while (n / a) {
//			left = n / (a * 10), now = n / a % 10, right = n % a;
//			if (now == 0) ans += left * a;
//			else if (now == 1) ans += left * a + right + 1;
//			else ans += (left + 1) * a; 
//			a = a * 10;
//		}
//		return ans;
//	}
//};
