//////#include<iostream>
//////#include<string>
//////#include<unordered_map>
//////using namespace std;
//////int graph[205][205];
//////int city[205], dis[205], happiness[205];//每个城市的幸福值、到达每个城市时的距离和幸福值
//////int pathnum[205], past[205], pastnum[205];//到达每个城市时的最短路径条数、每个城市的前驱城市、到达每个城市前经过的城市
//////bool visit[205];//每个城市是否被访问过
//////unordered_map<string, int>STOI;//将城市字符串映射到整数
//////string ITOS[205];//将整数映射到字符串
//////int N, K;
//////void Dijkstra(int vend) {
//////	while (!visit[vend]) {//当未遍历到终点城市时
//////		int v = -1, MIN = INT_MAX;
//////		for (int i = 0; i < N; ++i)//找出当前未被访问的距离最小的城市
//////			if (!visit[i] && MIN > dis[i]) {
//////				v = i;
//////				MIN = dis[i];
//////			}
//////		if (v == -1)//图不连通直接返回
//////			return;
//////		visit[v] = true;//当前城市已访问
//////		for (int i = 0; i < N; ++i)//遍历当前城市能到达的城市
//////			if (!visit[i] && graph[v][i] != 0 && dis[i] > dis[v] + graph[v][i]) {//能到达的当前城市未被访问过且距离可更新
//////				dis[i] = dis[v] + graph[v][i];//更新到达该城市的距离
//////				happiness[i] = happiness[v] + city[i];//更新到达该城市的幸福值
//////				pastnum[i] = pastnum[v] + 1;//更新到达该城市前遍历过的城市数
//////				past[i] = v;//更新到达该城市的前驱城市
//////				pathnum[i] = pathnum[v];//更新到达该城市的最短路径条数
//////			}
//////			else if (graph[v][i] != 0 && dis[i] == dis[v] + graph[v][i]) {//到达该城市时的距离与该城市储存的距离相等
//////				pathnum[i] += pathnum[v];//更新到达该城市的最短路径条数
//////				if (happiness[i] < happiness[v] + city[i] || (happiness[i] == happiness[v] + city[i] && pastnum[i] > pastnum[v] + 1)) {
//////					past[i] = v;//更新到达该城市的前驱城市
//////					happiness[i] = happiness[v] + city[i];//更新到达该城市的幸福值
//////					pastnum[i] = pastnum[v] + 1;//更新到达该城市的最短路径条数
//////				}
//////			}
//////	}
//////}
//////void DFS(int v) {
//////	if (v == 0) {
//////		cout << ITOS[v];
//////		return;
//////	}
//////	DFS(past[v]);
//////	cout << "->" << ITOS[v];
//////}
//////int main() {
//////	scanf("%d%d", &N, &K);
//////	cin >> ITOS[0];
//////	STOI.insert({ ITOS[0],0 });
//////	for (int i = 1; i < N; ++i) {
//////		cin >> ITOS[i];
//////		STOI.insert({ ITOS[i],i });
//////		cin >> city[i];
//////	}
//////	while (K--) {
//////		int a;
//////		string s1, s2;
//////		cin >> s1 >> s2 >> a;
//////		graph[STOI[s1]][STOI[s2]] = graph[STOI[s2]][STOI[s1]] = a;
//////	}
//////	int vend = STOI["ROM"];//将ROM设置为终点城市
//////	fill(dis + 1, dis + N, INT_MAX);//距离初始化为INT_MAX
//////	pathnum[0] = 1;//起点城市最短路径条数设置为1
//////	Dijkstra(vend);
//////	printf("%d %d %d %d\n", pathnum[vend], dis[vend], happiness[vend], happiness[vend] / pastnum[vend]);
//////	DFS(vend);
//////	return 0;
//////}
////
////
////#include <iostream>
////#include <vector>
////#include <string>
////#include <unordered_map>
////#include <algorithm>
////using namespace std;
////#define NN 205
////int n, m, start, vend, num;
////int routes[NN][NN], happy[NN] = { 0 }, pathNums[NN] = { 0 }, pastCityNums[NN] = { 0 }, getHappy[NN] = { 0 }, path[NN], father[NN];
//////路线矩阵        幸福指数             最优路线数量           经过的城市数量      到达每个城市的最大幸福指数  最优路径值   路线
////unordered_map<string, int>getId;
////unordered_map<int, string>getName;
////void Dijkstra(int start)
////{
////	bool visit[NN] = { false };
////	fill(path, path + NN, INT32_MAX);
////	path[start] = 0;//起点的最短路径值为0
////	pathNums[start] = 1;//经过起点的最优路线为1
////	for (int i = 0; i < n; ++i)
////		father[i] = i;
////	for (int i = 0; i < n; ++i)
////	{
////		int u = -1, minDis = INT32_MAX;
////		for (int i = 0; i < n; ++i)//寻找新起点
////		{
////			if (visit[i] == false && minDis > path[i])
////			{
////				u = i;
////				minDis = path[i];
////			}
////		}
////		if (u == -1)return;
////		visit[u] = true;
////		for (int v = 0; v < n; ++v)
////		{
////			if (visit[v] == false && routes[u][v] < INT32_MAX)
////			{
////				if (path[v] > path[u] + routes[u][v])//获得更短路径
////				{					
////					path[v] = path[u] + routes[u][v];//经过城市v的代价值
////					getHappy[v] = getHappy[u] + happy[v];//经过城市v的幸福指数
////					pathNums[v] = pathNums[u];//经过城市v的路线数量
////					pastCityNums[v] = pastCityNums[u] + 1;//到达城市v所经过的城市数目
////					father[v] = u;
////				}
////				else if (path[v] == path[u] + routes[u][v])
////				{
////					pathNums[v] += pathNums[u];//经过城市v的路线数量
////					if (getHappy[v] < getHappy[u] + happy[v] ||//获得更多快乐，
////						(getHappy[v] == getHappy[u] + happy[v] && pastCityNums[v] > pastCityNums[u] + 1))
////					{//如果幸福指数相同，则选择平均幸福指数多的，即经过城市越少越好
////						father[v] = u;
////						getHappy[v] = getHappy[u] + happy[v];
////						pastCityNums[v] = pastCityNums[u] + 1;
////					}
////				}
////			}
////		}
////	}
////}
////void DFS(int x)
////{
////	if (x == start)
////	{
////		cout << getName[start];
////		return;
////	}
////	DFS(father[x]);
////	cout << "->" << getName[x];
////}
////int main()
////{
////	cin >> n >> m;
////	string name, c1, c2;
////	cin >> name;
////	getId[name] = 0;
////	getName[0] = name;
////	start = 0;
////	for (int i = 1; i < n; ++i)
////	{
////		cin >> name >> num;
////		getId[name] = i;
////		getName[i] = name;
////		happy[i] = num;
////	}
////	vend = getId["ROM"];
////	fill(routes[0], routes[0] + NN * NN, INT32_MAX);
////	for (int i = 0; i < m; ++i)
////	{
////		cin >> c1 >> c2 >> num;
////		int a = getId[c1], b = getId[c2];
////		routes[a][b] = routes[b][a] = num;
////	}
////	Dijkstra(start);	
////	printf("%d %d %d %d\n", pathNums[vend], path[vend], getHappy[vend], getHappy[vend] / pastCityNums[vend]);
////	DFS(vend);
////	return 0;
////}
////
//
//
//
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//using namespace std;
//int n, m, k, ve, index = 1;
//int cost[205][205] = { 0 }, passCity[205] = { 0 }, path[205], happy[205] = { 0 }, getHappy[205] = { 0 };
//string as, bs, cs;
//vector<int>father[205];
//unordered_map<string, int>sToi;
//unordered_map<int, string>iTos;
//void Dijkstra(int sv)
//{
//	vector<bool>visit(n + 1, false);
//	fill(path, path + n + 1, INT32_MAX);
//	path[sv] = 0;
//	passCity[sv] = 1;
//	getHappy[sv] = happy[sv];
//	for (int i = 1; i <= n; ++i)
//	{
//		int u = -1, minCost = INT32_MAX;
//		for (int j = 1; j <= n; ++j)
//		{
//			if (visit[j] == false && minCost > path[j])
//			{
//				minCost = path[j];
//				u = j;
//			}
//		}
//		if (u == -1)break;
//		visit[u] = true;
//		for (int v = 1; v <= n; ++v)
//		{
//			if (visit[v] == false && cost[u][v] > 0)
//			{
//				if (path[v] > path[u] + cost[u][v])
//				{
//					path[v] = path[u] + cost[u][v];
//					getHappy[v] = getHappy[u] + happy[v];
//					passCity[v] = passCity[u];
//					father[v].clear();
//					father[v].push_back(u);
//				}
//				else if (path[v] == path[u] + cost[u][v])
//				{
//					passCity[v] += passCity[u];
//					if (getHappy[v] < getHappy[u] + happy[v])
//					{
//						getHappy[v] = getHappy[u] + happy[v];				
//						father[v].clear();
//						father[v].push_back(u);
//					}
//					else if (getHappy[v] == getHappy[u] + happy[v])
//						father[v].push_back(u);
//				}
//			}
//		}
//	}
//}
//vector<int>tempPath, resPath;
//int maxAvg = 0;
//void DFS(int index)
//{
//	tempPath.push_back(index);
//	if (index == sToi["ROM"])
//	{
//		int sumHappy = 0, avg;
//		for (auto a : tempPath)
//			sumHappy += happy[a];
//		avg = sumHappy / (tempPath.size()-1);
//		if (avg > maxAvg)
//		{
//			maxAvg = avg;
//			resPath = tempPath;
//		}
//	}
//	for (auto a : father[index])
//		DFS(a);
//	tempPath.pop_back();
//}
//int main()
//{
//	cin >> n >> m >> cs;
//	sToi[cs] = index;
//	iTos[index++] = cs;
//	ve = sToi[cs];//终点
//	for (int i = 0; i < n - 1; ++i)
//	{
//		cin >> as >> k;
//		sToi[as] = index;
//		iTos[index] = as;
//		happy[index++] = k;			
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> as >> bs >> k;
//		int a = sToi[as], b = sToi[bs];
//		cost[a][b] = cost[b][a] = k;
//	}
//	Dijkstra(sToi["ROM"]);
//	DFS(ve);
//	printf("%d %d %d %d\n", passCity[ve], path[ve], getHappy[ve], maxAvg);
//	for (int i = 0; i < resPath.size(); ++i)
//		cout << (i == 0 ? "" : "->") << iTos[resPath[i]];
//	return 0;	
//}
