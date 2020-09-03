//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n, m, k, v[1010][1010] = { 0 }, path[1010], check[1010];
//bool Dijkstra(int x)
//{
//	vector<bool>visit(n + 1, false);
//	fill(path, path + n + 1, INT32_MAX);
//	path[x] = 0;
//	for (int t = 1; t <= n; ++t)
//	{
//		int index = -1, minDis = INT32_MAX;
//		for (int i = 1; i <= n; ++i)
//		{
//			if (visit[i] == false && minDis > path[i])
//			{
//				minDis = path[i];
//				index = i;
//			}
//		}
//		if (path[check[t]] == minDis)index = check[t];//按照给出数组的顺序选择中间节点
//		else return false;
//		visit[index] = true;
//		for (int u = 1; u <= n; ++u)
//			if (visit[u] == false && v[index][u] > 0)
//				if (path[u] > path[index] + v[index][u])
//					path[u] = path[index] + v[index][u];
//	}
//	return true;
//}
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		v[a][b] = v[b][a] = c;
//	}
//	cin >> k;
//	while (k--)
//	{
//		for (int i = 1; i <= n; ++i)
//			cin >> check[i];
//		if (Dijkstra(check[1]))
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//	return 0;
//}
