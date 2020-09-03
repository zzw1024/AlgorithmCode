#include "000�⺯��.h"



struct  SqDoubleStack
{
	ElemType data[MAXSIZE];
	int top1;
	int top2;
};


//��ʼ��
Status InitStack(SqDoubleStack *s) {
	s->top1 = -1;
	s->top2 = MAXSIZE;//�����м��ջ�ռ�
	return OK;
}
Status Push(SqDoubleStack *s, int j, int n) {
	if (n == 1) {
		if (++(s->top1) < s->top2) {
			s->data[s->top1] = j;
			return OK;
		}
		else
			return NO;
	}
	else if (n == 2) {
		if (--(s->top2) > s->top1) {
			s->data[s->top2] = j;
			return OK;
		}
		else
			return NO;
	}
	else
		return NO;

}

void StackTraverse(SqDoubleStack s) {
	if (s.top1 < 0 && s.top2 >= MAXSIZE)
		cout << "ջ�������ݣ�" << endl;
	if (s.top1 > -1) {
		cout << "ջ1������Ϊ��" << endl;
		int i = 0;
		while (i <= s.top1) {
			cout << s.data[i] << '\t';
			++i;
		}
		cout << endl;
	}
	if (s.top2 < MAXSIZE) {
		cout << "ջ2������Ϊ��" << endl;
		int i = MAXSIZE - 1;
		while (i >= s.top2) {
			cout << s.data[i] << '\t';
			--i;
		}
		cout << endl;
	}
		
}

//ջ��
int  StackLength(SqDoubleStack s) {
	return s.top1 + 1 + MAXSIZE - s.top2;
}

//��ջ
void Pop(SqDoubleStack *s, int *e, int n) {
	if (n == 1 && s->top1 > -1) {
		*e = s->data[s->top1];
		--(s->top1);
	}
	else if (n == 2 && s->top2 < MAXSIZE) {
		*e = s->data[s->top2];
		++(s->top2);
	}
	else
		return;
}
//ջ��
Status StackEmpty(SqDoubleStack s) {
	if (s.top1 < 0 && s.top2 >= MAXSIZE) return OK;
	else return NO;
}
//��ջ
Status ClearStack(SqDoubleStack *s) {
	s->top1 = -1;
	s->top2 = MAXSIZE;
	return OK;
}


int T008()
{
	int j;
	SqDoubleStack s;
	int e;
	if (InitStack(&s) == OK)
	{
		for (j = 1; j <= 5; j++)
			Push(&s, j, 1);
		for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
			Push(&s, j, 2);
	}

	printf("ջ��Ԫ������Ϊ��");
	StackTraverse(s);

	printf("��ǰջ��Ԫ���У�%d \n", StackLength(s));

	Pop(&s, &e, 2);
	printf("������ջ��Ԫ�� e=%d\n", e);
	printf("ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));

	for (j = 6; j <= MAXSIZE - 2; j++)
		Push(&s, j, 1);

	printf("ջ��Ԫ������Ϊ��");
	StackTraverse(s);

	printf("ջ����%d(1:�� 0:��)\n", Push(&s, 100, 1));


	ClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));

	return 0;
}