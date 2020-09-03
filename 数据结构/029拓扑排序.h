#include "000�⺯��.h"

#define MAXEDGE 20
#define MAXVEX 14
#define INFINITY 65535

//�ٽӾ���ṹ��ʼ��
struct MGraph {
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

//�ڽӱ�ṹ
struct EdgeNode
{
	int adjvex;    /* �ڽӵ��򣬴洢�ö����Ӧ���±� */
	int weight;		/* ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next; /* ����ָ����һ���ڽӵ� */
};

//ͷ���Ľṹ
struct AdjList {
	int in;	/* ������� */
	int data; /* �����򣬴洢������Ϣ */
	EdgeNode *firstedge;/* �߱�ͷָ�� */
};

//ͼ����Ϣ
struct GraphAdjList
{
	AdjList adjList[MAXVEX];
	int numVertexes, numEdges; /* ͼ�е�ǰ�������ͱ��� */
};


//����ͼ
MGraph * CreateMGraph(MGraph *G)/* ����ͼ */
{
	int i, j;

	/* printf("����������Ͷ�����:"); */
	G->numEdges = MAXEDGE;
	G->numVertexes = MAXVEX;

	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}

	G->arc[0][4] = 1;
	G->arc[0][5] = 1;
	G->arc[0][11] = 1;
	G->arc[1][2] = 1;
	G->arc[1][4] = 1;
	G->arc[1][8] = 1;
	G->arc[2][5] = 1;
	G->arc[2][6] = 1;
	G->arc[2][9] = 1;
	G->arc[3][2] = 1;
	G->arc[3][13] = 1;
	G->arc[4][7] = 1;
	G->arc[5][8] = 1;
	G->arc[5][12] = 1;
	G->arc[6][5] = 1;
	G->arc[8][7] = 1;
	G->arc[9][10] = 1;
	G->arc[9][11] = 1;
	G->arc[10][13] = 1;
	G->arc[12][9] = 1;

	return G;
}

//�����ٽӱ�
GraphAdjList * CreateALGraph(MGraph *G, GraphAdjList *GL) {
	GL->numEdges = G->numEdges;
	GL->numVertexes = G->numVertexes;
	for (int i = 0; i < G->numVertexes; ++i) {
		GL->adjList[i].data = i;
		GL->adjList[i].firstedge = NULL;
		GL->adjList[i].in = 0;
	}

	for (int i = 0; i < G->numVertexes; ++i) {
		for (int j = 0; j < G->numVertexes; ++j) {
			if (G->arc[i][j] > 0) {
				EdgeNode *p = new EdgeNode;
				p->adjvex = j;
				p->weight = G->arc[i][j];
				p->next = GL->adjList[i].firstedge;
				GL->adjList[i].firstedge = p;
				GL->adjList[j].in++;//��ȣ����м���������
			}
		}
	}
	return GL;

}


//����������
//ԭ��ܼ򵥣����Ǹ����ٽӱ�ͨ����ȥ�����Ϊ0�Ľڵ㣨��Ϊû��ָ��ý��ĵ㣬�ʿ�����ȥ����
//��ô˳����ǣ�����ͬ���Ϊ0�Ľڵ㣬��ջ��Ȼ��ͨ����ջ������
//��ջ��ͬʱ���ֽ��ճ�ջ�Ľ��ĵ����һ�飬�ý����ǵ���ȼ�һ����Ϊ�õ��ѳ�ջ��ɾ�������������1
//��ʱ�����ж�������Ƿ�Ϊ0��ʡȥ�ڴ�ͷ����������Ϊ0�����ջ
//Ȼ���ٳ�ջ��ֱ��ջ�գ����ջ����Ϊ��������

int  TopologicalSort(GraphAdjList *GL) {
	stack<int>s;//�����Ϊ0��������ջ
	vector<int>v;//���ܳ�ջ�����֣���Ϊ��

	for (int j = 0; j < GL->numVertexes; ++j)
		if ( GL->adjList[j].in == 0) //δ��ջ�����Ϊ0
			s.push(j);
	
	while (!s.empty()) {
		int pot = s.top();//��ջ
		v.push_back(pot);//��¼
		s.pop();
		EdgeNode*p = GL->adjList[pot].firstedge;
		while (p) {
			if (!(--(GL->adjList[p->adjvex].in)))s.push(p->adjvex);//���ý�����Ľڵ�����1,��Ϊ0�ˣ�����ջ
			p = p->next;
		}

	}
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.size() << endl;
	return 1;

}

int T029(void)
{
	MGraph *G;
	GraphAdjList *GL;
	int result;
	G = new MGraph;
	G = CreateMGraph(G);
	GL = new GraphAdjList;
	GL = CreateALGraph(G, GL);
	result = TopologicalSort(GL);
	printf("result:%d", result);

	return 0;
}
