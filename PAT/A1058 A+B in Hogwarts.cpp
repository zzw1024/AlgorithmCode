////#include <iostream>
////using namespace std;
////int main()
////{
////	int A[3], B[3], C[3], s = 0;
////	scanf("%d.%d.%d", &A[0], &A[1], &A[2]);
////	scanf("%d.%d.%d", &B[0], &B[1], &B[2]);
////	C[2] = (A[2] + B[2] + s) % 29;
////	s = (A[2] + B[2] + s) / 29;
////	C[1] = (A[1] + B[1] + s) % 17;
////	s = (A[1] + B[1] + s) / 17;
////	C[0] = A[0] + B[0] + s;
////	printf("%d.%d.%d\n", C[0], C[1], C[2]);
////	return 0;
////}
//
//
//
//
//
//#include <iostream>
//using namespace std;
//int main()
//{
//	int g1, g2, s1, s2, k1, k2, g, s, k, c = 0;
//	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
//	k = (k1 + k2 + c) % 29;
//	c = (k1 + k2 + c) / 29;
//	s = (s1 + s2 + c) % 17;
//	c = (s1 + s2 + c) / 17;
//	g = (g1 + g2 + c);
//	printf("%d.%d.%d", g, s, k);
//	return 0;
//}