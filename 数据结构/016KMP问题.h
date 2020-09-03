#pragma once
#include "000�⺯��.h"

//0λ��Ϊ��/***************���Ĵ���***********************/
vector<int> getNext(string T, vector<int> next) {
	int i = 0;//ǰ׺  
	int j = 1;//��׺
	next[0] = -1;//������λ
	next[1] = 0;
	int t = T.size();//��ΪT.size()���޷����ͣ�
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

// �����Ӵ�T������S��pos���ַ�֮���λ��
// �������ڣ��򷵻�0
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

