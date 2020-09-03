#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//
//Problem:
//	����һ���ַ������͵�����strs���ҵ�һ��ƴ�ӷ�ʽ��ʹ�ð���
//	���� ����ƴ����֮���γɵ��ַ���������͵��ֵ���
//
//
//		Solution:


string lowString(vector<string>v)
{
	string res = "";
	if (v.empty())
		return res;
	else
	{
		sort(v.begin(), v.end(), [=](string a, string b) {return ((a + b) < (b + a)); });
		for (auto str : v)
			res += str;
	}
	return res;
}

void Test()
{
	vector<string>v;
	v = { "jibw", "ji", "jp", "bw", "jibw" };
	cout << lowString(v) << endl;

	v = { "ba","b" };
	cout << lowString(v) << endl;
}

