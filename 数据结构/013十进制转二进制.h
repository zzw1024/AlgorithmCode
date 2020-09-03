#pragma once
#include "000库函数.h"
//使用栈链来将十进制转二进制


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






int T013()
{
	LinkStack s;
	InitStack(&s);
	cout << "输入一个十进制数字：";
	int n;
	cin >> n;
	cout << n << "  的二进制数为：";
	while (n) {
		int m = n % 2;
		n = n / 2;
		Push(&s, m);
	}
	
	StackTraverse(s);

	
	return 0;
}
