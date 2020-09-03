#pragma once
#include "000库函数.h"
/******************自解***********************/
//虽然很快通过，但不满足题中不允许使用除法的要求   36ms
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0)return 0;
		double i = (double)dividend / (double)divisor;
		if ((i < -1 * pow(2, 31)) || (i > pow(2, 31) - 1))return pow(2, 31) - 1;
		else return (int)i;
	}
};
//超出时长
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0)return 0;
		int flag = 1;
		double k = (double)dividend;
		if (k < 0) {
			k *= -1;//防止此处溢出
			flag *= -1;
		}
		double t = (double)divisor;
		if (t < 0) {
			t *= -1;
			flag *= -1;
		}
		double i= 0;
		double n = t;
		while (k >= t+t) {
			i += 2;
			t += n;
			k -= n;

		}
		if (k >= t)
			++i;
		i *= flag;
		if ((i < -1 * pow(2, 31)) || (i > pow(2, 31) - 1))return pow(2, 31) - 1;
		else return (int)i;
	}
};
/*********************博客答案***************************/
//采用移位运算  36ms
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
		long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		if (n == 1) return sign == 1 ? m : -m;
		while (m >= n) {
			long long t = n, p = 1;
			while (m >= (t << 1)) {
				t <<= 1;
				p <<= 1;
			}
			res += p;
			m -= t;
		}
		return sign == 1 ? res : -res;
	}
};

class Solution {
public:
	int divide(int dividend, int divisor) {
		long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
		if (m < n) return 0;
		while (m >= n) {
			long long t = n, p = 1;
			while (m > (t << 1)) {
				t <<= 1;
				p <<= 1;
			}
			res += p;
			m -= t;
		}
		if ((dividend < 0) ^ (divisor < 0)) res = -res;
		return res > INT_MAX ? INT_MAX : res;
	}
};
//使用递归  36ms
class Solution {
public:
	int divide(int dividend, int divisor) {
		long long res = 0;
		long long m = abs((long long)dividend), n = abs((long long)divisor);
		if (m < n) return 0;
		long long t = n, p = 1;
		while (m > (t << 1)) {
			t <<= 1;
			p <<= 1;
		}
		res += p + divide(m - t, n);
		if ((dividend < 0) ^ (divisor < 0)) res = -res;
		return res > INT_MAX ? INT_MAX : res;
	}
};


void T029() {
	Solution s;
	cout << s.divide(10, 3) << endl;
	cout << s.divide(7, -3) << endl;
}