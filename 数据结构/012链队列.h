#pragma once
#include "000�⺯��.h"

//�뵥���������ֻ�����ǽ���β�巨������Ϊͷɾ��

struct QueuePtr{
	ElemType data;
	struct QueuePtr* next;
};

struct LinkQueue{	
	QueuePtr *front;
	QueuePtr *rear;
};

//��ʼ��
Status InitQueue(LinkQueue *q) {
	QueuePtr* p = new QueuePtr;//��һ����ַ�ռ䣬�ö�����ͷβ
	p->next = NULL;
	q->front = p;
	q->rear = p;
	return NO;
}

//�ӿ�
Status QueueEmpty(LinkQueue q) {
	if (q.front == q.rear)return OK;
	return NO;
}



//�Գ�
int QueueLength(LinkQueue q) {
	QueuePtr*p = q.front;
	int n = 0;
	while (p != q.rear) {
		++n;
		p = p->next;
	}
	return n;
}

//����
Status EnQueue(LinkQueue *q, int i) {
	QueuePtr*p = new QueuePtr;
	p->data = i;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
	return OK;
}

//����
Status QueueTraverse(LinkQueue q) {
	if (q.front == q.rear)return NO;
	while (q.front != q.rear) {
		q.front = q.front->next;
		cout << q.front->data << '\t';
	}
	cout << endl;
	return OK;
}

//����ͷ
Status GetHead(LinkQueue q, int *d) {
	if (q.front == q.rear)return NO;
	*d = q.front->next->data;
	return OK;
}
//ɾ��ͷ
Status DeQueue(LinkQueue *q, int *d) {
	if (q->front == q->rear)return NO;
	*d = q->front->next->data;
	q->front = q->front->next;
	return OK;
}
//���ջ
Status ClearQueue(LinkQueue *q) {
	QueuePtr *p = q->front->next;//��һ��ͷ���
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

//���ٶ�
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
		printf("�ɹ��ع�����һ���ն���!\n");
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ", QueueEmpty(q));
	printf("���еĳ���Ϊ%d\n", QueueLength(q));
	EnQueue(&q, -5);
	EnQueue(&q, 5);
	EnQueue(&q, 10);
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n", QueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ", QueueEmpty(q));
	printf("���е�Ԫ������Ϊ��");
	QueueTraverse(q);
	i = GetHead(q, &d);
	if (i == OK)
		printf("��ͷԪ���ǣ�%d\n", d);
	DeQueue(&q, &d);
	printf("ɾ���˶�ͷԪ��%d\n", d);
	i = GetHead(q, &d);
	if (i == OK)
		printf("�µĶ�ͷԪ���ǣ�%d\n", d);
	ClearQueue(&q);
	printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
	DestroyQueue(&q);
	printf("���ٶ��к�,q.front=%u q.rear=%u\n", q.front, q.rear);

	return 0;
}
