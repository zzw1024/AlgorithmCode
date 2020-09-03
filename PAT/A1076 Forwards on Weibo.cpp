//////#include <iostream>
//////#include <vector>
//////#include <queue>
//////using namespace std;
//////bool people[1010][1010];
//////int N, L, K;
//////int BFS(int v)//广度优先搜索
//////{
//////	int num = 0;
//////	vector<int>level(N + 1, 0);
//////	vector<bool>visit(N + 1, false);
//////	queue<int>q;
//////	q.push(v);
//////	visit[v] = true;
//////	while (!q.empty())
//////	{
//////		v = q.front();
//////		q.pop();
//////		for (int i = 1; i <= N; ++i)
//////		{
//////			if (visit[i] == false && people[v][i] == true && level[v] < L)
//////			{
//////				num++;
//////				visit[i] = true;
//////				level[i] = level[v] + 1;
//////				q.push(i);
//////			}
//////		}
//////	}
//////	return num;
//////}
//////
//////int main()
//////{
//////	cin >> N >> L;
//////	fill(people[0], people[0] + 1010 * 1010, false);
//////	for (int i = 1; i <= N; ++i)
//////	{
//////		int a, m;
//////		cin >> m;
//////		for (int j = 1; j <= m; ++j)
//////		{
//////			cin >> a;
//////			people[a][i] = true;//请记住，存的是a的粉丝
//////		}
//////	}
//////	cin >> K;
//////	vector<int>test(K);
//////	for (int i = 0; i < K; ++i)
//////	{
//////		int a;
//////		cin >> a;
//////		cout << BFS(a) << endl;//使用广度优先搜索，即使用层序遍历
//////	}
//////	return 0;
//////}
//////
////////DFS
//////#include <iostream>
//////#include <vector>
//////using namespace std;
//////int N, L, K;
//////vector<int> graph[1005];//图
//////bool visit[1005];//visit表示是否已被访问，person用于最后统计
//////int layer[1005];//储存每个结点被遍历到时的层数
//////void DFS(int v, int level) 
//////{//深度优先遍历
//////	visit[v] = true;//当前结点置为已访问
//////	layer[v] = level;//更新被遍历时所处层数
//////	if (level != L)//还没有遍历到层数上限
//////		for (int i : graph[v])//遍历当前结点能够到达的结点
//////			if (!visit[i] || layer[i] > level + 1)//这个节点以前从未访问过或者这个节点当前被访问时的层数<layer数组中对应的层数
//////				DFS(i, level + 1);//继续深度优先遍历
//////}
//////int main()
//////{
//////	scanf("%d%d", &N, &L);
//////	for (int i = 1; i <= N; ++i) 
//////	{
//////		int num, a;
//////		scanf("%d", &num);
//////		while (num--) 
//////		{
//////			scanf("%d", &a);
//////			graph[a].push_back(i);
//////		}
//////	}
//////	scanf("%d", &K);
//////	while (K--) 
//////	{
//////		fill(visit + 1, visit + N + 1, false);
//////		fill(layer + 1, layer + N + 1, -1);
//////		int a, num = 0;
//////		scanf("%d", &a);
//////		DFS(a, 0);
//////		for (int i = 1; i < N + 1; ++i)//遍历layer数组，元素>0的即为符合条件的人，进行递增
//////			num += layer[i] > 0 ? 1 : 0;
//////		printf("%d\n", num);//输出
//////	}
//////	return 0;
//////}
////
////#include <iostream>
////#include <vector>
////#include <queue>
////using namespace std;
////vector<vector<int>>v;
////int visit[1010];
////int n, m, l, k, a, res;
////void BFS(int u)
////{
////	vector<int>level(n + 1, 0);
////	queue<int>q;
////	q.push(u);
////	visit[u] = true;
////	while (!q.empty())
////	{
////		int p = q.front();
////		q.pop();
////		for (auto t : v[p])
////		{
////			if (visit[t] == false && level[p] < l)
////			{
////				res++;
////				q.push(t);
////				visit[t] = true;
////				level[t] = level[p] + 1;
////			}
////		}
////	}
////}
////int main()
////{
////	cin >> n >> l;
////	v.resize(n + 1);
////	for (int i = 1; i <= n; ++i)
////	{
////		cin >> m;
////		while (m--)
////		{
////			cin >> a;//i的关注者
////			v[a].push_back(i);//a关注了i
////		}
////	}
////	cin >> k;
////	while (k--)
////	{
////		cin >> a;
////		res = 0;
////		fill(visit, visit + 1010, false);
////		//DFS(a, 1);
////		BFS(a);
////		cout << res << endl;
////	}
////	return 0;
////}
//
////两个难点：
////如果使用visit，那么会使得提前剪枝
////如果仅仅依靠L层数来剪枝，那么会在相互关注的两个人中消耗大量的时间
////考试的时候可以使用visit[] <=5来避开死循环中的时间消耗，但这不是个明智之举
////解决方法，使用BFS，虽然没有避开死循环，但由于不是递归，所以不会超时
////使用DFS,使用一个层数来记录每个节点的最小层数，若层数太深，则无需遍历
//
//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//vector<int>v[1010];
//bool visit[1010];
//int layer[1010];
//int n, m, k, x;
//unordered_set<int>res;//使用set来去重
//void DFS(int index, int level)
//{
//	if (level > m)return;
//	visit[index] = true;
//	layer[index] = level;
//	res.insert(index);
//	for (auto a : v[index])
//		if (visit[a] == false || layer[a] > level + 1)//更上一层那就遍历
//			DFS(a, level + 1);
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> k;
//		while (k--)
//		{
//			cin >> x;
//			v[x].push_back(i);
//		}
//	}
//	cin >> k;
//	while (k--)
//	{
//		cin >> x;
//		fill(visit, visit + n + 1, 0);
//		fill(layer, layer + n + 1, 0);
//		res.clear();
//		DFS(x, 0);
//		cout << res.size()-1 << endl;//不能算博主自己
//	}
//	return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <unordered_set>
//#include <algorithm>
//using namespace std;
//int n, m, k, b;
//int level[1010];
//bool visit[1010];
//vector<int>v[1010];
//unordered_set<int>res;//用来去重
//void DFS(int index, int L)
//{
//	if (L > m)return;
//	res.insert(index);
//	visit[index] = true;
//	level[index] = L;
//	for (auto a : v[index])
//		if (visit[a] == false || level[a] > L + 1)//节点没有访问过，或者节点在更上一层
//			DFS(a, L + 1);
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> k;
//		while (k--)
//		{
//			cin >> b;
//			v[b].push_back(i);
//		}
//	}
//	cin >> k;
//	while (k--)
//	{
//		cin >> b;
//		res.clear();
//		fill(level, level + n + 1, n + 1);//数据初始化，注意，这两个变量如果使用vector创建的话，会导致最后一个测试集超时
//		fill(visit, visit + n + 1, false);
//		DFS(b, 0);
//		cout << res.size() - 1 << endl;
//	}
//	return 0;
//}




//
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//int n, m, query, res;
//vector<int>v[1010];
//void BFS(int index)
//{
//	vector<bool>visit(n + 1, false);
//	queue<pair<int, int>>q;
//	q.push(make_pair(0, index));
//	while (!q.empty())
//	{
//		pair<int, int>p = q.front();
//		q.pop();
//		if (p.first > m || visit[p.second] == true)continue;
//		if (p.first <= m && visit[p.second] == false)++res;
//		visit[p.second] = true;
//		for (auto a : v[p.second])
//			q.push(make_pair(p.first + 1, a));
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; ++i)
//	{
//		int k, b;
//		cin >> k;
//		while (k--)
//		{
//			cin >> b;
//			v[b].push_back(i);
//		}
//	}
//	cin >> query;
//	while (query--)
//	{
//		int b;
//		cin >> b;
//		res = 0;
//		BFS(b);
//		cout << res - 1 << endl;
//	}
//	return 0;
//}