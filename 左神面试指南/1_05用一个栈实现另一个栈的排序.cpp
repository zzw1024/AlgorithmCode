//#pragma once
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
////һ��ջ��Ԫ�ص�����Ϊ���ͣ������뽫��ջ�Ӷ����װ��Ӵ�С��˳������
////ֻ������һ��ջ������֮�⣬���������µı����������������������ݽṹ��
////����������
////
////�ҵ��뷨������n�������Ǿ͵���n�Σ�ÿ���ҵ�һ����Сֵ
////��Ҫ�����ջ��Ϊstack������ĸ���ջ��Ϊhelp����stack��ִ��pop������������Ԫ�ؼ�Ϊcur��
////�����curС�ڻ����help��ջ��Ԫ�أ���curֱ��ѹ��help��
////�����cur����help��ջ��Ԫ�أ���help��Ԫ����һ������
////	��һѹ��stack��ֱ��curС�ڻ����help��ջ��Ԫ�أ��ٽ�curѹ��help��
////һֱִ�����ϲ�����ֱ��stack�е�ȫ��Ԫ�ض�ѹ�뵽help��
////	���help�е�����Ԫ����һѹ��stack�����������
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
//		while (!h.empty() && a > h.top())//��ԭջ��Ԫ�ش���hջ��Ԫ�أ���hջ����ȫ������
//		{
//			s.push(h.top());
//			h.pop();
//		}
//		h.push(a);
//	}
//	while (!h.empty())//�źõ����ݷ��ظ�ԭջ
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