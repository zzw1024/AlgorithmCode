////#include <iostream>
////#include <queue>
////#include <vector>
////using namespace std;
////int N, M, maxN = 1, resL = 1, root = 1, level[105] = { 0 }, manN[105] = { 0 };
////vector<int>man[105];
////void BFS()
////{
////	queue<int>q;
////	q.push(root);
////	level[root] = 1;
////	manN[level[root]]++;
////	while (!q.empty())
////	{
////		root = q.front();
////		q.pop();
////		int temp = 0;
////		for (auto v : man[root])
////		{
////			level[v] = level[root] + 1;
////			manN[level[v]]++;//记录每一层的人数
////			if (man[v].size() > 0)
////				q.push(v);
////		}
////	}	
////}
////
////void DFS(int s,int l)
////{
////	manN[l]++;//l层的人数
////	for (auto v : man[s])
////		DFS(v, l + 1);
////}
////
////int main()
////{
////	cin >> N >> M;
////	for (int i = 0; i < M; ++i)
////	{
////		int a, b, k;
////		cin >> a >> k;
////		for (int j = 0; j < k; ++j)
////		{
////			cin >> b;
////			man[a].push_back(b);
////		}
////	}
////	//BFS();
////	DFS(1, 1);
////	for (int i = 1; i <= N; ++i)
////	{
////		if (maxN < manN[i])
////		{
////			maxN = manN[i];
////			resL = i;
////		}
////	}	
////	cout << maxN << " " << resL << endl;
////	return 0;
////}
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//int n, m, maxG = 1, resL = 1;
//vector<vector<int>>v;
//vector<int>nums;
//void DFS(int x,int level)
//{
//	nums[level]++;
//	if (maxG < nums[level])
//	{
//		maxG = nums[level];
//		resL = level;
//	}
//	for (auto t : v[x])
//		DFS(t, level + 1);
//}
//void BFS(int x)
//{
//	vector<int>level(n + 1, 0), nums(n + 1, 0);
//	queue<int>q;
//	q.push(x);
//	level[x] = 1;
//	nums[1]++;
//	while (!q.empty())
//	{
//		int p = q.front();
//		q.pop();
//		for (auto t:v[p])
//		{
//			level[t] = level[p] + 1;
//			nums[level[t]]++;
//			if (nums[level[t]] > maxG)
//			{
//				maxG = nums[level[t]];
//				resL = level[t];
//			}
//			q.push(t);
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	v.resize(n + 1);
//	for (int i = 0; i < m; ++i)
//	{
//		int id, k, child;
//		cin >> id >> k;
//		while (k--)
//		{
//			cin >> child;
//			v[id].push_back(child);
//		}
//	}
//	nums.resize(n + 1);
//	DFS(01, 1);
//	//BFS(01);
//	cout << maxG << " " << resL << endl;
//	return 0;
//}
//
