//#include <iostream>
//#include <future>
//#include <mutex>
//#include <thread>
//#include <condition_variable>
//#include <chrono>
//#include <Windows.h>
//
//
//using namespace std;
//
//mutex mut;//全局锁，就一把
//bool ready = false;//就绪状态
//condition_variable cv;
//
//void do_print(int id)
//{
//		//mut.lock();
//		while (!ready);
//		cout << "线程" << endl;
//		//mut.unlock();
//	
//}
//void go()
//{
//	if (mut.try_lock())
//	{
//		//mut.lock();
//		ready = true;
//		cout << "   thread:  ";// << //this_thread::get_id() << endl;
//		mut.unlock();
//	}
//}
//
//int main()
//{
//	Sleep(5000);
//	cout << "kaishi:" << endl;
//	cout.flush();
//	pthrea
//	return 0;
//}
//
