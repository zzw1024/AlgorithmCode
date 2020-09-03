//#pragma once
//#include <iostream>
//#include <vector>
//#include <deque>
//
//using namespace std;
////
////【题目】
////	给定一个整型矩阵map，其中的值只有0和1两种，求其中全是1
////	的所有矩形区域中，最大的矩形区域为1的数量。
////	例如：
////	1 1 1 0
////	其中，最大的矩形区域有3个1，所以返回3。
////	再如：
////	1 0 1 1
////	1 1 1 1
////	1 1 1 0
////	其中，最大的矩形区域有6个1，所以返回6。
////【解】
////	使用单调栈
////	栈序为从小到大顺序。
////	将矩阵从第一行向下将每一行进行累加，新的行中为0则其累加和为0
////  计算每一行的累加和的最大矩阵
////	如上例的第一行累加和数组为[1,0,1,1]
////			第二行累加和数组为[2,1,2,2]
////			第三行累加和数组为[3, 2, 3, 0];
////	然后将累加和数组利用单调栈进行计算出最大矩阵面积，维持栈为从小到大的排序
//
//
//int MaxRecArea(const vector<vector<int>>v)
//{
//	vector<int>Sum(v[0].size(), 0);//储存每行的累加和
//	int res = 0;
//	for (int i = 0; i < v.size(); ++i)
//	{
//		for (int j = 0; j < v[0].size(); ++j)
//			Sum[j] = v[i][j] == 0 ? 0 : (Sum[j] + v[i][j]);
//
//		deque<int>d;//单调栈
//		for (int j = 0; j < Sum.size(); ++j)
//		{
//			while (!d.empty() && Sum[j] <= Sum[d.back()])//维持栈为从小到大的排序
//			{
//				int index = d.back();
//				d.pop_back();
//				if (d.empty())//弹出的数能到最左边-1的位置
//					res = res > (Sum[index] * j) ? res : (Sum[index] * j);
//				else//弹出的数有左边界
//					res = res > (Sum[index] * (j - d.back() - 1)) ? res : (Sum[index] * (j - d.back() - 1));
//			}
//			d.push_back(j);
//		}
//		while (!d.empty())//弹出剩余的数，其都无右边界，右边界为数组的大小
//		{
//			int index = d.back();
//			d.pop_back();
//			if (d.empty())//弹出的数能到最左边-1的位置
//				res = res > (Sum[index] * Sum.size()) ? res : (Sum[index] * Sum.size());
//			else//弹出的数有左边界,
//				res = res > (Sum[index] * (Sum.size() - d.back() - 1)) ? res : (Sum[index] * (Sum.size() - d.back() - 1));
//		}
//	}
//	return res;
//}
//
//
//
//void Test()
//{
//	vector<vector<int>>v;
//	v = { { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 0, 1, 1 }, };
//	cout << MaxRecArea(v) << endl;
//
//}