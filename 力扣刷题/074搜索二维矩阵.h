#include "_000�⺯��.h"


//��ĿҪ��ʹ�ø�Ч�㷨������֪���Ч�����ĸ�
//���ⷨ���Ӷ�Ϊm+n
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

//��Ȼ�����Ҳ����ʹ��һ�ζ��ֲ��ҷ���������ǰ�S�ͱ����ö�ά���飬
//���Եõ�һ�������һά���飬��ô����ֻ��Ҫ��һ�ζ��ֲ��ҷ���
//���ؼ������������ת������ΰѶ�ά�����һά����ת���ǹؼ��㣬
//��һ������Ϊn��һά����ת��Ϊm*n�Ķ�ά����(m*n = n)��
//��ôԭһά�������±�Ϊi��Ԫ�ؽ������ڶ�ά�����е�[i / n][i%n]��λ�ã�
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