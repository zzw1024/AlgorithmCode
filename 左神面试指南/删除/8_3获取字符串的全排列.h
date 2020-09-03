#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

void AllPermution(string str, vector<string>& v, int i)
{
	if (i >= str.length())
		v.push_back(str);
	for (int j = i; j < str.length(); ++j)
	{
		swap(str[i], str[j]);
		AllPermution(str, v, i + 1);
		swap(str[i], str[j]);//»»»ØÀ´£¬
	}

}

void AllPermution2(string str, vector<string>& v, int i)
{

}

void Test()
{
	vector<string>v;
	string str;
	str = "abc";
	AllPermution(str, v, 0);
	for (auto a : v)
		cout << a << endl;
}