#include "_000库函数.h"


//题目要求使用高效算法，但不知最高效的是哪个
//本解法复杂度为m+n
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())return false;
		int m = matrix.size();
		int n = matrix[0].size();
		if (target< matrix[0][0] || target>matrix[m - 1][n - 1])return false;
		for (int i = 0; i < m; ++i)
			if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
				for (int j = 0; j < n; ++j)
					if (target == matrix[i][j])return true;
				return false;
			}
		return false;
	}
};

//当然这道题也可以使用一次二分查找法，如果我们按S型遍历该二维数组，
//可以得到一个有序的一维数组，那么我们只需要用一次二分查找法，
//而关键就在于坐标的转换，如何把二维坐标和一维坐标转换是关键点，
//把一个长度为n的一维数组转化为m*n的二维数组(m*n = n)后，
//那么原一维数组中下标为i的元素将出现在二维数组中的[i / n][i%n]的位置，
//

// One binary search
class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		if (target < matrix[0][0] || target > matrix.back().back()) return false;
		int m = matrix.size(), n = matrix[0].size();
		int left = 0, right = m * n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (matrix[mid / n][mid % n] == target) return true;
			else if (matrix[mid / n][mid % n] < target) left = mid + 1;
			else right = mid - 1;
		}
		return false;
	}
};

void T074() {
	Solution s;
	vector<vector<int>>v;
	v = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
	cout << s.searchMatrix(v, 3) << endl;
	cout << s.searchMatrix(v, 13) << endl;


}