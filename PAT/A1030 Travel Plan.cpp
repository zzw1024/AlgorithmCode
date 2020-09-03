////#include <iostream>
////#include <vector>
////using namespace std;
////#define inf 999999999
//////使用dijkstra
////int N, M, S, D;
////vector<int>tempPath, path;
////struct Node
////{
////	int dis = inf, w = inf;
////}node;
////int minW = inf;
////void DFS(vector<vector<Node>>&city, vector<vector<int>>&father, int k)
////{
////	tempPath.push_back(k);
////	if (k == S)
////	{
////		int tempW = 0;
////		for (int i = tempPath.size() - 1; i > 0; --i)
////			tempW += city[tempPath[i]][tempPath[i - 1]].w;
////		if (tempW < minW)
////		{
////			minW = tempW;
////			path = tempPath;
////		}
////		tempPath.pop_back();
////		return;
////	}
////	for (int i = 0; i < father[k].size(); ++i)
////		DFS(city, father, father[k][i]);
////	tempPath.pop_back();
////}
////int main()
////{
////	cin >> N >> M >> S >> D;
////	vector<vector<Node>>city(N, vector<Node>(N, node));
////	vector<vector<int>>father(N, vector<int>(1, S));
////	for (int i = 0; i < M; ++i)
////	{
////		int a, b;
////		cin >> a >> b >> node.dis >> node.w;
////		city[a][b] = city[b][a] = node;
////	}	
////	vector<int>dis(N , inf);
////	vector<bool>visit(N, false);
////	dis[S] = 0;
////	//Dijkstra
////	for (int i = 0; i < N; ++i)
////	{
////		int index = -1, minDis = inf;
////		for (int j = 0; j < N; ++j)
////		{
////			if (visit[j]== false && minDis > dis[j])
////			{
////				index = j;
////				minDis = dis[j];
////			}
////		}
////		if (index == -1)break;
////		visit[index] = true;
////		for (int j = 0; j < N; ++j)
////		{
////			if (visit[j] == false && city[index][j].dis < inf)
////			{
////				if (dis[j] > dis[index] + city[index][j].dis)
////				{
////					dis[j] = dis[index] + city[index][j].dis;
////					father[j][0] = index;
////				}
////				else if(dis[j] == dis[index] + city[index][j].dis)
////					father[j].push_back(index);
////			}
////		}
////	}
////	DFS(city, father, D);
////	for (int i = path.size() - 1; i >= 0; --i)
////		cout << path[i] << " ";
////	cout << dis[D] << " " << minW;
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m, start, dest;
//int main()
//{
//	cin >> n >> m >> start >> dest;
//	vector<vector<int>>citys(n, vector<int>(n, INT32_MAX)), W(n, vector<int>(n, INT32_MAX));
//	vector<int>dis(n, INT32_MAX), cost(n, INT32_MAX), visit(n, false), father(n), res;
//	for (int i = 0; i < n; ++i)
//		father[i] = i;
//	for (int i = 0; i < m; ++i)
//	{
//		int a, b, c, d;
//		cin >> a >> b >> c >> d;
//		citys[a][b] = citys[b][a] = c;
//		W[a][b] = W[b][a] = d;
//	}
//	dis[start] = 0;
//	cost[start] = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		int v = -1, minDis = INT32_MAX;
//		for (int j = 0; j < n; ++j)
//		{
//			if (visit[j] == false && minDis > dis[j])
//			{
//				minDis = dis[j];
//				v = j;
//			}
//		}
//		if (v == -1)break;
//		visit[v] = true;
//		for (int u = 0; u < n; ++u)
//		{
//			if (visit[u] == false && citys[v][u] < INT32_MAX)
//			{
//				if (dis[u] > dis[v] + citys[v][u])
//				{
//					dis[u] = dis[v] + citys[v][u];
//					father[u] = v;
//					cost[u] = cost[v] + W[v][u];
//				}
//				else if (dis[u] == dis[v] + citys[v][u])
//				{
//					if (cost[u] > cost[v] + W[v][u])
//					{
//						father[u] = v;
//						cost[u] = cost[v] + W[v][u];
//					}
//				}
//			}
//		}
//	}
//	int k = dest;
//	res.push_back(k);
//	while (father[k] != k)
//	{
//		k = father[k];
//		res.push_back(k);
//	}
//	for (int i = res.size() - 1; i >= 0; --i)
//		cout << res[i] << " ";
//	cout << dis[dest] << " " << cost[dest] << endl;
//	return 0;
//}