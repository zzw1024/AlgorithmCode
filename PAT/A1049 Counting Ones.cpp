////#include <iostream>
////using namespace std;
////int main()
////{
////	int n, ans = 0;
////	cin >> n;
////	int left = n / 10, right = 0, cur = n % 10;
////	for (int i = 1; right != n; i *= 10)
////	{
////		ans += left * i + (cur == 0 ? 0 : cur == 1 ? (right + 1) : i);
////		right += cur * i;
////		cur = left % 10;
////		left /= 10;
////	}
////	cout << ans << endl;
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n, ans = 0;
//	cin >> n;
//	int l = n / 10, r = 0, cur = n % 10;
//	for (int i = 1; r != n; i *= 10)
//	{
//		ans += l * i + (cur == 0 ? 0 : cur == 1 ? (r + 1) : i);
//		r += cur * i;
//		cur = l % 10;
//		l /= 10;
//	}
//	cout << ans << endl;
//	return 0;
//}