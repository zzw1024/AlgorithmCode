
#include "_000�⺯��.h"

//����뷨����ʱ��
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)return x;
		double n = 0;//��ֹint���
		while (++n) {
			if (n*n > x) {
				--n;
				return (int)n;
			}
			else if (n*n == x)
				return (int)n;
		}
		return 0;//���۷ǵ�Ҫ�������һ��return,������
	}
};

//�ö��۷�
//��ΪxΪint�����Ϊ65536��ƽ��
//�������죬�ڴ����
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)return x;
		double min = 1, max = 65536, mid = (int)((min + max)/2);//��ֹint���
		while (min < max&&mid*mid != x) {
			if (mid*mid < x)min = mid + 1;
			else max = mid - 1;
			mid = (int)((min + max)/2);
		}
		if (mid*mid > x)--mid;
		return (int)mid;
	}
};


//ͬ���۰룬�����
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

//��ţ�Ƶķ���
//��ţ�ٵ��������ǵø����к��񽲵���������������ñƽ����󷽳̸���������
//��ΪҪ��x2 = n�Ľ⣬��f(x)=x2-n���൱�����f(x)=0�Ľ⣬�����������ʽ���£�
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