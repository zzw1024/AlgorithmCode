#include "000�⺯��.h"

/*
	��Ϊ����ͼ
	Kruskal�㷨˼��ܼ򵥣������ڰ���Ȩֵ����ı���������

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

//Ѱ����һ������λ��
int Find(vector<int>parent, int v) {
	while (parent[v] > 0)v = parent[v];
	return v;
}


//ʹ��MiniSpanTree_Kruskal������С��
void MiniSpanTree_Kruskal(MGraph *G) {
	int n, m;
	int k = 0;
	vector<int> Parent(MAXVEX, 0);//����һ�����飬�����ж��Ƿ��γ��˻�·
	int Edge[MAXVEX][3];//Ȩֵ�������ʼ�㡢��ֹ�㡢Ȩֵ
	//����Ȩֵ��
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
	//��������
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


	/*************************�㷨�ĺ���*****************************/




	int adjvex[MAXVEX];//������ض�����±�
	int lowcost[MAXVEX]; // ������ض����ߵ�Ȩֵ
	lowcost[0] = 0;//��v0����������
	adjvex[0] = 0;//��ʼ����һ������Ϊ0
	for (int i = 1; i < G->numVertexes; ++i) {
		lowcost[i] = G->arc[0][i];//�Ƚ�v0�ܵ�������ľ����¼����
		adjvex[i] = 0;//������ÿ�������ʼ�㶼Ϊ0��
	}

	for (int i = 0; i < k; ++i) {//ѭ��ÿһ��Ȩֵ����
		n = Find(Parent, Edge[i][0]);
		m = Find(Parent, Edge[i][1]);
		if (n != m) {//�����γɻ�������ʹ��
			Parent[n] = m;
			cout << Edge[i][0] << "," << Edge[i][1] << endl;
		}
	}
}

	

int T026(void) {
	MGraph *G;
	G = new MGraph;//��ʼ��ͼ
	G = CreateMGraph(G);
	MiniSpanTree_Kruskal(G);

	return 0;

}