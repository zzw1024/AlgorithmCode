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
//mutex mut;//ȫ��������һ��
//bool ready = false;//����״̬
//condition_variable cv;
//
//void do_print(int id)
//{
//		//mut.lock();
//		while (!ready);
//		cout << "�߳�" << endl;
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
