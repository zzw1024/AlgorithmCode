#pragma once
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//
//Problem：
//	给定数组arr和整数num，共返回有多少个子数组满足如下情况：
//	max(arr[i..j]) - min(arr[i..j]) <= num
//	max(arr[i..j])表示子数组arr[i..j]中的最大值，min(arr[i..j])表示子数组arr[i..j]
//	中的最小值。
//	【要求】
//	如果数组长度为N，请实现时间复杂度为O(N)的解法。
//
//
//Solution：
//	一个大数组符合要求，则大数组内所有的子数组都符合要求
//	如果一个小数组不符合要求，则再将该数组扩大，也是不符合要求的。
//	即新建一个窗口，两个队列，一个维持最大值，一个维持最小值，
//	当R移到N位置满足条件，而N + 1位置不满足条件，则停止，计算目前共有n + 1个子数组满足要求；
//	然后L移动一个位置，更新两个队列，然后R向右移动，直至M位置满足要求，M + 1不满足要求，子数组数量加M + 1 - 1个
//	然后一直到R遍历完整个数组
//	整体复杂度为O(N)
//


int getSubArray(vector<int>v, const int num)
{
	deque<int>maxList;//存储最大值
	deque<int>minList;//存储最小值
	int res = 0;
	int i, j;
	i = j = 0;
	for (int i = 0, j = 0; i < v.size(); ++i)
	{
		while (!maxList.empty() && v[i] >= v[maxList.back()])
			maxList.pop_back();
		maxList.push_back(i);

		while (!minList.empty() && v[i] <= v[minList.back()])
			minList.pop_back();
		minList.push_back(i);

		if ((v[maxList.front()] - v[minList.front()]) <= num )//满足要求则继续入栈
			continue;
		//此时不满足要求,计算前面满足要求的子数组
		res = res + i - j;

		while ((v[maxList.front()] - v[minList.front()]) > num)
		{
			if (maxList.front() == j)
				maxList.pop_front();
			if (minList.front() == j)
				minList.pop_front();
			++j;
		}

	}
	//res = res + i - j;
	return res;
}

int getSubArray00(vector<int>v, const int num)
{
	deque<int>maxList;//存储最大值
	deque<int>minList;//存储最小值
	int res = 0;
	int i, j;
	i = j = 0;
	while (j < v.size())
	{
		while (i < v.size())
		{
			while (!maxList.empty() && v[i] >= v[maxList.back()])
				maxList.pop_back();
			maxList.push_back(i);

			while (!minList.empty() && v[i] <= v[minList.back()])
				minList.pop_back();
			minList.push_back(i);

			if ((v[maxList.front()] - v[minList.front()]) > num)//不满足要求则跳出
				break;
			++i;
		}
		if (maxList.front() == j)
			maxList.pop_front();
		if (minList.front() == j)
			minList.pop_front();

		res += i - j;
		++j;
	}
	
	return res;
}

void Test()
{
	vector<int>v;
	v = { 1,2,3,4,5 };
	cout << getSubArray(v, 0) << endl;
	cout << getSubArray00(v, 0) << endl;
}