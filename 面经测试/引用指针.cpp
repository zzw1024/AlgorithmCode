//#include "head.h"
//
//class A {
//public:
//	int a;
//};
//class B : public A {
//public:
//	long b;
//};
//void seta(A* data, int idx) {
//	data[idx].a = 2;
//}
//int main(int argc, char *argv[]) {
//	B data[4];
//	for (int i = 0; i < 4; ++i) {
//		data[i].a = 1;
//		data[i].b = 1;
//		seta(data, i);
//	}
//	for (int i = 0; i < 4; ++i) {
//		std::cout << data[i].a << data[i].b;    //22221111
//	}
//	return 0;
//}
