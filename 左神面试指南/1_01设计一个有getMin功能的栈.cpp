//#pragma once
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
////
////ʵ��һ�������ջ����ʵ��ջ�Ļ������ܵĻ����ϣ���ʵ�ַ���ջ����СԪ�صĲ�����
////��Ҫ��
////1��pop��push��getMin������ʱ�临�Ӷȶ���O(1)��
////2����Ƶ�ջ���Ϳ���ʹ���ֳɵ�ջ�ṹ��
////
////
////����˼·��
////	ʹ��һ������ջ��������Ŀǰջ�е���Сֵ
//
//
//class GetMin
//{
//public:
//	void PushData(int a)
//	{
//		Data.push(a);
//		if (Min.empty())
//			Min.push(a);//����δ����ʱ��Ŀǰջ�е���Сֵ���ǵ�һ����
//		else
//			Min.push(Min.top() <= a ? Min.top() : a);
//		//���¼��������ջ�е���Сֵ��ȣ������µ���Сֵ����ά��Data��Minջ�ĸ߶�һ��
//	}
//
//	int GetTop()
//	{
//		if (Data.size())
//			return Data.top();
//		return -1;
//	}
//
//	int theMin()
//	{
//		if (Data.size())
//			return Min.top();
//		return -1;
//	}
//
//	void PopData()
//	{
//		if (Data.size())
//		{
//			Data.pop();
//			Min.pop();
//		}
//	}
//
//private:
//	stack<int>Data;
//	stack<int>Min;
//};
//
//void main()
//{
//	GetMin ss;
//	ss.PushData(6);
//	cout << ss.theMin() << endl;
//	ss.PushData(5);
//	cout << ss.theMin() << endl;
//	ss.PushData(2);
//	cout << ss.theMin() << endl;
//	ss.PushData(1);
//	cout << ss.theMin() << endl;
//	ss.PushData(3);
//	cout << ss.theMin() << endl;
//	ss.PushData(6);
//	cout << ss.theMin() << endl;
//
//	ss.PopData();
//	cout << ss.theMin() << endl;
//	ss.PopData();
//	cout << ss.theMin() << endl;
//	ss.PopData();
//	cout << ss.theMin() << endl;
//	ss.PopData();
//	cout << ss.theMin() << endl;
//}