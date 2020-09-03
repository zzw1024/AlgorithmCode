#include "000�⺯��.h"

struct LinkStackPtr
{
	ElemType data;
	struct LinkStackPtr *next;
};

struct LinkStack {
	LinkStackPtr *top;
	int count;
};
//��ʼ��
Status InitStack(LinkStack *s) {
	s->count = 0;
	s->top = NULL;
	return OK;
}
//��ջ  ջ�����£�ջ������
Status Push(LinkStack *s, int j) {
	LinkStackPtr *p = new LinkStackPtr;
	p->data = j;
	p->next = s->top;
	s->top = p;
	++(s->count);
	return OK;
}

//�������  ֻ�ܴ�ջ�����
Status StackTraverse(LinkStack s) {
	if (s.top == NULL)return NO;
	/*int i = s.count;
	while (i) {
		cout << s.top->data << '\t';
		s.top = s.top->next;
		--i;
	}*/

	while (s.top) {
		cout << s.top->data << '\t';
		s.top = s.top->next;
	}

	cout << endl;
	return OK;
}

//��ջ  ֻ�ܴ����濪ʼ��ջ
Status Pop(LinkStack *s, int *e) {
	if (s->top == NULL)return NO;
	*e = s->top->data;
	LinkStackPtr *p = s->top;
	s->top = p->next;
	free(p);
	--(s->count);
}

//ջ��
Status  StackEmpty(LinkStack s) {
	if (s.top == NULL)return OK;
	else return NO;
}

//��ȡջ��
Status GetTop(LinkStack s, int *e) {
	if (s.top == NULL)return NO;
	*e = s.top->data;
	return OK;
}

Status ClearStack(LinkStack *s) {
	s->count = 0;
	while (s->top) {
		LinkStackPtr *p = s->top;
		s->top = p->next;
		free(p);
	}
	return OK;
}

//ջ��
int StackLength(LinkStack s) {
	return s.count;
}

int T009()
{
	int j;
	LinkStack s;
	int e;
	if (InitStack(&s) == OK)
		for (j = 1; j <= 10; j++)
			Push(&s, j);
	printf("ջ��Ԫ������Ϊ��");
	StackTraverse(s);
	Pop(&s, &e);
	printf("������ջ��Ԫ�� e=%d\n", e);
	printf("ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	return 0;
}