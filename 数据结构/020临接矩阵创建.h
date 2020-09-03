#include "000�⺯��.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ��󶥵�����Ӧ���û����� */
#define INFINITY 65535

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char VertexType; /* ��������Ӧ���û�����  */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
struct MGraph {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numNodes, numEdges;
};

void CreateMGraph(MGraph **G) {
	cout << "�����붥��ͱ���" << endl;
	cin >> (*G)->numNodes >> (*G)->numEdges;
	for (int i = 0; i < (*G)->numNodes; ++i) {
		cin >> (*G)->vexs[i];
	}
	//�ٽӾ����ʼ��
	for (int i = 0; i < (*G)->numNodes; ++i) {
		for (int j = 0; j < (*G)->numNodes; ++j) {
			(*G)->arc[i][j] = INFINITY;
		}
	}
	//�����ڽӾ���
	for (int i = 0; i < (*G)->numNodes; ++i){
		for (int j = 0; j < (*G)->numNodes; ++j) {
			if (i == j)(*G)->arc[i][j] = 0;
			else {
				cout << "�������i��j��Ȩֵ��" << endl;
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

