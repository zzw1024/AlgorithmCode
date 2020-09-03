#pragma once
#include "000库函数.h"

//与单链表很想像，只不过是进队尾插法，出队为头删法

struct QueuePtr{
	ElemType data;
	struct QueuePtr* next;
};

struct LinkQueue{	
	QueuePtr *front;
	QueuePtr *rear;
};

//初始化
Status InitQueue(LinkQueue *q) {
	QueuePtr* p = new QueuePtr;//给一个地址空间，让队列有头尾
	p->next = NULL;
	q->front = p;
	q->rear = p;
	return NO;
}

//队空
Status QueueEmpty(LinkQueue q) {
	if (q.front == q.rear)return OK;
	return NO;
}



//对长
int QueueLength(LinkQueue q) {
	QueuePtr*p = q.front;
	int n = 0;
	while (p != q.rear) {
		++n;
		p = p->next;
	}
	return n;
}

//进队
Status EnQueue(LinkQueue *q, int i) {
	QueuePtr*p = new QueuePtr;
	p->data = i;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
	return OK;
}

//读队
Status QueueTraverse(LinkQueue q) {
	if (q.front == q.rear)return NO;
	while (q.front != q.rear) {
		q.front = q.front->next;
		cout << q.front->data << '\t';
	}
	cout << endl;
	return OK;
}

//读队头
Status GetHead(LinkQueue q, int *d) {
	if (q.front == q.rear)return NO;
	*d = q.front->next->data;
	return OK;
}
//删队头
Status DeQueue(LinkQueue *q, int *d) {
	if (q->front == q->rear)return NO;
	*d = q->front->next->data;
	q->front = q->front->next;
	return OK;
}
//清空栈
Status ClearQueue(LinkQueue *q) {
	QueuePtr *p = q->front->next;//留一个头结点
	q->rear = q->front;
	q->front->next = NULL;
	while (p) {
		QueuePtr *k;
		k = p->next;
		delete(p);
		p = k;
	}
	return OK;
}

//销毁队
Status DestroyQueue(LinkQueue *q) {
	while (q->front) {
		q->rear = q->front->next;
		delete(q->front);
		q->front = q->rear;
	}
	return OK;
}


int T012()
{
	int i;
	ElemType d;
	LinkQueue q;
	i = InitQueue(&q);
	if (i)
		printf("成功地构造了一个空队列!\n");
	printf("是否空队列？%d(1:空 0:否)  ", QueueEmpty(q));
	printf("队列的长度为%d\n", QueueLength(q));
	EnQueue(&q, -5);
	EnQueue(&q, 5);
	EnQueue(&q, 10);
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", QueueLength(q));
	printf("是否空队列？%d(1:空 0:否)  ", QueueEmpty(q));
	printf("队列的元素依次为：");
	QueueTraverse(q);
	i = GetHead(q, &d);
	if (i == OK)
		printf("队头元素是：%d\n", d);
	DeQueue(&q, &d);
	printf("删除了队头元素%d\n", d);
	i = GetHead(q, &d);
	if (i == OK)
		printf("新的队头元素是：%d\n", d);
	ClearQueue(&q);
	printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
	DestroyQueue(&q);
	printf("销毁队列后,q.front=%u q.rear=%u\n", q.front, q.rear);

	return 0;
}
