#pragma once
#include "000�⺯��.h"


//ͷ��β��

struct SqQueue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
};

//��ʼ��
Status InitQueue(SqQueue *Q) {
	Q->front = -1;
	Q->rear = -1;
	return OK;
}

//�ӿգ�
Status  QueueEmpty(SqQueue Q) {
	if (Q.rear == Q.front)return OK;
	return NO;
}
//����
Status EnQueue(SqQueue *Q, int d) {
	if (Q->rear == MAXSIZE)return NO;
	++(Q->rear);
	Q->data[Q->rear] = d;
	return OK;
}
//�ӳ�
int QueueLength(SqQueue Q) {
	return Q.rear - Q.front;
}

//ɾ��
Status DeQueue(SqQueue *Q, int *d) {
	if (Q->front == Q->rear)return NO;
	++(Q->front);
	*d = Q->data[Q->front];
	return OK;
}
//�� ��
Status QueueTraverse(SqQueue Q) {
	if (Q.front == Q.rear)return NO;
	while (Q.rear >= Q.front) {
		++(Q.front);
		cout << Q.data[Q.front] << '\t';
	}
	cout << endl;
	return OK;
}
//��ͷ
Status GetHead(SqQueue Q, int *d) {
	if (Q.front == Q.rear)return NO;
	*d = Q.data[Q.rear];
	return OK;
}
Status ClearQueue(SqQueue *Q) {
	Q->front = -1;
	Q->rear = -1;
	return OK;
}

int T011()
{
	Status j;
	int i = 0, l;
	ElemType d;
	SqQueue Q;
	InitQueue(&Q);
	printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n", QueueEmpty(Q));

	printf("���������Ͷ���Ԫ��(������%d��),-1Ϊ��ǰ������: ", MAXSIZE - 1);
	do
	{
		/* scanf("%d",&d); */
		d = i + 100;
		if (d == -1)
			break;
		i++;
		EnQueue(&Q, d);
	} while (i < MAXSIZE - 1);

	printf("���г���Ϊ: %d\n", QueueLength(Q));
	printf("���ڶ��пշ�%u(1:�� 0:��)\n", QueueEmpty(Q));
	printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n", MAXSIZE);
	for (l = 1; l <= MAXSIZE; l++)
	{
		DeQueue(&Q, &d);
		printf("ɾ����Ԫ����%d,�����Ԫ��:%d \n", d, l + 1000);
		/* scanf("%d",&d); */
		d = l + 1000;
		EnQueue(&Q, d);
	}
	l = QueueLength(Q);

	printf("���ڶ����е�Ԫ��Ϊ: \n");
	QueueTraverse(Q);
	printf("�����β������%d��Ԫ��\n", i + MAXSIZE);
	if (l - 2 > 0)
		printf("�����ɶ�ͷɾ��%d��Ԫ��:\n", l - 2);
	while (QueueLength(Q) > 2)
	{
		DeQueue(&Q, &d);
		printf("ɾ����Ԫ��ֵΪ%d\n", d);
	}

	j = GetHead(Q, &d);
	if (j)
		printf("���ڶ�ͷԪ��Ϊ: %d\n", d);
	ClearQueue(&Q);
	printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n", QueueEmpty(Q));
	return 0;
}

