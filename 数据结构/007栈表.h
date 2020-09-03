#include "000�⺯��.h"


struct  SqStack {
	ElemType data[MAXSIZE];
	int top;//ָ����ջ����ӵ�����ݵ��Ǹ��ռ��λ��
};

//��ʼ��
Status InitStack(SqStack *s) {
	s->top = -1;//ջ�գ��Ҵ�0��λ�ÿ�ʼ�������
	return OK;
}
//��ջ
void Push(SqStack *s, int j) {
	++(s->top);
	s->data[s->top] = j;
}
//�������
void StackTraverse(SqStack s) {
	if (s.top < 0)return;
	int i = 0;
	while (i <= s.top) {
		cout << s.data[i] << '\t';
		++i;
	}
	cout << endl;
}

//��ջ
void Pop(SqStack *s, int *e) {
	if (s->top < 0)return;
	*e = s->data[s->top];
	--(s->top);
}
//ջ�ĳ���
Status StackEmpty(SqStack s) {
	if (s.top < 0)return OK;
	else return NO;
}

//��ȡջ��
void GetTop(SqStack s, int *e) {
	if (s.top < 0)return;
	*e = s.data[s.top];
}
//��ȡջ�ĳ���
int StackLength(SqStack s) {
	return s.top + 1;
}
//��ջ
void  ClearStack(SqStack *s) {
	s->top = -1;
}


int T007()
{
	int j;
	SqStack s;
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

