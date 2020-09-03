#pragma once
#include <iostream>

using namespace std;

//Problem:
//	“之”字形打印矩阵【题目】 给定一个矩阵matrix，按照“之”字形的方式打印这个矩阵，
//	例如： 1 2 3 4 5 6 7 8 9  10 11 12
//	“之”字形打印的结果为：1，2，5，9，6，3，4，7，10，11，8，12
//	【要求】 额外空间复杂度为O(1）
//
//Solution:
//	使用A,B两个坐标，初始值为（0，0），（0，0），A,B的连线为之字形的斜线
//	A移动方向为向右走，B移动方向为向下走，A到最右边了就向下走，B到最下面了就向右走
//  使用一个bool值，判断是向右上方方向遍历A-B直线，还是向左下角方向遍历A-B直线
//		A 
//		|
//	B-  1 2 3 4 
//		5 6 7 8
//		9 1 0 5

template<class T>
void ZiPrint(const T arr, const int x, const int y)
{
	int Ax = 0, Ay = 0;//初始化A,B的坐标
	int Bx = 0, By = 0;
	bool flag = true;//true为右上方方向遍历， false为左下角方向遍历

	while (Ax <= x-1 && Ay <= y-1)//A到右下角就遍历完毕
	{
		if(flag)//右上方方向遍历
		{
			int Tx = Bx, Ty = By;
			while (Tx >= Ax || Ty <= Ay)
			{
				cout << arr[Tx][Ty] << "  ";
				Tx -= 1;
				Ty += 1;
			}
			flag = false;
		}
		else//向左下角方向遍历
		{
			int Tx = Ax, Ty = Ay;
			while (Tx <= Bx || Ty >= By)
			{
				cout << arr[Tx][Ty] << "  ";
				Tx += 1;
				Ty -= 1;
			}
			flag = true;
		}
		//更新A,B
		if (Ay < y - 1)
			Ay += 1;
		else
			Ax += 1;

		if (Bx < x - 1)
			Bx += 1;
		else
			By += 1;

	}
	cout << endl;

}

void Test()
{
	int aa[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	ZiPrint(aa, 3, 4);
}