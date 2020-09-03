#pragma once

#include <iostream>


using namespace std;
//
//Problem：
//	旋转正方形矩阵【题目】 给定一个整型正方形矩阵matrix，
//	请把该矩阵调整成顺时针旋转90度的样子。
//	【要求】 额外空间复杂度为O(1).
//
//Solution:
//	同样，采用由外向内一圈一圈变换，找到元素变换位置的规律即可。
//	难点在于区分偶数维矩阵和奇数维矩阵的不同操作

template<class T>
void RotateMatrix(T& arr,const int x, const int y)//使用数组的引用传参，怎可在原数组上进行旋转
{
	int lx = 0, ly = 0; //左上角坐标
	int rx = x - 1, ry = y - 1;//右下角的坐标

	while (lx < rx || ly < ry)
	{

		for (int k = 0; k < ry - ly; ++k)//每一个圈次中所要旋转的元素
		{
			int temp = arr[lx][ly + k];
			arr[lx][ly + k] = arr[rx - k][lx];
			arr[rx - k][lx] = arr[rx][ry - k];
			arr[rx][ry - k] = arr[lx + k][ry];
			arr[lx + k][ry] = temp;
		}

		lx += 1;//左上角右下移
		ly += 1;
		rx -= 1;//右下角左上移
		ry -= 1;
	}
	
}

void Test()
{
	int aa[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int bb[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	RotateMatrix(aa, 3, 3);
	for (auto &a : aa)
	{
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl << "******************************" << endl;

	RotateMatrix(bb, 4, 4);
	for (auto &a : bb)
	{
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl << "******************************" << endl;


}