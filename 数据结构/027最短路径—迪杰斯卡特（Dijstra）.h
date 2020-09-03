/*

*/


#include "000�⺯��.h"

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

struct MGraph{
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

void  ShortestPath_Dijkstra(MGraph *G) {
	vector<int>Res(MAXVEX, 0);//����ÿ�����ǰ��㶼��v0��
	vector<int>Dis;//�������¾���
	vector<bool>flag(MAXVEX, true);//��¼�Ѿ��������ĵ�
	int num = 0;//��¼�Ѿ���������������

	for (int i = 0; i < G->numVertexes; ++i) 
		Dis.push_back(G->arc[0][i]);//���ȼ���0��������ľ���Ϊ���·�����ڴ˻����Ͻ��и���

	int start = 0;//��ʼ��
	flag[start] = false;//�õ��߳��´ε�ѡ��Χ
	++num;//��¼�������ĵ�

	while (num < G->numVertexes) {
		int min = INFINITY;//��Сֵ
		for (int j = 1; j < G->numVertexes; ++j) {
			if (flag[j] && min > Dis[j]) {//��ʣ�µĵ����ҵ�������С��ֵ
				min = Dis[j];
				start = j;
			}
		}

		flag[start] = false;//�õ��߳��´ε�ѡ��Χ
		++num;//��¼�������ĵ�

		for (int i = 0; i < G->numVertexes; ++i) {
			if (flag[i] && G->arc[start][i] + Dis[start] < Dis[i]) {//����start���ٵ����i�ľ����Ƿ��ԭ���Ķ̣�
				Dis[i] = G->arc[start][i] + Dis[start];//���̾͸���Ϊ���̵ľ���
				Res[i] = start;//����ǰ���Ϊstart
			}
		}
	}
	
	stack<int>s;
	int end = G->numVertexes - 1;//��¼

	while (end) {//ʹ��ѹջ���л��ݳ���ʼ�㵽�յ��·��
		s.push(end);
		end = Res[end];
	}
	s.push(end);

	while (!s.empty()) {//��ӡ��·��
		cout << s.top() << "->";
		s.pop();
	}
	cout << endl << "�ܾ���Ϊ��" << Dis[G->numVertexes - 1] << endl;
}


int T027(void) {
	int i, j, v0;
	MGraph *G;
	G = new MGraph;
	G = CreateMGraph(G);

	ShortestPath_Dijkstra(G);
	return 0;
}

