////#include <iostream>
////#include <vector>
////using namespace std;
////int main()
////{
////	int n, m, k, a, b, start, graph[205][205];
////	bool visit[205];//记录每个顶点遍历一次
////	fill(graph[0], graph[0] + 25 * 205, -1);
////	cin >> n >> m;
////	while (m--)
////	{
////		cin >> a >> b;
////		graph[a][b] = graph[b][a] = 1;
////	}
////	cin >> m;
////	while (m--)
////	{
////		cin >> k;
////		bool flag = true;
////		fill(visit, visit + 205, false);
////		for (int i = 0; i < k; ++i)
////		{
////			cin >> b;
////			if (flag == false || k != n + 1)//遍历所有的顶点并回到起点，则一定走过n+1个点
////			{
////				flag = false;
////				continue;
////			}
////			if (i == 0)
////				start = b;//记录起点
////			else if (graph[a][b] != 1)//此路不通
////				flag = false;
////			else if (i == k - 1 && b != start)//最后一个点不是起点
////				flag = false;
////			else if (i != k - 1 && visit[b] != false)//除了最后一次重复遍历起点，出现了其他点重复遍历，
////				flag = false;
////			else
////				visit[b] = true;//遍历过
////			a = b;//记录前一个点
////		}
////		if (flag)
////		{
////			for (int i = 1; i <= n && flag == true; ++i)
////				if (visit[i] == false)//存在没有遍历的顶点
////					flag = false;
////			if (flag)
////				cout << "YES" << endl;
////		}
////		if (flag == false)
////			cout << "NO" << endl;
////	}
////	return 0;	
////}
//
//
//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//int main()
//{
//	int n, m, k, a, b;
//	cin >> n >> m;
//	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));	
//	while (m--)
//	{
//		cin >> a >> b;
//		v[a][b] = v[b][a] = 1;
//	}
//	cin >> k;
//	while (k--)
//	{
//		cin >> m;
//		vector<int>temp(m);
//		unordered_set<int>s;
//		for (int i = 0; i < m; ++i)
//		{
//			cin >> temp[i];
//			s.insert(temp[i]);
//		}
//		bool flag = true;
//		if (m - 1 != n || s.size() != n || temp[0] != temp.back())
//			flag = false;
//		else
//		{
//			for(int i=1;i<m;++i)
//				if (v[temp[i]][temp[i - 1]] != 1)
//				{
//					flag = false;
//					break;
//				}
//		}
//		if (flag)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}