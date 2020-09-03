#include "_000库函数.h"

//与上题螺旋矩阵输出数组一样
//一个时输出，一个是输入
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>>res(n, vector<int>(n, 0));
		int u = 0, d = n - 1, l = 0, r = n - 1;
		int num = 1;
		while (num <= n * n) {
			for (int j = l; j <= r; ++j)res[u][j] = num++;//左向右行
			if (++u > d)break;
			for (int i = u; i <= d; ++i)res[i][r] = num++;//上向下列
			if (--r < l)break;
			for (int j = r; j >= l; --j)res[d][j] = num++;//右向左行
			if (--d < u)break;
			for (int i = d; i >= u; --i)res[i][l] = num++;//下向上列
			if (++l > r)break;
		}
		return res;

	}
};

void T059() {
	vector<vector<int>>res;
	Solution s;
	res = s.generateMatrix(3);
	for (auto &a : res) {
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	cout << "*****************" << endl;

	res = s.generateMatrix(4);
	for (auto &a : res) {
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	cout << "*****************" << endl;


}