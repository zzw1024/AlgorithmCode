#pragma once

#include <iostream>
#include <map>

using namespace std;

//不使用比较排序，实现一个数组排序
//时间复杂度O(N)，额外空间复杂度O(N)
//
//思路
//使用桶排序思维，申请一个额外数组，叫桶，用来记录数字出现的次数，然后输出即可
//但桶排序一般适用于0-9的元素数字排序，因为此时桶只需申请0-9的空间，若array元素为999，
//则桶的空间至少得申请0-999，那样就不适用。
//
//
//扩展，使用map来实现桶，那么就可以实现任何数组桶排序功能


//使用桶数组
void Test01(const int array[], int N)
{
	int TT[10] = { 0 };
	for (int i = 0; i < N; ++i)
		TT[array[i]]++;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < TT[i]; ++j)
			cout << i << "  ";

	cout << endl << "*******************" << endl;
}


//使用map
void Test02(const int array[], int N)
{
	map<int, int>M;
	for (int i = 0; i < N; ++i)
		M[array[i]]++;

	for (auto ptr = M.cbegin(); ptr != M.cend(); ++ptr)
		for (int j = 0; j < ptr->second; ++j)
			cout << ptr->first << "  ";
	cout << endl << "*******************" << endl;



}


//补充问题
//给定一个数组，求如果排序之后，相邻两数的最大差值，要求时
//间复杂度O(N)，且要求不能用非基于比较的排序。

//对于已排好序的数组array，给一个额外n + 1空间ZZ数组作为桶。
//array[0]即最小值放在ZZ[0]，array[n - 1]即最大值放在ZZ[n]中。
//桶ZZ的每个位置按(array[n - 1] - array[0]) / n，分配区间
//
//然后建立三个参数数组【可用结构体】：
//ZZbool : 用来标志桶位置是否放入数据了
//	ZZmin : 用来记录一个桶位置中放入数据的最小值；
//	ZZmax : 用来记录一个桶位置中放入数据的最大值；
//	由于array大小为N; ZZ大小为N + 1，故ZZ必有一个位置是空的。
//	请记住，相邻两个数据的差值一定出现在不同的桶的位置中，因为一个桶内数据差最大不会超过桶位置的范围值，如图中，最大差值不会超过10，而相邻桶可以达到20的差值，而ZZ中含有一个空桶，那么空桶前非空桶的最大值与空桶后面的非桶中的最小值的差值一定大于10，而ZZZ中可能含有多个空桶，故最大差值一定不在一个桶内；
//	所以每次比较相邻桶的差值大小即，左桶的max - 右桶min即可。





void NoSort()
{
	int arr[] = { 9,1,4,8,5,6,7,1,2,5,4,9,0,6 };
	Test01(arr, sizeof(arr) / sizeof(arr[0]));
	Test02(arr, sizeof(arr) / sizeof(arr[0]));

}