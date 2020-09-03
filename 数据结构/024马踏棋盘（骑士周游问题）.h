#include "000库函数.h"
/*
	问题描述：
		在8*8的国际象棋盘中，把马放在任意的位置上，按照马走大日的走法
		能够走遍棋盘的所有位置
		
*/
#define X 8
#define Y 8

int chess[X][Y];

//马走大日的走法
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
//使用回溯法进行遍历
int TravelChessBoard(int x,int y,int &c) {
	chess[x][y] = 1;//标记已经走过
	cout << x << "  " << y << endl;
	c++;
	for (int i = 0; i < 8; ++i) {//总共7种情况
		if (nextxy(&x, &y, i))
			TravelChessBoard(x, y, c);
	}

	return 1;
}

int T024()
{
	int i, j;
	clock_t start, finish;

	start = clock();//计时
	//棋盘初始化
	for (i = 0; i < X; i++)	{
		for (j = 0; j < Y; j++) {
			chess[i][j] = 0;
		}
	}
	//计算走过的步数
	int count = 0;
	if (!TravelChessBoard(2, 0, count)){
		printf("抱歉，马踏棋盘失败鸟~\n");
	}

	finish = clock();
	printf("\n本次计算一共耗时: %f秒\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
	cout << count << endl;
	return 0;
}