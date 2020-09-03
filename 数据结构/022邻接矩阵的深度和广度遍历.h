#include "000�⺯��.h"
//����ͼ

typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

#define MAXSIZE 9 /* �洢�ռ��ʼ������ */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

struct MGraph {//�ٽӾ������
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

struct Queue {//������
	char data;//���
	Queue *front;//ͷ
	Queue *rear;//β
};
//queue����ĳ�ʼ��
void InitQueue(Queue **q) {
	(*q) = new Queue;
	(*q)->data = 0;
	(*q)->front = NULL;
	(*q)->rear = NULL;
}

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

Queue *q;//�����洢·��
vector<bool>a(MAXVEX, true);//���ʱ�־
void DFS(MGraph *G, int pot) {
	a[pot] = false;//�Ѿ����ʹ�
	Queue *p;
	InitQueue(&p);
	p->data = G->vexs[pot];
	q->rear = p;
	p->front = q;
	q = p;
	for (int i = 0; i < G->numVertexes; ++i) {
		if (G->arc[pot][i] && a[i]) {//��·
			DFS(G, i);//�ݹ����,������B,�͵�B���ҿ���·����A�������Ŀ���·���Ժ��ٱ���
		}
	}
}

void DFSTraverse(MGraph *G) {//��ȱ���
	InitQueue(&q);
	Queue *head = q;
	for (int i = 0; i < G->numVertexes; ++i) {
		if (a[i])//δ���ʹ�
			DFS(G, i);//�������
	}
	Queue *p = head->rear;
	while (p) {
		cout << p->data << "  ";
		p = p->rear;
	}
	cout << endl;
	
	
}


vector<char> bf;
vector<bool>b(MAXVEX, true);//���ʱ�־
deque<int>s;
void BFS(MGraph *G, int pot) {
	s.pop_front();//��ջ
	bf.push_back(G->vexs[pot]);
	if (bf.size() >= G->numVertexes)return;
	for (int j = 0; j < G->numVertexes; ++j) {
		if (G->arc[pot][j] && b[j]) {
			b[j] = false;//������
			s.push_back(j);
		}			
	}
	BFS(G, s.front());	
}

void BFSTraverse(MGraph *G) {
	for (int i = 0; i < G->numVertexes; ++i) {
		if (b[i]) {
			s.push_back(i);
			b[i] = false;//������
			BFS(G, s.front());
		}
	}
	for (auto f : bf)
		cout << f << "  ";
	cout << endl;
}
int T022(void)
{
	MGraph *G;
	CreateMGraph(&G);
	//printf("\n��ȱ�����");
	//DFSTraverse(G);
	printf("\n��ȱ�����");
	BFSTraverse(G);
	return 0;
}
