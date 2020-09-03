#include "000库函数.h"

/*
	此为无向图
	Kruskal算法思想很简单，依托于按照权值升序的表格进行排序

	就是从顶点0开始，依次比较起始点到下一个点的最短路径，并将其更新
	然后仍以0为起点，在此在剩下的路径中找到最短值，然后根据其连接线，再次更新距离值
	直到所有点都遍历完为止！
*/

#include "000库函数.h"

#define MAXVEX 20
#define INFINITY 65535//视为无穷大

//临接矩阵的数据结构
struct MGraph {
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

//初始化临接矩阵
MGraph *CreateMGraph(MGraph *G) {
	G->numEdges = 15;
	G->numVertexes = 9;

	for (int i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (int j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}

	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	G->arc[1][2] = 18;
	G->arc[1][8] = 12;
	G->arc[1][6] = 16;
	G->arc[2][8] = 8;
	G->arc[2][3] = 22;
	G->arc[3][8] = 21;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][4] = 20;
	G->arc[4][7] = 7;
	G->arc[4][5] = 26;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;

	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
	return G;
}

//寻找下一个顶点位置
int Find(vector<int>parent, int v) {
	while (parent[v] > 0)v = parent[v];
	return v;
}


//使用MiniSpanTree_Kruskal生成最小树
void MiniSpanTree_Kruskal(MGraph *G) {
	int n, m;
	int k = 0;
	vector<int> Parent(MAXVEX, 0);//定义一个数组，用来判断是否形成了环路
	int Edge[MAXVEX][3];//权值表，存放起始点、终止点、权值
	//构建权值表
	for (int i = 0; i < G->numVertexes; ++i) {
		for (int j = i + 1; j < G->numVertexes; ++j) {
			if (G->arc[i][j] < INFINITY) {
				Edge[k][0] = i;
				Edge[k][1] = j;
				Edge[k][2] = G->arc[i][j];
				k++;
			}
		}
	}
	//进行排序
	for (int i = 0; i < k; ++i) {
		int min = Edge[i][2];
		for (int j = i + 1; j < k; ++j) {
			if (min > Edge[j][2]) {
				min = Edge[j][2];
				for (int t = 0; t < 3; ++t) {
					int temp;
					temp = Edge[i][t];
					Edge[i][t] = Edge[j][t];
					Edge[j][t] = temp;
				}
			}
		}
	}


	/*************************算法的核心*****************************/




	int adjvex[MAXVEX];//保存相关顶点的下标
	int lowcost[MAXVEX]; // 保存相关顶点间边的权值
	lowcost[0] = 0;//将v0顶点加入进来
	adjvex[0] = 0;//初始化第一个顶点为0
	for (int i = 1; i < G->numVertexes; ++i) {
		lowcost[i] = G->arc[0][i];//先将v0能到其他点的距离记录下来
		adjvex[i] = 0;//即到达每个点的起始点都为0点
	}

	for (int i = 0; i < k; ++i) {//循环每一个权值矩阵
		n = Find(Parent, Edge[i][0]);
		m = Find(Parent, Edge[i][1]);
		if (n != m) {//不会形成环，可以使用
			Parent[n] = m;
			cout << Edge[i][0] << "," << Edge[i][1] << endl;
		}
	}
}

	

int T026(void) {
	MGraph *G;
	G = new MGraph;//初始化图
	G = CreateMGraph(G);
	MiniSpanTree_Kruskal(G);

	return 0;

}