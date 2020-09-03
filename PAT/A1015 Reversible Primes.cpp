////#include <iostream>
////#include <math.h>
////#include <string>
////
////using namespace std;
//////其实就是将输入的数字转化为该进制的反序列，然后再转化为10进制
//////然后判断是否是素数即可
////
////bool isPrim(int a)
////{
////	if (a < 2)
////		return false;
////	int b = (int)sqrt(1.0 * a);
////	for (int i = 2; i <= b; ++i)
////	{
////		if (a%i == 0)
////			return false;
////	}
////	return true;
////}
////
////int getReverNum(int a, int b)
////{
////	string str = "";//得到反转的序列
////	while (a > 0)
////	{
////		str += a % b + '0';
////		a /= b;
////	}
////	int n = 0;
////	for (int i = str.length() - 1, j = 0; i >= 0; --i, ++j)
////		n += (str[i] - '0')*pow(b, j);
////	return n;
////}
////
////int main()
////{
////	int a, b;
////	while (cin >> a)
////	{
////		if (a < 0)break;
////		cin >> b;
////		if (isPrim(a) && isPrim(getReverNum(a,b)))
////			cout << "Yes" << endl;
////		else
////			cout << "No" << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int n, d;
//bool isPrime(int x)
//{
//	if (x < 3)
//		return x > 1 ? 1 : 0;
//	for (int i = 2; i*i <= x; ++i)
//		if (x%i == 0)
//			return false;
//	return true;
//}
//int getDeciaml(string s, int x)
//{
//	int res = 0, temp = 1;
//	for (int i = s.length() - 1; i >= 0; --i)
//	{
//		res += (s[i] - '0')*temp;
//		temp *= x;
//	}
//	return res;
//}
//string getString(int num,int x )
//{
//	string s = "";
//	while (num != 0)
//	{
//		s += (num % x + '0');//得到的是反向的进制数
//		num /= x;
//	}
//	return s;
//}
//int main()
//{
//	string str;
//	while (true)
//	{
//		cin >> n >> d;
//		if (n < 0)break;
//		str = getString(n, d);//得到的就是反转二进制
//		if (isPrime(n) && isPrime(getDeciaml(str, d)))
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}