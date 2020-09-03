#include "_000�⺯��.h"


// ��һ�뷨���ǵ��������������
// ������ʼ���飬����Ϊ1������Ϊ2
// �������У�������ʱ��������
class solution {
public:
	int uniquepaths(int m, int n) {
		vector<int>v(m-1,1);//m-1������
		v.insert(v.end(), n - 1, 2);//n-1������
		int nums = 1;
		while (next_permutation(v.begin(), v.end()))nums++;
		return nums;
	}
};

//�������ͺ󣬲ŷ��֣����ظ����ֵ�ȫ������������ǽ�С������ȡ����Ŀ
class solution {
public:
	int uniquepaths(int m, int n) {
		int min = m > n ? n : m;
		double res = 1, denom = 1;
		for (int i = 1; i <= min - 1; ++i) {
			res *= m + n - 1 - i;
			denom *= i;
		}
		return (int) (res / denom);
	}
};

//�õݹ鲻֪���᲻���һ��
// ��ʱ��

class solution {
public:
	int uniquepaths(int m, int n) {
		return combin(1, 1, m, n);
	}
	int combin(int row, int col, int m, int n) {
		if (row == m && col == n)//�������½�
			return 1;
		if (row > m || col > n)//������Ҫ��
			return 0;
		return combin(row + 1, col, m, n) + combin(row, col + 1, m, n);
	}

};

//ʹ�ö�̬�滮
//��ô������������һ����������Ҫ�ö�̬�滮Dynamic Programming���⣬
//���ǿ���ά��һ����ά����dp������dp[i][j]��ʾ����ǰλ�ò�ͬ���߷��ĸ�����
//Ȼ����Եõ�����ʽΪ: dp[i][j] = dp[i - 1][j] + dp[i][j - 1]��
//����Ϊ�˽�ʡ�ռ䣬����ʹ��һά����dp��һ��һ�е�ˢ��Ҳ���ԣ��������£�
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> dp(n, 1);
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				dp[j] += dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};

void T062() {
	Solution s;
	cout << s.uniquePaths(7, 3) << endl;
}