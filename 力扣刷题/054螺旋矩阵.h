#include "_000库函数.h"


//我们定义p，q为当前环的高度和宽度，当p或者q为1时，
//表示最后一个环只有一行或者一列，可以跳出循环。
//此题的难点在于下标的转换，如何正确的转换下标是解此题的关键，
//我们可以对照着上面的3x3的例子来完成下标的填写，代码如下：
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int>res;
		if (matrix.empty() || matrix[0].empty())return res;
		int m = matrix.size(), n = matrix[0].size();
		int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
		int p = m, q = n;
		for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
			for (int col = i; col < i + q; ++col)//向右扫行
				res.push_back(matrix[i][col]);
			for (int row = i + 1; row < i + p; ++row)//向下扫列
				res.push_back(matrix[row][i + q - 1]);
			if (p == 1 || q == 1)break;
			for (int col = i + q - 2; col >= i; --col)//向左扫行
				res.push_back(matrix[i + p - 1][col]);
			for (int row = i + p - 2; row > i; --row)//向上扫列
				res.push_back(matrix[row][i]);
		}
		return res;
	}
};
	
//对于这种螺旋遍历的方法，重要的是要确定上下左右四条边的位置，
//那么初始化的时候，上边up就是0，下边down就是m - 1，左边left是0，右边right是n - 1。
//然后我们进行while循环，先遍历上边，将所有元素加入结果res，然后上边下移一位，
//如果此时上边大于下边，说明此时已经遍历完成了，直接break。同理对于下边，左边，右边，
//依次进行相对应的操作，这样就会使得坐标很有规律，并且不易出错，参见代码如下：

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int>res;
		if (matrix.empty() || matrix[1].empty())return res;
		int m = matrix.size(), n = matrix[0].size();
		int up = 0, down = m - 1, left = 0, right = n - 1;
		while (1) {
			for (int j = left; j <= right; ++j)res.push_back(matrix[up][j]);
			if (++up > down)break;
			for (int i = up; i <= down; ++i)res.push_back(matrix[i][right]);
			if (--right < left)break;
			for (int j = right; j >= left; --j)res.push_back(matrix[down][j]);
			if (--down < up)break;
			for (int i = down; i >= up; --i)res.push_back(matrix[i][left]);
			if (++left > right)break;
		}
		return res;
	}	
};



void T054() {
	Solution s;
	vector<int>v;
	vector<vector<int>>m;
	m = { {1,2,3},{4,5,6},{7,8,9} };
	v = s.spiralOrder(m);
	for (auto a : v)
		cout << a << "  ";
	cout << endl;
	m = { {1} };
	v = s.spiralOrder(m);
	for (auto a : v)
		cout << a << "  ";
	cout << endl;
	
}