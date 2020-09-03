////#include <iostream>
////#include <vector>
////#include <unordered_map>
////
////using namespace std;
////
////int main()
////{
////	int M, N;
////	cin >> M >> N;
////	unordered_map<int, int>res;
////	vector<vector<int>>data(M, vector<int>(N, 0));
////	for (int i = 0; i < N; ++i)
////	{
////		for (int j = 0; j < M; ++j)
////		{
////			int a;
////			cin >> a;
////			res[a]++;
////			if (res[a] > M*N / 2)
////			{
////				cout << a << endl;
////				break;
////			}
////		}
////	}
////	return 0;
////
////}
//
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//	int n, m, res = 0, a;
//	unordered_map<int, int>color;
//	cin >> n >> m;
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			cin >> a;
//			color[a]++;
//			if (color[a] > n*m / 2)
//				res = a;	
//		}
//	}
//	cout << res << endl;
//	return 0;
//}