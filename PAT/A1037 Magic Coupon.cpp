////#include <iostream>
////#include <vector>
////#include <string>
////#include <algorithm>
////using namespace std;
//////牛客这道题涉及数相乘会int溢出，而PAT没有，所以pat使用int类型就可以，而牛客需要使用longlong型
////long long Nc, Np, p = 0, q = 0, a, res = 0;
////int main()
////{
////	cin >> Nc;
////	vector<long>Vc, Vp;
////	for (int i = 0; i < Nc; ++i)
////	{
////		cin >> a;
////		Vc.push_back(a);
////	}
////	cin >> Np;
////	for (int i = 0; i < Np; ++i)
////	{
////		cin >> a;
////		Vp.push_back(a);
////	}
////	sort(Vc.begin(), Vc.end(), [](long long u, long long v) {return u < v; });
////	sort(Vp.begin(), Vp.end(), [](long long u, long long v) {return u < v; });
////	while (p < Nc&&q < Np&&Vc[p] < 0 && Vp[q] < 0)//先负数相乘
////	{
////		res += Vc[p] * Vp[q];
////		++p;
////		++q;
////	}
////	p = Nc - 1;
////	q = Np - 1;
////	while (p >= 0 & q >= 0 && Vc[p] > 0 && Vp[q] > 0)//正数从后开始乘
////	{
////		res += Vc[p] * Vp[q];
////		--p;
////		--q;
////	}
////	cout << res << endl;
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
//	vector<long long>v1, v2, v3, v4;
//	long long res = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		int a;
//		cin >> a;
//		if (a >= 0)
//			v1.push_back(a);
//		else
//			v2.push_back(a);
//	}
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		int a;
//		cin >> a;
//		if (a >= 0)
//			v3.push_back(a);
//		else
//			v4.push_back(a);
//	}
//	sort(v1.begin(), v1.end(), [](long long a, long long b) {return a > b; });
//	sort(v3.begin(), v3.end(), [](long long a, long long b) {return a > b; });
//	sort(v2.begin(), v2.end(), [](long long a, long long b) {return a < b; });
//	sort(v4.begin(), v4.end(), [](long long a, long long b) {return a < b; });
//	for (int i = 0; i < min(v1.size(), v3.size()); ++i)
//		res += v1[i] * v3[i];
//	for (int i = 0; i < min(v2.size(), v4.size()); ++i)
//		res += v2[i] * v4[i];
//	cout << res;
//	return 0;
//}
