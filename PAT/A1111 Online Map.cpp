////#include <iostream>
////#include <vector>
////using namespace std;
////#define inf 999999999
////int N, M, start, des, shortest[2];//shortest�洢���·���ĳ���(�±�Ϊ0)�����·����ʱ��(�±�Ϊ1)
////int graph[505][505][2];//ͼ���ڽӾ���
////int dis[505], past[505], num[505];////������̾��롢���ڵ㡢num�����·��ʱ�洢ʱ�䣬�����·��ʱ�洢��ǰ·���Ͻ�����
////bool visit[505] = { false };
////vector<int>path[2];//�±�Ϊ0�洢���·�����±�Ϊ1�洢���·��
////void Dijkstra(int k)//k==0�����·����k==1�����·��
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
////				dis[i] = dis[v] + graph[v][i][k];//���¾���
////				past[i] = v;//���¸��ڵ�
////				if (k == 0)//�������·��
////					num[i] = num[v] + graph[v][i][1];//����ʱ��
////				else//�����·��
////					num[i] = num[v] + 1;//���Ӿ�����·���ڵ�
////			}
////			else if (graph[v][i][k] != 0 && dis[i] == dis[v] + graph[v][i][k])//·���������
////			{
////				if (k == 0 && num[i] > num[v] + graph[v][i][1])//ʱ�����
////				{
////					past[i] = v;//Ҫ���������
////					num[i] = num[v] + graph[v][i][1];//���Ӿ�����ʱ��
////				}
////				else if (k == 1 && num[i] > num[v] + 1)//�������ٵĽڵ�
////				{
////					past[i] = v;//�򾭹��õ�
////					num[i] = num[v] + 1;//���Ӿ����Ľڵ�
////				}
////			}
////		}
////	}
////	shortest[k] = dis[des];//�洢����Ϣ
////}
////void DFS(int v, int k)//ʹ��DFSѰ�ҳ���
////{
////	if (v == start)//�����
////	{
////		path[k].push_back(v);
////		return;
////	}
////	DFS(past[v], k);//�Ӻ���ǰѰ������DFS����м�¼·������·������˳���
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
////void printPath(int k)//·����ӡ
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
////		if (c == 0)//��˫���
////		{
////			graph[b][a][0] = d;
////			graph[b][a][1] = e;
////		}
////	}
////	cin >> start >> des;
////	for (int i = 0; i < 2; ++i)//ʹ������Dij+DFS
////	{
////		fill(visit, visit + N, false);
////		fill(dis, dis + N, inf);
////		fill(num, num + N, inf);
////		dis[start] = 0;
////		num[start] = 0;
////		Dijkstra(i);
////		DFS(des,i);//���յ㿪ʼѰ��
////	}
////	if (cmp())//�Ƚ�·���Ƿ���ͬ
////	{
////		printf("Distance = %d; Time = %d: ", shortest[0], shortest[1]);
////		printPath(0);
////	}
////	else//�����
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