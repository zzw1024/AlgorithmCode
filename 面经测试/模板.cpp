//#include "head.h"
////Ä£°åÊÇ
//
//
//template<typename T>
//class Array
//{
//private:
//	enum {_size = 100};
//	T arr[_size];
//public:
//	T& operator[](int index) {}
//};
//
//template<typename T> T& Array<T>::operator[](int index)
//{
//
//}
//
//int main()
//{
//	Array<int>arry;
//	for (int i = 0; i < 20; ++i)
//		arry[i] = i + 1;
//	for (int i = 0; i < 20; ++i)
//		cout << arry[i] << endl;
//	return 0;
//
//}
//
//
//template<typename ...T>
//void func(T ...args)
//{
//	cout << "the nums  is" << sizeof...(args) << endl;
//}
//
//int main()
//{
//	func();
//	func(1.5);
//	func(1, 2);
//	return 0;
//}