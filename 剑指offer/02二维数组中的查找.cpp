//#include "head.h"
//
//
//class Solution {
//public:
//	bool Find(int target, vector<vector<int>> array) {
//		int px = array.size(), py = array[0].size();
//		if (px==0 || py == 0 ||target<array[0][0] || target>array[px - 1][py - 1])return false;
//		for (int x = 0, y = 0; y < py && x < px &&y >= 0 && x>=0;)
//		{
//			if (target == array[x][y])return true;
//			else if ((y == py-1 && target > array[x][y])||(y < py - 1 && target < array[x][y + 1] && target > array[x][y]))
//				++x;
//			else if (target < array[x][y])
//				--y;
//			else
//				y++;
//		}
//		return false;
//	}
//};
//
//int main()
//{
//	vector<vector<int>> array = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
//	Solution A;
//	cout << A.Find(15, array) << endl;
//	while (1);
//}
//class Solution {
//public:
//	bool Find(int target, vector<vector<int>> array) {
//		int px = array.size(), py = array[0].size();
//		if (target<array[0][0] || target>array[px - 1][py - 1])return false;
//		int x = 0, y = py - 1;
//		while (x < px && y >= 0)
//		{
//			if (target == array[x][y])return true;
//			else if (target > array[x][y]) ++x;
//			else if (target < array[x][y]) --y;
//		}
//		return false;
//	}
//};
//
