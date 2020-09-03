#pragma once
#include <iostream>
#include <string>

using namespace std;

//Problem:
//	Manacher算法扩展题目
//	给定一个字符串str1，只能往str1的后面添加字符变成str2，要求str2
//	整体都是回文串且最短。
//	举例：
//	str1 = ABC12321, 返回ABC12321CBA
//
//Solution:
//	使用Manacher算法来找打最长的回文字符
//


string getStr(string str)
{
	string newStr = "#";
	//字符预处理
	for (auto c : str)
		newStr = newStr + c + "#";

	int* rArry = new int[newStr.length()];//回文半径记录
	int c = -1;//回文中心
	int R = -1;//回文右边界 R位于回文对称右边界的右边一个字母
	int maxL = INT_MIN;//记录最长回文字长
	int p = str.length() - 1;//需要反着复制的字符位置
	for (int i = 0; i < newStr.length(); ++i)
	{
		//第一步直接取得可能的最短的回文半径，当i>R时，最短的回文半径是1，
		//反之，最短的回文半径可能是i对应的i'的回文半径或者i到R的距离
		if (R > i)
			rArry[i] = rArry[2 * c - i] < R - i ? rArry[2 * c - i] : R - i;
		else
			rArry[i] = 1;
		//取最小值后开始从边界暴力匹配，匹配失败就直接退出
		while (i + rArry[i] < newStr.length() && i - rArry[i] > -1)
		{
			if (newStr[i + rArry[i]] == newStr[i - rArry[i]])//向两边扩展，找回文字母
				rArry[i]++;
			else
				break;
		}
		//观察此时R和C是否能够更新
		if (i + rArry[i] > R)
		{
			R = i + rArry[i];
			c = i;
		}
		if (R == newStr.length())//回文右边界到达最后，则知道该字符末尾为回文
			int p = (newStr.length() - 2 * rArry[c]) / 2;//得到需要添加的字符
	}
	//判断字符后半截是否为回文字符
	//若是，则回文边界必在最后的字符位置上
	for (int i = p; i >= 0; --i)
		str += str[i];

	delete[] rArry;
	return str;
}

void Test()
{
	string str;
	str = "abc12321";
	cout << str << endl;
	cout << getStr(str) << endl << endl;
	str = "abc123";
	cout << str << endl;
	cout << getStr(str) << endl << endl;
	str = "abc1234321ab";
	cout << str << endl;
	cout << getStr(str) << endl << endl;
}
