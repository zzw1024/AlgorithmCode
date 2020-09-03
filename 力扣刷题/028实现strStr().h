#pragma once
#include "000库函数.h"

/*********************自解**************/
//使用算法中的find       12ms
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.size() == 0 && needle.size() != 0)return -1;
		if (needle.size() == 0)return 0;
		return haystack.find(needle);
	}
};


/********************博客解法*****************/
//使用暴力遍寻法        44ms
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int m = haystack.size(), n = needle.size();
		if (m < n) return -1;
		for (int i = 0; i <= m - n; ++i) {
			int j = 0;
			for (j = 0; j < n; ++j) {
				if (haystack[i + j] != needle[j]) break;
			}
			if (j == n) return i;
		}
		return -1;
	}
};

void T028() {
	string haystack, needle;
	haystack = "hello";
	needle = "ll";
	Solution s;
	cout << s.strStr(haystack, needle) << endl;
	haystack = "aaaaa";
	needle = "bba";
	cout << s.strStr(haystack, needle) << endl;
}