//#pragma once
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
////一个栈中元素的类型为整型，现在想将该栈从顶到底按从大到小的顺序排序，
////只许申请一个栈。除此之外，可以申请新的变量，但不能申请额外的数据结构。
////如何完成排序？
////
////我的想法就是有n个数，那就倒腾n次，每次找到一个最小值
////将要排序的栈记为stack，申请的辅助栈记为help。在stack上执行pop操作，弹出的元素记为cur。
////·如果cur小于或等于help的栈顶元素，则将cur直接压入help；
////·如果cur大于help的栈顶元素，则将help的元素逐一弹出，
////	逐一压入stack，直到cur小于或等于help的栈顶元素，再将cur压入help。
////一直执行以上操作，直到stack中的全部元素都压入到help。
////	最后将help中的所有元素逐一压入stack，即完成排序。
//
//
//
//void stackSort(stack<int>&s)
//{
//	if (s.size() < 2)
//		return;
//	stack<int>h;
//	while (!s.empty())
//	{
//		int a = s.top();
//		s.pop();
//		while (!h.empty() && a > h.top())//当原栈顶元素大于h栈顶元素，将h栈数据全部弹出
//		{
//			s.push(h.top());
//			h.pop();
//		}
//		h.push(a);
//	}
//	while (!h.empty())//排好的数据返回给原栈
//	{
//		s.push(h.top());
//		h.pop();
//	}
//}
//
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
//void Test()
//{
//	stack<int>s;
//	s.push(5);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//	s.push(1);
//	printStack(s);
//	stackSort(s);
//	printStack(s);
//}