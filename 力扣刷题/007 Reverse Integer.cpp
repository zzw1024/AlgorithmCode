//#include"000库函数.h"
//
//翻转一个带字符整数
//最高数值为【-2^31 - 2^31-1】32位系统
//int reverse(int x) {
//	int rev = 0;
//	while (x != 0) {
//		int pop = x % 10;
//		x /= 10;
//		if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
//		if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
//		rev = rev * 10 + pop;
//	}
//	return rev;
//}
////上面解答为答案，以下为自己答案
//int reverse(int x) {
//	double rev = 0;
//	int pop;
//	while (x != 0) {
//		pop = x % 10;
//		x /= 10;
//		rev = rev * 10 + pop;
//	}
//	if (rev > (pow(2, 31) - 1) || rev < (-1 * pow(2, 31))) {
//		return 0;
//	}
//	else {
//		int a = (int)rev;
//		return a;
//	}
//}