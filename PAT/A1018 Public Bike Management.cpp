//#include <iostream>
//#include <algorithm>
//#include <vector>
////using namespace std;
////const int inf = 99999999;
////int cmax, n, sp, m;
////int minneed = inf, minback = inf;
////int e[510][510], dis[510], weight[510];
////bool visit[510];
////vector<int> pre[510], path, temppath;
////void dfs(int v) {
////	temppath.push_back(v);
////	if (v == 0) {
////		int need = 0, back = 0;
////		for (int i = temppath.size() - 1; i >= 0; i--) {
////			int id = temppath[i];
////			if (weight[id] > 0) {
////				back += weight[id];
////			}
////			else {
////				if (back > (0 - weight[id])) {
////					back += weight[id];
////				}
////				else {
////					need += ((0 - weight[id]) - back);
////					back = 0;
////				}
////			}
////		}
////		if (need < minneed) {
////			minneed = need;
////			minback = back;
////			path = temppath;
////		}
////		else if (need == minneed && back < minback) {
////			minback = back;
////			path = temppath;
////		}
////		temppath.pop_back();
////		return;
////	}
////	for (int i = 0; i < pre[v].size(); i++)
////		dfs(pre[v][i]);
////	temppath.pop_back();
////}
////int main() {
////	fill(e[0], e[0] + 510 * 510, inf);
////	fill(dis, dis + 510, inf);
////	scanf("%d%d%d%d", &cmax, &n, &sp, &m);
////	for (int i = 1; i <= n; i++) {
////		scanf("%d", &weight[i]);
////		weight[i] = weight[i] - cmax / 2;
////	}
////	for (int i = 0; i < m; i++) {
////		int a, b;
////		scanf("%d%d", &a, &b);
////		scanf("%d", &e[a][b]);
////		e[b][a] = e[a][b];
////	}
////	dis[0] = 0;
////	for (int i = 0; i <= n; i++) {
////		int u = -1, minn = inf;
////		for (int j = 0; j <= n; j++) {
////			if (visit[j] == false && dis[j] < minn) {
////				u = j;
////				minn = dis[j];
////			}
////		}
////		if (u == -1) break;
////		visit[u] = true;
////		for (int v = 0; v <= n; v++) {
////			if (visit[v] == false && e[u][v] != inf) {
////				if (dis[v] > dis[u] + e[u][v]) {
////					dis[v] = dis[u] + e[u][v];
////					pre[v].clear();
////					pre[v].push_back(u);
////				}
////				else if (dis[v] == dis[u] + e[u][v]) {
////					pre[v].push_back(u);
////				}
////			}
////		}
////	}
////	dfs(sp);
////	printf("%d 0", minneed);
////	for (int i = path.size() - 2; i >= 0; i--)
////		printf("->%d", path[i]);
////	printf(" %d", minback);
////	return 0;
////}
////
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int C, N, Sp, M, c1, c2, w;
//int bikes[505] = { 0 }, graph[505][505], dis[505];
//vector<int>father[505], path, tempPath;//因为每个节点的父节点可能有多个
//bool visit[505] = { false };
//int minNeed = INT32_MAX, minBack = INT32_MAX;
//void Dijkstra(int st)
//{
//	dis[st] = 0;
//	for (int i = 0; i <= N; ++i)
//	{
//		int u = -1, minDis = INT32_MAX;
//		for (int j = 0; j <= N; ++j)
//		{
//			if (visit[j] == false && minDis > dis[j])
//			{
//				u = j;
//				minDis = dis[j];
//			}
//		}
//		if (u == -1)break;
//		visit[u] = true;
//		for (int v = 0; v <= N; ++v)
//		{
//			if (visit[v] == false && graph[u][v] <INT32_MAX)
//			{
//				if (dis[v] > dis[u] + graph[u][v])
//				{
//					dis[v] = dis[u] + graph[u][v];
//					father[v].clear();
//					father[v].push_back(u);
//				}
//				else if (dis[v] == dis[u] + graph[u][v])
//					father[v].push_back(u);
//			}
//		}
//	}
//}
//void DFS(int v)
//{
//	tempPath.push_back(v);
//	if (v == 0)//回到了起点，我们计算需要的自行车数量
//	{
//		int need = 0, back = 0;
//		for (int i = tempPath.size() - 1; i >= 0; --i)
//		{
//			int id = tempPath[i];
//			if (bikes[id] > 0)//车的数量过多，需要拿回去
//				back += bikes[id];
//			else
//			{//车的数量不够
//				if (back > (0 - bikes[id]))//拿回去的比要的多，那就还得拿回去
//					back += bikes[id];
//				else //需要的比拿回去的多，还得拿过来
//				{
//					need += ((0 - bikes[id]) - back);
//					back = 0;
//				}
//			}
//		}
//		if (minNeed > need)
//		{
//			minNeed = need;
//			minBack = back;
//			path = tempPath;
//		}
//		else if (minNeed == need && back< minBack)
//		{
//			minBack = back;
//			path = tempPath;
//		}
//		tempPath.pop_back();
//		return;
//	}
//	for (int i = 0; i < father[v].size(); ++i)
//		DFS(father[v][i]);
//	tempPath.pop_back();
//}
//int main()
//{
//	fill(graph[0], graph[0] + 505 * 505, INT32_MAX);
//	fill(dis, dis + 505, INT32_MAX);
//	cin >> C >> N >> Sp >> M;
//	for (int i = 1; i <= N; ++i)
//	{
//		cin >> bikes[i];
//		bikes[i] = bikes[i] - C / 2;
//	}
//	while (M--)
//	{
//		cin >> c1 >> c2 >> w;
//		graph[c1][c2] = graph[c2][c1] = w;
//	}
//	Dijkstra(0);
//	DFS(Sp);
//	cout << minNeed << " " << 0;
//	for (int i = path.size() - 2; i >= 0; --i)
//		cout << "->" << path[i];
//	cout << " " << minBack;
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int theC, n, m, den, cap[505], v[505][505] = { 0 };
//vector<int>father[505];
//void Dijstra( )
//{
//	vector<int>path(n + 1, INT32_MAX);
//	vector<bool>visit(n + 1, false);
//	path[0] = 0;
//	for (int i = 0; i <= n; ++i)
//	{
//		int index = -1, minD = INT32_MAX;
//		for (int j = 0; j <= n; ++j)
//		{
//			if (visit[j] == false && minD > path[j])
//			{
//				index = j;
//				minD = path[j];
//			}
//		}
//		if (index == -1)break;
//		visit[index] = true;
//		for (int u = 0; u <= n; ++u)
//		{
//			if (visit[u] == false && v[index][u] > 0)
//			{
//				if (path[u] > path[index] + v[index][u])
//				{
//					path[u] = path[index] + v[index][u];
//					father[u].clear();
//					father[u].push_back(index);
//				}
//				else if (path[u] == path[index] + v[index][u])
//					father[u].push_back(index);
//			}
//		}
//	}
//}
//int minNeed = INT32_MAX, minBack = INT32_MAX;
//vector<int>temp, res;
//void DFS(int x)
//{
//	temp.push_back(x);
//	if (x == 0)
//	{
//		int need = 0, back = 0;
//		for (int i = temp.size()-2; i >= 0; --i)
//		{
//			int dis = cap[temp[i]] - theC / 2;
//			if (dis >= 0)
//				back += dis;
//			else
//			{
//				if (back + dis >= 0)//带回去的可以补充缺少的
//					back += dis;
//				else//缺太多
//				{
//					need -= (back + dis);
//					back = 0;
//				}
//			}
//		}
//		if (need < minNeed)
//		{
//			res = temp;
//			minNeed = need;
//			minBack = back;
//		}
//		else if (need ==minNeed && back < minBack)
//		{
//			minBack = back;
//			res = temp;
//		}
//	}
//	for (auto a : father[x])
//		DFS(a);
//	temp.pop_back();
//}
//int main()
//{
//	cin >> theC >> n >> den >> m;
//	for (int i = 1; i <= n; ++i)
//		cin >> cap[i];
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		v[a][b] = v[b][a] = c;		
//	}
//	Dijstra( );
//	DFS(den);
//	cout << minNeed << " " << 0;
//	for (int i = res.size() - 2; i >= 0; --i)
//		cout << "->" << res[i];
//	cout << " " << minBack;
//	return 0;
//}
