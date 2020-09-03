#include "000�⺯��.h"

//�Խ�ʧ��
//class Solution {
//public:
//	void solveSudoku(vector<vector<char>>& board) {
//		int row[9][10];
//		int col[9][10];
//		int cell[9][10];
//		for (int i = 0; i < 9; ++i)
//			for (int j = 0; j < 10; ++j) {
//				row[i][j] = j;
//				col[i][j] = j;
//				cell[i][j] = j;
//			}
//
//		for (int i = 0; i < 9; ++i) {
//			for (int j = 0; j < 9; ++j) {
//				if (board[i][j] != '.') {
//					int c = board[i][j] - '0';
//					row[i][c] = 0;
//					col[j][c] = 0;
//					cell[3 * (i / 3) + j / 3][c] = 0;
//				}
//			}
//		}
//
//		for (int i = 0; i < 9; ++i) {
//			for (int j = 0; j < 9; ++j) {
//				if (board[i][j] == '.') {
//					for (int t = 0; t < 10; ++t) {
//						if (row[i][t] != 0) {
//							int a = row[i][t];
//							if (col[j][a] != 0 && cell[3 * (i / 3) + j / 3][a] != 0) {
//								board[i][j] = a + '0';
//								row[i][t] = 0;
//								col[j][a] = 0;
//								cell[3 * (i / 3) + j / 3][a] = 0;
//								break;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//};

//���������Ƶ��� Permutations ȫ���У�Combinations ���� N - Queens N�ʺ�����ȵȣ�
//���������Ǹ� N - Queens N�ʺ�����Ľ���˼·�������ƣ�����ÿ����Ҫ�����ֵĸ��Ӵ���1��9��
//ÿ����һ�����ֶ��ж����Ƿ�Ϸ�������Ϸ��ͼ�����һ�εݹ飬����ʱ���������'.'��
//�ж��¼���������Ƿ�Ϸ�ʱ��ֻ��Ҫ�ж���ǰ�����Ƿ�Ϸ�������Ҫ�ж���������Ƿ�Ϊ�������飬
//��Ϊ֮ǰ�ӽ������ֶ��ǺϷ��ģ���������ʹ������Ӹ�ЧһЩ������ʵ���������ʾ��
//��8�ʺ����⼰�����ƣ��û��ݷ���֤���Ƿ���Ч
//
class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
		solveSudokuDFS(board, 0, 0);
	}

	bool solveSudokuDFS(vector<vector<char> > &board, int i, int j) {
		if (i == 9) return true;
		if (j >= 9) return solveSudokuDFS(board, i + 1, 0);
		if (board[i][j] == '.') {
			for (int k = 1; k <= 9; ++k) {
				board[i][j] = (char)(k + '0');//�Ž�ȥ����
				if (isValid(board, i, j)) {
					if (solveSudokuDFS(board, i, j + 1)) return true;
				}
				board[i][j] = '.';
			}
		}
		else {
			return solveSudokuDFS(board, i, j + 1);//��һλ���ҵ��հ�λ��
		}
		return false;
	}

	bool isValid(vector<vector<char> > &board, int i, int j) {
		for (int col = 0; col < 9; ++col) {//�бȽ�
			if (col != j && board[i][j] == board[i][col]) return false;
		}
		for (int row = 0; row < 9; ++row) {//�бȽ�
			if (row != i && board[i][j] == board[row][j]) return false;
		}
		for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row) {
			for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) {
				if ((row != i || col != j) && board[i][j] == board[row][col]) return false;//С�Ź���Ƚ�
			}
		}
		return true;
	}
};

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		//��¼ĳ�У�ĳλ�����Ƿ񱻰ڷ�
		vector<vector<int>> row;
		row.resize(9, vector<int>(10, 0));
		vector<vector<int>> col;//��¼ĳ�У�ĳλ�����Ƿ񱻰ڷ�
		col.resize(9, vector<int>(10, 0));
		vector<vector<int>> block;//��¼ĳ�飬ĳλ�����Ƿ񱻰ڷ�
		block.resize(9, vector<int>(10, 0));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0';
					row[i][num] = 1;
					col[j][num] = 1;
					block[i / 3 * 3 + j / 3][num] = 1;
				}
			}
		}
		dfs(board, row, col, block, 0, 0);
	}

	bool dfs(vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& block, int i, int j)
	{
		while (board[i][j] != '.') {
			if (++j >= 9) {
				i++; j = 0; //��һ��
			}
			if (i >= 9) return true; //��������
		}
		for (int num = 1; num <= 9; num++) {
			int blockIndex = i / 3 * 3 + j / 3;
			if (!row[i][num] && !col[j][num] && !block[blockIndex][num])//δ��д����
			{
				board[i][j] = (char)('0' + num);//д������
				row[i][num] = 1;
				col[j][num] = 1;
				block[blockIndex][num] = 1;
				if (dfs(board, row, col, block, i, j)) {
					return true;
				}
				else {
					row[i][num] = 0;
					col[j][num] = 0;
					block[blockIndex][num] = 0;
					board[i][j] = '.';
				}


			}
		}
		return false;
	}
};


void T037() {
	vector<vector<char>>board = {
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}
	};
	Solution s;
	s.solveSudoku(board);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j)
			cout << board[i][j] << "   ";
		cout << endl;
	}
	cout << endl;
}






		


