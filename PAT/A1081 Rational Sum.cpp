////#include <iostream>
////#include <vector>
////#include <math.h>
////using namespace std;
////long int  gcd(long int a, long int b)
////{
////	if(b==0) return a;
////	else return gcd(b,a%b);	
////}
////int main()
////{
////	int N;
////	cin >> N;
////	long long Inter = 0, resa = 0, resb = 1, a, b, Div, Mul;
////	for (int i = 0; i < N; ++i)
////	{
////		char c;
////		cin >> a >> c >> b;
////		resa = resa * b + a * resb;//同分相加的分子
////		resb = resb * b;
////		Inter += resa / resb;//简化
////		resa = resa - resb * (resa / resb);
////		Div = gcd(resb, resa);
////		resa /= Div;
////		resb /= Div;
////	}
////	if (Inter == 0 && resa == 0)
////		cout << 0 << endl;
////	else if (Inter != 0 && resa == 0)
////		cout << Inter << endl;
////	else if (Inter == 0 && resa != 0)
////		cout << resa << "/" << resb << endl;
////	else
////		cout << Inter << " " << resa << "/" << resb << endl;
////	return 0;
////}
//
//
//
//#include <iostream>
//using namespace std;
//long int getGcd(long int a, long int b)
//{
//	if (a%b == 0)
//		return b;
//	else
//		return getGcd(b, a%b);
//}
//int main()
//{
//	int n;
//	cin >> n;
//	long int A, B, res = 0, resA = 0, resB = 1;
//	while (n--)
//	{
//		scanf("%ld/%ld", &A, &B);
//		long int gcd = getGcd(A, B);
//		long int C = B * resB / gcd;
//		resA = resA * C / resB + A * C / B;
//		resB = C;
//		gcd = getGcd(resA, resB);
//		resA /= gcd;
//		resB /= gcd;
//		res += resA / resB;
//		resA = resA % resB;
//	}
//	if (res != 0)
//		cout << res;
//	if (res != 0 && resA != 0)
//		cout << " ";
//	if (resA != 0)
//		cout << resA << "/" << resB;
//	if (res == 0 && resA == 0)
//		cout << 0;
//	return 0;
//}