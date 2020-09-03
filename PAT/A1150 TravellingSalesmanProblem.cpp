//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m, k, x;
//int dis[205][205] = { 0 };
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < m; ++i)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		dis[a][b] = dis[b][a] = c;
//	}
//	cin >> k;
//	int minDis = INT32_MAX, minIdex = 0;
//	for (int t = 1; t <= k; ++t)
//	{
//		int calDis = 0;
//		bool isCycle = true;
//		vector<bool>visit(n + 1, true);
//		cin >> x;
//		vector<int>path(x);
//		for (int i = 0; i < x; ++i)
//		{
//			cin >> path[i];
//			visit[path[i]] = false;
//		}
//		for (int i = 1; i < x; ++i)
//		{
//			if (dis[path[i - 1]][path[i]] > 0)
//				calDis += dis[path[i - 1]][path[i]];
//			else//此路不通
//			{
//				isCycle = false;
//				calDis = -1;//没有结果。输出为NA
//				break;
//			}
//		}
//		if (path[0] != path[x - 1])isCycle = false;//不是回路
//		for (int i = 1; i <= n && isCycle; ++i)
//			if (visit[i] == true)
//				isCycle = false;
//		if(calDis<0)
//			printf("Path %d: NA (Not a TS cycle)\n", t);
//		else if (!isCycle)
//			printf("Path %d: %d (Not a TS cycle)\n", t, calDis);
//		else if(x==n+1)
//			printf("Path %d: %d (TS simple cycle)\n", t, calDis);
//		else 
//			printf("Path %d: %d (TS cycle)\n", t, calDis);
//		if (isCycle && minDis > calDis)
//		{
//			minDis = calDis;
//			minIdex = t;
//		}
//	}
//	printf("Shortest Dist(%d) = %d", minIdex, minDis);
//	return 0;
//}#include <iostream>
//#include <vector>
//using namespace std;
//int n, m, k, x;
//int dis[205][205] = { 0 };
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < m; ++i)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		dis[a][b] = dis[b][a] = c;
//	}
//	cin >> k;
//	int minDis = INT32_MAX, minIdex = 0;
//	for (int t = 1; t <= k; ++t)
//	{
//		int calDis = 0;
//		bool isCycle = true;
//		vector<bool>visit(n + 1, true);
//		cin >> x;
//		vector<int>path(x);
//		for (int i = 0; i < x; ++i)
//		{
//			cin >> path[i];
//			visit[path[i]] = false;
//		}
//		for (int i = 1; i < x; ++i)
//		{
//			if (dis[path[i - 1]][path[i]] > 0)
//				calDis += dis[path[i - 1]][path[i]];
//			else//此路不通
//			{
//				isCycle = false;
//				calDis = -1;//没有结果。输出为NA
//				break;
//			}
//		}
//		if (path[0] != path[x - 1])isCycle = false;//不是回路
//		for (int i = 1; i <= n && isCycle; ++i)
//			if (visit[i] == true)
//				isCycle = false;
//		if(calDis<0)
//			printf("Path %d: NA (Not a TS cycle)\n", t);
//		else if (!isCycle)
//			printf("Path %d: %d (Not a TS cycle)\n", t, calDis);
//		else if(x==n+1)
//			printf("Path %d: %d (TS simple cycle)\n", t, calDis);
//		else 
//			printf("Path %d: %d (TS cycle)\n", t, calDis);
//		if (isCycle && minDis > calDis)
//		{
//			minDis = calDis;
//			minIdex = t;
//		}
//	}
//	printf("Shortest Dist(%d) = %d", minIdex, minDis);
//	return 0;
//}