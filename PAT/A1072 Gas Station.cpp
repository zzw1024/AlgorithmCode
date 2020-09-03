////#include <iostream>
////#include <vector>
////#include <string>
////#define inf 999999999
////using namespace std;
////int N, M, K, Ds, indexG = -1;
////double minG = -1, avgG;
////int city[1010][1010];
////int main()
////{
////	cin >> N >> M >> K >> Ds;
////	fill(city[0], city[0] + 1010 * 1010, inf);
////	for (int i = 0; i < K; ++i)
////	{
////		string s1, s2;
////		int a = 0, b = 0, dis;
////		cin >> s1 >> s2 >> dis;
////		if (s1[0] == 'G')
////		{
////			a += N;
////			s1.erase(0, 1);
////		}
////		if (s2[0] == 'G')
////		{
////			b += N;
////			s2.erase(0, 1);
////		}
////		a += stoi(s1);
////		b += stoi(s2);
////		city[a][b] = city[b][a] = dis;
////	}
////	//Dijsktra
////	for (int k = N+1; k <= N+M; ++k)//每个加油站都是用一次dij
////	{
////		int temp[1010];
////		fill(temp, temp + 1010, inf);
////		bool visit[1010];
////		fill(visit, visit + 1010, false);
////		temp[k] = 0;
////		for (int i = 1; i <= N+M; ++i)
////		{
////			int v = -1, minDis = inf;
////			for (int j = 1; j <= N+M; ++j)
////			{
////				if (visit[j] == false && minDis > temp[j])
////				{
////					v = j;
////					minDis = temp[j];
////				}
////			}
////			if (v == -1)break;
////			visit[v] = true;
////			for (int u = 1; u <= N+M; ++u)
////			{
////				if (visit[u] == false && city[v][u] != inf)
////				{
////					if (temp[u] > temp[v] + city[v][u])
////						temp[u] = temp[v] + city[v][u];
////				}
////			}
////		}
////		int flag = 1, minD = inf;
////		double avgD = 0.0;
////		for (int i = 1; i <= N; ++i)
////		{
////			minD = minD < temp[i] ? minD : temp[i];
////			avgD += (double)temp[i];
////			if (temp[i] > Ds)
////			{
////				flag = 0;
////				break;
////			}
////		}
////		avgD /= N;
////		if (flag == 1 && minG <= minD)
////		{
////			if ((minG < minD) || (minG == minD && avgD < avgG))
////			{
////				minG = minD;
////				indexG = k;
////				avgG = avgD;
////			}
////			else if (minG == minD && avgD == avgG)
////				indexG = indexG < k ? indexG : k;
////		}
////	}
////	if (indexG == -1)
////		cout << "No Solution" << endl;
////	else
////		printf("G%d\n%.1f %.1f\n", indexG - N, minG, avgG);
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//#define NN 1100
//struct Node
//{
//	int id;
//	double minDis, avargDis;
//};
//int routes[NN][NN], path[NN];
//bool visit[NN];
//vector<Node>res;
//int n, m, k, Ds;
//void Dijkstra(int start)
//{
//	path[start] = 0;
//	for (int i = 1; i <= n + m; ++i)
//	{
//		int u = -1, minDis = INT32_MAX;
//		for (int j = 1; j <= n + m; ++j)
//		{
//			if (visit[j] == false && path[j] < minDis)
//			{
//				u = j;
//				minDis = path[j];
//			}
//		}
//		if (u == -1)break;
//		visit[u] = true;
//		for (int v = 1; v <= n + m; ++v)
//			if (visit[v] == false && routes[u][v] < INT32_MAX)
//				if (path[v] > path[u] + routes[u][v])
//					path[v] = path[u] + routes[u][v];			
//	}
//}
//int main()
//{
//	cin >> n >> m >> k >> Ds;
//	fill(routes[0], routes[0] + NN * NN, INT32_MAX);
//	for (int i = 0; i < k; ++i)
//	{
//		int a = 0, b = 0, dis;
//		string s1, s2;
//		cin >> s1 >> s2 >> dis;
//		if (s1[0] == 'G')
//		{
//			s1.erase(0, 1);
//			a += n;
//		}
//		if (s2[0] == 'G')
//		{
//			s2.erase(0, 1);
//			b += n;
//		}
//		a += atoi(s1.c_str());
//		b += atoi(s2.c_str());
//		routes[b][a] = routes[a][b] = dis;
//	}
//	for (int i = 1; i <= m; ++i)
//	{
//		fill(path, path + NN, INT32_MAX);
//		fill(visit, visit + NN, false);
//		Dijkstra(n + i);
//		double minDis = INT32_MAX, sum = 0, maxDis = -1;
//		for (int j = 1; j <= n; ++j)
//		{
//			if (minDis > path[j])
//				minDis = path[j];
//			if (maxDis < path[j])
//				maxDis = path[j];
//			sum += path[j];
//		}
//		if (maxDis <= Ds)
//			res.push_back({ i,minDis,sum / n });
//	}
//	sort(res.begin(), res.end(), [](Node a, Node b) {
//		if (a.avargDis == b.avargDis && a.minDis == b.minDis)
//			return a.id < b.id;
//		else if (a.minDis == b.minDis)
//			return a.avargDis < b.avargDis;
//		else
//			return a.minDis > b.minDis;
//	});
//	if (res.size() == 0)
//		printf("No Solution");
//	else
//		printf("G%d\n%.1f %.1f\n", res[0].id, res[0].minDis, res[0].avargDis);
//	return 0;
//}