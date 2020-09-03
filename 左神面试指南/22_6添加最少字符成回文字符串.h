#pragma once
#include <iostream>
#include <string>

using namespace std;

//Problem:
//	Manacher�㷨��չ��Ŀ
//	����һ���ַ���str1��ֻ����str1�ĺ�������ַ����str2��Ҫ��str2
//	���嶼�ǻ��Ĵ�����̡�
//	������
//	str1 = ABC12321, ����ABC12321CBA
//
//Solution:
//	ʹ��Manacher�㷨���Ҵ���Ļ����ַ�
//


string getStr(string str)
{
	string newStr = "#";
	//�ַ�Ԥ����
	for (auto c : str)
		newStr = newStr + c + "#";

	int* rArry = new int[newStr.length()];//���İ뾶��¼
	int c = -1;//��������
	int R = -1;//�����ұ߽� Rλ�ڻ��ĶԳ��ұ߽���ұ�һ����ĸ
	int maxL = INT_MIN;//��¼������ֳ�
	int p = str.length() - 1;//��Ҫ���Ÿ��Ƶ��ַ�λ��
	for (int i = 0; i < newStr.length(); ++i)
	{
		//��һ��ֱ��ȡ�ÿ��ܵ���̵Ļ��İ뾶����i>Rʱ����̵Ļ��İ뾶��1��
		//��֮����̵Ļ��İ뾶������i��Ӧ��i'�Ļ��İ뾶����i��R�ľ���
		if (R > i)
			rArry[i] = rArry[2 * c - i] < R - i ? rArry[2 * c - i] : R - i;
		else
			rArry[i] = 1;
		//ȡ��Сֵ��ʼ�ӱ߽籩��ƥ�䣬ƥ��ʧ�ܾ�ֱ���˳�
		while (i + rArry[i] < newStr.length() && i - rArry[i] > -1)
		{
			if (newStr[i + rArry[i]] == newStr[i - rArry[i]])//��������չ���һ�����ĸ
				rArry[i]++;
			else
				break;
		}
		//�۲��ʱR��C�Ƿ��ܹ�����
		if (i + rArry[i] > R)
		{
			R = i + rArry[i];
			c = i;
		}
		if (R == newStr.length())//�����ұ߽絽�������֪�����ַ�ĩβΪ����
			int p = (newStr.length() - 2 * rArry[c]) / 2;//�õ���Ҫ��ӵ��ַ�
	}
	//�ж��ַ������Ƿ�Ϊ�����ַ�
	//���ǣ�����ı߽���������ַ�λ����
	for (int i = p; i >= 0; --i)
		str += str[i];

	delete[] rArry;
	return str;
}

void Test()
{
	string str;
	str = "abc12321";
	cout << str << endl;
	cout << getStr(str) << endl << endl;
	str = "abc123";
	cout << str << endl;
	cout << getStr(str) << endl << endl;
	str = "abc1234321ab";
	cout << str << endl;
	cout << getStr(str) << endl << endl;
}
