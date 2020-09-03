////#include <iostream>
////using namespace std;
////long long dv, res1, res2;
////long long DIV(long long a, long long b)
////{
////	if (b == 0)
////		return abs(a);
////	return DIV(b, a%b);
////}
////void print(long long a1, long long b1, long long a2, long long b2, char c)
////{
////	if (a1 == 0)
////		printf("%d %c ", 0, c);
////	else
////	{
////		printf("%s", a1 > 0 ? "" : "(");
////		dv = DIV(a1, b1);
////		a1 /= dv;
////		b1 /= dv;
////
////		if (a1 / b1 != 0)
////			printf("%d", a1 / b1);
////		if (a1 - b1 * (a1 / b1) != 0)
////			printf("%s%d/%d", a1 / b1 != 0 ? " " : "", a1 / b1 != 0 ? abs(a1 - b1 * (a1 / b1)) : a1, b1);
////		printf("%s %c ", a1 > 0 ? "" : ")", c);
////	}
////
////	if(a2 == 0)
////		printf("%d %s ", 0, "=");
////	else
////	{
////		printf("%s", a2 > 0 ? "" : "(");
////		dv = DIV(a2, b2);
////		a2 /= dv;
////		b2 /= dv;
////		if (a2 / b2 != 0)
////			printf("%d", a2 / b2);
////		if (a2 - b2 * (a2 / b2) != 0)
////			printf("%s%d/%d", a2 / b2 != 0 ? " " : "", a2 / b2 != 0 ? abs(a2 - b2 * (a2 / b2)) : a2, b2);
////		printf("%s %s ", a2 > 0 ? "" : ")", "=");
////	}
////
////	if (res1 == 0)
////	{
////		printf("%d\n",0);
////		return;
////	}
////	else if (res2 == 0)
////	{
////		printf("Inf\n");
////		return;
////	}
////	printf("%s", res1 > 0 ? "" : "(");
////	dv = DIV(res1, res2);
////	res1 /= dv;
////	res2 /= dv;
////	if (res1 / res2 != 0)
////		printf("%d", res1 / res2);
////	if (res1 - res2 * (res1 / res2) != 0)
////		printf("%s%d/%d", res1 / res2 != 0 ? " " : "", res1 / res2 != 0 ? abs(res1 - res2 * (res1 / res2)) : res1, res2);
////	printf("%s\n", res1 > 0 ? "" : ")");
////}
////int main()
////{
////	char c;
////	long long a1, b1, a2, b2;
////	cin >> a1 >> c >> b1 >> a2 >> c >> b2;
////	// +
////	res1 = a1 * b2 + a2 * b1;
////	res2 = b1 * b2;
////	print(a1, b1, a2, b2, '+');
////	// -
////	res1 = a1 * b2 - a2 * b1;
////	res2 = b1 * b2;
////	print(a1, b1, a2, b2, '-');
////	// *
////	res1 = a1 * a2;
////	res2 = b1 * b2;
////	print(a1, b1, a2, b2, '*');
////	// /
////	res1 = a2 > 0 ? a1 * b2 : a1 * b2*-1;
////	res2 = b1 * abs(a2);
////	print(a1, b1, a2, b2, '/');
////	return 0;
////}
//
//
//
//
//
//#include <iostream>
//using namespace std;
//long int getGcd(long int a, long int b)
//{
//	if (a%b == 0)
//		return (b < 0 ? b * -1 : b);
//	return getGcd(b, a%b);
//}
//string printNum(long int a, long int b)
//{
//	long int gcd = getGcd(a, b);
//	a = a / gcd, b = b / gcd;
//	bool flag = false;
//	if (a < 0)
//		flag = true;
//	if (a%b == 0)//只有整数
//		cout << (flag ? "(" : "") << (a / b) << (flag ? ")" : "");
//	else if (a / b == 0)//只有分数
//		cout << (flag ? "(" : "") << a << "/" << b << (flag ? ")" : "");
//	else //既有整数又有分数
//		cout << (flag ? "(" : "") << (a / b) << " " << ((a < 0 ? a * -1 : a) % b) << "/" << b << (flag ? ")" : "");
//	return "";
//}
//int main()
//{
//	long int  resA, resB, A1, B1, A2, B2;
//	scanf("%ld/%ld %ld/%ld", &A1, &B1, &A2, &B2);
//	resB = B1 / getGcd(B1, B2)*B2;
//	resA = resB / B1 * A1 + resB / B2 * A2;
//	printNum(A1, B1), printf(" + "), printNum(A2, B2), printf(" = "), printNum(resA, resB), printf("\n");
//	resB = B1 / getGcd(B1, B2)*B2;
//	resA = resB / B1 * A1 - resB / B2 * A2;
//	printNum(A1, B1), printf(" - "), printNum(A2, B2), printf(" = "), printNum(resA, resB), printf("\n");
//	resB = B1 * B2;
//	resA = A1 * A2;
//	printNum(A1, B1), printf(" * "), printNum(A2, B2), printf(" = "), printNum(resA, resB), printf("\n");
//	if (A2 == 0)
//		printNum(A1, B1), printf(" / 0 = Inf\n");
//	else
//	{
//		resA = A1 * B2, resB = B1 * A2;
//		if (resB < 0){
//			resA *= -1, resB *= -1;
//		}
//		printNum(A1, B1), printf(" / "), printNum(A2, B2), printf(" = "), printNum(resA, resB), printf("\n");
//	}
//	return 0;
//}