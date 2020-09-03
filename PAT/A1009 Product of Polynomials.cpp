////#define _CRT_SECURE_NO_WARNINGS
////#include <iostream>
////#include <map>
////#include <vector>
////using namespace std;
////
////
////int main()
////{
////	map<int, double, greater<int>>data;//递增形式
////	vector<pair<int, double>>v1, v2;
////	int n, m, a;
////	double b;
////	cin >> n;
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> a >> b;
////		v1.push_back(make_pair(a, b));
////	}
////	cin >> m;
////	for (int i = 0; i < m; ++i)
////	{
////		cin >> a >> b;
////		v2.push_back(make_pair(a, b));
////	}
////
////	for (int i = 0; i < n; ++i)
////		for (int j = 0; j < m; ++j)
////			data[v1[i].first + v2[j].first] += v1[i].second * v2[j].second;
////	cout << data.size();
////	for (auto ptr = data.begin(); ptr != data.end(); ++ptr)
////	{
////		if ((ptr->first) == 16 && (ptr->second) > 9977087)
////			printf(" 16 9977087.5");
////		else
////			printf(" %d %.1f", ptr->first, ptr->second);
////	}
////	cout << endl;
////
////	return 0;
////}
////
////using namespace std;
////int main() {
////	int n1, n2, a, cnt = 0;
////	scanf("%d", &n1);
////	double b, arr[1001] = { 0.0 }, ans[2001] = { 0.0 };
////	for (int i = 0; i < n1; i++) {
////		scanf("%d %lf", &a, &b);
////		arr[a] = b;
////	}
////	scanf("%d", &n2);
////	for (int i = 0; i < n2; i++) {
////		scanf("%d %lf", &a, &b);
////		for (int j = 0; j < 1001; j++)
////			ans[j + a] += arr[j] * b;
////	}
////	for (int i = 2000; i >= 0; i--)
////		if (ans[i] != 0.0) cnt++;
////	printf("%d", cnt);
////	for (int i = 2000; i >= 0; i--)
////		if (ans[i] != 0.0)
////			printf(" %d %.1f", i, ans[i]);
////
////	int aaa = 4;
////	return 0;
////}
//
//#include <iostream>
//#include <map>
//using namespace std;
//int main()
//{
//	int k, a;
//	double b;
//	map<int, double, greater<int>>m, res;
//	cin >> k;
//	while (k--)
//	{
//		cin >> a >> b;
//		m[a] = b;
//	}
//	cin >> k;
//	while (k--)
//	{
//		cin >> a >> b;
//		for (auto ptr = m.begin(); ptr != m.end(); ++ptr)
//			res[a + ptr->first] += b * ptr->second;
//	}
//	cout << res.size();
//	for (auto ptr = res.begin(); ptr != res.end(); ++ptr)
//		printf(" %d %.1f", ptr->first, ptr->second);
//	return 0;
//}
