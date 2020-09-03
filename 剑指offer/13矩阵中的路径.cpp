//////#include "head.h"
//////
//////class Solution {
//////public:
//////	bool hasPath(char* matrix, int rows, int cols, char* str)
//////	{
//////		if (matrix == nullptr || rows < 1 || cols < 1)return false;
//////		if (str == nullptr)return true;
//////		vector<bool>visit(rows*cols, false);
//////		int pot = 0;
//////		for (int i = 0; i < rows; ++i)
//////			for (int j = 0; j < cols; ++j)
//////				if (DFS(matrix, rows, cols, i, j, visit, str, pot))
//////					return true;
//////		return false;
//////	}
//////	bool DFS(const char* matrix, const int rows, const int cols,int i, int j, vector<bool>&visit,const char *str, int &pot)
//////	{
//////		if (str[pot] == '\0')return true;
//////		bool flag = false;
//////		if (i >= 0 && i < rows && j >= 0 && j < cols &&
//////			matrix[i*cols + j] == str[pot] && visit[i*cols + j] == false)
//////		{
//////			++pot;
//////			visit[i*cols + j] = true;
//////			flag = DFS(matrix, rows, cols, i + 1, j, visit, str, pot) ||
//////					DFS(matrix, rows, cols, i - 1, j, visit, str, pot) ||
//////					DFS(matrix, rows, cols, i, j + 1, visit, str, pot) ||
//////					DFS(matrix, rows, cols, i, j - 1, visit, str, pot);
//////			if (flag == false)
//////			{
//////				--pot;
//////				visit[i*cols + j] = false;//回溯
//////			}
//////		}
//////		return flag;
//////	}
//////};
////
//
////记住，这道题是不需要走到右下脚才结束
////而是任意起点和任意终点
////所以只要匹配上了字符就结束
//#include "head.h"
//class Solution {
//public:
//	bool exist(vector<vector<char>>& board, string word) {
//		n = board.size(), m = board[0].size();
//		if (n == 0 || m == 0 || word.empty())return false;
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < m; ++j)
//			{
//				vector<bool>visit(n*m, false);
//				if (helper(board, visit, word, i, j, 0))
//					return true;
//			}
//		}
//		return false;
//	}
//	bool helper(vector<vector<char>>&board, vector<bool>&visit, string &word, int i, int j, int nums)
//	{
//		if (nums == word.length())return true;
//		bool res = false;
//		if (i >= 0 && i < n && j >= 0 && j < m && visit[i*m + j] == false && word[nums] == board[i][j])
//		{
//			visit[i*m + j] = true;//切记不能是i*j
//			res = helper(board, visit, word, i - 1, j, nums + 1) ||
//				helper(board, visit, word, i + 1, j, nums + 1) ||
//				helper(board, visit, word, i, j - 1, nums + 1) ||
//				helper(board, visit, word, i, j + 1, nums + 1);
//			visit[i*m + j] = false;//回溯
//		}
//		return res;
//	}
//private:
//	int n, m;//记住使用全局变量
//};
//
//int main()
//{
//	Solution s;
//	vector<vector<char>>board = { {'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'} };
//	cout << s.exist(board, "abcced") << endl;
//	cout << s.exist(board, "abccbbaaaa") << endl;
//	return 0;
//}
