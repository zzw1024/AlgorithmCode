//////#include "head.h"
//////
//////class Solution {
//////public:
//////	int movingCount(int threshold, int rows, int cols)
//////	{
//////		if (threshold < 0 || rows < 1 || cols < 1)return 0;
//////		int res = 0;
//////		vector<bool>visit(rows*cols, false);
//////		DFS(threshold, rows, cols, 0, 0, visit, res);
//////		return res;
//////	}
//////	void DFS(const int threshold, const int rows, const int cols, int i, int j, vector<bool>&visit, int &res)
//////	{
//////		int s = 0, tempI = i, tempJ = j;
//////		while (tempI)
//////		{
//////			s += tempI % 10;
//////			tempI /= 10;
//////		}
//////		while (tempJ)
//////		{
//////			s += tempJ % 10;
//////			tempJ /= 10;
//////		}
//////		if (i >= 0 && i < rows && j >= 0 && j < cols && s <= threshold && visit[i*cols + j] == false)
//////		{
//////			res++;
//////			visit[i*cols + j] = true;
//////			DFS(threshold, rows, cols, i + 1, j, visit, res);
//////			DFS(threshold, rows, cols, i - 1, j, visit, res);
//////			DFS(threshold, rows, cols, i, j + 1, visit, res);
//////			DFS(threshold, rows, cols, i, j - 1, visit, res);
//////		}
//////	}
//////};
////
////
//#include "head.h"
//
//class Solution {
//public:
//	int movingCount(int m, int n, int k) {
//		if (k < 0 || m < 1 || n < 1)return 0;
//		vector<bool>visit(m*n, false);
//		int res = 0;
//		helper(visit, 0, 0, m, n, k, res);
//		return res;
//	}
//	void helper(vector<bool>&visit, int i, int j, int m, int n, int k, int &res)
//	{
//		int tempI = i, tempJ = j, sum = 0;
//		while (tempI)
//		{
//			sum += tempI % 10;
//			tempI /= 10;
//		}
//		while (tempJ)
//		{
//			sum += tempJ % 10;
//			tempJ /= 10;
//		}
//		if (sum <= k && i >= 0 && i < m && j >= 0 && j < n && visit[i*n + j] == false)
//		{
//			++res;
//			visit[i*n + j] = true;
//			helper(visit, i - 1, j, m, n, k, res);
//			helper(visit, i + 1, j, m, n, k, res);
//			helper(visit, i, j + 1, m, n, k, res);
//			helper(visit, i, j - 1, m, n, k, res);
//			//visit[i*n + j] = false;不能回溯，因为是一次性走完，而不是回溯之后再走，而且真要回溯的话，--res，且答案为max(res)
//		}
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	cout << s.movingCount(2, 3, 1) << endl;
//	cout << s.movingCount(3, 1, 0) << endl;
//	return 0;
//}