
#include "000�⺯��.h"

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

struct MGraph {
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

//����ͼ����Ϣ
MGraph * CreateMGraph(MGraph *G)
{
	int i, j;

	/* printf("����������Ͷ�����:"); */
	G->numEdges = 16;
	G->numVertexes = 9;

	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
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
	int Dis[MAXVEX][MAXVEX];//�����󣬽��и���
	int Path[MAXVEX][MAXVEX];//·��ǰ���ľ���

	for (int i = 0; i < G->numVertexes; ++i) {
		for (int j = 0; j < G->numVertexes; ++j) {
			Dis[i][j] = G->arc[i][j];//����ʼ���ٽӾ���ֵ��������ʼ������
			Path[i][j] = j;//��ʼ��·����ǰ���
		}
	}

	for (int k = 0; k < G->numVertexes; ++k) {
		for (int i = 0; i < G->numVertexes; ++i) {
			for (int j = 0; j < G->numVertexes; ++j) {
				if (Dis[i][k] + Dis[k][j] < Dis[i][j]) {//i����k��j�ľ���᲻���ֱ�ӵ�j�ľ���̣�
					Dis[i][j] = Dis[i][k] + Dis[k][j];//����i��j�ľ���
					Path[i][j] = Path[i][k];//i��j��·���У�Ҫ�ȴ�i��k
				}
			}
		}
	}
	
	for (int i = 0; i < G->numVertexes; ++i) {
		int start = 0;//��ʼ��̶�Ϊ0
		vector<int>s;
		s.push_back(start);
		cout << "��� 0 �� " << i << " �����·��Ϊ�� " << endl;
		while (s.size() < i) {
			start = Path[start][i];
			s.push_back(start);
		}
		for (auto a : s)
			cout << a << "��>";
		cout << "��̾���Ϊ��" << Dis[0][i] << endl;
	}
}

void T028() {

	MGraph *G;
	G = new MGraph;
	G = CreateMGraph(G);
	ShortestPath_Floyd(G);
}