//#pragma once
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
////
////实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。
////【要求】
////1．pop、push、getMin操作的时间复杂度都是O(1)。
////2．设计的栈类型可以使用现成的栈结构。
////
////
////解题思路：
////	使用一个辅助栈，里面存的目前栈中的最小值
//
//
//class GetMin
//{
//public:
//	void PushData(int a)
//	{
//		Data.push(a);
//		if (Min.empty())
//			Min.push(a);//当还未存数时，目前栈中的最小值就是第一个数
//		else
//			Min.push(Min.top() <= a ? Min.top() : a);
//		//将新加入的数与栈中的最小值相比，存入新的最小值，以维持Data与Min栈的高度一样
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