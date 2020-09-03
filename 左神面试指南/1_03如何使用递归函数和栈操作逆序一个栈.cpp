//#pragma once
//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
////【题目】
////一个栈依次压入1、2、3、4、5，那么从栈顶到栈底分别为5、4、3、2、1。
////将这个栈转置后，从栈顶到栈底为1、2、3、4、5，也就是实现栈中元素的逆序，
////但是只能用递归函数来实现，不能用其他数据结构。
////
////【题解】
////使用两个递归函数：
////一个递归函数是将栈底的元素返回并删除
////另一个函数是将返回的元素进行存入
//
//int getBottomData(stack<int>&s)
//{
//	int res = s.top();
//	s.pop();
//	if (s.empty())
//		return res;//将栈底元素弹出
//	else
//	{
//		int last = getBottomData(s);
//		s.push(res);//重新压回数据
//		return last;	//
//	}
//}
//
//void reversStack(stack<int>&s)
//{
//	if (s.empty())
//		return;
//	int a = getBottomData(s);
//	reversStack(s);
//	s.push(a);
//}
//
//void printStack(stack<int>s)
//{
//	while (!s.empty())
//	{
//		cout << s.top() << " ";
//		s.pop();
//	}
//	cout << endl;
//}
//
//void main()
//{
//	stack<int>s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//	s.push(5);
//	printStack(s);
//	reversStack(s);
//	printStack(s);
//}