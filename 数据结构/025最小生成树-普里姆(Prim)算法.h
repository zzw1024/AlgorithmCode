/*
	��Ϊ����ͼ
	Prim�㷨˼��ܼ򵥣������ٽӾ���
	���ǴӶ���0��ʼ�����αȽ���ʼ�㵽��һ��������·�������������
	Ȼ������0Ϊ��㣬�ڴ���ʣ�µ�·�����ҵ����ֵ��Ȼ������������ߣ��ٴθ��¾���ֵ
	ֱ�����е㶼������Ϊֹ��
*/

#include "000�⺯��.h"

#define MAXVEX 20
#define INFINITY 65535//��Ϊ�����

//�ٽӾ�������ݽṹ
struct MGraph {
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

//��ʼ���ٽӾ���
MGraph *CreateMGraph(MGraph *G) {
	G->numEdges = 15;
	G->numVertexes = 9;

	for (int i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
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

//ʹ��Prim�㷨������С��
void MiniSpanTree_Prim(MGraph *G) {
	int min, i, j, k;
	int adjvex[MAXVEX];//������ض�����±�
	int lowcost[MAXVEX]; // ������ض����ߵ�Ȩֵ
	lowcost[0] = 0;//��v0����������
	adjvex[0] = 0;//��ʼ����һ������Ϊ0
	for (int i = 1; i < G->numVertexes; ++i) {
		lowcost[i] = G->arc[0][i];//�Ƚ�v0�ܵ�������ľ����¼����
		adjvex[i] = 0;//������ÿ�������ʼ�㶼Ϊ0��
	}

	for (int i = 1; i < G->numVertexes; ++i) {
		min = INFINITY;//�����·����Ϊ����
		j = 1; k = 0;
		while (j < G->numVertexes) {
			if (lowcost[j] != 0 && lowcost[j] < min) {//�ҵ���0����һ��������̵�ֵ
				min = lowcost[j];//
				k = j;//��ס��Сֵ�ĵ�
			}
			++j;
		}

		printf("(%d, %d)\n", adjvex[k], k);
		lowcost[k] = 0;//�����Ե�kΪ��ʼ�㣬Ȼ�����Ѱ����һ�����·��
		for (j = 1; j < G->numVertexes; ++j) {
			if (lowcost[j] != 0 && G->arc[k][j] < lowcost[j]) {//�ҵ���һ�����·��
				lowcost[j] = G->arc[k][j];
				adjvex[j] = k;
			}
		}

	}
}

int T025(void){
	MGraph *G;
	G = new MGraph;//��ʼ��ͼ
	G = CreateMGraph(G);
	MiniSpanTree_Prim(G);

	return 0;

}