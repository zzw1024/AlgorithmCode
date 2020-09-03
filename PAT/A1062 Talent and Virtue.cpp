//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int ID, vir, tal, lab;
//}node[100010];
//int N, L, H;
//bool cmp(Node a, Node b)
//{
//	if (a.lab != b.lab)
//		return a.lab < b.lab;
//	else if ((a.tal + a.vir) != (b.tal + b.vir))
//		return (a.tal + a.vir) > (b.tal + b.vir);
//	else if (a.vir!=b.vir)
//		return a.vir > b.vir;
//	else
//		return a.ID < b.ID;
//}
//int main()
//{
//	cin >> N >> L >> H;
//	int M = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> node[M].ID >> node[M].vir >> node[M].tal;
//		if (node[M].vir < L || node[M].tal < L)
//			continue;
//		else if (node[M].vir >= H && node[M].tal >= H)
//			node[M].lab = 1;
//		else if (node[M].vir >= H && node[M].tal < H)
//			node[M].lab = 2;
//		else if (node[M].vir < H && node[M].tal < H && node[M].vir >= node[M].tal)
//			node[M].lab = 3;
//		else
//			node[M].lab = 4;
//		M++;			
//	}
//	cout << M << endl;
//	sort(node, node + M, cmp);
//	for (int i = 0; i < M; ++i)
//		cout << node[i].ID << " " << node[i].vir << " " << node[i].tal << endl;
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int id, virtue, talent, rank;
//};
//bool cmp(Node a, Node b)
//{
//	if (a.rank == b.rank && (a.talent + a.virtue) == (b.talent + b.virtue) && b.virtue == a.virtue)
//		return a.id < b.id;
//	else if (a.rank == b.rank && (a.talent + a.virtue) == (b.talent + b.virtue))
//		return a.virtue > b.virtue;
//	else if (a.rank == b.rank)
//		return (a.talent + a.virtue) > (b.talent + b.virtue);
//	else return a.rank < b.rank;
//}
//int main()
//{
//	int n, L, H, id, v, t;
//	cin >> n >> L >> H;
//	vector<Node>res;
//	while (n--)
//	{
//		cin >> id >> v >> t;
//		if (v < L || t < L)
//			continue;
//		if (t >= H && v >= H)
//			res.push_back({ id,v,t,1 });
//		else if (t < H && v >= H)
//			res.push_back({ id,v,t,2 });
//		else if (t < H && v < H)
//			res.push_back({ id,v,t,3 });
//		else
//			res.push_back({ id,v,t,4 });
//	}
//	sort(res.begin(), res.end(), cmp);
//	cout << res.size() << endl;
//	for (auto v : res)
//		printf("%08d %d %d\n", v.id, v.virtue, v.talent);
//	return 0;
//}