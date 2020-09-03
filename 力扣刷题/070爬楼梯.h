#include "_000�⺯��.h"
//�о��кö�������
//�����뵽����ȫ����
//���ǳ�ʱ��һ�õ�ȫ���оͳ�ʱ
class Solution {
public:
	int climbStairs(int n) {
		vector<int>v(n, 1);//��ʼʹ��һ��һ�ڵ�����
		int res = 1;
		int num1 = n, num2 = 0;//һ������ڵ�����
		while (1) {
			sort(v.begin(), v.end());
			while (next_permutation(v.begin(), v.end())) ++res;
			v.clear();
			num1 -= 2;
			if (num1 < 0)break;
			++num2;//����һ����һ�����ڴ���
			v.insert(v.end(), num1, 1);
			v.insert(v.end(), num2, 2);
			++res;
		}
		return res;
	}
};


//ʹ�ö�̬�滮˼��
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 1) return 1;
		vector<int> dp(n);
		dp[0] = 1; dp[1] = 2;
		for (int i = 2; i < n; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp.back();
	}
};


//�Ż���Ĵ���
class Solution {
public:
	int climbStairs(int n) {
		int a = 1, b = 1;
		while (n--) {
			b += a;
			a = b - a;
		}
		return a;
	}
};
void T070() {
	Solution s;
	cout << "1:	" << s.climbStairs(1) << endl;
	cout << "2:	" << s.climbStairs(2) << endl;
	cout << "3:	" << s.climbStairs(3) << endl;
	cout << "5:	" << s.climbStairs(5) << endl;
}