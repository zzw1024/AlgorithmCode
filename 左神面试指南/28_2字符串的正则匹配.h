#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//
//【题目】
//	给定字符串str，其中绝对不含有字符'.'和'*'。再给定字符串exp，
//	其中可以含有'.'或'*'，'*'字符不能是exp的首字符，并且任意两个
//	'*'字符不相邻。exp中的'.'代表任何一个字符，exp中的'*'表示'*' 的前一个字符可以
//	有0个或者多个。请写一个函数，判断str是否能被exp匹配。
//	【举例】
//		str = "abc"，exp = "abc"，返回true。
//		str = "abc"，exp = "a.c"，exp中单个'.'可以代表任意字符，所以返回
//		true。
//	str = "abcd"，exp = ".*"。exp中'*'的前一个字符是'.'，所以可表示任
//	意数量的'.'字符，当exp是"...."时与"abcd"匹配，返回true。
//	str = ""，exp = "..*"。exp中'*'的前一个字符是'.'，可表示任意数量
//	的'.'字符，但是".*"之前还有一个'.'字符，该字符不受'*'的影响，
//	所以str起码有一个字符才能被exp匹配。所以返回false。
//
//【题解】
//	1、使用递归
//		str   i
//		exp  j
//		func(i, j)用来判断str中i后面的字符能不能由exp中j后面的字符变出来
//		首先观察j + 1的位置：
//		j + 1在末尾：
//		j + 1为*：
//		j + 1不是*：那么i，j必须匹配【j可以是.】
//
///使用递归
bool isValid(string str, string exp)//这是判断字符是否满足题目要求
{
	for (auto c : str)
		if (c == '*' || c == '.')
			return false;
	for (int i = 0; i < exp.length(); ++i)
		if (exp[i] == '*' && (i == 0 || exp[i - 1] == '*'))
			return false;
	return true;
}

bool  process(string str, int p, string exp, int q)
{
	if (q == exp.length())//达到边界了
		return p == str.length();
	if (q + 1 == exp.length() || exp[q + 1] != '*')
		return p != str.length() && (exp[q] == str[p] || exp[q] == '.') && process(str, p + 1, exp, q + 1);
	while (p != str.length() && (exp[q] == str[p] || exp[q] == '.'))
	{
		if (process(str, p, exp, q + 2))
			return true;
		++p;
	}
	return process(str, p, exp, q+2);
}

bool isMatching(string str, string exp)
{
	if (str.length() == 0 || exp.length() == 0)
		return false;
	return isValid(str, exp) ? process(str, 0, exp, 0) : false;
}

///使用动态规划
bool isMatchDP(string str, string exp)
{
	if (str.length() == 0 || exp.length() == 0)
		return false;

	if (!isValid(str, exp))
		return false;

	vector<vector<bool>>dp(str.length() + 1, vector<bool>(exp.length()+1, 0));
	dp[str.length()][exp.length()] = true;
	for (int i = exp.length() - 2; i > -1; i -= 2)
	{
		if (exp[i] != '*' && exp[i + 1] == '*')
			dp[str.length()][i] = true;
		else
			break;
	}
	if (str.length() > 0 && exp.length() > 0)
		if (exp[exp.length() - 1] == '.' || str[str.length() - 1] == exp[exp.length() - 1])
			dp[str.length() - 1][exp.length() - 1] = true;

	for (int i = str.length() - 1; i > -1; --i)
		for (int j = exp.length() - 2; j > -1; --j)
		{
			if (exp[j + 1] != '*')
				dp[i][j] = (str[i] == exp[j] || exp[j] == '.') && dp[i + 1][j + 1];
			else
			{
				int p = i;
				while (p != str.length() && (str[p] == exp[j] || exp[j] == '.'))
				{
					if (dp[p][j + 2])
					{
						dp[i][j] = true;
						break;
					}
					++p;
				}
				if (dp[i][j] != true)
					dp[i][j] = dp[p][j + 2];
			}
		}
	return dp[0][0];
}

void Test()
{
	string str, exp;
	str = "abcccdefg";
	exp = "abcccdefg";

	cout << isMatching(str, exp) << endl;
	cout << isMatchDP(str, exp) << endl;
}
