//#include <iostream>
//#include <queue>
//#include <stack>
//
//using namespace std;
//
//
////�������Ƚ��ȳ���ջ���Ƚ��������ôһ��ջ�����ݣ�
////һ��ջ�������ݣ���Ҫ��������ʱ��������ջ���ڵ�����ջ��
////Ȼ�󵯳�����ջ��ջ�����ٴ���ջ��ֱ��ѹ������ջ�������򵯳�����ջ����
////һ������ջΪ�գ�������ջ�������ݽ�����ջ���мǣ�����ջֻѹ�����ݣ�������ջֻ��������
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