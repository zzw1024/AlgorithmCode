//////#include <iostream>
//////#include <queue>
//////using namespace std;
//////struct Node
//////{
//////	int x, y, z;
//////	Node(int xx, int yy, int zz) :x(xx), y(yy), z(zz) {}
//////};
//////int M, N, L, T, res = 0;
//////int direct[6][3] = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };
//////bool G[1300][130][70];//遍历记录
//////int BFS(Node p)
//////{
//////	int num = 0;
//////	queue<Node>q;
//////	q.push(p);
//////	G[p.x][p.y][p.z] = false;
//////	while (!q.empty())
//////	{
//////		p = q.front();
//////		q.pop();
//////		++num;
//////		for (int i = 0; i < 6; ++i)
//////		{
//////			int x = p.x + direct[i][0];
//////			int y = p.y + direct[i][1];
//////			int z = p.z + direct[i][2];
//////			if (x < M && x >= 0 && y >= 0 && y < N && z >= 0 && z <= L && G[x][y][z])
//////			{
//////				q.push(Node(x, y, z));
//////				G[x][y][z] = false;
//////			}
//////		}
//////	}
//////	return num;
//////}
//////int main()
//////{
//////	cin >> M >> N >> L >> T;
//////	for (int k = 0; k < L; ++k)
//////		for (int i = 0; i < M; ++i)
//////			for (int j = 0; j < N; ++j)
//////				cin >> G[i][j][k];
//////	for(int i=0;i<M;++i)
//////		for(int j=0;j<N;++j)
//////			for(int k=0;k<L;++k)
//////				if (G[i][j][k])
//////				{
//////					int temp = BFS(Node(i, j, k));
//////					if (temp >= T)
//////						res += temp;
//////				}
//////	cout << res << endl;
//////	return 0;
//////}
////
////#include <iostream>
////#include <vector>
////#include <queue>
////#include <algorithm>
////using namespace std;
////int maps[65][130][130];
////int m, n, l, t, res = 0;
////int DFS(int z, int x, int y)
////{
////	if (z < 0 || z >= l || x < 0 || x >= m || y < 0 || y >= n || maps[z][x][y] != 1)
////		return 0;
////	int nums = 1;
////	maps[z][x][y] = 2;
////	nums += DFS(z + 1, x, y);
////	nums += DFS(z - 1, x, y);
////	nums += DFS(z, x+1, y);
////	nums += DFS(z, x-1, y);
////	nums += DFS(z, x, y+1);
////	nums += DFS(z, x, y-1);
////	return nums;
////}
////struct Node
////{
////	int z, x, y;
////};
////int BFS(int z, int x, int y)
////{
////	queue<Node>q;
////	q.push({ z,x,y });
////	int nums = 0;
////	int pot[6][3] = { {1,0,0},{-1,0,0},{0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };	
////	maps[z][x][y] = 2;
////	while (!q.empty())
////	{
////		Node p = q.front();
////		q.pop();		
////		nums++;
////		for (int i = 0; i < 6; ++i)
////		{
////			Node node;
////			node.z = p.z + pot[i][0];
////			node.x = p.x + pot[i][1];
////			node.y = p.y + pot[i][2];
////			if (node.z >= 0 && node.z < l && node.x >= 0 && node.x < m && node.y >= 0 && node.y < n && maps[node.z][node.x][node.y] == 1)
////			{
////				maps[node.z][node.x][node.y] = 2;//之所以只能在这里进行感染，是因为防止出现相同的node，故不能在pop处感染
////				q.push(node);
////			}
////		}
////	}
////	return nums;
////}
////int main()
////{
////	cin >> m >> n >> l >> t;
////	for (int i = 0; i < l; ++i)
////		for (int x = 0; x < m; ++x)
////			for (int y = 0; y < n; ++y)
////				cin >> maps[i][x][y];
////	for (int z = 0; z < l; ++z)
////		for (int x = 0; x < m; ++x)
////			for (int y = 0; y < n; ++y)
////				if (maps[z][x][y] == 1)
////				{
////					//int nums = DFS(z, x, y); 
////					int nums = BFS(z, x, y);
////					if (nums >= t)
////						res += nums;
////				}
////	cout << res;	
////	return 0;
////}
////
//
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//int m, n, l, t, res = 0;
//int v[65][150][150] = { 0 };
//int visit[65][150][150] = { false };
//void DFS(int z, int x, int y, int &cnt)//数据过大，DFS栈容易溢出
//{
//	if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l || visit[z][x][y] == true || v[z][x][y] == 0)
//		return;
//	visit[z][x][y] = true;
//	++cnt;
//	DFS(z - 1, x, y, cnt);
//	DFS(z + 1, x, y, cnt);
//	DFS(z, x - 1, y, cnt);
//	DFS(z, x + 1, y, cnt);
//	DFS(z, x, y - 1, cnt);
//	DFS(z, x, y + 1, cnt);
//}
//bool isTrue(int z, int x, int y)
//{
//	if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l || visit[z][x][y] == true || v[z][x][y] == 0)
//		return false;
//	return true;
//}
//void BFS(int z, int x, int y, int &cnt)//BFS可以避开DFS中栈溢出的问题
//{
//	queue<vector<int>>q;
//	q.push({ z,x,y });
//	visit[z][x][y] = true;//这里千万不能忘
//	vector<vector<int>>change = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
//	while (!q.empty())
//	{
//		vector<int>p = q.front();
//		q.pop();
//		++cnt;//不能在此处对visit进行禁忌表，因为会使得先取出的位置的六个方向会与后面压入的位置重复		
//		for (int i = 0; i < change.size(); ++i)
//		{
//			z = p[0] + change[i][0];
//			x = p[1] + change[i][1];
//			y = p[2] + change[i][2];
//			if (isTrue(z, x, y))
//			{
//				visit[z][x][y] = true;
//				q.push({ z,x,y });
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> m >> n >> l >> t;
//	for (int z = 0; z < l; ++z)
//		for (int x = 0; x < m; ++x)
//			for (int y = 0; y < n; ++y)
//				cin >> v[z][x][y];
//	for (int z = 0; z < l; ++z)
//		for (int x = 0; x < m; ++x)
//			for (int y = 0; y < n; ++y)
//			{
//				if (v[z][x][y] == 1 && visit[z][x][y]==false)
//				{
//					int cnt = 0;
//					//DFS(z, x, y, cnt);
//					BFS(z, x, y, cnt);
//					if (cnt >= t)
//						res += cnt;
//				}
//			}
//	cout << res;
//	return 0;
//}
