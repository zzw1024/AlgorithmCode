////#include <iostream>
////#include <vector>
////using namespace std;
////int n;
////double sum = 0.0;
////int main()
////{
////	cin >> n;
////	double *v = new double[n];
////	for (int i = 0; i < n; ++i)
////		cin >> v[i];
////	for (int i = 0; i < n; ++i)
////		sum += v[i] * (i + 1)*(n - i);
////	printf("%.2f\n", sum);
////	return 0;
////}
//
//
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	double res = 0.0;
//	vector<double>v(n + 1);
//	for (int i = 1; i <= n; ++i)
//		cin >> v[i];
//	for (int i = 1; i <= n; ++i)
//		res += (n - i + 1)*v[i] * i;
//	printf("%.2f\n", res);
//	return 0;
//}