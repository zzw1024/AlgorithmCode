#pragma once

#include <iostream>
#include <queue>

using namespace std;

//Problem:
//	【题目】 给定一个整型矩阵matrix，请按照转圈的方式打印它。
//	例如： 1 2 3 4 5 6 7 8 9 10 11 12 13 14
//	15 16 打印结果为：1，2，3，4，8，12，16，15，14，13，9，
//	5，6，7，11， 10
//	【要求】 额外空间复杂度为O(1)。
//
//Solution:
//	采用一圈一圈打印的方式，即确定左上角与右下角，然后从外向内打印一圈，打印完了之后，
//	左上角向右下一一个，右下角向上上移一个，继续打印
//	左上角的行>右下角的行或者左上角的列 > 右下角的列， 则打印完毕
template<class T>
void RotatePrint(T arr, const int x, const int y)
{
	int lx = 0, ly = 0; //左上角坐标
	int rx = x - 1, ry = y - 1;//右下角的坐标

	while (lx <= rx || ly <= ry)
	{
		if (lx == rx)
		{
			for (int i = ly; i <= ry; ++i)//打印一行的矩阵
				cout << arr[lx][i] << "  ";
		}
		else if (ly == ry)
		{
			for (int i = lx; i <= rx; ++i)//打印一列的矩阵
				cout << arr[i][ly] << "  ";
		}
		else 
		{  //打印不是单行或单列的矩阵

			for (int i = ly; i < ry; ++i)//打印上行
				cout << arr[lx][i] << "  ";
			for (int i = lx; i < rx; ++i)//打印右列
				cout << arr[i][ry] << "  ";
			for (int i = ry; i > ly; --i)//打印下行
				cout << arr[rx][i] << "  ";
			for (int i = rx; i > lx; --i)//打印左列
				cout << arr[i][ly] << "  ";
		}

		lx += 1;//左上角右下移
		ly += 1;
		rx -= 1;//右下角左上移
		ry -= 1;
	}
	cout << endl << "******************************" << endl;

}


void Test()
{
	int aa[3][3] = { 1,2,3, 4,5,6, 7,8,9 };
	int bb[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	RotatePrint(aa, 3, 3);
	RotatePrint(bb, 3, 4);



}