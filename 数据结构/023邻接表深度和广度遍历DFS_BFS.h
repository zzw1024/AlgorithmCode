#include "000�⺯��.h"
//����ͼ

#define MAXSIZE 9 /* �洢�ռ��ʼ������ */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */

typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

struct MGraph {//�ٽӾ������
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

struct EdgeNode {//�ڽӱ�
	int adjvex;//�ڵ�
	EdgeType wt;//Ȩ��
	struct EdgeNode *next;//ָ��
};

struct VertexNode {//�����ڵ�
	int in;//�ڵ�����
	VertexType data;
	EdgeNode *firstedge;
};

struct GraphAdjList {
	VertexNode adjList[MAXVEX];
	int numNodes, numEdges;
};

void CreateMGraph(MGraph **G) {
	(*G) = new MGraph;
	(*G)->numEdges = 15;
	(*G)->numVertexes = 9;
	/* ���붥����Ϣ����������� */
	(*G)->vexs[0] = 'A';
	(*G)->vexs[1] = 'B';
	(*G)->vexs[2] = 'C';
	(*G)->vexs[3] = 'D';
	(*G)->vexs[4] = 'E';
	(*G)->vexs[5] = 'F';
	(*G)->vexs[6] = 'G';
	(*G)->vexs[7] = 'H';
	(*G)->vexs[8] = 'I';


	for (int i = 0; i < (*G)->numVertexes; ++i)/* ��ʼ��ͼ */
	{
		for (int j = 0; j < (*G)->numVertexes; ++j)
		{
			(*G)->arc[i][j] = 0;
		}
	}

	(*G)->arc[0][1] = 1;
	(*G)->arc[0][5] = 1;

	(*G)->arc[1][2] = 1;
	(*G)->arc[1][8] = 1;
	(*G)->arc[1][6] = 1;

	(*G)->arc[2][3] = 1;
	(*G)->arc[2][8] = 1;

	(*G)->arc[3][4] = 1;
	(*G)->arc[3][7] = 1;
	(*G)->arc[3][6] = 1;
	(*G)->arc[3][8] = 1;

	(*G)->arc[4][5] = 1;
	(*G)->arc[4][7] = 1;

	(*G)->arc[5][6] = 1;

	(*G)->arc[6][7] = 1;


	for (int i = 0; i < (*G)->numVertexes; ++i)/* ��ʼ��ͼ */
	{
		for (int j = 0; j < (*G)->numVertexes; ++j)
		{
			(*G)->arc[j][i] = (*G)->arc[i][j];
		}
	}

}


//�����ٽӱ�
void CreateALGraph(MGraph *G, GraphAdjList **GL) {
	(*GL) = new GraphAdjList;
	(*GL)->numEdges = G->numEdges;
	(*GL)->numNodes = G->numVertexes;
	for (int i = 0; i < G->numVertexes; ++i) {
		(*GL)->adjList[i].data = G->vexs[i];
		(*GL)->adjList[i].firstedge = NULL;
		(*GL)->adjList[i].in = 0;
	}
	for (int i = 0; i < G->numVertexes; ++i) {
		for (int j = 0; j < G->numVertexes; ++j) {
			if (G->arc[i][j] != 0) {
				EdgeNode *p = new EdgeNode;
				p->adjvex = j;
				p->wt = 1;
				p->next = (*GL)->adjList[i].firstedge;
				(*GL)->adjList[i].firstedge = p;
				(*GL)->adjList[i].in += 1;
			}
		}
	}

}
//��ȱ���
vector<char>DFSRes;
void DFS(GraphAdjList *GL, vector <bool>&flag, EdgeNode *p) {
	if (DFSRes.size() == GL->numNodes)return;
	while (p) {
		if (flag[p->adjvex]) {
			DFSRes.push_back(GL->adjList[p->adjvex].data);//��һ����ջ�������жϵ�
			flag[p->adjvex] = false;
			p = GL->adjList[p->adjvex].firstedge;//��һ����
			DFS(GL, flag, p);
			DFSRes.pop_back();//����ջ���ú�����ݻ�����Ԫ����ջ��
		}
		else
			p = p->next;
	}
}

void DFSTraverse(GraphAdjList *GL) {
	vector<bool>flag(GL->numNodes, true);//��־
	for (int i = 0; i < GL->numNodes; ++i) {
		DFSRes.push_back(GL->adjList[i].data);
		flag[i] = false;
		EdgeNode *p = GL->adjList[i].firstedge;
		DFS(GL, flag, p);
	}
	cout << "/*****DFS*****/" << endl;
	for (auto a : DFSRes)
		cout << a << "->";
	cout << endl;
}


//��ȱ���
vector<char>BFSRes;
deque<int>dq;//ѹ��ڷ���

void BFS(GraphAdjList *GL, EdgeNode *p, vector<bool>&flag) {
	BFSRes.push_back(GL->adjList[dq.front()].data);
	dq.pop_front();	
	while (p) {
		if (flag[p->adjvex]) {//δ������
			flag[p->adjvex] = false;			
			dq.push_back(p->adjvex);			
		}
		p = p->next;
	}
	if (dq.empty())return ;
	BFS(GL, GL->adjList[dq.front()].firstedge, flag);//��һ����
}


void BFSTraverse(GraphAdjList *GL) {
	vector<bool>flag(GL->numNodes, true);//���ʱ�־
	dq.push_back(0);
	flag[0] = false;
	BFS(GL, GL->adjList[dq.front()].firstedge, flag);
	cout << "/*****BFS*****/" << endl;
	for (auto b : BFSRes)
		cout << b << "->";
	cout << endl;
}



int T023(void)
{
	MGraph *G;
	GraphAdjList *GL;
	CreateMGraph(&G);
	CreateALGraph(G, &GL);

	//printf("\n��ȱ���:");
	//DFSTraverse(GL);
	printf("\n��ȱ���:");
	BFSTraverse(GL);
	return 0;
}


