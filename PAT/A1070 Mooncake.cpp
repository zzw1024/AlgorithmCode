////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	double qty, prof, pric;
////}node;
////int N, D;
////int main()
////{
////	cin >> N >> D;
////	vector<Node>Cake;
////	double res = 0.0;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> node.qty;
////		Cake.push_back(node);
////	}
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> Cake[i].prof;
////		Cake[i].pric = Cake[i].prof / Cake[i].qty;
////	}
////	sort(Cake.begin(), Cake.end(), [](Node a, Node b) {return a.pric > b.pric; });
////	for (int i = 0; i < N && D>0; ++i)
////	{
////		int buy = Cake[i].qty < D ? Cake[i].qty : D;
////		D -= buy;
////		res += buy * Cake[i].pric;
////	}
////	printf("%.2f\n", res);
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	double w, p;
//};
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<Node>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i].w;
//	for (int i = 0; i < n; ++i)
//		cin >> v[i].p;
//	sort(v.begin(), v.end(), [](Node a, Node b) {return (a.p / a.w) > (b.p / b.w); });
//	double res = 0;
//	for (int i = 0; i < n && m>0; ++i)
//	{
//		if (m >= v[i].w)
//			res += v[i].p;
//		else
//			res += v[i].p / v[i].w*m;
//		m -= v[i].w;
//	}
//	printf("%.2f\n", res);
//	return 0;
//}