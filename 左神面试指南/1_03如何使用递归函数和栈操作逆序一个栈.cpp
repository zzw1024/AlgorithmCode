//#pragma once
//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
////����Ŀ��
////һ��ջ����ѹ��1��2��3��4��5����ô��ջ����ջ�׷ֱ�Ϊ5��4��3��2��1��
////�����ջת�ú󣬴�ջ����ջ��Ϊ1��2��3��4��5��Ҳ����ʵ��ջ��Ԫ�ص�����
////����ֻ���õݹ麯����ʵ�֣��������������ݽṹ��
////
////����⡿
////ʹ�������ݹ麯����
////һ���ݹ麯���ǽ�ջ�׵�Ԫ�ط��ز�ɾ��
////��һ�������ǽ����ص�Ԫ�ؽ��д���
//
//int getBottomData(stack<int>&s)
//{
//	int res = s.top();
//	s.pop();
//	if (s.empty())
//		return res;//��ջ��Ԫ�ص���
//	else
//	{
//		int last = getBottomData(s);
//		s.push(res);//����ѹ������
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