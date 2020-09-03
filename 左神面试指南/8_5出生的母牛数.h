#pragma once
#include <iostream>

using namespace std;

int CowNum(int n)
{
	if (n < 1)
		return 0;
	if (n == 1 || n == 2 || n == 3)//3年后才能生
		return n;
	return CowNum(n - 1) + CowNum(n - 3);
}

void Test()
{
	cout << CowNum(4) << endl;
}
