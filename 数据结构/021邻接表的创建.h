#include "000�⺯��.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ��󶥵���,Ӧ���û����� */

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

struct EdgeNode {//�ڽӱ�
	int adjvex;//�ڵ�
	EdgeType info;//Ȩ��
	struct EdgeNode *next;//ָ��
};

struct VertexNode{//�����ڵ�
	VertexType data;
	EdgeNode *firstedge;
};

struct GraphAdjList{
	VertexNode adjList[MAXVEX];
	int numNodes, numEdges;
};

//����  ������ͼ��
void CreateALGraph(GraphAdjList **G) {
	*G = new GraphAdjList;
	cout << "�����붥��ͱ���" << endl;
	cin >> (*G)->numNodes >> (*G)->numEdges;
	cout << "���붥��" << endl;
	for (int i = 0; i < (*G)->numNodes; ++i) {
		cin >> (*G)->adjList[i].data;
		(*G)->adjList[i].firstedge = NULL;//��ʼ��
	}
	for (int i = 0; i < (*G)->numEdges; ++i) {
		cout << "�����i,j��ż���Ȩ��" << endl;
		int k, t, f;
		cin >> k >> t >> f;
		EdgeNode *e = new EdgeNode;
		e->adjvex = t;
		e->info = f;
		e->next = NULL;
		//β�巨
		//if ((*G)->adjList[i].firstedge)//�Ѿ�������
		//{
		//	EdgeNode *p = (*G)->adjList[i].firstedge;
		//	while (p->next)
		//		p = p->next;
		//	p->next = e;
		//}
		//else//��һ������
		//	(*G)->adjList[i].firstedge = e;
		
		//ͷ�巨
		e->next = (*G)->adjList[i].firstedge;//ָ���
		(*G)->adjList[i].firstedge = e;
	}


}

int T021(void)
{
	GraphAdjList *G;
	CreateALGraph(&G);

	return 0;
}

