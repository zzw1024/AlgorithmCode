#pragma once

#include <iostream>
#include <queue>

using namespace std;

//Problem:
//	����Ŀ�� ����һ�����;���matrix���밴��תȦ�ķ�ʽ��ӡ����
//	���磺 1 2 3 4 5 6 7 8 9 10 11 12 13 14
//	15 16 ��ӡ���Ϊ��1��2��3��4��8��12��16��15��14��13��9��
//	5��6��7��11�� 10
//	��Ҫ�� ����ռ临�Ӷ�ΪO(1)��
//
//Solution:
//	����һȦһȦ��ӡ�ķ�ʽ����ȷ�����Ͻ������½ǣ�Ȼ��������ڴ�ӡһȦ����ӡ����֮��
//	���Ͻ�������һһ�������½���������һ����������ӡ
//	���Ͻǵ���>���½ǵ��л������Ͻǵ��� > ���½ǵ��У� ���ӡ���
template<class T>
void RotatePrint(T arr, const int x, const int y)
{
	int lx = 0, ly = 0; //���Ͻ�����
	int rx = x - 1, ry = y - 1;//���½ǵ�����

	while (lx <= rx || ly <= ry)
	{
		if (lx == rx)
		{
			for (int i = ly; i <= ry; ++i)//��ӡһ�еľ���
				cout << arr[lx][i] << "  ";
		}
		else if (ly == ry)
		{
			for (int i = lx; i <= rx; ++i)//��ӡһ�еľ���
				cout << arr[i][ly] << "  ";
		}
		else 
		{  //��ӡ���ǵ��л��еľ���

			for (int i = ly; i < ry; ++i)//��ӡ����
				cout << arr[lx][i] << "  ";
			for (int i = lx; i < rx; ++i)//��ӡ����
				cout << arr[i][ry] << "  ";
			for (int i = ry; i > ly; --i)//��ӡ����
				cout << arr[rx][i] << "  ";
			for (int i = rx; i > lx; --i)//��ӡ����
				cout << arr[i][ly] << "  ";
		}

		lx += 1;//���Ͻ�������
		ly += 1;
		rx -= 1;//���½�������
		ry -= 1;
	}
	cout << endl << "******************************" << endl;

}


void Test()
{
	int aa[3][3] = { 1,2,3, 4,5,6, 7,8,9 };
	int bb[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	RotatePrint(aa, 3, 3);
	RotatePrint(bb, 3, 4);



}