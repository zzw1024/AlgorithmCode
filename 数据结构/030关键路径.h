#include "000库函数.h"

#define MAXEDGE 30
#define MAXVEX 30
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
	G->numEdges = 13;
	G->numVertexes = 10;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
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
			if (i!=j && G->arc[i][j] <INFINITY ) {
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

//拓扑排序
void TopologicalSort(GraphAdjList *GL, vector<int>&etv, vector<int>&v) {
	stack<int>s;//将入度为0的数字入栈

	for (int j = 0; j < GL->numVertexes; ++j) {
		if (GL->adjList[j].in == 0) //未入栈且入度为0
			s.push(j);
		etv.push_back(0);//初始化
	}

	while (!s.empty()) {
		int pot = s.top();//出栈
		v.push_back(pot);//记录
		s.pop();
		EdgeNode*p = GL->adjList[pot].firstedge;
		while (p) {
			if (!(--(GL->adjList[p->adjvex].in)))s.push(p->adjvex);//将该结点进入的节点的入减1,若为0了，就入栈
		
			if ((etv[pot] + p->weight) > etv[p->adjvex])
				etv[p->adjvex] = etv[pot] + p->weight;//更新最早时间表
			//因为我要发生的前提是，前面所有的时间都已经发生了，不能说一个先发生就运行，
			//必须等最后一个都发生了，然后我才能发生，故是最大值

			p = p->next;
		}

	}

	cout << "拓扑排序为：" << endl;
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.size() << endl;

}

//求关键路径
void CriticalPath(GraphAdjList *GL) {
	vector<int>v;//接受出栈的数字
	vector<int>ltv;//最晚发生事件的数组
	vector<int>etv;//最早发生事件的数组
	TopologicalSort(GL, etv, v);//接受出栈的数字，即为答案	);

	for (int i = 0; i < GL->numVertexes; ++i)
		ltv.push_back(etv[GL->numVertexes - 1]);//对ltv进行初始化

	while (!v.empty()) {
		int pot = v.back();//得到最晚出栈的结点
		v.pop_back();
		EdgeNode*p = GL->adjList[pot].firstedge;
		while (p) {
			if (ltv[p->adjvex] - p->weight < ltv[pot])
				ltv[pot] = ltv[p->adjvex] - p->weight;//计算出最晚点事件完成时间
			p = p->next;
		}
	}
	cout << "打印出最早发生事件的时间: " << endl;
	for (auto a : etv)
		cout << a << "  ";
	cout << endl;
	cout << "打印出最晚发生事件的时间: " << endl;
	for (auto a : ltv)
		cout << a << "  ";
	cout << endl;

	cout << "关键路径为： " << endl;
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
