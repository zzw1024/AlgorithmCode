//#include "head.h"
//
////������Ĺ���
//class Temp{
//public:
//	Temp() { ++N; sum += N; }
//	static void Reset() { N = 0; sum = 0; }
//	static unsigned int getRes() { return sum; }
//private:
//	static unsigned int N, sum;//һ�����Ǿ�̬������ÿ�δ����ǻ����¸�ֵ
//};
//unsigned int Temp::N = 0; //һ�����ȳ�ʼ��
//unsigned int Temp::sum = 0;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		Temp::Reset();
//		Temp *t = new Temp[n];
//		delete[]t;
//		t = nullptr;
//		return Temp::getRes();
//	}
//};
////�����������
//class A;
//A *Array[2];
//class A{
//public:
//	virtual unsigned int sum(unsigned int n){
//		return 0;
//	}
//};
//class B :public A {
//public:
//	virtual unsigned int sum(unsigned int n) {
//		return Array[!!n]->sum(n - 1) + n;
//	}
//};
//int getSum(int n) {
//	A a;
//	B b;
//	Array[0] = &a;
//	Array[1] = &b;
//	return Array[1]->sum(n);
//}
////���ú���ָ��
//typedef unsigned int(*fun)(unsigned int);
//unsigned int Solution3_Teminator(unsigned int n){
//	return 0;
//}
//
//unsigned int Sum_Solution3(unsigned int n){
//	static fun f[2] = { Solution3_Teminator, Sum_Solution3 };
//	return n + f[!!n](n - 1);
//}
//
//// ����ģ��
//template <unsigned int n> struct Sum_Solution4{
//	enum Value { N = Sum_Solution4<n - 1>::N + n };
//};
//
//template <> struct Sum_Solution4<1>{
//	enum Value { N = 1 };
//};
//
//template <> struct Sum_Solution4<0>{
//	enum Value { N = 0 };
//};
//
//int main()
//{
//	Solution s;
//	cout << s.Sum_Solution(5) << endl;
//	return 0;
//}