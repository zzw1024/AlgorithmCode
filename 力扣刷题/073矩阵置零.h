#include "_000库函数.h"


//先使用m*n的额外空间
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		vector<vector<int>>temp = matrix;
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
				if (temp[i][j] == 0) {
					for (int t = 0; t < matrix.size(); ++t)
						matrix[t][j] = 0;
					for (int t = 0; t < matrix[0].size(); ++t)
						matrix[i][t] = 0;
				}
	}
};

//使用m+n的额外空间，只需要记录的行和列就行
//此处可以再优化一下，不另外开辟空间，使用原矩阵的第一行和第一列来记录就行
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		vector<int>r(matrix.size(), 0);//行标记  m
		vector<int>l(matrix[0].size(), 0);//列标记  n
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
				if (matrix[i][j] == 0) {
					r[i] = 1;
					l[j] = 1;
				}

		for (int i = 0; i < matrix.size(); ++i)
			if (r[i])
				for (int j = 0; j < matrix[0].size(); ++j)
					matrix[i][j] = 0;

		for (int j = 0; j < matrix[0].size(); ++j)
			if (l[j])
				for (int i = 0; i < matrix.size(); ++i)
					matrix[i][j] = 0;
	}
					
};
void T073() {
	Solution s;
	vector<vector<int>>v;
	v = { {1,1,1}, {1,0,1},{1,1,1} };
	s.setZeroes(v);
	for (auto &a : v) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl;
	v = { {0,1,2,0}, {3,4,5,2},{1,3,1,5} };
	s.setZeroes(v);
	for (auto &a : v) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl;


}

