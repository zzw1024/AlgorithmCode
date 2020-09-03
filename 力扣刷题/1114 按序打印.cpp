#include <iostream>
#include <thread>
#include <algorithm>
#include <condition_variable>
#include <mutex>
#include <semaphore.h>
#include <vector>

using namespace std;

�޷��򿪰����ļ�: ��semaphore.h�� : No such file or directory

//ʹ��ѭ���ȴ�
//��ʱ��
class Foo1 {
public:
	Foo1() {
		value = 1;
	}

	void first(function<void()> printFirst) {
			// printFirst() outputs "first". Do not change or remove this line.
			printFirst();
			++value;
	}

	void second(function<void()> printSecond) {
		while (value!=2) {}//�ȴ�
			// printSecond() outputs "second". Do not change or remove this line.
			printSecond();
			++value;
	}

	void third(function<void()> printThird) {
		while (value!=3) {}//�ȴ�
			// printThird() outputs "third". Do not change or remove this line.
			printThird();
			value = 1;
	}
private:
	volatile int value;
};

//ʹ�û��������ٶȸ���
class Foo2 {
public:
	Foo2() {
		mut1.lock();
		mut2.lock();
	}

	void first(function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		mut1.unlock();
	}

	void second(function<void()> printSecond) {
		// printSecond() outputs "second". Do not change or remove this line.
		lock_guard<mutex>lck(mut1);
		printSecond();
		mut2.unlock();
	}

	void third(function<void()> printThird) {
		// printThird() outputs "third". Do not change or remove this line.
		lock_guard<mutex>lck(mut2);
		printThird();
		//mut1.lock();����������,�ᳬʱ��
		//mut2.lock();		
	}
private:
	mutex mut1, mut2;
};

//ʹ���ź�
class Foo {
public:
	Foo() {
		mut1.lock();
		mut2.lock();
	}

	void first(function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		mut1.unlock();
	}

	void second(function<void()> printSecond) {
		// printSecond() outputs "second". Do not change or remove this line.
		lock_guard<mutex>lck(mut1);
		printSecond();
		mut2.unlock();
	}

	void third(function<void()> printThird) {
		// printThird() outputs "third". Do not change or remove this line.
		lock_guard<mutex>lck(mut2);
		printThird();
		//mut1.lock();����������,�ᳬʱ��
		//mut2.lock();		
	}
private:
	sem_
};


void printFirst() { cout << "first!" << endl; };
void printSecond() { cout << "Second!" << endl; };
void printThird() { cout << "Third!" << endl; };


int main()
{
	Foo f;
	vector<int>v = { 2,1,3 };
	thread th1, th2, th3;
	for (auto a : v)
		if (a == 1)
			th1 = thread(&Foo::first, &f, printFirst);
		else if(a==2)
			th2 = thread(&Foo::second, &f, printSecond);
		else
			th3 = thread(&Foo::third, &f, printThird);
	th1.join();
	th2.join();
	th3.join();

	return 0;
}