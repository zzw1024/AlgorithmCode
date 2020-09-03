

#include "000�⺯��.h"

//ʹ�û��ݷ�
class Solution {
public:
	int totalNQueens(int n) {
		int res = 0;
		vector<int>x(n, -1);//���
		NQueue(x, res, 0);
		return res;
	}

	void NQueue(vector<int>&x, int &num, int row) {
		int n = x.size();
		if (n == row)
			num++;
		for (int col = 0; col < n; ++col) 
			if (Danger(x, row, col)) {
				x[row] = col;
				NQueue(x, num, row + 1);
				x[row] = -1;//����
			}		
	}

	bool Danger(vector<int>x, int row, int col) {
		for (int i = 0; i < row; ++i)
			if (col == x[i] || abs(row - i) == abs(x[i] - col))
				//������б��
				return false;
		return true;
	}
};

void T052() {
	Solution s;
	cout << s.totalNQueens(4) << endl;
	cout << s.totalNQueens(8) << endl;
}