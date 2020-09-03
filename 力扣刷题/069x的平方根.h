
#include "_000库函数.h"

//最简单想法，耗时长
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)return x;
		double n = 0;//防止int溢出
		while (++n) {
			if (n*n > x) {
				--n;
				return (int)n;
			}
			else if (n*n == x)
				return (int)n;
		}
		return 0;//力扣非得要在这里加一个return,无语了
	}
};

//用对折法
//因为x为int，最大为65536的平方
//贼鸡儿快，内存很少
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)return x;
		double min = 1, max = 65536, mid = (int)((min + max)/2);//防止int溢出
		while (min < max&&mid*mid != x) {
			if (mid*mid < x)min = mid + 1;
			else max = mid - 1;
			mid = (int)((min + max)/2);
		}
		if (mid*mid > x)--mid;
		return (int)mid;
	}
};


//同样折半，更简洁
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1) return x;
		int left = 0, right = x;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (x / mid >= mid) left = mid + 1;
			else right = mid;
		}
		return right - 1;
	}
};

//更牛逼的方法
//用牛顿迭代法，记得高数中好像讲到过这个方法，是用逼近法求方程根的神器，
//因为要求x2 = n的解，令f(x)=x2-n，相当于求解f(x)=0的解，可以求出递推式如下：
//
//xi + 1 = xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n / xi) / 2

class Solution {
public:
	int mySqrt(int x) {
		long res = x;
		while (res * res > x) {
			res = (res + x / res) / 2;
		}
		return res;
	}
};
void T069() {
	Solution s;
	cout << "2:	" << s.mySqrt(2) << endl;
	cout << "8:	" << s.mySqrt(8) << endl;
	cout << "0:	" << s.mySqrt(0) << endl;
	cout << "9:	" << s.mySqrt(9)<<endl;
}