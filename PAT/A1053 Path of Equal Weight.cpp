//////#include <iostream>
//////#include <vector>
//////#include <algorithm>
//////using namespace std;
//////struct Node
//////{
//////	int val;
//////	vector<int>child;
//////}node[101];
//////int N, M, S;
//////int path[101];
//////void DFS(int head, int numNode, int sum)
//////{
//////	if (sum > S)
//////		return;
//////	if (sum == S)
//////	{
//////		if (node[head].child.size() != 0)//不是叶子节点
//////			return;
//////		for (int i = 0; i < numNode; ++i)
//////			cout << node[path[i]].val << (i < numNode - 1 ? " " : "");
//////		cout << endl;
//////		return;
//////	}
//////	for (int i = 0; i < node[head].child.size(); ++i)
//////	{
//////		path[numNode] = node[head].child[i];
//////		DFS(node[head].child[i], numNode + 1, sum + node[node[head].child[i]].val);
//////	}
//////}
//////int main()
//////{
//////	cin >> N >> M >> S;
//////	for (int i = 0; i < N; ++i)
//////		cin >> node[i].val;
//////	int a, b, k;
//////	for (int i = 0; i < M; ++i)
//////	{
//////		cin >> a >> k;
//////		for (int j = 0; j < k; ++j)
//////		{
//////			cin >> b;
//////			node[a].child.push_back(b);
//////		}
//////		sort(node[a].child.begin(), node[a].child.end(),
//////			[](int a, int b) {return node[a].val > node[b].val; });
//////	}
//////	path[0] = 0;
//////	DFS(0, 1, node[0].val);
//////	return 0;
//////}
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////vector<vector<int>>nodes, res;
////vector<int>w, temp;
////int visit[105];
////int n, m, s, head = 0;
////void DFS(int v, int sum)
////{
////	sum += w[v];	
////	if (sum > s || (sum==s&&nodes[v].size() != 0))//一定要在叶子节点结束
////		return;
////	temp.push_back(w[v]);
////	if (sum == s)
////			res.push_back(temp);
////	for (int i = 0; i < nodes[v].size(); ++i)
////		DFS(nodes[v][i], sum);
////	temp.pop_back();
////}
////int main()
////{
////	cin >> n >> m >> s;
////	nodes.resize(n);
////	w.resize(n);
////	//fill(visit, visit + 105, false);
////	for (int i = 0; i < n; ++i)
////		cin >> w[i];
////	for (int i = 0; i < m; ++i)
////	{
////		int id, k, child;
////		cin >> id >> k;
////		while (k--)
////		{
////			cin >> child;
////			nodes[id].push_back(child);
////		}
////		sort(nodes[id].begin(), nodes[id].end(), [=](int a, int b) {return w[a] > w[b]; });//直接排好序
////	}
////	DFS(head, 0);
////	for (int i = 0; i < res.size(); ++i)
////	{
////		for (int j = 0; j < res[i].size(); ++j)
////			cout << (j == 0 ? "" : " ") << res[i][j];
////		cout << endl;
////	}
////	return 0;
////}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n, m, k, w, cost[105];
//vector<int>v[105], temp;
//vector<vector<int>> res;
//void DFS(int index,int sum)
//{
//	sum += cost[index];
//	if (sum > w || sum == w && v[index].size() > 0)return;//不是叶子节点返回
//	temp.push_back(index);//一定是在return的后面，不然压入后再出现了return就会导致push与pop次数不匹配
//	if (sum == w)
//		res.push_back(temp);//千万不要返回，因为temp.push了数据，此时需要对应的后面进行pop,让下一个循环sum>w的时候返回
//	for (auto a : v[index])
//		DFS(a, sum);
//	temp.pop_back();//pop为不选择的路线，所以，一定是在DFS后面
//}
//int main()
//{
//	cin >> n >> m >> w;
//	for (int i = 0; i < n; ++i)
//		cin >> cost[i];
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> k;
//		while (k--)
//		{
//			cin >> b;
//			v[a].push_back(b);
//		}
//		sort(v[a].begin(), v[a].end(), [=](int a, int b) {return cost[a] > cost[b]; });
//	}
//	DFS(0, 0);
//	for (auto a : res)
//	{
//		for (int i = 0; i < a.size(); ++i)
//			cout << (i == 0 ? "" : " ") << cost[a[i]];
//		cout << endl;
//	}
//	return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int w;
//	vector<int>child;
//}nodes[105];
//int n, m, k;
//vector<int>temp;
//void DFS(int index, int sum)
//{
//	if (sum > k)return;
//	temp.push_back(nodes[index].w);
//	if (nodes[index].child.size() == 0 && sum == k)
//	{
//		for (int i = 0; i < temp.size(); ++i)
//			cout << (i == 0 ? "" : " ") << temp[i];
//		cout << endl;
//	}
//	for (auto a : nodes[index].child)
//		DFS(a, sum + nodes[a].w);
//	temp.pop_back();
//}
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 0; i < n; ++i)
//		cin >> nodes[i].w;
//	while (m--)
//	{
//		int id, t, child;
//		cin >> id >> t;
//		while (t--)
//		{
//			cin >> child;
//			nodes[id].child.push_back(child);
//		}
//		sort(nodes[id].child.begin(), nodes[id].child.end(), [=](int a, int b) {
//			return nodes[a].w > nodes[b].w; });
//	}
//	DFS(0, nodes[0].w);
//	return 0;
//}
