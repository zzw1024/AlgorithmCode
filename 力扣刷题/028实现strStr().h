#pragma once
#include "000�⺯��.h"

/*********************�Խ�**************/
//ʹ���㷨�е�find       12ms
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.size() == 0 && needle.size() != 0)return -1;
		if (needle.size() == 0)return 0;
		return haystack.find(needle);
	}
};


/********************���ͽⷨ*****************/
//ʹ�ñ�����Ѱ��        44ms
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