//#include "000�⺯��.h"
//
//
////ʹ��λ����
//class Solution {
//public:
//	int divide(int dividend, int divisor) {
//		if (dividend == INT32_MIN && divisor == -1)return INT32_MAX;//�������
//		int sign = (dividend < 0) ^ (divisor < 0);
//		long m = labs(dividend), n = labs(divisor), res = 0;//�мǴ˴��������������
//		if (n == 1)return sign ? -m : m;
//		while (m >= n)
//		{
//			long p = n, k = 1;
//			while (m >= (p << 1))//�����ıȽ�
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