#pragma once
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>&v, int l, int r)
{
	int p = v[l];
	while (l < r)
	{
		if (v[r] < p)
			swap(v[l], v[r]);
		else if (v[l] > p)
			swap(v[l], v[r]);
		
		if (v[l] == p)
			r--;
		else
			l++;			
	}
	return l;
}

void quickSort(vector<int>&v, int l, int r)
{
	if (l >= r)
		return;
	int m = partition(v, l, r);
	quickSort(v, l, m - 1);//mŒª÷√±£¡Ù
	quickSort(v, m + 1, r);	
}

void Test()
{
	vector<int>v;
	v = { 14,1,5,41,28,8,9,54,3,42,56,7,16,13 }; 
	quickSort(v, 0, v.size() - 1);
	for (auto a : v)
		cout << a << "  ";
	cout << endl;
}