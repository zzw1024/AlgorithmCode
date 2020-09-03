#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

//【题目】
//	定义数组的异或和的概念：
//	数组中所有的数异或起来，得到的结果叫做数组的异或和，
//	比如数组{ 3,2,1 }的异或和是，3 ^ 2 ^ 1 = 0
//	给定一个数组arr，你可以任意把arr分成很多不相容的子数组，你的目的是：
//	分出来的子数组中，异或和为0的子数组最多。
//	请返回：分出来的子数组中，异或和为0的子数组最多是多少？
//
//【题解】
//	异或运算性质：
//	满足交换律和结合律且 0 ^ m = m
//	DP，假设数组最后一个数的下标是i，并且数组存在一个最优划分，使得划分的子数组个数最多，
//	那么i有两种情况，
//		第一，i所在的划分区间异或为0；
//		第二，i所在的划分区间，异或不为0。
//	对于第一种情况dp[i] = dp[i - 1]的，
//	对于第二种情况，假设i的最优划分区间是[k, i]，0到i的连续异或为sum，之要求出一个最大的下标k - 1，使得0到k - 1的异或也为sum就行了


int XORSumArray(vector<int>v)
{
	int res = 0;
	int Xor = 0;//异或和
	vector<int>dp(v.size(), 0);
	map<int, int>m;// key表示异或结果,value表示出现下标
	m[0] = -1;//最初异或和为0的位置为-1
	for (int i = 0; i < v.size(); ++i)
	{
		Xor ^= v[i];
		if (m.find(Xor) != m.end())//存在
			dp[i] = m[Xor] == -1 ? 1 : (dp[m[Xor]] + 1);
		if (i > 0)
			dp[i] = dp[i - 1] > dp[i] ? dp[i - 1] : dp[i];
		m[Xor] = i;
		res = res > dp[i] ? res : dp[i];
	}
	return res;	
}

void Test()
{
	vector<int>v;
	v = {1,2,3,1,2,3,1,2,3};
	cout << XORSumArray(v) << endl;
	v = {1,2,3,4,5,6,7,8,9,10};
	cout << XORSumArray(v) << endl;
	v = { 1,2,3,4,5,6,7,8,9,10,11 };
	cout << XORSumArray(v) << endl;
}