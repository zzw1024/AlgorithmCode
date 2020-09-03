#pragma once
#include "000库函数.h"

//0位置为空/***************核心代码***********************/
vector<int> getNext(string T, vector<int> next) {
	int i = 0;//前缀  
	int j = 1;//后缀
	next[0] = -1;//无用用位
	next[1] = 0;
	int t = T.size();//因为T.size()无无符号型，
	while (j < t-1) {
		if (0 == i || T[i] == T[j]) {
			++i;
			++j;
			if (T[i] != T[j])
				next[j] = i;
			else
				next[j] = next[i];
		}
		else
			i = next[i];
	}
	return next;
}




void get_next(String T, int *next)
{
	int j = 0;
	int i = 1;
	next[1] = 0;

	while (i < T[0])
	{
		if (0 == j || T[i] == T[j])
		{
			i++;
			j++;
			if (T[i] != T[j])
			{
				next[i] = j;
			}
			else
			{
				next[i] = next[j];
			}
		}
		else
		{
			j = next[j];
		}
	}
}

// 返回子串T在主串S第pos个字符之后的位置
// 若不存在，则返回0
int Index_KMP(String S, String T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];

	get_next(T, next);

	while (i <= S[0] && j <= T[0])
	{
		if (0 == j || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if (j > T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}

