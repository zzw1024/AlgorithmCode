////#include <iostream>
////#include <vector>
////#include <queue>
////
////using namespace std;
////
//////����һ��������ÿһ���Ҷ�ӽ������
//////ʹ��BFS����DFS
////
////vector<vector<int>>nodes(1001);
////vector<int>depth(1001);
////int maxDepth = -1;
////
////void DFS(int index, int h)
////{
////	maxDepth = maxDepth > h ? maxDepth : h;
////	if (nodes[index].size() == 0)//data[index].size() == 0)//��ΪҶ�ӽ��
////		depth[h]++;//����
////
////	for (int i = 0; i < nodes[index].size(); ++i)
////		DFS(nodes[index][i], h + 1);
////}
////
////void BFS( )
////{
////	queue<int>q;
////	q.push(1);
////	vector<int>level(1001, 0);//��¼�ڵ����
////	while (!q.empty())
////	{
////		int index = q.front();
////		q.pop();
////		maxDepth = maxDepth > level[index] ? maxDepth : level[index];//�洢���Ĳ���
////		if (nodes[index].size() == 0)//�˽ڵ�ΪҶ�ӽڵ�
////			depth[level[index]]++;//֮����Ҫ��¼ÿ���ڵ�Ĳ���������Ϊ��ͬһ���ж���ڵ�
////		for (int i = 0; i < nodes[index].size(); ++i)
////		{
////			level[nodes[index][i]] = level[index] + 1;//���ӽ������ȸ��ڵ��һ��
////			q.push(nodes[index][i]);//���亢��ȫ������
////		}
////	}
////}
////
////
////
////int main()
////{
////	int N, M;//NΪ�ڵ���Ŀ
////	cin >> N >> M;		
////	for (int i = 0; i < M; ++i)
////	{
////		int ID, k, a;
////		cin >> ID >> k;
////		for (int j = 0; j < k; ++j)
////		{
////			cin >> a;
////			nodes[ID].push_back(a);//��Ϊһ���ڵ�������ҵ��ӽڵ�
////		}
////	}
////
////	//DFS(1,0);
////	BFS( );
////	cout << depth[0];
////	for (int i = 1; i <= maxDepth; ++i)
////		cout << " " << depth[i];
////	cout << endl;
////
////	return 0;
////
////}
//
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//struct Node
//{
//	vector<int>v;
//}node[105];
//int n, m, k;
//int main()
//{
//	cin >> n >> m;
//	int root = 01;
//	while (m--)
//	{
//		int head, k, child;
//		cin >> head >> k;
//		while (k--)
//		{
//			cin >> child;
//			node[head].v.push_back(child);
//		}
//	}
//	queue<int>num, q;
//	q.push(root);
//	while (!q.empty())
//	{
//		queue<int>temp;
//		int tempN = 0;
//		while (!q.empty())
//		{
//			int p = q.front();
//			q.pop();
//			if (node[p].v.size() == 0)
//				tempN++;
//			for (int i = 0; i < node[p].v.size(); ++i)
//				temp.push(node[p].v[i]);
//		}
//		q = temp;
//		num.push(tempN);
//	}
//	while (!num.empty())
//	{
//		cout << num.front() << (num.size() > 1 ? " " : "");
//		num.pop();
//	}
//	return 0;
//}

//
//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m, k, maxL = 0;
//vector<int>nodes[105];
//vector<int>level(105, 0);
//void DFS(int index, int L)
//{
//	maxL = maxL > L ? maxL : L;
//	if (nodes[index].size() == 0)++level[L];
//	for (auto a : nodes[index])
//		DFS(a, L + 1);
//}
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> k;
//		while (k--)
//		{
//			cin >> b;
//			nodes[a].push_back(b);
//		}
//	}
//	DFS(01, 0);
//	for (int i = 0; i <= maxL; ++i)
//		cout << (i == 0 ? "" : " ") << level[i];
//	return 0;
//}