//////题⽬⼤意：如果⼀个连通图的所有结点的度都是偶数，那么它就是Eulerian，如果除了两个结点的度是
//////奇数其他都是偶数，那么它就是Semi - Eulerian，否则就是Non - Eulerian～
//////分析：⽤邻接表存储图，判断每个结点的度【也就是每个结点i的v[i].size()】是多少即可得到最终结果
//////～注意：图必须是连通图，所以要⽤⼀个深搜判断⼀下连通性，从结点1开始深搜，如果最后发现统计
//////的连通结点个数cnt != n说明是不是连通图，要输出Non - Eulerian～
////#include <iostream>
////using namespace std;
////int path[505] = { 0 }, graph[505][505];
////int n, m, a, b, odd = 0, num = 0;
////bool visit[505] = { false };
////void DFS(int s)
////{
////	visit[s] = true;
////	num++;
////	for (int i = 1; i <= n; ++i)
////		if (graph[s][i] == 1 && visit[i] == false)			
////			DFS(i);
////}
////int main()
////{	
////	cin >> n >> m;	
////	while (m--)
////	{
////		cin >> a >> b;
////		path[a]++;
////		path[b]++;
////		graph[a][b] = graph[b][a] = 1;
////	}
////	for (int i = 1; i <= n; ++i)
////	{
////		if (path[i] % 2 == 1)
////			odd++;
////		cout << (i == 1 ? "" : " ") << path[i];
////	}
////	DFS(1);//判断是不是连通图
////	if (num == n && odd == 0)
////		cout << endl << "Eulerian" << endl;
////	else if (num == n && odd == 2)
////		cout << endl << "Semi-Eulerian" << endl;
////	else
////		cout << endl << "Non-Eulerian" << endl;
////	return 0;
////}
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m, nums = 0, odds = 0;
//vector<vector<int>>v;
//bool visit[505] = { false };
//void DFS(int x)
//{
//	visit[x] = true;
//	nums++;
//	for (int i = 0; i < v[x].size(); ++i)
//		if (visit[v[x][i]] == false)
//			DFS(v[x][i]);
//}
//int main()
//{
//	cin >> n >> m;
//	v.resize(n + 1);
//	vector<int>path(n + 1, 0);
//	for (int i = 0; i < m; ++i)
//	{
//		int a, b;
//		cin >> a >> b;
//		path[a]++;
//		path[b]++;
//		v[a].push_back(b);
//		v[b].push_back(a);
//	}
//	for (int i = 1; i <= n; ++i)
//	{
//		if (path[i] % 2 == 1)
//			odds++;
//		cout << (i == 1 ? "" : " ") << path[i];
//	}
//	cout << endl;
//	DFS(1);
//	if (nums != n || odds != 0 && odds != 2)
//		cout << "Non-Eulerian" << endl;
//	else if (odds == 2)
//		cout << "Semi-Eulerian" << endl;
//	else
//		cout << "Eulerian" << endl;
//	return 0;
//}