#include "000库函数.h"
//无向图

#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

struct MGraph {//临接矩阵参数
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

struct EdgeNode {//邻接表
	int adjvex;//节点
	EdgeType wt;//权重
	struct EdgeNode *next;//指针
};

struct VertexNode {//顶点表节点
	int in;//节点的入度
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


//构建临接表
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
//深度遍历
vector<char>DFSRes;
void DFS(GraphAdjList *GL, vector <bool>&flag, EdgeNode *p) {
	if (DFSRes.size() == GL->numNodes)return;
	while (p) {
		if (flag[p->adjvex]) {
			DFSRes.push_back(GL->adjList[p->adjvex].data);//第一遍入栈，用来判断的
			flag[p->adjvex] = false;
			p = GL->adjList[p->adjvex].firstedge;//下一个点
			DFS(GL, flag, p);
			DFSRes.pop_back();//弹出栈，让后面回溯回来的元素入栈！
		}
		else
			p = p->next;
	}
}

void DFSTraverse(GraphAdjList *GL) {
	vector<bool>flag(GL->numNodes, true);//标志
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


//广度遍历
vector<char>BFSRes;
deque<int>dq;//压入节符号

void BFS(GraphAdjList *GL, EdgeNode *p, vector<bool>&flag) {
	BFSRes.push_back(GL->adjList[dq.front()].data);
	dq.pop_front();	
	while (p) {
		if (flag[p->adjvex]) {//未遍历过
			flag[p->adjvex] = false;			
			dq.push_back(p->adjvex);			
		}
		p = p->next;
	}
	if (dq.empty())return ;
	BFS(GL, GL->adjList[dq.front()].firstedge, flag);//下一个表
}


void BFSTraverse(GraphAdjList *GL) {
	vector<bool>flag(GL->numNodes, true);//访问标志
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

	//printf("\n深度遍历:");
	//DFSTraverse(GL);
	printf("\n广度遍历:");
	BFSTraverse(GL);
	return 0;
}


