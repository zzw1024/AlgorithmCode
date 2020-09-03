//////mmp,看了半天都没有看懂题，英语弱到爆
//////百度后才知道，每条边至少有一个顶点存在set总，则该set是vertex cover
////#include <iostream>
////#include <vector>
////using namespace std;
////int a, b, n, m, k,nv;
////int main()
////{
////	cin >> n >> m;
////	vector<pair<int, int>>graph(m);
////	for (int i = 0; i < m; ++i)
////		cin >> graph[i].first >> graph[i].second;
////	cin >> k;
////	while (k--)
////	{
////		cin >> nv;
////		vector<bool>map(n, false);
////		while (nv--)
////		{
////			cin >> a;
////			map[a] = true;
////		}
////		bool flag = true;
////		for (int i = 0; flag&&i < m; ++i)
////			if (map[graph[i].first] == false && map[graph[i].second] == false)//没有一个顶点存在map中
////				flag = false;
////		cout << (flag ? "Yes" : "No") << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, m, k, t, p;
//	cin >> n >> m;
//	vector<pair<int, int>>edge(m);
//	for (int i = 0; i < m; ++i)
//		cin >> edge[i].first >> edge[i].second;
//	cin >> k;
//	while (k--)
//	{
//		cin >> t;
//		bool flag = true;
//		vector<bool>vertex(n, false);
//		while (t--)
//		{
//			cin >> p;
//			vertex[p] = true;
//		}
//		for (int i = 0; i < m; ++i)
//		{
//			if (vertex[edge[i].first] == false && vertex[edge[i].second] == false)
//			{
//				flag = false;
//				break;
//			}
//		}
//		if (flag)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}