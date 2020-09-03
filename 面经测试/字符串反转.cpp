//#include "head.h"
//
//void ReverseString(string& str, int L, int R)
//{
//	while (L < R)
//	{
//		swap(str[L], str[R]);
//		++L;
//		--R;
//	}
//}
//
//void RotateString(string& str, int n, int m)
//{
//	m %= n;
//	ReverseString(str, 0, m - 1);
//	ReverseString(str, m, n - 1);
//	ReverseString(str, 0, n - 1);
//	cout << str;
//}
//
//int main()
//{
//	string str = "abcdefghijklmn";
//	RotateString(str, str.size(), 6);
//	return 0;
//}