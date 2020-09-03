#include "000库函数.h"

//一看，没想出什么好法子，就遍历了
//最重要的是如何比较小九宫格的数据
//44ms
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')continue;
				for (int k = 8; k > j; --k)
					if (board[i][j] == board[i][k])return false;//比较行		
				for (int k = 8; k > i; --k)
					if (board[i][j] == board[k][j])return false;//比较列
				for (int k = i + 1; k % 3 != 0; k++) //比较九宫格
					for (int h = j / 3 * 3; h < j / 3 * 3 + 3; h++)
						if (board[i][j] == board[k][h])
							return false;
			}
		return true;
	}
};


//博客答案
//使用容器，大大减少了循环次数，但大大增加了内存空间 
//36ms
class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		vector<vector<bool> > rowFlag(9, vector<bool>(9, false));//9*9用来标记行的
		vector<vector<bool> > colFlag(9, vector<bool>(9, false));//9*9用来标记列的
		vector<vector<bool> > cellFlag(9, vector<bool>(9, false));//9*9用来标记九宫格【共有9个】
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') continue;
				int c = board[i][j] - '1';
				if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) return false;
				//如果行或列或九宫已经被标记过，则出行重复
				rowFlag[i][c] = true;//进行标记
				colFlag[c][j] = true;
				cellFlag[3 * (i / 3) + j / 3][c] = true;//最好的就是这样判断哪个九宫格的位置，一直是困扰博主的一个地方
				
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