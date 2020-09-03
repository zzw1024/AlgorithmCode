#include "000�⺯��.h"

//һ����û���ʲô�÷��ӣ��ͱ�����
//����Ҫ������αȽ�С�Ź��������
//44ms
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')continue;
				for (int k = 8; k > j; --k)
					if (board[i][j] == board[i][k])return false;//�Ƚ���		
				for (int k = 8; k > i; --k)
					if (board[i][j] == board[k][j])return false;//�Ƚ���
				for (int k = i + 1; k % 3 != 0; k++) //�ȽϾŹ���
					for (int h = j / 3 * 3; h < j / 3 * 3 + 3; h++)
						if (board[i][j] == board[k][h])
							return false;
			}
		return true;
	}
};


//���ʹ�
//ʹ����������������ѭ��������������������ڴ�ռ� 
//36ms
class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		vector<vector<bool> > rowFlag(9, vector<bool>(9, false));//9*9��������е�
		vector<vector<bool> > colFlag(9, vector<bool>(9, false));//9*9��������е�
		vector<vector<bool> > cellFlag(9, vector<bool>(9, false));//9*9������ǾŹ��񡾹���9����
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') continue;
				int c = board[i][j] - '1';
				if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) return false;
				//����л��л�Ź��Ѿ�����ǹ���������ظ�
				rowFlag[i][c] = true;//���б��
				colFlag[c][j] = true;
				cellFlag[3 * (i / 3) + j / 3][c] = true;//��õľ��������ж��ĸ��Ź����λ�ã�һֱ�����Ų�����һ���ط�
				
			}
		}
		return true;
	}
};

void T036() {

	vector<vector<char>> board;
	board = { {'.','.','5'},{'3','.','.'},{'.','.','3'} };
	Solution s;
	cout << s.isValidSudoku(board) << endl;

		

				
	

}