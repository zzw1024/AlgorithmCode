#include <iostream>
#include <vector>
#include <stack>

#define INF 9999
#define N 100

using namespace std;

void ShortPath(const int a[][N], int Start, int n)
{
	int Is[N] = { 0 };//判断是否该点已经遍历了
	Is[Start] = 1;

	int Dis[N] = { 0 };//记录距离值
	int Pot[N] = { 0 };//每个点的父节点记录

	for (int i = 1; i <= n; ++i)
	{
		if (i != Start)
			Dis[i] = a[Start][i];
		else
			Dis[i] = 0;

		Pot[i] = Start;//假设每个点的父节点都为Start
	}


	for (int i = 1; i <= n; ++i)
	{
		int m = INF;
		int r = Start;
		//每次从最短距离点出发
		for (int j = 1; j <= n; ++j)
		{
			if (Is[j] == 0 && m > Dis[j])
			{
				r = j;
				m = Dis[j];
			}
		}

		if (r == Start)
			break;

		Is[r] = 1;//剔除已遍历的点

		//与Dijkstra的重点区别：不是更新记录点，而是遍历了就可以，因为下次就从该点遍历到下一个点
		for (int j = 1; j <= n; ++j)
		{
			if (Is[j] == 0 && a[r][j] < Dis[j])
			{
				Dis[j] = a[r][j];
				Pot[j] = r;
			}
		}
	}

	//输出花费
	for (auto a : Dis)
	{
		cout << a << "  ";
	}
	cout << endl;


}



void  Prim()
{
	int c[N][N];
	int n, m;
	cout << "请输入图的顶点数与边：";
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			c[i][j] = INF;

	cout << "请输入节点v与u的权重value：" << endl;
	/*int a[15][3] = { {0,1,10},{0,5,11},{1,8,12},{1,6,16},{1,2,18},{2,8,8},{2,3,22},
					 {3,7,16},{3,4,20},{3,8,21},{3,6,35},{4,7,7},{4,5,26},{5,6,17},
					{6,7,19} }; */
	for (int i = 1; i <= m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		c[a][b] = c[b][a] = w;

		//c[a[i-1][0]+1][a[i-1][1]+1] = a[i-1][2];
		//c[a[i-1][1]+1][a[i-1][0]+1] = a[i-1][2];
	}
	cout << "请输入起始节点：";
	int Start;
	cin >> Start;

	ShortPath(c, Start, n);



}