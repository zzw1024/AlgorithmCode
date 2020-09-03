//
//
////水题咯
//bool isPalindrome(int x) {
//	if (x == 0)return true;
//	if (x < 0 || (x % 10 == 0))return false;//负数和尾数为0都不是回文数字
//	double num = 0;
//	int s = x;
//	while (x > 0) {
//		num = 10 * num + x % 10;
//		x = x / 10;
//	}
//	if (num == s)return true;
//	else return false;
//}