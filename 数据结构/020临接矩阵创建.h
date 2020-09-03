#include "000库函数.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */
struct MGraph {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numNodes, numEdges;
};

void CreateMGraph(MGraph **G) {
	cout << "请输入顶点和边数" << endl;
	cin >> (*G)->numNodes >> (*G)->numEdges;
	for (int i = 0; i < (*G)->numNodes; ++i) {
		cin >> (*G)->vexs[i];
	}
	//临接矩阵初始化
	for (int i = 0; i < (*G)->numNodes; ++i) {
		for (int j = 0; j < (*G)->numNodes; ++j) {
			(*G)->arc[i][j] = INFINITY;
		}
	}
	//计算邻接矩阵
	for (int i = 0; i < (*G)->numNodes; ++i){
		for (int j = 0; j < (*G)->numNodes; ++j) {
			if (i == j)(*G)->arc[i][j] = 0;
			else {
				cout << "请输入边i，j的权值：" << endl;
				int w;
				cin >> w;
				(*G)->arc[i][j] = w;
				(*G)->arc[j][i] = (*G)->arc[i][j];
			}
		}
	}
}

int T020(void)
{
	MGraph *G;
	CreateMGraph(&G);

	return 0;
}

