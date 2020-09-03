#include "000�⺯��.h"



//ʹ���۰��㷨  ţ���㷨
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)return 1;
		double res = 1.0;
		for (int i = n; i != 0; i /= 2) {
			if (i % 2 != 0)
				res *= x;
			x *= x;
		}
		return n > 0 ? res : 1 / res;
	}

};


//ͬ��ʹ�ö��ַ�������ʹ�õݹ�˼��
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)return 1;
		double res = myPow(x, n / 2);
		if (n % 2 == 0)return x * x;//��ż������԰����֮��������������ˣ�x^n==(x^n/2)^2
		if (n > 0) return res * res * x;
		return res * res / x;
	}
};

void T050() {
	Solution s;
	double x;
	int n;
	x = 0.0001;
	n = 2147483647;
	cout << s.myPow(x, n) << endl;
	x = 2.1;
	n = 3;
	cout << s.myPow(x, n) << endl;
	x = 2;
	n = -2;
	cout << s.myPow(x, n) << endl;
	x = 0.9;
	n = 2147483647;
	cout << s.myPow(x, n) << endl;


}