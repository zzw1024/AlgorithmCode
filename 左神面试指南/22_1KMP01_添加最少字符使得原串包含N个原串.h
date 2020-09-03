#pragma once
#include <iostream>
#include <string>

using namespace std;

//
//Problem:
//	   ����һ���ַ���str1��ֻ����str1�ĺ�������ַ����str2��
//		Ҫ��1��str2�����������str1������str1�������غϣ����ǲ�
//		����ͬһ��λ�ÿ�ͷ��
//		Ҫ��2��str2������
//		���շ���str2
//		������
//		str1 = 123��str2 = 123123 ʱ����������str1���Ҳ�����ͬ
//		λ�ÿ�ͷ����str2��̡�
//		str1 = 123123��str2 = 123123123 ʱ����������str1���Ҳ�
//		����ͬλ�ÿ�ͷ����str2��̡�
//		str1 = 111��str2 = 1111 ʱ����������str1���Ҳ�����ͬλ
//		�ÿ�ͷ����str2��̡�
//
//Solution:
//		ʹ��KMP�㷨��
//		�����һ���ַ��ĺ�һ����λ�����ͬǰ��׺���ȣ�
//		Ȼ���ַ�ǰ�治������ͬ�������N�ξ���


void getIndex(int*& index, string str)
{
	for (int i = 0, p = 0; i <= str.length(); ++i)
	{
		if (i == 0)
			index[i] = -1;
		else if (i == 1)
			index[i] = 0;
		else
		{
			if (str[i - 1] == str[p])
				index[i] = ++p;
			else if (p > 0)
				p = index[p];
			else
				index[i] = 0;
		}
	}
}

string addStr(string str, int N)
{
	string res = str;
	int* index = new int[str.size() + 1];
	getIndex(index, str);//��ȡ�ǰ��׺�Ǳ�

	int L = str.length() - index[str.length()];//���һ��λ�õ�ǰ��׺����
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < L; ++j)
			res += str[j];
	}
	delete[] index;
	return res;
}


void Test()
{
	string str;
	str = "abcabc";
	cout << addStr(str, 3) << endl;

	str = "12345";
	cout << addStr(str, 2) << endl;
}


