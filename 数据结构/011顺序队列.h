#pragma once
#include "000库函数.h"


//头进尾出

struct SqQueue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
};

//初始化
Status InitQueue(SqQueue *Q) {
	Q->front = -1;
	Q->rear = -1;
	return OK;
}

//队空？
Status  QueueEmpty(SqQueue Q) {
	if (Q.rear == Q.front)return OK;
	return NO;
}
//进队
Status EnQueue(SqQueue *Q, int d) {
	if (Q->rear == MAXSIZE)return NO;
	++(Q->rear);
	Q->data[Q->rear] = d;
	return OK;
}
//队长
int QueueLength(SqQueue Q) {
	return Q.rear - Q.front;
}

//删队
Status DeQueue(SqQueue *Q, int *d) {
	if (Q->front == Q->rear)return NO;
	++(Q->front);
	*d = Q->data[Q->front];
	return OK;
}
//读 队
Status QueueTraverse(SqQueue Q) {
	if (Q.front == Q.rear)return NO;
	while (Q.rear >= Q.front) {
		++(Q.front);
		cout << Q.data[Q.front] << '\t';
	}
	cout << endl;
	return OK;
}
//队头
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
	printf("初始化队列后，队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));

	printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ", MAXSIZE - 1);
	do
	{
		/* scanf("%d",&d); */
		d = i + 100;
		if (d == -1)
			break;
		i++;
		EnQueue(&Q, d);
	} while (i < MAXSIZE - 1);

	printf("队列长度为: %d\n", QueueLength(Q));
	printf("现在队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));
	printf("连续%d次由队头删除元素,队尾插入元素:\n", MAXSIZE);
	for (l = 1; l <= MAXSIZE; l++)
	{
		DeQueue(&Q, &d);
		printf("删除的元素是%d,插入的元素:%d \n", d, l + 1000);
		/* scanf("%d",&d); */
		d = l + 1000;
		EnQueue(&Q, d);
	}
	l = QueueLength(Q);

	printf("现在队列中的元素为: \n");
	QueueTraverse(Q);
	printf("共向队尾插入了%d个元素\n", i + MAXSIZE);
	if (l - 2 > 0)
		printf("现在由队头删除%d个元素:\n", l - 2);
	while (QueueLength(Q) > 2)
	{
		DeQueue(&Q, &d);
		printf("删除的元素值为%d\n", d);
	}

	j = GetHead(Q, &d);
	if (j)
		printf("现在队头元素为: %d\n", d);
	ClearQueue(&Q);
	printf("清空队列后, 队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));
	return 0;
}

