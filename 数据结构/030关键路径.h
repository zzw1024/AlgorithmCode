#include "000�⺯��.h"

#define MAXEDGE 30
#define MAXVEX 30
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
	G->numEdges = 13;
	G->numVertexes = 10;

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
				G->arc[i][j] = INFINITY;
		}
	}

	G->arc[0][1] = 3;
	G->arc[0][2] = 4;
	G->arc[1][3] = 5;
	G->arc[1][4] = 6;
	G->arc[2][3] = 8;
	G->arc[2][5] = 7;
	G->arc[3][4] = 3;
	G->arc[4][6] = 9;
	G->arc[4][7] = 4;
	G->arc[5][7] = 6;
	G->arc[6][9] = 2;
	G->arc[7][8] = 5;
	G->arc[8][9] = 3;


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
			if (i!=j && G->arc[i][j] <INFINITY ) {
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

//��������
void TopologicalSort(GraphAdjList *GL, vector<int>&etv, vector<int>&v) {
	stack<int>s;//�����Ϊ0��������ջ

	for (int j = 0; j < GL->numVertexes; ++j) {
		if (GL->adjList[j].in == 0) //δ��ջ�����Ϊ0
			s.push(j);
		etv.push_back(0);//��ʼ��
	}

	while (!s.empty()) {
		int pot = s.top();//��ջ
		v.push_back(pot);//��¼
		s.pop();
		EdgeNode*p = GL->adjList[pot].firstedge;
		while (p) {
			if (!(--(GL->adjList[p->adjvex].in)))s.push(p->adjvex);//���ý�����Ľڵ�����1,��Ϊ0�ˣ�����ջ
		
			if ((etv[pot] + p->weight) > etv[p->adjvex])
				etv[p->adjvex] = etv[pot] + p->weight;//��������ʱ���
			//��Ϊ��Ҫ������ǰ���ǣ�ǰ�����е�ʱ�䶼�Ѿ������ˣ�����˵һ���ȷ��������У�
			//��������һ���������ˣ�Ȼ���Ҳ��ܷ������������ֵ

			p = p->next;
		}

	}

	cout << "��������Ϊ��" << endl;
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.size() << endl;

}

//��ؼ�·��
void CriticalPath(GraphAdjList *GL) {
	vector<int>v;//���ܳ�ջ������
	vector<int>ltv;//�������¼�������
	vector<int>etv;//���緢���¼�������
	TopologicalSort(GL, etv, v);//���ܳ�ջ�����֣���Ϊ��	);

	for (int i = 0; i < GL->numVertexes; ++i)
		ltv.push_back(etv[GL->numVertexes - 1]);//��ltv���г�ʼ��

	while (!v.empty()) {
		int pot = v.back();//�õ������ջ�Ľ��
		v.pop_back();
		EdgeNode*p = GL->adjList[pot].firstedge;
		while (p) {
			if (ltv[p->adjvex] - p->weight < ltv[pot])
				ltv[pot] = ltv[p->adjvex] - p->weight;//�����������¼����ʱ��
			p = p->next;
		}
	}
	cout << "��ӡ�����緢���¼���ʱ��: " << endl;
	for (auto a : etv)
		cout << a << "  ";
	cout << endl;
	cout << "��ӡ���������¼���ʱ��: " << endl;
	for (auto a : ltv)
		cout << a << "  ";
	cout << endl;

	cout << "�ؼ�·��Ϊ�� " << endl;
	for (int i = 0; i < GL->numVertexes; ++i) {
		EdgeNode*p = GL->adjList[i].firstedge;
		while (p) {
			if (etv[i] == (ltv[p->adjvex] - p->weight))
				cout << "< " << GL->adjList[i].data << ", " << GL->adjList[p->adjvex].data << " >" << endl;
			p = p->next;
		}
	}
}

int T030(void)
{
	MGraph *G;
	GraphAdjList *GL;
	int result;
	G = new MGraph;
	G = CreateMGraph(G);
	GL = new GraphAdjList;
	GL = CreateALGraph(G, GL);
	CriticalPath(GL);
	return 0;
}
