#include "000库函数.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数,应由用户定义 */

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

struct EdgeNode {//邻接表
	int adjvex;//节点
	EdgeType info;//权重
	struct EdgeNode *next;//指针
};

struct VertexNode{//顶点表节点
	VertexType data;
	EdgeNode *firstedge;
};

struct GraphAdjList{
	VertexNode adjList[MAXVEX];
	int numNodes, numEdges;
};

//创建  【有向图】
void CreateALGraph(GraphAdjList **G) {
	*G = new GraphAdjList;
	cout << "请输入顶点和边数" << endl;
	cin >> (*G)->numNodes >> (*G)->numEdges;
	cout << "输入顶点" << endl;
	for (int i = 0; i < (*G)->numNodes; ++i) {
		cin >> (*G)->adjList[i].data;
		(*G)->adjList[i].firstedge = NULL;//初始化
	}
	for (int i = 0; i < (*G)->numEdges; ++i) {
		cout << "输入边i,j序号及其权重" << endl;
		int k, t, f;
		cin >> k >> t >> f;
		EdgeNode *e = new EdgeNode;
		e->adjvex = t;
		e->info = f;
		e->next = NULL;
		//尾插法
		//if ((*G)->adjList[i].firstedge)//已经有连接
		//{
		//	EdgeNode *p = (*G)->adjList[i].firstedge;
		//	while (p->next)
		//		p = p->next;
		//	p->next = e;
		//}
		//else//第一次连接
		//	(*G)->adjList[i].firstedge = e;
		
		//头插法
		e->next = (*G)->adjList[i].firstedge;//指向空
		(*G)->adjList[i].firstedge = e;
	}


}

int T021(void)
{
	GraphAdjList *G;
	CreateALGraph(&G);

	return 0;
}

