//#include "head.h"
//
//
//class Queue
//{
//public:
//	void push_back(const int &num)
//	{
//		List.push(num);
//		while (!maxNum.empty() && maxNum.back() < num)maxNum.pop_back();
//		maxNum.push_back(num);
//	}
//	void pop_front()
//	{
//		if (!maxNum.empty() && maxNum.front() == List.front())maxNum.pop_front();
//		if(!List.empty())List.pop();
//	}
//	int getMax()
//	{
//		if (!maxNum.empty())return maxNum.front();
//		return -1;
//	}
//private:
//	queue<int>List;
//	deque<int>maxNum;
//};
//int main()
//{
//	Queue q;
//	while (1)
//	{
//		int a,b;
//		cin >> b;
//		if (b == 1)
//		{
//			cin >> a;
//			q.push_back(a);
//		}
//		else
//			q.pop_front();
//		cout << q.getMax() << endl;		
//	}
//}