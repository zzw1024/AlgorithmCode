//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//
//int main()
//{
//	int T, N, M, op, X, Y;
//	cin >> T;
//	while (T--)
//	{
//		cin >> N >> M;	
//		vector<set<int>>v(N + 1);
//		for (int i = 1; i <= N; ++i)
//			v[i].insert(i);
//		for (int i = 0; i < M; ++i)
//		{
//			cin >> op;
//			if (op == 1)
//			{
//				cin >> X >> Y;
//				if (v[X] != v[Y])//
//				{
//					for (auto apt = v[Y].begin(); apt != v[Y].end(); ++apt)
//						v[X].insert(*apt);
//					for (auto apt = v[X].begin(); apt != v[X].end(); ++apt)
//						v[*apt] = v[X];
//				}
//			}
//			else if (op == 2)
//			{
//				cin >> X;
//				set<int>temp = v[X];
//				v[X].clear();
//				v[X].insert(X);
//				if (temp.size() > 1)//
//					for (auto apt = temp.begin(); apt != temp.end(); ++apt)
//						if (*apt != X)
//							v[*apt].erase(X);
//			}
//			else
//			{
//				cin >> X;
//				cout << v[X].size() << endl;
//			}
//		}
//	}
//	return 0;
//}