//#include "000库函数.h"
//
//
////使用位运算
//class Solution {
//public:
//	int divide(int dividend, int divisor) {
//		if (dividend == INT32_MIN && divisor == -1)return INT32_MAX;//会溢出的
//		int sign = (dividend < 0) ^ (divisor < 0);
//		long m = labs(dividend), n = labs(divisor), res = 0;//切记此处容易溢出！！！
//		if (n == 1)return sign ? -m : m;
//		while (m >= n)
//		{
//			long p = n, k = 1;
//			while (m >= (p << 1))//翻倍的比较
//			{
//				p <<= 1;
//				k <<= 1;
//			}
//			res += k;
//			m -= p;
//		}
//		return sign ? -res : res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.divide(10, 3) << endl;
//	cout << s.divide(-10, -3) << endl;
//	cout << s.divide(-10, 3) << endl;
//	cout << s.divide(10, -3) << endl;
//	return 0;
//}