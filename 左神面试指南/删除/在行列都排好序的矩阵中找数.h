#pragma once

#include <iostream>

using namespace std;


//Problem:
//	【题目】 给定一个有N*M的整型矩阵matrix和一个整数K，
//		matrix的每一行和每一 列都是排好序的。实现一个函数，
//		判断K是否在matrix中。 
//		例如： 
//			0 1 2 5 
//			2 3 4 7 
//		    4 4 4 8 
//			5 7 7 9 
//		如果K为7，返回true；如果K为6，返回false。
//	【要求】 时间复杂度为O(N + M)，额外空间复杂度为O(1)
//
//Solution:
//	请记住这道题肯定不能用遍历来做，因为遍历做的话，这道题就没有任何意义了。
//    请记住这道题的特点，这道题的特点是每一行都排好序了，而且每一列也是有序的。
//	然后从矩阵的右上角【或其他角】开始，然后假设矩阵的右上角为6，要找的数为4
//	也就说该数字6比要找到数4大的话，那么，就向右移动，因为6下面的数不可能比6还要小，比6小的数字只能在6的左边。
//	然后比要找的数小，如找到3后，然后就向下走，因为，比要找的数4小的，左边不可能。
//
//	请记住规律就是比要找的数字大的话就向左移动，比要找的数小的话就向下移动。
template<class T>
void FindNum(const T arr, const int x, const int y, const int num)
{
	int Tx=0, Ty=y-1;//选用右上角
	while (Tx >= 0 && Tx <= x - 1 && Ty >= 0 && Ty <= y - 1)
	{
		if (arr[Tx][Ty] == num)
		{
			cout << "the num is found, and it's position is: " << Tx << " " << Ty << endl;
			return;
		}
		else if (arr[Tx][Ty] > num)//大就向左移动
			Ty -= 1;
		else  //小就向下移动
			Tx += 1;

	}
	cout << "the num is not exist!" << endl;
	return;	
}

void Test()
{
	int a[3][4] = { 1,3,5,6,2,5,7,9,4,6,8,10 };
	FindNum(a, 3, 4, 11);
}


		