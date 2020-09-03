#include "_000�⺯��.h"


//��ʹ��m*n�Ķ���ռ�
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

//ʹ��m+n�Ķ���ռ䣬ֻ��Ҫ��¼���к��о���
//�˴��������Ż�һ�£������⿪�ٿռ䣬ʹ��ԭ����ĵ�һ�к͵�һ������¼����
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		vector<int>r(matrix.size(), 0);//�б��  m
		vector<int>l(matrix[0].size(), 0);//�б��  n
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

