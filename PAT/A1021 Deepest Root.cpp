//////#include <iostream>
//////#include <vector>
//////#include<set>
//////using namespace std;
//////vector<vector<int>>G;
//////int N, maxH = 0;
//////bool visit[10010];
//////set<int>res;
//////vector<int>temp;
//////
//////void DFS(int node, int H)
//////{
//////	if (H > maxH)
//////	{
//////		temp.clear();
//////		temp.push_back(node);//更新新的根节点
//////		maxH = H;
//////	}
//////	else if (H == maxH)
//////		temp.push_back(node);//相同的最优解
//////	visit[node] = true;
//////	for (int i = 0; i < G[node].size(); ++i)
//////		if (visit[G[node][i]] == false)
//////			DFS(G[node][i], H + 1);
//////}
//////
//////int main()
//////{
//////	int a, b, s1 = 0, cnt = 0;
//////	cin >> N;
//////	G.resize(N+1);
//////	for (int i = 1; i < N; ++i)
//////	{
//////		cin >> a >> b;
//////		G[a].push_back(b);
//////		G[b].push_back(a);
//////	}
//////	for (int i = 1; i <= N; ++i)
//////	{
//////		if (visit[i] == false)//开始深度搜索遍历，如果是一个联通区域，则只会执行一次
//////		{
//////			DFS(i, 1);
//////			if (i == 1)
//////			{
//////				if (temp.size() != 0)
//////					s1 = temp[0];
//////				for (int j = 0; j < temp.size(); ++j)
//////					res.insert(temp[j]);
//////			}
//////			cnt++;//计算集合数
//////		}		
//////	}
//////	if (cnt != 1)
//////		printf("Error: %d components\n", cnt);
//////	else
//////	{
//////		temp.clear();
//////		maxH = 0;
//////		fill(visit, visit + N + 1, false);
//////		DFS(s1, 1);
//////		for (int j = 0; j < temp.size(); ++j)
//////			res.insert(temp[j]);
//////		for (auto r : res)
//////			cout << r << endl;
//////	}
//////	return 0;
//////}
////
////
////#include <iostream>
////#include <algorithm>
////#include <vector>
////#include <set>
////using namespace std;
////vector<int>res, father;
////vector<vector<int>>graph;
////vector<bool>visit;
////vector<int>maxH, h;//每个节点的最大深度和当前深度
////int n;
////void DFS(int v,int start)
////{
////	visit[v] = true;
////	for (int i = 0; i < graph[v].size(); ++i)
////	{
////		if (visit[graph[v][i]] == false)
////		{
////			h[graph[v][i]] = h[v] + 1;
////			maxH[start] = maxH[start] > h[graph[v][i]] ? maxH[start] : h[graph[v][i]];
////			//记录每个点的最大深度
////			DFS(graph[v][i], start);
////		}
////	}	
////}
////int findFather(int x)
////{
////	if (x == father[x])
////		return x;
////	int temp = findFather(father[x]);
////	father[x] = temp;
////	return temp;
////}
////void Union(int a, int b)
////{
////	int aF = findFather(a), bF = findFather(b);
////	if (aF != bF)
////		father[aF] = bF;
////}
////int main()
////{
////	cin >> n;
////	father.resize(n + 1);
////	graph.resize(n + 1);
////	visit.resize(n + 1);
////	maxH.resize(n + 1);
////	h.resize(n + 1);
////	for (int i = 0; i <= n; ++i)
////	{
////		father[i] = i;
////		visit[i] = false;
////	}
////	for (int i = 0; i < n - 1; ++i)
////	{
////		int a, b;
////		cin >> a >> b;
////		graph[a].push_back(b);
////		graph[b].push_back(a);
////		Union(a, b);
////	}
////	int cnt = 0;
////	for (int i = 1; i <= n; ++i)
////		if (i == findFather(i))
////			cnt++;
////	if (cnt > 1)
////		cout << "Error: " << cnt << " components" << endl;
////	else
////	{
////		for (int i = 1; i <= n; ++i)
////		{
////			for (int j = 0; j <= n; ++j)
////			{
////				visit[j] = false;
////				h[j] = 0;
////			}
////			DFS(i, i);
////		}
////		int maxDeep = 0;
////		for(int i=1;i<=n;++i)
////		{
////			if (maxH[i] > maxDeep)
////			{
////				maxDeep = maxH[i];
////				res.clear();
////				res.push_back(i);
////			}
////			else if (maxH[i] == maxDeep)
////				res.push_back(i);			
////		}
////		for (auto p : res)
////			cout << p << endl;		
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <set>
//#include <queue>
//using namespace std;
//int n, maxDeep = 0;
//vector<vector<int>>v;
//vector<bool>visit;
//set<int>res;
//void DFS(int u)
//{
//	visit[u] = true;
//	for (int i = 0; i < v[u].size(); ++i)
//		if (visit[v[u][i]] == false)
//			DFS(v[u][i]);
//}
//int calComponents()
//{
//	int nums = 0;	
//	for (int i = 0; i <= n; ++i)
//		visit[i] = false;
//	for (int i = 1; i <= n; ++i)
//	{
//		if (visit[i] == false)
//		{
//			DFS(i);
//			++nums;
//		}
//	}
//	return nums;
//}
//void DFS(int s,int u, int deep)
//{
//	visit[u] = true;
//	if (deep > maxDeep)
//	{
//		maxDeep = deep;
//		res.clear();
//		res.insert(s);
//	}
//	else if (deep == maxDeep)
//		res.insert(s);		
//	for (int i = 0; i < v[u].size(); ++i)
//		if (visit[v[u][i]] == false)
//			DFS(s, v[u][i], deep + 1);
//}
//void BFS(int s)
//{
//	vector<int>deep(n + 1, 1);
//	queue<int>q;
//	q.push(s);
//	while (!q.empty())
//	{
//		int p = q.front();
//		q.pop();
//		visit[p] = true;
//		for (auto a : v[p])
//		{
//			if (visit[a] == false)
//			{
//				q.push(a);
//				deep[a] = deep[p] + 1;
//				if (deep[a] > maxDeep)
//				{
//					maxDeep = deep[a];
//					res.clear();
//					res.insert(s);
//				}
//				else if (deep[a] == maxDeep)
//					res.insert(s);
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	v.resize(n + 1);
//	for (int i = 1; i < n; ++i)
//	{
//		int a, b;
//		cin >> a >> b;
//		v[a].push_back(b);
//		v[b].push_back(a);
//	}
//	visit.resize(n + 1);
//	int nums = calComponents();
//	if (nums > 1)
//	{
//		cout << "Error: " << nums << " components" << endl;
//		return 0;
//	}
//	visit.resize(n + 1);
//	for (int i = 1; i <= n; ++i)
//	{		
//		for (int i = 0; i <= n; ++i)
//			visit[i] = false;
//		//DFS(i, i, 1);
//		BFS(i);
//	}
//	for (auto ptr = res.begin(); ptr != res.end(); ++ptr)
//		cout << *ptr << endl;
//	return 0;
//}
//
//
//
