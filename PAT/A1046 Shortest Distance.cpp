////#include <iostream>
////#include <vector>
////using namespace std;
////int N, M;
////int main()
////{
////	cin >> N;
////	int num, a, b;
////	vector<int>sum(N + 1, 0);
////	for (int i = 1; i <= N; ++i)
////	{
////		cin >> num;
////		if (i == N)
////			sum[0] = sum[N] + num;
////		else
////			sum[i + 1] = sum[i] + num;
////	}
////	cin >> M;
////	for (int i = 0; i < M; ++i)
////	{
////		cin >> a >> b;
////		if (a > b)
////			swap(a, b);
////		int d1 = sum[b] - sum[a];
////		int d2 = sum[0] - sum[b] + sum[a] - sum[1];
////		cout << (d1 < d2 ? d1 : d2) << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int>v;
//int n, m;
//int main()
//{
//	cin >> n;
//	v.resize(n + 1, 0);
//	for (int i = 1; i <= n; ++i)
//	{
//		int a = 0;
//		cin >> a;
//		v[i] = v[i - 1] + a;
//	}
//	cin >> m;
//	while (m--)
//	{
//		int a, b, temp, d1, d2;
//		cin >> a >> b;
//		temp = a < b ? a : b;
//		b = a > b ? a : b;
//		a = temp;
//		d1 = v[b - 1] - v[a - 1];
//		d2 = v[n] - d1;
//		cout << (d1 < d2 ? d1 : d2) << endl;
//	}
//	return 0;
//}