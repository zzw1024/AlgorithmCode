////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int n, s1 = 0, s2 = 0, nMin, sMin;
////int main()
////{
////	cin >> n;
////	vector<int>v(n);
////	for (int i = 0; i < n; ++i)
////		cin >> v[i];
////	sort(v.begin(), v.end());
////	for (int i = 0; i < n; ++i)
////	{
////		if (i < n / 2)
////			s1 += v[i];
////		else
////			s2 += v[i];
////	}
////	cout << n % 2 << " " << s2 - s1 << endl;
////	return 0;
////
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, s1 = 0, s2 = 0;
//	cin >> n;
//	vector<int>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end());
//	for (int i = 0; i < n; ++i)
//	{
//		if (i < n / 2)
//			s1 += v[i];
//		else
//			s2 += v[i];
//	}
//	cout << (n % 2 == 0 ? 0 : 1) << " " << s2 - s1 << endl;
//	return 0;
//}
//
//
