#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Problem:
//	一块金条切成两半，是需要花费和长度数值一样的铜板的。比如
//	长度为20的 金条，不管切成长度多大的两半，都要花费20个铜
//	板。一群人想整分整块金 条，怎么分最省铜板？
//	例如, 给定数组{ 10,20,30 }，代表一共三个人，整块金条长度为
//	10 + 20 + 30 = 60. 金条要分成10, 20, 30三个部分。 如果， 先把长
//	度60的金条分成10和50，花费60 再把长度50的金条分成20和30，
//	花费50 一共花费110铜板。
//	但是如果， 先把长度60的金条分成30和30，花费60 再把长度30
//	金条分成10和20，花费30 一共花费90铜板。
//	输入一个数组，返回分割的最小代价。
//
//Solution:
//	使用哈夫曼树思想
//	即选择最小的两个，组成和，在加入原数中，再从中找两个最小数，组成和，放回数组中，直至数组汇总只有一个数，即为根节点。

int CalCost(vector<int>v)
{
	int res = 0;
	int N = v.size();
	for (int i = 0; i < N - 1; ++i)//N个数，只需要合并N-1次即可
	{
		int min1, min2;
		int x1, x2;
		min1 = min2 = INT_MAX;
		x1 = x2 = -1;
		for (int j = 0; j < v.size(); ++j)
		{
			if (v[j] > 0 && v[j] < min1)//寻找最小的两个数
			{
				x2 = x1;
				min2 = min1;

				x1 = j;
				min1 = v[j];
			}
			else if (v[j] > 0 && v[j] < min2)
			{
				x2 = j;
				min2 = v[j];
			}
		}
		res += min1 + min2;
		v[x2] = -1;
		v[x1] = min1 + min2;//两数进行合并
	}
	return res;
}


void Test()
{
	vector<int>v;
	v = { 10,20,30,40 };
	cout << CalCost(v) << endl;
}