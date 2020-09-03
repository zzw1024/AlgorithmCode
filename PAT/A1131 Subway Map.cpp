//////#include <iostream>
//////#include <vector>
//////#include <unordered_map>
//////using namespace std;
//////vector<int> route[10005];
//////int visit[10005], minCnt, minTra, n, m, k, start, end1;
//////unordered_map<int, int>line;
//////vector<int>path, tempPath;
//////int transferCnt(vector<int>a)
//////{
//////	int cnt = -1, preLine = 0;
//////	for (int i = 1; i < a.size(); ++i)
//////	{
//////		if (line[a[i - 1] * 10000 + a[i]] != preLine)
//////		{
//////			cnt++;//换乘了
//////			preLine = line[a[i - 1] * 10000 + a[i]];
//////		}
//////	}
//////	return cnt;
//////}
//////void DFS(int node, int cnt)
//////{
//////	if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTra)))
//////	{
//////		minCnt = cnt;
//////		minTra = transferCnt(tempPath);
//////		path = tempPath;
//////	}
//////	if (node == end1)return;
//////	for (int i = 0; i < route[node].size(); ++i)
//////	{
//////		if (visit[route[node][i]] == 0)//未遍历过
//////		{
//////			visit[route[node][i]] = 1;
//////			tempPath.push_back(route[node][i]);//保存可行路径
//////			DFS(route[node][i], cnt + 1);//经过一站
//////			visit[route[node][i]] = 0;
//////			tempPath.pop_back();//使用回溯法				
//////		}
//////	}
//////}
//////int main()
//////{
//////	cin >> n;
//////	for (int i = 1; i <= n; ++i)
//////	{
//////		cin >> m >> start;
//////		for (int j = 1; j < m; ++j)
//////		{
//////			cin >> end1;
//////			route[start].push_back(end1);
//////			route[end1].push_back(start);
//////			line[start * 10000 + end1] = line[end1 * 10000 + start] = i;//用pot1*10000+pot来表示这两个站是可行的
//////			start = end1;
//////		}
//////	}
//////	cin >> k;
//////	while (k--)
//////	{
//////		cin >> start >> end1;
//////		minCnt = minTra = INT32_MAX-1;
//////		tempPath.clear();
//////		tempPath.push_back(start);
//////		visit[start] = 1;
//////		DFS(start, 0);
//////		visit[start] = 0;
//////		cout << minCnt << endl;
//////		int preLine = 0, preTra = start;
//////		for (int i = 1; i < path.size(); ++i)
//////		{
//////			if (line[path[i - 1] * 10000 + path[i]] != preLine)//换乘了
//////			{
//////				if (preLine != 0)
//////					printf("Take Line#%d from %04d to %04d.\n", preLine, preTra, path[i - 1]);
//////				preLine = line[path[i - 1] * 10000 + path[i]];
//////				preTra = path[i - 1];
//////			}
//////		}
//////		printf("Take Line#%d from %04d to %04d.\n", preLine, preTra, end1);
//////	}
//////	return 0;
//////}
////
////
////#include <iostream>
////#include <vector>
////#include <unordered_map>
////using namespace std;
////int n, m, k, vs, ve,minStop,minTra;
////vector<int>routes[10005], tempPath, path;
////bool visit[10005] = { false };
////unordered_map<int, int>lines;
////int transferCnt(vector<int>temp)
////{
////	int sum = -1, preLine = 0;
////	for (int i=1;i<temp.size();++i)
////		if (lines[temp[i - 1] * 10000 + temp[i]] != preLine)
////		{
////			sum++;//因为没有0号线，故sum初始化为-1
////			preLine = lines[temp[i - 1] * 10000 + temp[i]];
////		}
////	return sum;
////}
////void DFS(int x, int stops)
////{
////	int tras = transferCnt(tempPath);
////	if (x == ve && (stops < minStop || (stops == minStop && tras < minTra)))
////	{
////		path = tempPath;
////		minStop = stops;
////		minTra = tras;
////	}
////	if (x == ve)return;
////	for (int i = 0; i < routes[x].size(); ++i)
////	{
////		if (visit[routes[x][i]] == false)
////		{
////			visit[routes[x][i]] = true;
////			tempPath.push_back(routes[x][i]);
////			DFS(routes[x][i], stops + 1);
////			visit[routes[x][i]] = false;
////			tempPath.pop_back();
////		}
////	}
////}
////int main()
////{
////	cin >> n;
////	for (int i = 1; i <= n; ++i)
////	{
////		cin >> m >> vs;
////		for (int j = 1; j < m; ++j)
////		{
////			cin >> ve;
////			routes[vs].push_back(ve);
////			routes[ve].push_back(vs);
////			lines[vs * 10000 + ve] = lines[ve * 10000 + vs] = i;
////			vs = ve;
////		}
////	}
////	cin >> k;
////	while (k--)
////	{
////		cin >> vs >> ve;
////		minStop = minTra = INT32_MAX;
////		fill(visit, visit + 10005, false);
////		tempPath.clear();
////		tempPath.push_back(vs);
////		visit[vs] = true;
////		DFS(vs, 0);
////		cout << minStop << endl;
////		int preLine = 0, preTra = vs;
////		for (int i = 1; i < path.size(); ++i)
////		{
////			if (lines[path[i - 1] * 10000 + path[i]] != preLine)
////			{
////				if (preLine != 0)
////					printf("Take Line#%d from %04d to %04d.\n", preLine, preTra, path[i - 1]);
////				preLine = lines[path[i - 1] * 10000 + path[i]];
////				preTra = path[i - 1];
////			}				
////		}
////		printf("Take Line#%d from %04d to %04d.\n", preLine, preTra, ve);
////	}
////	return 0;
////}
////
////
//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//int n, m, sv, ev, minStop, minTra;
//vector<int>v[10010], res, tempPath;//用邻接矩阵会导致遍历的时间复杂度太大
//unordered_map<int, int>map;
//bool visit[10010];
//int calTransfer()//计算换乘次数
//{
//	int cnt = 0, pre = -1;
//	for (int i = 1; i < tempPath.size(); ++i)
//	{
//		if (map[tempPath[i - 1] * 10000 + tempPath[i]] != pre)
//		{
//			++cnt;
//			pre = map[tempPath[i - 1] * 10000 + tempPath[i]];
//		}
//	}
//	return cnt;
//}
//void DFS(int index, int stops)
//{
//	int tras = calTransfer();;
//	if (index == ev && (minStop > stops || (stops == minStop && minTra > tras)))
//	{
//		res = tempPath;
//		minStop = stops;
//		minTra = tras;
//	}
//	if (index == ev)return;
//	for (auto a : v[index])
//	{
//		if (visit[a] == false)
//		{
//			visit[a] = true;
//			tempPath.push_back(a);
//			DFS(a, stops + 1);
//			tempPath.pop_back();
//			visit[a] = false;
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> m >> sv;
//		for (int j = 1; j < m; ++j)
//		{
//			cin >> ev;
//			v[sv].push_back(ev);
//			v[ev].push_back(sv);
//			map[sv * 10000 + ev] = map[ev * 10000 + sv] = i;//用矩阵存储两个点是不是同线，空间复杂度太大
//			sv = ev;
//		}
//	}
//	cin >> m;
//	while (m--)
//	{
//		cin >> sv >> ev;
//		minStop = minTra = INT32_MAX;
//		fill(visit, visit + 10010, false);
//		res.clear();
//		tempPath.clear();
//		tempPath.push_back(sv);
//		visit[sv] = true;
//		DFS(sv, 0);
//			   
//		cout << minStop << endl;
//		int preLine = -1, preTra = sv;
//		for (int i = 1; i<res.size();++i)
//		{
//			if (map[res[i - 1] * 10000 + res[i]] != preLine)
//			{
//				if (preLine > 0)
//					printf("Take Line#%d from %04d to %04d.\n", preLine, preTra, res[i - 1]);
//				preLine = map[res[i - 1] * 10000 + res[i]];
//				preTra = res[i - 1];
//			}
//		}
//		printf("Take Line#%d from %04d to %04d.\n", preLine, preTra, ev);
//	}
//	return 0;
//}
//
//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//#define inf 10010
//int n, m, k, a, b;
//int v[inf][inf] = { 0 }, path[inf];
//bool visit[inf];
//vector<vector<int>>father;
//unordered_map<int, int>map;
//void Dijstra(int x)
//{
//	fill(visit, visit + inf, false);
//	fill(path, path + inf, INT32_MAX);
//	father.clear();
//	father.resize(inf);
//	path[x] = 0;
//	for (int i = 0; i < inf; ++i)
//	{
//		int index = -1, minDis = INT32_MAX;
//		for (int j = 0; j < inf; ++j)
//		{
//			if (visit[j] == false && minDis > path[j])
//			{
//				minDis = path[j];
//				index = j;
//			}
//		}
//		if (index == -1)break;
//		visit[index] = true;
//		for (int j = 0; j < inf; ++j)
//		{
//			if (visit[j] == false && v[index][j] == 1)
//			{
//				if (j == 6666)
//					int nn = 1;
//				if (path[j] > path[index] + v[index][j])
//				{
//					path[j] = path[index] + v[index][j];
//					father[j].clear();
//					father[j].push_back(index);
//				}
//				else if (path[j] == path[index] + v[index][j])
//					father[j].push_back(index);
//			}
//		}
//	}
//}
//vector<int>temp, res;
//int minTran;
//void DFS(int index, const int start)
//{
//	temp.push_back(index);
//	if (index == start)
//	{
//		int cnt = 0, preTran = -1;
//		for (int i = temp.size() - 1; i > 0; --i)
//		{
//			if (preTran != map[temp[i] * 10000 + temp[i - 1]])
//			{
//				++cnt;
//				preTran = map[temp[i] * 10000 + temp[i - 1]];
//			}
//		}
//		if (minTran > cnt)
//		{
//			minTran = cnt;
//			res = temp;
//		}
//	}
//	for (auto a : father[index])
//		DFS(a, start);
//	temp.pop_back();
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> k >> a;
//		while (--k)
//		{
//			cin >> b;
//			map[a * 10000 + b] = map[b * 10000 + a] = i;
//			v[a][b] = v[b][a] = 1;
//			a = b;
//		}
//	}
//	cin >> m;
//	while (m--)
//	{
//		cin >> a >> b;
//		Dijstra(a);
//		temp.clear();
//		res.clear();
//		minTran = INT32_MAX;
//		DFS(b, a);
//		cout << res.size() -1<< endl;
//		int preSta = a, preTran = -1;
//		for (int i = res.size() - 1; i > 0; --i)
//		{
//			if (preTran != map[res[i] * 10000 + res[i - 1]])
//			{
//				if (preTran != -1)
//					printf("Take Line#%d from %04d to %04d.\n", preTran, preSta, res[i]);
//				preSta = res[i];
//				preTran = map[res[i] * 10000 + res[i - 1]];
//			}			
//		}
//		printf("Take Line#%d from %04d to %04d.\n", preTran, preSta, b);
//	}
//	return 0;
//}