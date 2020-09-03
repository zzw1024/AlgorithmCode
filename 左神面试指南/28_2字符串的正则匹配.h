#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//
//����Ŀ��
//	�����ַ���str�����о��Բ������ַ�'.'��'*'���ٸ����ַ���exp��
//	���п��Ժ���'.'��'*'��'*'�ַ�������exp�����ַ���������������
//	'*'�ַ������ڡ�exp�е�'.'�����κ�һ���ַ���exp�е�'*'��ʾ'*' ��ǰһ���ַ�����
//	��0�����߶������дһ���������ж�str�Ƿ��ܱ�expƥ�䡣
//	��������
//		str = "abc"��exp = "abc"������true��
//		str = "abc"��exp = "a.c"��exp�е���'.'���Դ��������ַ������Է���
//		true��
//	str = "abcd"��exp = ".*"��exp��'*'��ǰһ���ַ���'.'�����Կɱ�ʾ��
//	��������'.'�ַ�����exp��"...."ʱ��"abcd"ƥ�䣬����true��
//	str = ""��exp = "..*"��exp��'*'��ǰһ���ַ���'.'���ɱ�ʾ��������
//	��'.'�ַ�������".*"֮ǰ����һ��'.'�ַ������ַ�����'*'��Ӱ�죬
//	����str������һ���ַ����ܱ�expƥ�䡣���Է���false��
//
//����⡿
//	1��ʹ�õݹ�
//		str   i
//		exp  j
//		func(i, j)�����ж�str��i������ַ��ܲ�����exp��j������ַ������
//		���ȹ۲�j + 1��λ�ã�
//		j + 1��ĩβ��
//		j + 1Ϊ*��
//		j + 1����*����ôi��j����ƥ�䡾j������.��
//
///ʹ�õݹ�
bool isValid(string str, string exp)//�����ж��ַ��Ƿ�������ĿҪ��
{
	for (auto c : str)
		if (c == '*' || c == '.')
			return false;
	for (int i = 0; i < exp.length(); ++i)
		if (exp[i] == '*' && (i == 0 || exp[i - 1] == '*'))
			return false;
	return true;
}

bool  process(string str, int p, string exp, int q)
{
	if (q == exp.length())//�ﵽ�߽���
		return p == str.length();
	if (q + 1 == exp.length() || exp[q + 1] != '*')
		return p != str.length() && (exp[q] == str[p] || exp[q] == '.') && process(str, p + 1, exp, q + 1);
	while (p != str.length() && (exp[q] == str[p] || exp[q] == '.'))
	{
		if (process(str, p, exp, q + 2))
			return true;
		++p;
	}
	return process(str, p, exp, q+2);
}

bool isMatching(string str, string exp)
{
	if (str.length() == 0 || exp.length() == 0)
		return false;
	return isValid(str, exp) ? process(str, 0, exp, 0) : false;
}

///ʹ�ö�̬�滮
bool isMatchDP(string str, string exp)
{
	if (str.length() == 0 || exp.length() == 0)
		return false;

	if (!isValid(str, exp))
		return false;

	vector<vector<bool>>dp(str.length() + 1, vector<bool>(exp.length()+1, 0));
	dp[str.length()][exp.length()] = true;
	for (int i = exp.length() - 2; i > -1; i -= 2)
	{
		if (exp[i] != '*' && exp[i + 1] == '*')
			dp[str.length()][i] = true;
		else
			break;
	}
	if (str.length() > 0 && exp.length() > 0)
		if (exp[exp.length() - 1] == '.' || str[str.length() - 1] == exp[exp.length() - 1])
			dp[str.length() - 1][exp.length() - 1] = true;

	for (int i = str.length() - 1; i > -1; --i)
		for (int j = exp.length() - 2; j > -1; --j)
		{
			if (exp[j + 1] != '*')
				dp[i][j] = (str[i] == exp[j] || exp[j] == '.') && dp[i + 1][j + 1];
			else
			{
				int p = i;
				while (p != str.length() && (str[p] == exp[j] || exp[j] == '.'))
				{
					if (dp[p][j + 2])
					{
						dp[i][j] = true;
						break;
					}
					++p;
				}
				if (dp[i][j] != true)
					dp[i][j] = dp[p][j + 2];
			}
		}
	return dp[0][0];
}

void Test()
{
	string str, exp;
	str = "abcccdefg";
	exp = "abcccdefg";

	cout << isMatching(str, exp) << endl;
	cout << isMatchDP(str, exp) << endl;
}
