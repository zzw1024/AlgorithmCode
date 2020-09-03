#include "_000库函数.h"

//此问题是一个DFS问题，每个单词可以像上下左右四个方向进行下一步行走



class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty())return false;
		int m = board.size(), n = board[0].size();
		vector<vector<bool>>visted(m, vector<bool>(n, false));//记录是否被访问过
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (search(board, visted, 0, i, j, word))return true;//每个单词单元都进行上下左右进行搜索！
			}
		}
	}

	bool search(vector<vector<char>>& board, vector<vector<bool>>& visted, int idx, int i, int j, string word) {
		if (idx == word.size())return true;
		int m = board.size(), n = board[0].size();
		if (i < 0 || j < 0 || i >= m || j >= n || visted[i][j] || board[i][j] != word[idx])return false;
		visted[i][j] = true;
		bool res = (search(board, visted, idx + 1, i - 1, j, word) ||
					search(board, visted, idx + 1, i + 1, j, word) ||
					search(board, visted, idx + 1, i, j - 1, word) ||
					search(board, visted, idx + 1, i, j + 1, word));
		visted[i][j] = false;//回溯
		return res;
	}
};

void T079() {
	Solution s;
	vector<vector<char>> board;
	string word;
	board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
	word = "ABCCED";
	cout << s.exist(board, word) << endl;

	
}