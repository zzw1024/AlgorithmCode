//#include "head.h"
//
//
//class Solution {
//public:
//	vector<int> printMatrix(vector<vector<int> > matrix) {
//		int Lx = 0, Ly = 0, Rx = matrix.size() - 1, Ry = matrix[0].size() - 1;
//		vector<int>res;
//		while (Lx <= Rx && Ly <= Ry)
//		{
//			if (Lx == Rx)//只有一行
//				for (int i = Ly; i <= Ry; ++i)
//					res.push_back(matrix[Lx][i]);
//			else if(Ly==Ry)//只有一列
//				for (int i = Lx; i <= Rx; ++i)
//					res.push_back(matrix[i][Ly]);
//			else
//			{
//				for (int i = Ly; i < Ry; ++i)
//					res.push_back(matrix[Lx][i]);
//				for (int i = Lx; i < Rx; ++i)
//					res.push_back(matrix[i][Ry]);
//				for (int i = Ry; i > Ly; --i)
//					res.push_back(matrix[Rx][i]);
//				for (int i = Rx; i > Lx; --i)
//					res.push_back(matrix[i][Ly]);
//			}
//			++Lx, ++Ly;
//			--Rx, --Ry;
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<vector<int> > matrix = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
//	vector<int> v = s.printMatrix(matrix);
//	for (auto a : v)cout << a << " ";
//	while (1);
//}