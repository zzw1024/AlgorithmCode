//#include <iostream>
//#include <queue>
//#include <stack>
//
//using namespace std;
//
//
////队列是先进先出，栈是先进后出，那么一个栈存数据，
////一个栈倒腾数据，当要弹出数据时，将数据栈倒腾到辅助栈，
////然后弹出辅助栈的栈顶，再次入栈则直接压入数据栈，弹出则弹出辅助栈顶，
////一旦辅助栈为空，则将数据栈倒腾数据进辅助栈，切记，数据栈只压入数据，而辅助栈只弹出数据
//
//class StackToQueue
//{
//private:
//	stack<int>DataPush, DataPop;
//
//public:
//	void Push(int a)
//	{
//		DataPush.push(a);
//	}
//	int Front()
//	{
//		if (DataPop.empty())
//		{
//			while (!DataPush.empty())
//			{
//				DataPop.push(DataPush.top());
//				DataPush.pop();
//			}
//		}
//		return DataPop.top();
//	}
//
//	void Pop()
//	{
//		if (DataPop.empty())
//		{
//			while (!DataPush.empty())
//			{
//				DataPop.push(DataPush.top());
//				DataPush.pop();
//			}
//		}
//		DataPop.pop();
//	}
//};
//
//
//void Test()
//{
//	
//	StackToQueue myQueue;
//	myQueue.Push(1);
//	myQueue.Push(2);
//	myQueue.Push(3);
//	myQueue.Push(4);
//	myQueue.Push(5);
//	myQueue.Push(6);
//
//	cout << myQueue.Front() << endl;
//	myQueue.Pop();
//	cout << myQueue.Front() << endl;
//	myQueue.Pop();
//	cout << myQueue.Front() << endl;
//
//	myQueue.Push(7);
//	myQueue.Push(8);
//
//	cout << myQueue.Front() << endl;
//}