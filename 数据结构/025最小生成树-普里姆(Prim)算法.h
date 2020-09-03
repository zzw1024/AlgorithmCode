/*
	此为无向图
	Prim算法思想很简单，依托临接矩阵
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

//使用Prim算法生成最小树
void MiniSpanTree_Prim(MGraph *G) {
	int min, i, j, k;
	int adjvex[MAXVEX];//保存相关顶点的下标
	int lowcost[MAXVEX]; // 保存相关顶点间边的权值
	lowcost[0] = 0;//将v0顶点加入进来
	adjvex[0] = 0;//初始化第一个顶点为0
	for (int i = 1; i < G->numVertexes; ++i) {
		lowcost[i] = G->arc[0][i];//先将v0能到其他点的距离记录下来
		adjvex[i] = 0;//即到达每个点的起始点都为0点
	}

	for (int i = 1; i < G->numVertexes; ++i) {
		min = INFINITY;//将最短路径设为无穷
		j = 1; k = 0;
		while (j < G->numVertexes) {
			if (lowcost[j] != 0 && lowcost[j] < min) {//找到点0到下一个距离最短的值
				min = lowcost[j];//
				k = j;//记住最小值的点
			}
			++j;
		}

		printf("(%d, %d)\n", adjvex[k], k);
		lowcost[k] = 0;//重新以点k为起始点，然后继续寻找下一个最短路径
		for (j = 1; j < G->numVertexes; ++j) {
			if (lowcost[j] != 0 && G->arc[k][j] < lowcost[j]) {//找到下一个最短路劲
				lowcost[j] = G->arc[k][j];
				adjvex[j] = k;
			}
		}

	}
}

int T025(void){
	MGraph *G;
	G = new MGraph;//初始化图
	G = CreateMGraph(G);
	MiniSpanTree_Prim(G);

	return 0;

}