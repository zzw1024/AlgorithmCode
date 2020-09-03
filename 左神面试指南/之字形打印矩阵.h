#pragma once
#include <iostream>

using namespace std;

//Problem:
//	��֮�����δ�ӡ������Ŀ�� ����һ������matrix�����ա�֮�����εķ�ʽ��ӡ�������
//	���磺 1 2 3 4 5 6 7 8 9  10 11 12
//	��֮�����δ�ӡ�Ľ��Ϊ��1��2��5��9��6��3��4��7��10��11��8��12
//	��Ҫ�� ����ռ临�Ӷ�ΪO(1��
//
//Solution:
//	ʹ��A,B�������꣬��ʼֵΪ��0��0������0��0����A,B������Ϊ֮���ε�б��
//	A�ƶ�����Ϊ�����ߣ�B�ƶ�����Ϊ�����ߣ�A�����ұ��˾������ߣ�B���������˾�������
//  ʹ��һ��boolֵ���ж��������Ϸ��������A-Bֱ�ߣ����������½Ƿ������A-Bֱ��
//		A 
//		|
//	B-  1 2 3 4 
//		5 6 7 8
//		9 1 0 5

template<class T>
void ZiPrint(const T arr, const int x, const int y)
{
	int Ax = 0, Ay = 0;//��ʼ��A,B������
	int Bx = 0, By = 0;
	bool flag = true;//trueΪ���Ϸ���������� falseΪ���½Ƿ������

	while (Ax <= x-1 && Ay <= y-1)//A�����½Ǿͱ������
	{
		if(flag)//���Ϸ��������
		{
			int Tx = Bx, Ty = By;
			while (Tx >= Ax || Ty <= Ay)
			{
				cout << arr[Tx][Ty] << "  ";
				Tx -= 1;
				Ty += 1;
			}
			flag = false;
		}
		else//�����½Ƿ������
		{
			int Tx = Ax, Ty = Ay;
			while (Tx <= Bx || Ty >= By)
			{
				cout << arr[Tx][Ty] << "  ";
				Tx += 1;
				Ty -= 1;
			}
			flag = true;
		}
		//����A,B
		if (Ay < y - 1)
			Ay += 1;
		else
			Ax += 1;

		if (Bx < x - 1)
			Bx += 1;
		else
			By += 1;

	}
	cout << endl;

}

void Test()
{
	int aa[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	ZiPrint(aa, 3, 4);
}