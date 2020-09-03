#pragma once
#include <iostream>
#include <string>

using namespace std;

//Problem��
//����һ���ַ���str����һ������k������str����ѭ������kλ��Ľ��
//
//Solution��
//	�򵥵�ֵ�����ﵽ��ѭ���ƶ�


void rightMove(string& s, int k)
{
	int n = s.length();
	k = k % n;
	if (k == 0)
		return;
	for (int i = 0; i < k; ++i)//����k��
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