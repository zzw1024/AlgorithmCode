#include "000�⺯��.h"

//��λ�ù���
//�Ȳ����չ���ʹ����һ������
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		vector < vector<int>>v = matrix;
		int n = matrix.size();
		for (int t = 0; t < 1; ++t) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					matrix[j][n - 1 - i] = v[i][j];
				}
			}
		}
	}
};

//1  2  3                 7  2  1                  7  4  1
//
//4  5  6      -- >		  4  5  6���� -- >		   8  5  2
//
//7  8  9                 9  8  3����������		   9  6  3
//

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		for (int i = 0; i < n / 2; ++i) {
			for (int j = i; j < n - 1 - i; ++j) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = tmp;
			}
		}
	}
};

//����һ�ֽⷨ�������ԴӶԽ���Ϊ�ᷭת��Ȼ������x���������·�ת���ɵõ����������ͼ��ʾ(������ɫ���ֱ�ʾ��ת��)��
//
//1  2  3������ ���� 9  6  3����������  7  4  1
//
//4  5  6����-- >    8  5  2���� -- >   8  5  2
//
//7  8  9 ������ ����7  4  1����������  9  6  3

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < n - i; ++j) {
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
			}
		}
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < n; ++j) {
				swap(matrix[i][j], matrix[n - 1 - i][j]);
			}
		}
	}
};

//���������һ�ַ��������ַ������ȶ�ԭ����ȡ��ת�þ���Ȼ���ÿ�е����ַ�ת�ɵõ������������ʾ(������ɫ���ֱ�ʾ��ת��)��
//
//1  2  3������ ���� 1  4  7����������  7  4  1
//
//4  5  6����-- >     2  5  8���� -- >   8  5  2
//
//7  8  9 ������ ����3  6  9��������     9  6  3


class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				swap(matrix[i][j], matrix[j][i]);
			}
			reverse(matrix[i].begin(), matrix[i].end());
		}
	}
};
void T048() {
	Solution s;
	vector < vector<int>>n;
	n = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	cout << "ԭ����" << endl;
	for (auto &a : n) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << "��ת֮��" << endl;
	s.rotate(n);
	for (auto &a : n) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	
}