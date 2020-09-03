#pragma once

#include <iostream>

using namespace std;
//Problem 1:
//用数组结构实现大小固定的栈
//
//解题思路：
//	给定一个指针即可实现。


class ArrayToStack
{
public:
	ArrayToStack(int size = 3)
	{
		this->size = size;
	}

	void Push(const int a)
	{
		if (ptr < size)
			arr[ptr++] = a;
		else
			cout << "error:the stack is full!" << endl;
	}

	int Top()
	{
		if (ptr > 0)
			return arr[ptr-1];
		else
			cout << "error:the stack is empty!" << endl;
		return -1;
	}

	void Pop()
	{
		if (ptr > 0)
			ptr--;
		else 
			cout << "error:the stack is empty!" << endl;
	}

private:
	int size;
	int *arr = new int[size];
	int ptr = 0;
};

//Problem2:
//使用数组实现队列和
//
//
//解题思路：
//	使用两个指针分别指向队列的前和尾：

class ArrayToQueue
{
public:
	ArrayToQueue(int size = 3) :N(size) {}

	void Push(int a)
	{
		if (size < N)
		{
			if (ptr1 >= N)
				ptr1 = 0;
			arr[ptr1++] = a;
			size++;
		}
		else
			cout << "error: the queue is full!" << endl;
	}

	int Top()
	{
		if (size > 0)
			return arr[ptr0];
		else
			cout << "error: the queue is empty!" << endl;
		return -1;
	}

	void Pop()
	{
		if (size > 0)
		{
			if (ptr0 >= N)
				ptr0 = 0;
			ptr0++;
			size--;
		}
		else
			cout << "error: the queue is empty!" << endl;
	}

private:
	int N;
	int ptr0 = 0, ptr1 = 0, size = 0;
	int *arr = new int [N];

};


void Test()
{
	ArrayToStack s(5);
	s.Pop();
	cout << s.Top() << endl;
	cout << "****************" << endl;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Push(6);
	cout << "****************" << endl;
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;


	cout << "==========================" << endl;
	cout << "==========================" << endl;
	cout << "==========================" << endl;
	ArrayToQueue q(5);
	cout << q.Top() << endl;
	q.Pop();

	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Push(6);

	cout << q.Top() << endl;
	q.Pop();
	cout << q.Top() << endl;

	q.Push(6);
	cout << q.Top() << endl;

}


