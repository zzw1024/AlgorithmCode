#include "_000库函数.h"


//竟然通过了，我还以为会挂了
//使用左上角指针和右下角指针组成矩阵的左上角和右下角
//["1",     "0",    "1",    "0",   "0"],
//
//["1",     "0",    "1",    "1",   "1"],
//                   start->             //左上角从每行最左d端开始遍历
//["1",     "1",    "1",    "1",   "1"],
//                   end->               //右下角从start 的列开始每行遍历
//["1",     "0",    "0",    "1",   "0"]
//为了避免将0包进去，用minPot记录离start最近的0列，则右侧不用再遍历

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int res = 0;
		for (int i = 0; i < matrix.size(); ++i) {//左上角遍历的行
			for (int start = 0; start < matrix[0].size(); ++start) {//左上角从每行的最左端开始遍历
				if (matrix[i][start] == '0')continue;
				int minRight = matrix[0].size();//记录右下角的位置，防止矩阵将0包含进去
				for (int j = i; j < matrix.size(); ++j) {//右右下角的遍历行
					for (int end = start; end < minRight; ++end) {//右下角从左上角的列开始遍历
						if (matrix[j][end] == '0') {
							minRight = minRight > end ? end : minRight;
							break;
						}
						res = res > ((end - start + 1)*(j - i + 1)) ? res : ((end - start + 1)*(j - i + 1));
					}
				}
			}
		}
		return res;
	}
};

//这道题的二维矩阵每一层向上都可以看做一个直方图，输入矩阵有多少行，就可以形成多少个直方图
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int res = 0, m = matrix.size(), n = matrix[0].size();
		vector<int> height(n + 1, 0);
		for (int i = 0; i < m; ++i) {
			stack<int> s;
			for (int j = 0; j < n + 1; ++j) {
				if (j < n) {
					height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
				}
				while (!s.empty() && height[s.top()] >= height[j]) {
					int cur = s.top(); s.pop();
					res = max(res, height[cur] * (s.empty() ? j : (j - s.top() - 1)));
				}
				s.push(j);
			}
		}
		return res;
	}
};

//下面这种方法的思路很巧妙，height数组和上面一样，
//这里的left数组表示左边界是1的位置，right数组表示右边界是1的位置，
//那么对于任意一行的第j个位置，矩形为(right[j] - left[j]) * height[j]，
//我们举个例子来说明，比如给定矩阵为：
//[
//	[1, 1, 0, 0, 1],
//	[0, 1, 0, 0, 1],
//	[0, 0, 1, 1, 1],
//	[0, 0, 1, 1, 1],
//	[0, 0, 0, 0, 1]
//]
//第0行：
//
//h : 1 1 0 0 1
//	l : 0 0 0 0 4
//	r : 2 2 5 5 5
//
//
//	第1行：
//
//	h : 1 1 0 0 1
//	l : 0 0 0 0 4
//	r : 2 2 5 5 5
//
//
//	第2行：
//
//	h : 0 0 1 1 3
//	l : 0 0 2 2 4
//	r : 5 5 5 5 5
//
//
//	第3行：
//
//	h : 0 0 2 2 4
//	l : 0 0 2 2 4
//	r : 5 5 5 5 5
//
//
//	第4行：
//
//	h : 0 0 0 0 5
//	l : 0 0 0 0 4
//	r : 5 5 5 5 5

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int res = 0, m = matrix.size(), n = matrix[0].size();
		vector<int> height(n, 0), left(n, 0), right(n, n);
		for (int i = 0; i < m; ++i) {
			int cur_left = 0, cur_right = n;
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1') {
					++height[j];
					left[j] = max(left[j], cur_left);
				}
				else {
					height[j] = 0;
					left[j] = 0;
					cur_left = j + 1;
				}
			}
			for (int j = n - 1; j >= 0; --j) {
				if (matrix[i][j] == '1') {
					right[j] = min(right[j], cur_right);
				}
				else {
					right[j] = n;
					cur_right = j;
				}
				res = max(res, (right[j] - left[j]) * height[j]);
			}
		}
		return res;
	}
};

void T085() {
	Solution s;
	vector<vector<char>>v;
	v = {
	  {'1','0','1','0','0'},
	  {'1','0','1','1','1'},
	  {'1','1','1','1','1'},
	  {'1','0','0','1','0'}
	};
	cout << s.maximalRectangle(v) << endl;

}