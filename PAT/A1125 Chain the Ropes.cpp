////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <cmath>
////using namespace std;
////int main()
////{
////	int n;
////	double res;
////	cin >> n;
////	vector<double>v(n);
////	for (int i = 0; i < n; ++i)
////		cin >> v[i];
////	sort(v.begin(), v.end());
////	for (int i = 1; i < n; ++i)
////		v[i] = (v[i] + v[i - 1]) / 2.0;
////	cout << floor(v[n - 1]);
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<double>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end());
//	for (int i = 1; i < n; ++i)
//		v[i] = (v[i] + v[i - 1]) / 2;
//	cout << (int)v[n - 1] << endl;
//	return 0;
//}