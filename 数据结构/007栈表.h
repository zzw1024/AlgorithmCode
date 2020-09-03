#include "000库函数.h"


struct  SqStack {
	ElemType data[MAXSIZE];
	int top;//指的是栈顶的拥有数据的那个空间的位置
};

//初始化
Status InitStack(SqStack *s) {
	s->top = -1;//栈空，且从0号位置开始存放数据
	return OK;
}
//进栈
void Push(SqStack *s, int j) {
	++(s->top);
	s->data[s->top] = j;
}
//遍历输出
void StackTraverse(SqStack s) {
	if (s.top < 0)return;
	int i = 0;
	while (i <= s.top) {
		cout << s.data[i] << '\t';
		++i;
	}
	cout << endl;
}

//出栈
void Pop(SqStack *s, int *e) {
	if (s->top < 0)return;
	*e = s->data[s->top];
	--(s->top);
}
//栈的长度
Status StackEmpty(SqStack s) {
	if (s.top < 0)return OK;
	else return NO;
}

//获取栈顶
void GetTop(SqStack s, int *e) {
	if (s.top < 0)return;
	*e = s.data[s.top];
}
//获取栈的长度
int StackLength(SqStack s) {
	return s.top + 1;
}
//清栈
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

