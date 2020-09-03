#include "000库函数.h"
//无向图

typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

struct MGraph {//临接矩阵参数
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

struct Queue {//遍历表
	char data;//标号
	Queue *front;//头
	Queue *rear;//尾
};
//queue链表的初始化
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
	/* 读入顶点信息，建立顶点表 */
	(*G)->vexs[0] = 'A';
	(*G)->vexs[1] = 'B';
	(*G)->vexs[2] = 'C';
	(*G)->vexs[3] = 'D';
	(*G)->vexs[4] = 'E';
	(*G)->vexs[5] = 'F';
	(*G)->vexs[6] = 'G';
	(*G)->vexs[7] = 'H';
	(*G)->vexs[8] = 'I';


	for (int i = 0; i < (*G)->numVertexes; ++i)/* 初始化图 */
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


	for (int i = 0; i < (*G)->numVertexes; ++i)/* 初始化图 */
	{
		for (int j = 0; j < (*G)->numVertexes; ++j)
		{
			(*G)->arc[j][i] = (*G)->arc[i][j];
		}
	}

}

Queue *q;//用来存储路径
vector<bool>a(MAXVEX, true);//访问标志
void DFS(MGraph *G, int pot) {
	a[pot] = false;//已经访问过
	Queue *p;
	InitQueue(&p);
	p->data = G->vexs[pot];
	q->rear = p;
	p->front = q;
	q = p;
	for (int i = 0; i < G->numVertexes; ++i) {
		if (G->arc[pot][i] && a[i]) {//有路
			DFS(G, i);//递归遍历,编历到B,就到B中找可行路径，A中其他的可行路径以后再遍历
		}
	}
}

void DFSTraverse(MGraph *G) {//深度遍历
	InitQueue(&q);
	Queue *head = q;
	for (int i = 0; i < G->numVertexes; ++i) {
		if (a[i])//未访问过
			DFS(G, i);//进入回溯
	}
	Queue *p = head->rear;
	while (p) {
		cout << p->data << "  ";
		p = p->rear;
	}
	cout << endl;
	
	
}


vector<char> bf;
vector<bool>b(MAXVEX, true);//访问标志
deque<int>s;
void BFS(MGraph *G, int pot) {
	s.pop_front();//出栈
	bf.push_back(G->vexs[pot]);
	if (bf.size() >= G->numVertexes)return;
	for (int j = 0; j < G->numVertexes; ++j) {
		if (G->arc[pot][j] && b[j]) {
			b[j] = false;//遍历过
			s.push_back(j);
		}			
	}
	BFS(G, s.front());	
}

void BFSTraverse(MGraph *G) {
	for (int i = 0; i < G->numVertexes; ++i) {
		if (b[i]) {
			s.push_back(i);
			b[i] = false;//遍历过
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
	//printf("\n深度遍历：");
	//DFSTraverse(G);
	printf("\n广度遍历：");
	BFSTraverse(G);
	return 0;
}
