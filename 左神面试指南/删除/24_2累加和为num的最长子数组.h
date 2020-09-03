#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

//【题目】
//	给定一个数组arr，和一个整数aim，求在arr中，累加和等于num的最长子数组的长度
//	例子：
//	arr = { 7,3,2,1,1,7,7,7 } aim = 7
//	其中有很多的子数组累加和等于7，但是最长的子数组是{ 3,2,1,1 }，所以返回其长度4
//
//【解题】
//	使用map,  从数组第一个数开始累加,  记录累加和到某个值的第一个位置
//	map初始存放数据为<0, -1>因为没有一个数字累加的和设置为0，该数字位置为数组的 - 1位置【即数组未开始遍历】
//	map<sum, index>, 当sum不变时，map不更新！！！
//	注意：
//	我们要找的是sum - aim = index == key在map中最早出现的位置，并进行记录
//	比如：7   3    2   1   1   7 - 6 - 1   7          num == 7
//	在累积第0个数字 7，sum = 7, sum - aim = 0， map中存在key = 0的位置，最早出现的 位置为 - 1， 
//	说明能组成一个子数组，使得累加和为aim，数组长度为0 - （ - 1） = 1
//	然后继续向后遍历，当遍历到第4个数字1时，
//	map记录为{ <0,-1><7,0><10,1><12,2><13,3><14,4> }，
//	此时sum为14， sum - aim = 14 - 7 = 7, key = 7存在map中，最早出现的位置为0，
//	说明能组成一个子数组，使得累加和为aim，数组长度为4 - （0） = 4



int mostLongSubArray(vector<int>v, int aim)
{
	int res = 0;//记录最长记录
	map<int, int>m;//记录累加和
	m[0] = -1;//最开始的位置sum为0
	int sum = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
		if (m.find(sum) == m.end())//累加和不存在
			m[sum] = i;
		auto ptr = m.find(sum - aim);
		if (ptr != m.end())//记录存在
			res = res > (i - (ptr->second)) ? res : (i - (ptr->second));//更新子数组最长记录
	}
	return res;
}

void Test()
{
	vector<int>v;
	v = { 7,3,2,1,1,7,7,7 };
	cout << mostLongSubArray(v, 7) << endl;
	v = { 7,3,2,1,1,7,-6,-1,7 };
	cout << mostLongSubArray(v, 7) << endl;
	v = { 7,5,2,4,3,1,1,1,1,1,1,1,1,7 };
	cout << mostLongSubArray(v, 7) << endl;
}