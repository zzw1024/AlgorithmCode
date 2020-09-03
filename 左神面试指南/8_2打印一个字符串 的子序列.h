#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void PrintSubStr(string str, vector<string>&v,int i)
{
	if (i == str.length())
		v.push_back(str);
	else 
	{
		PrintSubStr(str, v, i + 1);
		char temp = str[i];
		str[i] = 0;
		PrintSubStr(str, v, i + 1);
		str[i] = temp;
	}
}
void PrintSubStr2(string str, vector<string>&v)
{
	v.push_back("");
	for (auto c : str)
	{
		int n = v.size();
		for (int i = 0; i < n; ++i)
			v.push_back(v[i] + c);//每次添加一个字母就行
	}
}

void Test()
{
	vector<string>v;
	string str;
	str = "abc";
	PrintSubStr(str, v, 0);
	for (auto a : v)
		cout << a << endl;

	cout << "=================" << endl;
	v.clear();
	PrintSubStr2(str, v);
	for (auto a : v)
		cout << a << endl;

}