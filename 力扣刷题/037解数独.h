#include "000库函数.h"

//自解失败
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

//跟此题类似的有 Permutations 全排列，Combinations 组合项， N - Queens N皇后问题等等，
//其中尤其是跟 N - Queens N皇后问题的解题思路及其相似，对于每个需要填数字的格子带入1到9，
//每代入一个数字都判定其是否合法，如果合法就继续下一次递归，结束时把数字设回'.'，
//判断新加入的数字是否合法时，只需要判定当前数字是否合法，不需要判定这个数组是否为数独数组，
//因为之前加进的数字都是合法的，这样可以使程序更加高效一些，具体实现如代码所示：
//跟8皇后问题及其相似，用回溯法验证其是否有效
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
				board[i][j] = (char)(k + '0');//放进去看看
				if (isValid(board, i, j)) {
					if (solveSudokuDFS(board, i, j + 1)) return true;
				}
				board[i][j] = '.';
			}
		}
		else {
			return solveSudokuDFS(board, i, j + 1);//下一位，找到空白位置
		}
		return false;
	}

	bool isValid(vector<vector<char> > &board, int i, int j) {
		for (int col = 0; col < 9; ++col) {//列比较
			if (col != j && board[i][j] == board[i][col]) return false;
		}
		for (int row = 0; row < 9; ++row) {//行比较
			if (row != i && board[i][j] == board[row][j]) return false;
		}
		for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row) {
			for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) {
				if ((row != i || col != j) && board[i][j] == board[row][col]) return false;//小九宫格比较
			}
		}
		return true;
	}
};

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		//记录某行，某位数字是否被摆放
		vector<vector<int>> row;
		row.resize(9, vector<int>(10, 0));
		vector<vector<int>> col;//记录某列，某位数字是否被摆放
		col.resize(9, vector<int>(10, 0));
		vector<vector<int>> block;//记录某块，某位数字是否被摆放
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
				i++; j = 0; //换一行
			}
			if (i >= 9) return true; //数独填满
		}
		for (int num = 1; num <= 9; num++) {
			int blockIndex = i / 3 * 3 + j / 3;
			if (!row[i][num] && !col[j][num] && !block[blockIndex][num])//未填写数字
			{
				board[i][j] = (char)('0' + num);//写入数字
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






		


