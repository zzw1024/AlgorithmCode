#include <iostream>
#include <vector>
#include <stack>

#define INF 9999
using namespace std;


void FindPath(const vector<vector<int>>& Lin, vector<int>& Pot, vector<int>& Path, vector<int>& Dis)
{
	while (1)
	{
		vector<int>Temp;
		int min, r;

		min = INF + 1;//寻找最短距离
		r = -1;//找到的最近点		
		//寻找最小值
		for (int i = 0; i < Dis.size(); ++i)
		{
			if (Pot[i] && min > Dis[i])
			{
				r = i;
				min = Dis[i];
			}
		}
		if (r < 0)
			break;
		Pot[r] = 0;//去除已走过的路径
		Temp = Lin[r];
		for (int i = 0; i < Temp.size(); ++i)
		{
			if (Temp[i] + Dis[r] < Dis[i])
			{
				Dis[i] = Temp[i] + Dis[r];
				Path[i] = r;//更新父节点
			}
		}
	}
}

void Dijkstra()
{
	int N, M;
	cout << "Please input the number of Pot and End: " << endl;
	cin >> N >> M;
	//临接矩阵
	vector<vector<int>>Lin(N, vector<int>(N, INF));
	/*int a[15][3]= { {0,1,10},{0,5,11},{1,8,12},{1,6,16},{1,2,18},{2,8,8},{2,3,22},
					 {3,7,16},{3,4,20},{3,8,21},{3,6,35},{4,7,7},{4,5,26},{5,6,17},
					{6,7,19} };*/

	cout << "Please input the weight of Edge:" << endl;
	for (int i = 0; i < M; ++i)
	{
		int a, b, weight;
		cin >> a >> b >> weight;
		if (a < 0 || a >= N || b < 0 || b >= N)
		{
			cout << "输出有误" << endl;
			break;
		}
		Lin[a][b] = weight;
		/*Lin[a[i][0]][a[i][1]] = a[i][2];
		Lin[a[i][1]][a[i][0]] = a[i][2];*/
	}

	vector<int>Pot(N, 1);
	int Start;
	cout << "请输入起始点： " << endl;
	cin >> Start;
	int End;
	cout << "请输入起终止点： " << endl;
	cin >> End;


	if (Start < 0 || Start >= N)
		cout << "输入有误！" << endl;
	Pot[Start] = 0;
	vector<int>Path(N, Start);
	vector<int>Dis = Lin[Start];

	FindPath(Lin, Pot, Path, Dis);

	//输出最优路线：
	stack<int>route;
	route.push(End);
	while (End != Start)
	{
		End = Path[End];
		route.push(End);
	}

	while (!route.empty())
	{
		cout << route.top() << "->";
		route.pop();
	}

	
}