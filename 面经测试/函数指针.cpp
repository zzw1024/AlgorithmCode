////#include "head.h"
////
////void print(void){
////	cout << "i am printf\n";
////}
////
////void get(int x){
////	cout << "x = " << x << endl;
////}
////
////int add(int x, int y){
////	return x + y;
////}
////
////const double* f1(const double arr[], int n)
////{
////	return arr;     // 首地址 
////}
////
////const double* f2(const double arr[], int n)
////{
////	return arr + 1;
////}
////
////const double* f3(const double* arr, int n)
////{
////	return arr + 2;
////}
////
////
////int main()
////{
////	void(*ptr1)() = print;
////	void(*ptr2)(int) = get;
////	int(*ptr3)(int, int) = add;
////
////	(*ptr1)();
////	(*ptr2)(10);
////	cout << (*ptr3)(12, 13) << endl;
////
////	cout << "**************" << endl;
////
////	double a[3] = { 12.1, 3.4, 4.5 };
////
////	// 声明指针
////	const double* (*p1)(const double*, int) = f1;
////	cout << "Pointer 1 : " << p1(a, 3) << " : " << *(p1(a, 3)) << endl;
////	cout << "Pointer 1 : " << (*p1)(a, 3) << " : " << *((*p1)(a, 3)) << endl;
////
////	const double* (*parray[3])(const double *, int) = { f1, f2, f3 };   // 声明一个指针数组，存储三个函数的地址 
////	cout << "Pointer array : " << parray[2](a, 3) << " : " << *(parray[2](a, 3)) << endl;
////	cout << "Pointer array : " << parray[2](a, 3) << " : " << *(parray[2](a, 3)) << endl;
////	cout << "Pointer array : " << (*parray[2])(a, 3) << " : " << *((*parray[2])(a, 3)) << endl;
////
////
////	return 0;
////}
//
//void func()
//{
//
//}
//
//const void  func()
//{
//
//}
//
//int main()
//{
//	int a[10] = {0};
//	int *p1 = new int[10], *p2;
//	p2 = p1;
//	delete p1;
//	delete p2;
//	return 0;
//}