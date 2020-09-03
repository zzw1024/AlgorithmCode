////#include <iostream>
////#include <vector>
////using namespace std;
////#define inf 999999999
////int N, M, start, des, shortest[2];//shortest存储最短路径的长度(下标为0)和最快路径的时间(下标为1)
////int graph[505][505][2];//图的邻接矩阵
////int dis[505], past[505], num[505];////各点最短距离、父节点、num求最短路径时存储时间，求最快路径时存储当前路径上结点个数
////bool visit[505] = { false };
////vector<int>path[2];//下标为0存储最短路径，下标为1存储最快路径
////void Dijkstra(int k)//k==0求最短路径，k==1求最快路径
////{
////	while (visit[des] == false)
////	{
////		int v = -1, min = inf;
////		for (int i = 0; i < N; ++i)
////		{
////			if (visit[i] == false && min > dis[i])
////			{
////				v = i;
////				min = dis[i];
////			}			
////		}
////		if (v == -1)break;
////		visit[v] = true;
////		for (int i = 0; i < N; ++i)
////		{
////			if (visit[i] == false && graph[v][i][k] != 0 && dis[i] > dis[v] + graph[v][i][k])
////			{
////				dis[i] = dis[v] + graph[v][i][k];//更新距离
////				past[i] = v;//更新父节点
////				if (k == 0)//是求最短路径
////					num[i] = num[v] + graph[v][i][1];//叠加时间
////				else//求最快路径
////					num[i] = num[v] + 1;//叠加经过的路径节点
////			}
////			else if (graph[v][i][k] != 0 && dis[i] == dis[v] + graph[v][i][k])//路径距离相等
////			{
////				if (k == 0 && num[i] > num[v] + graph[v][i][1])//时间更短
////				{
////					past[i] = v;//要经过这个点
////					num[i] = num[v] + graph[v][i][1];//叠加经过的时间
////				}
////				else if (k == 1 && num[i] > num[v] + 1)//经过更少的节点
////				{
////					past[i] = v;//则经过该点
////					num[i] = num[v] + 1;//叠加经过的节点
////				}
////			}
////		}
////	}
////	shortest[k] = dis[des];//存储答案信息
////}
////void DFS(int v, int k)//使用DFS寻找出答案
////{
////	if (v == start)//到起点
////	{
////		path[k].push_back(v);
////		return;
////	}
////	DFS(past[v], k);//从后向前寻根，故DFS后进行记录路径，则路径则是顺序的
////	path[k].push_back(v);
////}
////bool cmp()
////{
////	if (path[0].size() != path[1].size())
////		return false;
////	for (int i = 0; i < path[0].size(); ++i)
////		if (path[0][i] != path[1][i])
////			return false;
////	return true;
////}
////void printPath(int k)//路径打印
////{
////	for (int i = 0; i < path[k].size(); ++i)
////		cout << path[k][i] << (i == path[k].size() - 1 ? "" : " -> ");
////	cout << endl;
////}
////int main()
////{
////	cin >> N >> M;
////	while (M--)
////	{
////		int a, b, c, d, e;
////		cin >> a >> b >> c >> d >> e;
////		graph[a][b][0] = d;
////		graph[a][b][1] = e;
////		if (c == 0)//有双向道
////		{
////			graph[b][a][0] = d;
////			graph[b][a][1] = e;
////		}
////	}
////	cin >> start >> des;
////	for (int i = 0; i < 2; ++i)//使用两次Dij+DFS
////	{
////		fill(visit, visit + N, false);
////		fill(dis, dis + N, inf);
////		fill(num, num + N, inf);
////		dis[start] = 0;
////		num[start] = 0;
////		Dijkstra(i);
////		DFS(des,i);//从终点开始寻根
////	}
////	if (cmp())//比较路径是否相同
////	{
////		printf("Distance = %d; Time = %d: ", shortest[0], shortest[1]);
////		printPath(0);
////	}
////	else//不相等
////	{
////		printf("Distance = %d: ", shortest[0]);
////		printPath(0);
////		printf("Time = %d: ", shortest[1]);
////		printPath(1);
////	}
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//#define NN 505
//struct Node
//{
//	int way, length, time;
//};
//int n, m, vs, ve;
//int fatherTime[NN], fatherLength[NN], shortest[NN], fastest[NN];
//Node citys[NN][NN];
//vector<int>resD, resT;
//void Dijkstra()
//{
//	for (int i = 0; i < n; ++i)
//		fatherLength[i] = fatherTime[i] = i;
//	int lenghtTime[NN], timeCross[NN];
//	bool visitTime[NN] = { false }, visitLenght[NN] = { false };
//	fill(shortest, shortest + n + 1, INT32_MAX);
//	fill(fastest, fastest + n + 1, INT32_MAX);
//	fill(lenghtTime, lenghtTime + n + 1, INT32_MAX);
//	fill(timeCross, timeCross + n + 1, INT32_MAX);
//	shortest[vs] = 0;
//	fastest[vs] = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		int uD = -1, uT = -1, minD = INT32_MAX, minT = INT32_MAX;
//		for (int j = 0; j < n; ++j)
//		{
//			if (visitLenght[j] == false && minD > shortest[j])
//			{
//				minD = shortest[j];
//				uD = j;
//			}
//			if (visitTime[j] == false && minT > fastest[j])
//			{
//				minT = fastest[j];
//				uT = j;
//			}
//		}
//		if (uT == -1 && uD == -1)break;
//		if (uD != -1)visitLenght[uD] = true;
//		if (uT != -1)visitTime[uT] = true;
//		for (int v = 0; v < n; ++v)
//		{
//			if (uD != -1 && visitLenght[v] == false && citys[uD][v].way == 1)
//			{
//				///
//				if (shortest[v] > shortest[uD] + citys[uD][v].length)
//				{
//					shortest[v] = shortest[uD] + citys[uD][v].length;
//					lenghtTime[v] = lenghtTime[uD] + citys[uD][v].time;
//					fatherLength[v] = uD;
//				}
//				else if (shortest[v] == shortest[uD] + citys[uD][v].length)
//				{
//					if (lenghtTime[v] > lenghtTime[uD] + citys[uD][v].time)
//					{
//						lenghtTime[v] = lenghtTime[uD] + citys[uD][v].time;
//						fatherLength[v] = uD;
//					}
//				}
//			}
//			if (uT != -1 && visitTime[v] == false && citys[uT][v].way == 1)
//			{
//				if (fastest[v] > fastest[uT] + citys[uT][v].time)
//				{
//					fastest[v] = fastest[uT] + citys[uT][v].time;
//					fatherTime[v] = uT;
//					timeCross[v] = timeCross[uT] + 1;
//				}
//				else if (fastest[v] == fastest[uT] + citys[uT][v].time)
//				{
//					if (timeCross[v] > timeCross[uT] + 1)
//					{
//						timeCross[v] == timeCross[uT] + 1;
//						fatherTime[v] = uT;
//					}
//				}
//			}
//		}
//	}
//}
//void DFS(int x,const char flag)
//{
//	if (x == vs)
//	{
//		if (flag == 'D')
//			resD.push_back(x);
//		else
//			resT.push_back(x);
//		return;	
//	}
//	if (flag == 'D')
//		DFS(fatherLength[x], flag);
//	else
//		DFS(fatherTime[x], flag);
//	if (flag == 'D')
//		resD.push_back(x);
//	else
//		resT.push_back(x);
//}
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		int a, b, way, length, time;
//		cin >> a >> b >> way >> length >> time;
//		if (way == 1)
//			citys[a][b] = { 1,length,time };
//		else
//			citys[a][b] = citys[b][a] = { 1,length,time };
//	}
//	cin >> vs >> ve;
//	Dijkstra();
//	DFS(ve, 'D');
//	DFS(ve, 'T');
//	if (resD==resT)
//	{
//		printf("Distance = %d; Time = %d: ", shortest[ve], fastest[ve]);
//		for (int i = 0; i < resD.size(); ++i)
//			cout << (i == 0 ? "" : " -> ") << resD[i];
//	}
//	else
//	{
//		printf("Distance = %d: ", shortest[ve]);
//		for (int i = 0; i < resD.size(); ++i)
//			cout << (i == 0 ? "" : " -> ") << resD[i];
//		cout << endl;
//		printf("Time = %d: ", fastest[ve]);
//		for (int i = 0; i < resT.size(); ++i)
//			cout << (i == 0 ? "" : " -> ") << resT[i];
//	}
//	return 0;
//}