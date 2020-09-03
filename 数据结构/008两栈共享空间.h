#include "000库函数.h"



struct  SqDoubleStack
{
	ElemType data[MAXSIZE];
	int top1;
	int top2;
};


//初始化
Status InitStack(SqDoubleStack *s) {
	s->top1 = -1;
	s->top2 = MAXSIZE;//共享中间的栈空间
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
		cout << "栈中无数据！" << endl;
	if (s.top1 > -1) {
		cout << "栈1的数据为：" << endl;
		int i = 0;
		while (i <= s.top1) {
			cout << s.data[i] << '\t';
			++i;
		}
		cout << endl;
	}
	if (s.top2 < MAXSIZE) {
		cout << "栈2的数据为：" << endl;
		int i = MAXSIZE - 1;
		while (i >= s.top2) {
			cout << s.data[i] << '\t';
			--i;
		}
		cout << endl;
	}
		
}

//栈长
int  StackLength(SqDoubleStack s) {
	return s.top1 + 1 + MAXSIZE - s.top2;
}

//出栈
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
//栈空
Status StackEmpty(SqDoubleStack s) {
	if (s.top1 < 0 && s.top2 >= MAXSIZE) return OK;
	else return NO;
}
//清栈
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

	printf("栈中元素依次为：");
	StackTraverse(s);

	printf("当前栈中元素有：%d \n", StackLength(s));

	Pop(&s, &e, 2);
	printf("弹出的栈顶元素 e=%d\n", e);
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));

	for (j = 6; j <= MAXSIZE - 2; j++)
		Push(&s, j, 1);

	printf("栈中元素依次为：");
	StackTraverse(s);

	printf("栈满否：%d(1:否 0:满)\n", Push(&s, 100, 1));


	ClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));

	return 0;
}