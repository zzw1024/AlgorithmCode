#pragma once
#include "000�⺯��.h"
//ʹ��ջ������ʮ����ת������


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






int T013()
{
	LinkStack s;
	InitStack(&s);
	cout << "����һ��ʮ�������֣�";
	int n;
	cin >> n;
	cout << n << "  �Ķ�������Ϊ��";
	while (n) {
		int m = n % 2;
		n = n / 2;
		Push(&s, m);
	}
	
	StackTraverse(s);

	
	return 0;
}
