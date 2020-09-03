#pragma once
#include <iostream>
#include <string>

using namespace std;

//Problem：
//给定一个字符串str，和一个整数k，返回str向右循环右移k位后的结果
//
//Solution：
//	简单的值交换达到右循环移动


void rightMove(string& s, int k)
{
	int n = s.length();
	k = k % n;
	if (k == 0)
		return;
	for (int i = 0; i < k; ++i)//右移k次
	{
		char temp = s[n - 1];
		int j = n - 1;
		while (j>0)
		{
			s[j] = s[j - 1];
			--j;
		}
		s[0] = temp;
	}
}

void Test()
{
	string s;
	s = "abcdef";
	rightMove(s, 1);
	cout << s << endl;
	s = "abcdef";
	rightMove(s, 2);
	cout << s << endl;
	s = "abcdef";
	rightMove(s, 3);
	cout << s << endl;
	s = "abcdef";
	rightMove(s, 4);
	cout << s << endl;
}