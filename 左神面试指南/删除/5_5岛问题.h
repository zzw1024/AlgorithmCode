#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Problem:
//	岛问题
//	一个矩阵中只有0和1两种值，每个位置都可以和自己的上、下、左、右
//	四个位置相连，如果有一片1连在一起，这个部分叫做一个岛，求一个
//	矩阵中有多少个岛？
//	举例：
//	0 0 1 0 1 0
//	1 1 1 0 1 0
//	1 0 0 1 0 0
//	0 0 0 0 0 0
//	这个矩阵中有三个岛。
//
//Solution:
//	【解题思路】：
//	使用感染函数法：
//	for ()
//		for ()
//	依次遍历，当为1，岛 + 1，然后用递归，将该位置的所有相连的1置为2，然后继续遍历，
//	只关注值为1的位置，遇到1，岛 + 1，递归将所有相连的1置为2。
//	当矩阵巨大无比，切割矩阵成多个部分来循坏快得多，
//	那么怎么判断重合的边界问题呢？
//

//感染函数
void Change(vector<vector<int>>&v, int i, int j)
{
	if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || v[i][j] != 1)
		return;
	v[i][j] = 2;
	Change(v, i - 1, j);//上移
	Change(v, i, j + 1);//右移
	Change(v, i + 1, j);//下移
	Change(v, i, j - 1);//左移
}

int isIsland(vector<vector<int>>v)
{
	int res = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
		{
			if (v[i][j] == 1)
			{
				++res;
				Change(v, i, j);
			}
		}
	}
	return res;
}

void Test()
{
	vector<vector<int>>v;
	v = {	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 0, 1, 1, 1, 0 },
			{ 0, 1, 1, 1, 0, 0, 0, 1, 0 },
			{ 0, 1, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
	cout << "the numbers of island is: " << isIsland(v) << endl;

	v = {	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 1, 1, 1, 1, 0 },
			{ 0, 1, 1, 1, 0, 0, 0, 1, 0 },
			{ 0, 1, 1, 0, 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
	cout << "the numbers of island is: " << isIsland(v) << endl;

}