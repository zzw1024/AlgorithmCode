/*

*/


#include "000库函数.h"

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

struct MGraph{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

//创建图的信息
MGraph * CreateMGraph(MGraph *G)
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
	G->numEdges = 16;
	G->numVertexes = 9;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}

	G->arc[0][1] = 1;
	G->arc[0][2] = 5;
	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;
	G->arc[3][4] = 2;
	G->arc[3][6] = 3;
	G->arc[4][5] = 3;

	G->arc[4][6] = 6;
	G->arc[4][7] = 9;
	G->arc[5][7] = 5;
	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;


	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
	return G;

}

void  ShortestPath_Dijkstra(MGraph *G) {
	vector<int>Res(MAXVEX, 0);//假设每个点的前向点都是v0点
	vector<int>Dis;//用来更新距离
	vector<bool>flag(MAXVEX, true);//记录已经遍历过的点
	int num = 0;//记录已经遍历过几个点了

	for (int i = 0; i < G->numVertexes; ++i) 
		Dis.push_back(G->arc[0][i]);//首先假设0到各个点的距离为最短路径，在此基础上进行更新

	int start = 0;//起始点
	flag[start] = false;//该点踢出下次的选择范围
	++num;//记录遍历过的点

	while (num < G->numVertexes) {
		int min = INFINITY;//最小值
		for (int j = 1; j < G->numVertexes; ++j) {
			if (flag[j] && min > Dis[j]) {//从剩下的点中找到距离最小的值
				min = Dis[j];
				start = j;
			}
		}

		flag[start] = false;//该点踢出下次的选择范围
		++num;//记录遍历过的点

		for (int i = 0; i < G->numVertexes; ++i) {
			if (flag[i] && G->arc[start][i] + Dis[start] < Dis[i]) {//经过start点再到达点i的距离是否比原来的短？
				Dis[i] = G->arc[start][i] + Dis[start];//更短就更新为更短的距离
				Res[i] = start;//更新前向点为start
			}
		}
	}
	
	stack<int>s;
	int end = G->numVertexes - 1;//记录

	while (end) {//使用压栈进行回溯出起始点到终点的路径
		s.push(end);
		end = Res[end];
	}
	s.push(end);

	while (!s.empty()) {//打印出路径
		cout << s.top() << "->";
		s.pop();
	}
	cout << endl << "总距离为：" << Dis[G->numVertexes - 1] << endl;
}


int T027(void) {
	int i, j, v0;
	MGraph *G;
	G = new MGraph;
	G = CreateMGraph(G);

	ShortestPath_Dijkstra(G);
	return 0;
}

