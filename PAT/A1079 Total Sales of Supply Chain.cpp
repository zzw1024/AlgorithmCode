////#include <iostream>
////#include <vector>
////#include <queue>
////#include <cmath>
////using namespace std;
////int N;
////double p, r, res = 0.0;
////struct Node
////{
////	int flag, w, l;
////	vector<int>next;
////	Node(int f = 1, int w = 0) :flag(f), w(w) {}
////};
////int main()
////{
////	cin >> N >> p >> r;
////	vector<Node*>v;//记录手下人
////	int k, a;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> k;
////		if (k == 0)
////		{
////			Node* node = new Node(0);
////			cin >> node->w;
////			v.push_back(node);
////		}
////		else
////		{
////			Node* node = new Node();
////			for (int j = 0; j < k; ++j)
////			{
////				cin >> a;
////				node->next.push_back(a);
////			}
////			v.push_back(node);
////		}
////	}
////	int level = 0;
////	queue<Node*>q;
////	v[0]->l = 0;
////	q.push(v[0]);
////	while (!q.empty())
////	{
////		Node* node = q.front();
////		q.pop();		
////		if (node->flag == 0)//零售商
////			res += p * pow((1.0 + r / 100.0), node->l) * node->w;
////		else
////		{
////			for (auto t :node->next)
////			{
////				v[t]->l = node->l + 1;
////				q.push(v[t]);
////			}
////		}
////	}
////	printf("%.1f\n", res);
////	return 0;
////}
//
//#include <iostream>
//#include <queue>
//#include <cmath>
//using namespace std;
//vector<vector<int>>v;
//vector<int>product;
//int n, k, id;
//double price, rate, res = 0.0;
//void DFS(int index, int level)
//{
//	if (v[index].size() == 0)
//		res += product[index] * price * pow(1 + rate / 100.0, level);
//	for (int i = 0; i < v[index].size(); ++i)
//		DFS(v[index][i], level + 1);
//}
//void BFS(int index)
//{
//	vector<int>level(n, 0);
//	queue<int>q;
//	q.push(index);
//	while (!q.empty())
//	{
//		int p = q.front();
//		q.pop();
//		for (auto a : v[p])
//		{
//			level[a] = level[p] + 1;
//			if (v[a].size() == 0)
//				res += product[a] * price * pow(1 + rate / 100.0, level[a]);
//			else
//				q.push(a);
//		}
//	}
//}
//int main()
//{	
//	cin >> n >> price >> rate;
//	v.resize(n);
//	product.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> k;
//		if (k == 0)
//			cin >> product[i];
//		while (k--)
//		{
//			cin >> id;
//			v[i].push_back(id);
//		}
//	}
//	//BFS(0);
//	DFS(0, 0);
//	printf("%.1f\n", res);
//	return 0;
//}