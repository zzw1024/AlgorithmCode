////#include <iostream>
////#include <vector>
////using namespace std;
////int main()
////{
////	int n, m, k, a, b, start, graph[205][205];
////	bool visit[205];//��¼ÿ���������һ��
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
////			if (flag == false || k != n + 1)//�������еĶ��㲢�ص���㣬��һ���߹�n+1����
////			{
////				flag = false;
////				continue;
////			}
////			if (i == 0)
////				start = b;//��¼���
////			else if (graph[a][b] != 1)//��·��ͨ
////				flag = false;
////			else if (i == k - 1 && b != start)//���һ���㲻�����
////				flag = false;
////			else if (i != k - 1 && visit[b] != false)//�������һ���ظ�������㣬�������������ظ�������
////				flag = false;
////			else
////				visit[b] = true;//������
////			a = b;//��¼ǰһ����
////		}
////		if (flag)
////		{
////			for (int i = 1; i <= n && flag == true; ++i)
////				if (visit[i] == false)//����û�б����Ķ���
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