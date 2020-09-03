////#include <iostream>
////#include <vector>
////#include <queue>
////#include <cmath>
////using namespace std;
////int N, root, maxL = 0, resN = 1, level[100100] = { 0 };
////double p, r;
////vector<int>G[100100];;
////void BFS(int root)
////{
////	queue<int>q;
////	q.push(root);
////	while (!q.empty())
////	{
////		root = q.front();
////		q.pop();
////		for (auto a : G[root])
////		{
////			level[a] = level[root] + 1;
////			if (maxL < level[a])
////			{
////				maxL = level[a];
////				resN = 1;
////			}
////			else if (maxL == level[a])
////				resN++;
////			if (G[a].size() > 0)
////				q.push(a);
////		}
////	}
////}
////void DFS(int root)
////{
////	if (G[root].size() == 0)
////		return;
////	for (auto a : G[root])
////	{
////		level[a] = level[root] + 1;
////		if (maxL < level[a])
////		{
////			maxL = level[a];
////			resN = 1;
////		}
////		else if (maxL == level[a])
////			resN++;
////		DFS(a);
////	}
////}
////int main()
////{
////	cin >> N >> p >> r;
////	int a;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> a;
////		if (a == -1)
////			root = i;
////		else
////			G[a].push_back(i);		
////	}
////	//BFS(root);
////	DFS(root);
////	printf("%.2f %d\n", p*pow(1.0 + r / 100.0, maxL), resN);
////	return 0;
////}
////
////
//
//
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cmath>
//using namespace std;
//vector<vector<int>>v;
//int n, head, num, maxLevel = 0, resNum = 0;
//double price, rate;
//void DFS(int x, int level)
//{
//	if (maxLevel < level)
//	{
//		maxLevel = level;
//		resNum = 1;
//	}
//	else if (maxLevel == level)
//		resNum++;
//	for (int i = 0; i < v[x].size(); ++i)
//		DFS(v[x][i], level + 1);
//}
//void BFS(int x)
//{
//	vector<int>level(n, 0);
//	queue<int>q;
//	q.push(x);
//	while (!q.empty())
//	{
//		int p = q.front();
//		q.pop();
//		if (level[p] > maxLevel)
//		{
//			maxLevel = level[p];
//			resNum = 1;
//		}
//		else if (level[p] == maxLevel)
//			resNum++;
//		for (auto t : v[p])
//		{
//			level[t] = level[p] + 1;			
//			q.push(t);
//		}
//	}
//}
//int main()
//{
//	cin >> n >> price >> rate;
//	v.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> num;
//		if (num == -1)
//			head = i;
//		else
//			v[num].push_back(i);
//	}
//	//DFS(head, 0);
//	BFS(head);
//	printf("%.2f %d\n", price*pow((1.0 + rate / 100.0), maxLevel), resNum);
//	return 0;
//}