
#include "000库函数.h"

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

struct MGraph {
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

void ShortestPath_Floyd(MGraph *G) {
	int Dis[MAXVEX][MAXVEX];//距离阵，进行更新
	int Path[MAXVEX][MAXVEX];//路径前向点的矩阵

	for (int i = 0; i < G->numVertexes; ++i) {
		for (int j = 0; j < G->numVertexes; ++j) {
			Dis[i][j] = G->arc[i][j];//将初始的临接矩阵赋值过来当初始距离阵
			Path[i][j] = j;//初始化路径的前向点
		}
	}

	for (int k = 0; k < G->numVertexes; ++k) {
		for (int i = 0; i < G->numVertexes; ++i) {
			for (int j = 0; j < G->numVertexes; ++j) {
				if (Dis[i][k] + Dis[k][j] < Dis[i][j]) {//i经过k到j的距离会不会比直接到j的距离短？
					Dis[i][j] = Dis[i][k] + Dis[k][j];//更新i到j的距离
					Path[i][j] = Path[i][k];//i到j的路径中，要先从i到k
				}
			}
		}
	}
	
	for (int i = 0; i < G->numVertexes; ++i) {
		int start = 0;//起始点固定为0
		vector<int>s;
		s.push_back(start);
		cout << "起点 0 到 " << i << " 的最短路径为： " << endl;
		while (s.size() < i) {
			start = Path[start][i];
			s.push_back(start);
		}
		for (auto a : s)
			cout << a << "—>";
		cout << "最短距离为：" << Dis[0][i] << endl;
	}
}

void T028() {

	MGraph *G;
	G = new MGraph;
	G = CreateMGraph(G);
	ShortestPath_Floyd(G);
}