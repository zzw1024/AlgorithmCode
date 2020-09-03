#pragma once

#include <iostream>


using namespace std;
//
//Problem��
//	��ת�����ξ�����Ŀ�� ����һ�����������ξ���matrix��
//	��Ѹþ��������˳ʱ����ת90�ȵ����ӡ�
//	��Ҫ�� ����ռ临�Ӷ�ΪO(1).
//
//Solution:
//	ͬ����������������һȦһȦ�任���ҵ�Ԫ�ر任λ�õĹ��ɼ��ɡ�
//	�ѵ���������ż��ά���������ά����Ĳ�ͬ����

template<class T>
void RotateMatrix(T& arr,const int x, const int y)//ʹ����������ô��Σ�������ԭ�����Ͻ�����ת
{
	int lx = 0, ly = 0; //���Ͻ�����
	int rx = x - 1, ry = y - 1;//���½ǵ�����

	while (lx < rx || ly < ry)
	{

		for (int k = 0; k < ry - ly; ++k)//ÿһ��Ȧ������Ҫ��ת��Ԫ��
		{
			int temp = arr[lx][ly + k];
			arr[lx][ly + k] = arr[rx - k][lx];
			arr[rx - k][lx] = arr[rx][ry - k];
			arr[rx][ry - k] = arr[lx + k][ry];
			arr[lx + k][ry] = temp;
		}

		lx += 1;//���Ͻ�������
		ly += 1;
		rx -= 1;//���½�������
		ry -= 1;
	}
	
}

void Test()
{
	int aa[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int bb[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	RotateMatrix(aa, 3, 3);
	for (auto &a : aa)
	{
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl << "******************************" << endl;

	RotateMatrix(bb, 4, 4);
	for (auto &a : bb)
	{
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl << "******************************" << endl;


}