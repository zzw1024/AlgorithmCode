#pragma once
#include <iostream>
#include <string>

using namespace std;

//
//Problem:
//	   给定一个字符串str1，只能往str1的后面添加字符变成str2。
//		要求1：str2必须包含两个str1，两个str1可以有重合，但是不
//		能以同一个位置开头。
//		要求2：str2尽量短
//		最终返回str2
//		举例：
//		str1 = 123，str2 = 123123 时，包含两个str1，且不以相同
//		位置开头，且str2最短。
//		str1 = 123123，str2 = 123123123 时，包含两个str1，且不
//		以相同位置开头，且str2最短。
//		str1 = 111，str2 = 1111 时，包含两个str1，且不以相同位
//		置开头，且str2最短。
//
//Solution:
//		使用KMP算法；
//		求最后一个字符的后一个空位的最长相同前后缀长度，
//		然后将字符前面不属于相同部分添加N次就行


void getIndex(int*& index, string str)
{
	for (int i = 0, p = 0; i <= str.length(); ++i)
	{
		if (i == 0)
			index[i] = -1;
		else if (i == 1)
			index[i] = 0;
		else
		{
			if (str[i - 1] == str[p])
				index[i] = ++p;
			else if (p > 0)
				p = index[p];
			else
				index[i] = 0;
		}
	}
}

string addStr(string str, int N)
{
	string res = str;
	int* index = new int[str.size() + 1];
	getIndex(index, str);//获取最长前后缀角标

	int L = str.length() - index[str.length()];//最后一个位置的前后缀长度
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < L; ++j)
			res += str[j];
	}
	delete[] index;
	return res;
}


void Test()
{
	string str;
	str = "abcabc";
	cout << addStr(str, 3) << endl;

	str = "12345";
	cout << addStr(str, 2) << endl;
}


