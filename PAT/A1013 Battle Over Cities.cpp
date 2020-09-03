//////#include <iostream>
//////#include <cstdio>
//////#include <algorithm>
//////using namespace std;
//////int v[1010][1010];
//////bool visit[1010];
//////int n;
//////void dfs(int node) {
//////	visit[node] = true;
//////	for (int i = 1; i <= n; i++) {
//////		if (visit[i] == false && v[node][i] == 1)
//////			dfs(i);
//////	}
//////}
//////int main() {
//////	int m, k, a, b;
//////	scanf("%d%d%d", &n, &m, &k);
//////	for (int i = 0; i < m; i++) {
//////		scanf("%d%d", &a, &b);
//////		v[a][b] = v[b][a] = 1;
//////	}
//////	for (int i = 0; i < k; i++) {
//////		fill(visit, visit + 1010, false);
//////		scanf("%d", &a);
//////		int cnt = 0;
//////		visit[a] = true;
//////		for (int j = 1; j <= n; j++) {
//////			if (visit[j] == false) {
//////				dfs(j);
//////				cnt++;
//////			}
//////		}
//////		if(n>1)
//////			printf("%d\n", cnt - 1);
//////		else
//////			printf("%d\n", cnt);
//////	}
//////	return 0;
//////}
////
//////有一个做法就是使用查并集，即先找到图中有几个连通量，然后需要添加 路径数就是连通量-1
////#include <iostream>
////#include <vector>
////using namespace std;
////#define NN 1005
////int n, m, k, a, b, city[NN][NN] = { 0 };
////bool visit[NN] = { false };
////void dfs(int v)
////{
////	visit[v] = true;
////	for (int i = 1; i <= n; ++i)
////		if (visit[i] == false && city[v][i] == 1)
////			dfs(i);
////}
////int main()
////{
////	cin >> n >> m >> k;
////	for (int i = 0; i < m; ++i)
////	{
////		cin >> a >> b;
////		city[a][b] = city[b][a] = 1;
////	}
////	for (int i = 0; i < k; ++i)
////	{
////		fill(visit, visit + n + 1, false);
////		cin >> a;
////		int cnt = 0;
////		visit[a] = true;
////		for (int j = 1; j <= n; ++j)
////		{
////			if (visit[j] == false)
////			{
////				dfs(j);
////				cnt++;
////			}
////		}
////		cout << cnt - 1 << endl;
////	}
////	return 0;
////}
//
//
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int>father;
//int findFather(int v)
//{
//	if (father[v] == v)
//		return v;
//	int temp = findFather(father[v]);
//	father[v] = temp;
//	return temp;
//}
//void Union(int a, int b)
//{
//	int va = findFather(a), vb = findFather(b);
//	if (va != vb)
//		father[va] = vb;
//}
//int main()
//{
//	int n, m, k;
//	cin >> n >> m >> k;
//	father.resize(n + 1);
//	vector<pair<int, int>>path;	
//	for (int i = 0; i < m; ++i)
//	{
//		int a, b;
//		cin >> a >> b;
//		path.push_back(make_pair(a, b));
//	}
//	while (k--)
//	{
//		cin >> m;
//		int nums = 0;
//		for (int i = 0; i <= n; ++i)father[i] = i;
//		for (auto a : path)
//			if (a.first != m && a.second != m)
//				Union(a.first, a.second);
//		for (int i = 1; i <= n; ++i)
//			if (findFather(i) == i)
//				++nums;
//		cout << nums - 2 << endl;//将删除的城市也删除
//	}
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m, k, res;
//int v[1005][1005] = { 0 };
//bool visit[1005] = { false };
//void DFS(int index,const int b)
//{
//	visit[index] = true;
//	for (int i = 1; i <= n; ++i)
//		if (visit[i] == false && i != b && v[index][i] == 1)
//			DFS(i, b);
//}
//int main()
//{
//	cin >> n >> m >> k;
//	while(m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		v[a][b] = v[b][a] = 1;
//	}
//	while (k--)
//	{
//		int b;
//		cin >> b;
//		res = 0;
//		fill(visit, visit + n + 1, false);
//		for (int i = 1; i <= n; ++i)
//		{
//			if (visit[i] == false && i != b)
//			{
//				++res;
//				DFS(i, b);
//			}
//		}
//		cout << res - 1 << endl;
//	}
//	return 0;
//}



