//#include "head.h"
//
//class Solution01 {
//public:
//	double Power(double base, int exponent) {
//		if (exponent == 0 || equal(base, 0.0, 0.0))return 1;
//		double res = 1.0;
//		for (int i = 1; i <= abs(exponent); ++i)
//			res *= base;
//		return exponent < 0 ? (1.0 / res) : res;
//	}
//};
//
//
//class Solution02 {
//public:
//	double Power(double base, int exponent) {
//		if (exponent == 0 || equal(base, 0.0, 0.0))return 1;
//		double res = PowerMul(base, abs(exponent));
//		return exponent < 0 ? (1.0 / res) : res;
//	}
//	double PowerMul(double base, unsigned int exponent)
//	{
//		if (exponent == 0)return 1;
//		if (exponent == 1)return base;
//
//		double res = PowerMul(base, exponent >> 1);
//		res *= res;
//		if (exponent & 1)//ÆæÊý
//			res *= base;
//		return res;
//	}
//};