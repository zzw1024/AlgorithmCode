////#include <iostream>
////#include <vector>
////
////using namespace std;
////
////#define INF 99999
////int  main()
////{
////	int N, M, C1, C2;
////	cin >> N >> M >> C1 >> C2;
////	vector<vector<int>>dis(N, vector<int>(N, INF));//-1表示路不通
////	vector<int>v(N, 0);
////	for (int i = 0; i < N; ++i)
////		cin >> v[i];
////	for (int i = 0; i < M; ++i)
////	{
////		int a, b, c;
////		cin >> a >> b >> c;
////		dis[a][b] = dis[b][a] = c;
////	}
////	vector<int>index(N, 1);//用来标记是否已经遍历过的点
////	vector<int>w(N, 0);//用来更新权重
////	vector<int>num(N, 0);//用来保存最优路径数量
////	vector<int>D(N, INF);
////	D[C1] = 0; // Start开始出发
////	w[C1] = v[C1];
////	num[C1] = 1;//最开始初始化有一条
////
////	for (int i = 0; i < N; ++i)
////	{
////		//先找出发点去往下一个最近的点
////		int p = -1;
////		int minD = INF;
////		for (int j = 0; j < N; ++j)
////		{
////			if (index[j] && minD > D[j])
////			{
////				p = j;
////				minD = D[j];
////			}
////		}
////		if (p == -1)
////			break;//遍历完毕
////		index[p] = false;//已经遍历过了
////		//那么就遍历点p能去往的点
////		for (int j = 0; j < N; ++j)
////		{
////			//更新点Start->j的距离
////			if (index[j] && D[j] > D[p] + dis[p][j])
////			{
////				D[j] = D[p] + dis[p][j];
////				num[j] = num[p];
////				w[j] = w[p] + v[j];
////			}
////			else if (index[j] && D[j] == D[p] + dis[p][j])//出现相同路径
////			{
////				num[j] += num[p];//叠加最优路径数量
////				w[j] = w[j] > (w[p] + v[j]) ? w[j] : (w[p] + v[j]);//新路的权重是否更大？
////			}
////		}
////	}
////	cout << num[C2] << " " << w[C2] << endl;
////
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m, c1, c2, w[505], path[505][505];
//int route[505], numR[505] = { 0 }, numW[505] = { 0 };
//void Dijkstra()
//{	
//	bool visit[505];
//	fill(route, route + 505, INT32_MAX);
//	fill(visit, visit + 505, false);
//	route[c1] = 0;	
//	numR[c1] = 1;
//	numW[c1] = w[c1];
//	for (int i = 0; i < n; ++i)
//	{
//		int v = -1, minN = INT32_MAX;
//		for (int j = 0; j < n; ++j)
//		{
//			if (visit[j] == false && minN > route[j])
//			{
//				minN = route[j];
//				v = j;
//			}
//		}
//		if (v == -1)break;
//		visit[v] = true;
//		for (int u = 0; u < n; ++u)
//		{
//			if (visit[u] == false && path[v][u] != INT32_MAX)
//			{
//				if (route[u] > route[v] + path[v][u])
//				{
//					route[u] = route[v] + path[v][u];
//					numR[u] = numR[v];//u点的路径数量==v点的路径数量
//					numW[u] = numW[v] + w[u];//权重相加
//				}
//				else if (route[u] == route[v] + path[v][u])
//				{
//					numR[u] += numR[v];//增加一条路径，路径数量叠加
//					numW[u] = numW[u] > (numW[v] + w[u]) ? numW[u] : numW[v] + w[u];//取大值
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m >> c1 >> c2;
//	fill(path[0], path[0] + 505 * 505, INT32_MAX);
//	for (int i = 0; i < n; ++i)
//		cin >> w[i];
//	
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		path[a][b] = path[b][a] = c;
//	}
//	Dijkstra();
//	cout << numR[c2] << " " << numW[c2];
//	return 0;
//}
//
