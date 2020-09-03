//#include "000库函数.h"
//
//class Solution {
//public:
//	int uniquePathsIII(vector<vector<int>>& grid) {
//		n = grid.size();
//		m = grid[0].size();
//		int nums = 0, res = 0;
//		for(int i=0;i<n;++i)
//			for (int j = 0; j < m; ++j)
//			{
//				if (grid[i][j] == 0)
//					++nums;//统计可走空格数量
//				if (grid[i][j] == 1)//起点
//				{
//					sx = i;
//					sy = j;
//				}
//				else if (grid[i][j] == 2)//终点
//				{
//					ex = i;
//					ey = j;
//				}
//			}
//		helper(grid, res, sx, sy,nums);	
//		return res;
//	}
//	void helper(vector<vector<int>>& grid, int &res,int i, int j, int nums)
//	{
//		if (grid[i][j] == 2 && nums == 0)
//			++res;
//		int pre = grid[i][j];
//		if (pre == 0)
//			--nums;
//		grid[i][j] = -1;
//		for (auto a : path)
//		{
//			int x = i + a[0], y = j + a[1];
//			if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != -1)//记住，除了-1都可以走
//				helper(grid, res,x, y,nums);
//		}
//		grid[i][j] = pre;
//	}
//private:
//	int n, m, sx, sy, ex, ey;
//	vector<int> path[4] = { {-1,0},{1,0},{0,-1},{0,1} };
//};
//
//int main()
//{
//	vector<vector<int>>v = { {1,0,0,0},{0,0,0,0},{0,0,2,-1} };
//	Solution s;
//	cout << s.uniquePathsIII(v);
//	return 0;
//}