#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//
//Problem:
//	给定一个字符串类型的数组strs，找到一种拼接方式，使得把所
//	有字 符串拼起来之后形成的字符串具有最低的字典序
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

