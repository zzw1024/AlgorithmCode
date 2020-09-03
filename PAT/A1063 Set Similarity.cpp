////#include <iostream>
////#include <unordered_set>//用set来去重
////using namespace std;
//////Nc为两组数组中的公共数字的个数
//////Nt为去重后，两组数据的总个数
////int N, M, K, d;
////unordered_set<int>nums[55];
////int main()
////{
////	cin >> N;
////	for (int i = 1; i <= N; ++i)
////	{
////		cin >> M;
////		for (int j = 0; j < M; ++j)
////		{
////			cin >> d;
////			nums[i].insert(d);
////		}
////	}
////	cin >> K;
////	for (int i = 0; i < K; ++i)
////	{
////		int a, b;
////		double res, Nc = 0, Nt = 0;
////		cin >> a >> b;
////		for (auto v : nums[a])
////			if (nums[b].find(v) != nums[b].end())
////				Nc++;
////		Nt = nums[a].size() + nums[b].size() - Nc;
////		res = (Nc / Nt)*100.0;
////		printf("%.1f%%\n", res);
////	}
////	return 0;
////}
//
//
//#include <iostream>
//#include <unordered_set>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, m, k, a, b;
//	cin >> n;
//	vector<unordered_set<int>>v(n + 1);
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> m;
//		while (m--)
//		{
//			cin >> a;
//			v[i].insert(a);
//		}
//	}
//	cin >> k;
//	while (k--)
//	{
//		cin >> a >> b;
//		double c1 = 0.0, c2 = 0.0;
//		for (auto t : v[a])
//			if (v[b].find(t) != v[b].end())
//				c1++;
//		printf("%.1f%\n", 100.0*c1 / (v[a].size() + v[b].size() - c1));
//	}
//	return 0;
//}