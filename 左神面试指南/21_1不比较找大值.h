#pragma once
#include <iostream>
#include <vector>

using namespace std;



//����������a��b����β��ñȽ�����������ؽϴ����

//ʹ��λ����

int whoIsBig(int a, int b)
{
	//���ж�����
	if (a^(1 << 31) == a && b^(1 << 31) != b )
		return a;
	if (a ^ (1 << 31) != a && b ^ (1 << 31) == b)
		return b;
	for (int i = 30; i >= 0; --i)
	{
		if ((a&(1 << i)) == (b&(1 << i)))//��λ��ͬ
			continue;
		if ((((a)&(1 << i)) >> i) == 1)
			return a;
		else
			return b;
	}
	return -1;
}

int whoIsBig2(int a, int b)
{
	//�õ���������  ��Ϊ1����Ϊ0
	int singA = (a >> 31) ^ 1;
	int singB = (b >> 31) ^ 1;
	int singC = ((a - b) >> 31) ^ 1;
	if (singA == 1 && singB == 0)
		return a;
	if (singA == 0 && singB == 1)
		return b;
	if (singC == 1)
		return a;
	else return b;

}

void Test()
{
	cout << whoIsBig2(-5, -7) << endl;
	cout << whoIsBig2(5, 5) << endl;
	cout << whoIsBig2(10, 6) << endl;
	cout << whoIsBig2(-10, 6) << endl;
	cout << whoIsBig2(2147483647, -2147480000) << endl;
}