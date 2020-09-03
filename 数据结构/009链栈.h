#include "000库函数.h"

struct LinkStackPtr
{
	ElemType data;
	struct LinkStackPtr *next;
};

struct LinkStack {
	LinkStackPtr *top;
	int count;
};
//初始化
Status InitStack(LinkStack *s) {
	s->count = 0;
	s->top = NULL;
	return OK;
}
//进栈  栈底在下，栈顶在上
Status Push(LinkStack *s, int j) {
	LinkStackPtr *p = new LinkStackPtr;
	p->data = j;
	p->next = s->top;
	s->top = p;
	++(s->count);
	return OK;
}

//遍历输出  只能从栈顶输出
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

//出栈  只能从上面开始出栈
Status Pop(LinkStack *s, int *e) {
	if (s->top == NULL)return NO;
	*e = s->top->data;
	LinkStackPtr *p = s->top;
	s->top = p->next;
	free(p);
	--(s->count);
}

//栈空
Status  StackEmpty(LinkStack s) {
	if (s.top == NULL)return OK;
	else return NO;
}

//获取栈顶
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

//栈长
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
	printf("栈中元素依次为：");
	StackTraverse(s);
	Pop(&s, &e);
	printf("弹出的栈顶元素 e=%d\n", e);
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	return 0;
}