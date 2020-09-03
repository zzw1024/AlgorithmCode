#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Problem:
//	找到未排序数组中第k大的数
//	比如在1-500的乱序数组中，
//	找到第15大的数
//
//Solution：
//	使用BFPRT算法，进行快速排序
int BFPRT(vector<int>& v, int left, int right, const int k);

//插入排序，返回中位数的下角标
int InsertSort(vector<int>& v, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
			int temp = v[i];
			int j = i - 1;
			while (j >= left && v[j] > temp)
			{
				v[j + 1] = v[j];
				--j;
			}
			v[j + 1] = temp;
	}
	return left + (right - left) >> 1;//返回中位数
}

//返回中位数的中位数的下角标
int GetMidIndex(vector<int>& v, int left, int right)
{
	if (right - left < 5)
		return InsertSort(v, left, right);//最后一组进行排序
	int subRight = left - 1;
	for (int i = left; i + 4 <= right; i + 5)//分组进行排序
	{
		int index = InsertSort(v, i, i + 4);
		swap(v[++subRight], v[index]);//将中位数放最左端
	}
	return BFPRT(v, left, subRight, (subRight - left + 1) >> 1 + 1);
}

//利用中位数的中位数的下角标进行划分，返回边界线下标
int Partition(vector<int>&v, int left, int right, int midIndex)
{
	swap(v[midIndex], v[right]);//将中位数的的中位数放在最末尾

	int divideIndex = left;//跟踪划分分界线
	for (int i = left; i < right; ++i)//中位数的中位数在v[right]上
		if (v[i] < v[right])
			swap(v[divideIndex++], v[i]);//比中位数的中位数小的方在左边

	swap(v[midIndex], v[right]);//换回来
	return divideIndex;
}


int BFPRT(vector<int>& v, int left, int right, const int k )
{
	int midIndex = GetMidIndex(v, left, right);//得到中位数的中位数的下标
	int divideIndex = Partition(v, left, right, midIndex);//进行划分，返回划分边界
	int num = divideIndex - left + 1;
	if (num == k)
		return divideIndex;
	else if (num > k)
		return BFPRT(v, left, divideIndex - 1, k);
	else
		return BFPRT(v, divideIndex + 1, right, k - num);
}

void Test()
{
	vector<int>v;
	v = { 1,1,2,3,1,5,-1,7,8,-10 };

	int k = 5;
	cout << "原数组:" << endl;
	for (auto a : v)
		cout << a << "  ";
	cout << endl;

	cout << "第" << k << "小值为：" << v[BFPRT(v, 0, v.size() - 1, k)] << endl;
	
	cout << "变化后的数组:" << endl;
	for (auto a : v)
		cout << a << "  ";
	cout << endl;


}





