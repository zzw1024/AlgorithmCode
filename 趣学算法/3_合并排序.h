#pragma once
#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int>&v, int l, int m, int r)//合并
{
	vector<int>res(r - l + 1);
	int i = l, j = m+1, k = 0;
	while (i <= m && j <= r)
	{
		if (v[i] < v[j])
			res[k++] = v[i++];
		else
			res[k++] = v[j++];
	}
	while (i <= m)
		res[k++] = v[i++];
	while (j <= r)
		res[k++] = v[j++];
	k = 0;
	while (l <= r)
		v[l++] = res[k++];//赋值

}

void MergeSort(vector<int>&v, int l, int r)//二分
{
	if (l >= r)
		return;
	int m = l + (r - l) / 2;
	MergeSort(v, l, m);//分两部分
	MergeSort(v, m + 1, r);
	Merge(v, l, m, r);//合并
}

void Test()
{
	vector<int>v;
	v = { 14,1,5,41,28,8,9,54,3,42,56,7,16,13 };
	MergeSort(v, 0, v.size() - 1);
	for (auto a : v)
		cout << a << "  ";
	cout << endl;
}