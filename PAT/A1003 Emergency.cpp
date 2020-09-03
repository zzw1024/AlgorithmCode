////#include <iostream>
////#include <vector>
////
////using namespace std;
////
////#define INF 99999
////int  main()
////{
////	int N, M, C1, C2;
////	cin >> N >> M >> C1 >> C2;
////	vector<vector<int>>dis(N, vector<int>(N, INF));//-1��ʾ·��ͨ
////	vector<int>v(N, 0);
////	for (int i = 0; i < N; ++i)
////		cin >> v[i];
////	for (int i = 0; i < M; ++i)
////	{
////		int a, b, c;
////		cin >> a >> b >> c;
////		dis[a][b] = dis[b][a] = c;
////	}
////	vector<int>index(N, 1);//��������Ƿ��Ѿ��������ĵ�
////	vector<int>w(N, 0);//��������Ȩ��
////	vector<int>num(N, 0);//������������·������
////	vector<int>D(N, INF);
////	D[C1] = 0; // Start��ʼ����
////	w[C1] = v[C1];
////	num[C1] = 1;//�ʼ��ʼ����һ��
////
////	for (int i = 0; i < N; ++i)
////	{
////		//���ҳ�����ȥ����һ������ĵ�
////		int p = -1;
////		int minD = INF;
////		for (int j = 0; j < N; ++j)
////		{
////			if (index[j] && minD > D[j])
////			{
////				p = j;
////				minD = D[j];
////			}
////		}
////		if (p == -1)
////			break;//�������
////		index[p] = false;//�Ѿ���������
////		//��ô�ͱ�����p��ȥ���ĵ�
////		for (int j = 0; j < N; ++j)
////		{
////			//���µ�Start->j�ľ���
////			if (index[j] && D[j] > D[p] + dis[p][j])
////			{
////				D[j] = D[p] + dis[p][j];
////				num[j] = num[p];
////				w[j] = w[p] + v[j];
////			}
////			else if (index[j] && D[j] == D[p] + dis[p][j])//������ͬ·��
////			{
////				num[j] += num[p];//��������·������
////				w[j] = w[j] > (w[p] + v[j]) ? w[j] : (w[p] + v[j]);//��·��Ȩ���Ƿ����
////			}
////		}
////	}
////	cout << num[C2] << " " << w[C2] << endl;
////
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m, c1, c2, w[505], path[505][505];
//int route[505], numR[505] = { 0 }, numW[505] = { 0 };
//void Dijkstra()
//{	
//	bool visit[505];
//	fill(route, route + 505, INT32_MAX);
//	fill(visit, visit + 505, false);
//	route[c1] = 0;	
//	numR[c1] = 1;
//	numW[c1] = w[c1];
//	for (int i = 0; i < n; ++i)
//	{
//		int v = -1, minN = INT32_MAX;
//		for (int j = 0; j < n; ++j)
//		{
//			if (visit[j] == false && minN > route[j])
//			{
//				minN = route[j];
//				v = j;
//			}
//		}
//		if (v == -1)break;
//		visit[v] = true;
//		for (int u = 0; u < n; ++u)
//		{
//			if (visit[u] == false && path[v][u] != INT32_MAX)
//			{
//				if (route[u] > route[v] + path[v][u])
//				{
//					route[u] = route[v] + path[v][u];
//					numR[u] = numR[v];//u���·������==v���·������
//					numW[u] = numW[v] + w[u];//Ȩ�����
//				}
//				else if (route[u] == route[v] + path[v][u])
//				{
//					numR[u] += numR[v];//����һ��·����·����������
//					numW[u] = numW[u] > (numW[v] + w[u]) ? numW[u] : numW[v] + w[u];//ȡ��ֵ
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m >> c1 >> c2;
//	fill(path[0], path[0] + 505 * 505, INT32_MAX);
//	for (int i = 0; i < n; ++i)
//		cin >> w[i];
//	
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		path[a][b] = path[b][a] = c;
//	}
//	Dijkstra();
//	cout << numR[c2] << " " << numW[c2];
//	return 0;
//}
//
