#pragma once
#include <iostream>
#include <string>

using namespace std;


//�����KMP�㷨
void getIndex(int*& index, string str)
{
	int p = 0;
	for (int i = 0; i < str.length(); ++i)
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


int KMP(string str1, string str2)
{
	if (str1.empty() || str2.empty() || str2.length() > str1.length())
		return -1;
	int* index = new int[str1.length()];
	//��ȡ��ͬǰ׺����׺�ĳ���
	getIndex(index, str2);
	
	int i, j;
	i = j = 0;
	while (i < str1.length() && j < str2.length())
	{
		if (str1[i] == str2[j])
		{
			++i; 
			++j;
		}
		else if (index[j] == -1)//����ͷ��ʼ��
		{
			j = 0;
			++i;
		}
		else
		{
			j = index[j];//��������ͬǰ��׺
		}
	}
	delete[] index;
	return (i <= str1.length() && j >= str2.length());//str2�Ƿ�ƥ�����
}


void Test()
{
	string str1, str2;
	str1 = "abcabcababacc";
	str2 = "ababa";
	cout << KMP(str1, str2) << endl;
}
