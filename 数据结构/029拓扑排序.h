#include "000库函数.h"

#define MAXEDGE 20
#define MAXVEX 14
#define INFINITY 65535

//临接矩阵结构初始化
struct MGraph {
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

//邻接表结构
struct EdgeNode
{
	int adjvex;    /* 邻接点域，存储该顶点对应的下标 */
	int weight;		/* 用于存储权值，对于非网图可以不需要 */
	struct EdgeNode *next; /* 链域，指向下一个邻接点 */
};

//头结点的结构
struct AdjList {
	int in;	/* 顶点入度 */
	int data; /* 顶点域，存储顶点信息 */
	EdgeNode *firstedge;/* 边表头指针 */
};

//图的信息
struct GraphAdjList
{
	AdjList adjList[MAXVEX];
	int numVertexes, numEdges; /* 图中当前顶点数和边数 */
};


//创建图
MGraph * CreateMGraph(MGraph *G)/* 构件图 */
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
	G->numEdges = MAXEDGE;
	G->numVertexes = MAXVEX;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
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

//生成临接表
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
				GL->adjList[j].in++;//入度，即有几个结点进来
			}
		}
	}
	return GL;

}


//求拓扑排序
//原理很简单，就是根据临接表，通过逐步去除入度为0的节点（因为没有指向该结点的点，故可以先去除）
//那么顺序就是，有相同入度为0的节点，入栈，然后通过出栈来排序
//出栈的同时，又将刚出栈的结点的点遍历一遍，好将他们的入度减一，因为该点已出栈（删除），故入度少1
//此时可以判断其入度是否为0，省去在从头遍历，若已为0，则进栈
//然后再出栈，直至栈空，则出栈次序即为拓扑排序

int  TopologicalSort(GraphAdjList *GL) {
	stack<int>s;//将入度为0的数字入栈
	vector<int>v;//接受出栈的数字，即为答案

	for (int j = 0; j < GL->numVertexes; ++j)
		if ( GL->adjList[j].in == 0) //未入栈且入度为0
			s.push(j);
	
	while (!s.empty()) {
		int pot = s.top();//出栈
		v.push_back(pot);//记录
		s.pop();
		EdgeNode*p = GL->adjList[pot].firstedge;
		while (p) {
			if (!(--(GL->adjList[p->adjvex].in)))s.push(p->adjvex);//将该结点进入的节点的入减1,若为0了，就入栈
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
