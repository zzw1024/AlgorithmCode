#pragma once
#include "000�⺯��.h"

int Fbi(int n) {
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fbi(n - 1) + Fbi(n - 2);
}

int T010()
{
	int i;
	int a[40];
	printf("������ʾ쳲��������У�\n");
	a[0] = 0;
	a[1] = 1;
	printf("%d ", a[0]);
	printf("%d ", a[1]);
	for (i = 2; i < 40; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("�ݹ���ʾ쳲��������У�\n");
	for (i = 0; i < 40; i++)
		printf("%d ", Fbi(i));
	return 0;
}

