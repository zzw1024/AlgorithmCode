#include "000�⺯��.h"
/*
	����������
		��8*8�Ĺ����������У�������������λ���ϣ��������ߴ��յ��߷�
		�ܹ��߱����̵�����λ��
		
*/
#define X 8
#define Y 8

int chess[X][Y];

//���ߴ��յ��߷�
int nextxy(int *x, int *y, int count)
{
	switch (count)
	{
	case 0:
		if (*x + 2 <= X - 1 && *y - 1 >= 0 && chess[*x + 2][*y - 1] == 0)
		{
			*x = *x + 2;
			*y = *y - 1;
			return 1;
		}
		break;

	case 1:
		if (*x + 2 <= X - 1 && *y + 1 <= Y - 1 && chess[*x + 2][*y + 1] == 0)
		{
			*x = *x + 2;
			*y = *y + 1;
			return 1;
		}
		break;

	case 2:
		if (*x + 1 <= X - 1 && *y - 2 >= 0 && chess[*x + 1][*y - 2] == 0)
		{
			*x = *x + 1;
			*y = *y - 2;
			return 1;
		}
		break;

	case 3:
		if (*x + 1 <= X - 1 && *y + 2 <= Y - 1 && chess[*x + 1][*y + 2] == 0)
		{
			*x = *x + 1;
			*y = *y + 2;
			return 1;
		}
		break;

	case 4:
		if (*x - 2 >= 0 && *y - 1 >= 0 && chess[*x - 2][*y - 1] == 0)
		{
			*x = *x - 2;
			*y = *y - 1;
			return 1;
		}
		break;

	case 5:
		if (*x - 2 >= 0 && *y + 1 <= Y - 1 && chess[*x - 2][*y + 1] == 0)
		{
			*x = *x - 2;
			*y = *y + 1;
			return 1;
		}
		break;

	case 6:
		if (*x - 1 >= 0 && *y - 2 >= 0 && chess[*x - 1][*y - 2] == 0)
		{
			*x = *x - 1;
			*y = *y - 2;
			return 1;
		}
		break;

	case 7:
		if (*x - 1 >= 0 && *y + 2 <= Y - 1 && chess[*x - 1][*y + 2] == 0)
		{
			*x = *x - 1;
			*y = *y + 2;
			return 1;
		}
		break;

	default:
		break;
	}

	return 0;
}
//ʹ�û��ݷ����б���
int TravelChessBoard(int x,int y,int &c) {
	chess[x][y] = 1;//����Ѿ��߹�
	cout << x << "  " << y << endl;
	c++;
	for (int i = 0; i < 8; ++i) {//�ܹ�7�����
		if (nextxy(&x, &y, i))
			TravelChessBoard(x, y, c);
	}

	return 1;
}

int T024()
{
	int i, j;
	clock_t start, finish;

	start = clock();//��ʱ
	//���̳�ʼ��
	for (i = 0; i < X; i++)	{
		for (j = 0; j < Y; j++) {
			chess[i][j] = 0;
		}
	}
	//�����߹��Ĳ���
	int count = 0;
	if (!TravelChessBoard(2, 0, count)){
		printf("��Ǹ����̤����ʧ����~\n");
	}

	finish = clock();
	printf("\n���μ���һ����ʱ: %f��\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
	cout << count << endl;
	return 0;
}