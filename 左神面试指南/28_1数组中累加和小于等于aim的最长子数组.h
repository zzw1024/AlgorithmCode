#pragma once
#include <iostream>
#include <vector>

using namespace std;

//【题目】
//	给定一个数组arr，全是正数；一个整数aim，求累加和小于等
//	于aim的，最长子数组，要求额外空间复杂度O(1)，时间
//	复杂度O(N)
//
//【题解】
//	使用窗口：
//	双指针，当sum <= aim，，R->, 当sum > aim, L->
//	记录最大的R - L即可
//
//【进阶】
//	给定一个数组arr，值可正，可负，可0；一个整数aim，求累加
//	和小于等于aim的，最长子数组，要求时间复杂度O(N)
//【题解】
//	之所以比原题更难，是因为负数可以使得整个子数组开始的和很大，但加到负数时，整体和就变小了
//	借助两个数组
//	min_sum[]  //min_sum[i]  ==  即必须以i开头的数组的最小累积和
//	min_sum_index[]//    min_sum_index[i]    ==  即以i开头数组的最小累加和的达到的最右端位置
//	技巧：
//	从数组的后向前算：
//	当n位置的最小累加和为负数时，那么n - 1的最小累加和一定是自己加上n的最小累加和，其最右边界与n相同
//	当n位置的最小累加和为正数时，那么n - 1的最小累加和一定是自己，因为再向后面加也是加一个正数，其最右边界就是自己的位置
//
//	求解：
//	从第0个数开始，R直接到0位置的最右边界，sum + 0位置的最小累加和，若，sum<aim, 则再加入R位置的最小累加和，并且R移到R位置的最右边界
//		直至sum>aim，则可以知道最长数组是多少了
//

int theLongestArray(vector<int>v, int aim)
{
	//使用两个指针，作为窗口的左右端
	int l = -1;
	int r = 0;
	int sum = 0;
	int res = 0;
	for (; r < v.size(); ++r)
	{
		sum += v[r];
		while (sum > aim && l < r)//向右移动窗口
		{
			++l;
			sum -= v[l];
		}
		res = res > (r - l) ? res : (r - l);
	}
	return res;
}


int theLongestArray_2(vector<int>v, int aim)
{
	int* min_sum = new int[v.size()];//以i开头的数组的最小和
	int* min_sum_index = new int[v.size()];//以i开头的数组的最小和数组右端
	for (int i = v.size()-1; i >= 0; --i)
	{
		if (i + 1 < v.size() && min_sum[i + 1] < 0)//右端最小和为负数，则可加上自己比自己更小
		{
			min_sum[i] = min_sum[i + 1] + v[i];
			min_sum_index[i] = min_sum_index[i + 1];
		}
		else//右端为整数，加上自己比自己大，那么就以自己为最小的数组和
		{
			min_sum[i] = v[i];
			min_sum_index[i] = i;
		}
	}
	//定义窗口的左右边界
	int l = -1;
	int r = 0;
	int res = 0;
	int sum = 0;
	for (int i=0;i<v.size();++i)
	{
		sum += min_sum[i];
		r = min_sum_index[i];
		while (l<r && sum>aim)
		{
			++l;
			sum -= v[l];
		}
		res = res > (r - l) ? res : (r - l);
	}
	delete[]min_sum;
	delete[]min_sum_index;
	return res;

}
void  Test()
{
	vector<int>v;
	v = {1,2,3,4,5,1,1,1,1,1,1,1,7,8,9};
	cout << theLongestArray(v, 7) << endl;
	v = { 1,2,3,4,5,1,1,-99,1,1,1,1,1,7,8,9,10,11,-99};
	cout << theLongestArray_2(v, 7) << endl;
}