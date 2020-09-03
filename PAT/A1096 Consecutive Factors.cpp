////#include <iostream>
////#include <vector>
////#include <cmath>
////using namespace std;
////int N, num = 0, first = -1;
////int main()
////{
////	cin >> N;
////	for (int i = 2; i <= (int)sqrt(N*1.0); ++i)//2~根号N
////	{
////		if (N%i == 0)
////		{
////			int nn = 0;
////			for (int j = i; N%j == 0; j*=i+nn)//从i开始的连续数字,确保能连续除下去，而不是除以一个数字
////				++nn;
////			if (nn > num)//更新最长数字串
////			{
////				first = i;
////				num = nn;
////			}
////		}
////	}
////	if (num == 0)//N就是质数
////		cout << 1 << endl << N << endl;
////	else
////	{
////		cout << num << endl;
////		for (int i = 0; i < num; ++i)
////			cout << first + i << (i == num - 1 ? "" : "*");
////	}
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, maxL = 0, L, R;
//	cin >> n;
//	for (int i = 2, j; i*i <= n; ++i)
//	{
//		int sum = 1;
//		for (j = i; j <= n; ++j)
//		{
//			sum *= j;
//			if (n%sum != 0)
//				break;
//		}
//		if (j - i > maxL)
//		{
//			maxL = j - i;
//			L = i;
//			R = j - 1;
//		}
//	}
//	cout << maxL << endl;
//	for (int i = L; i <= R; ++i)
//		cout << (i == L ? "" : "*") << i;
//	return 0;
//}