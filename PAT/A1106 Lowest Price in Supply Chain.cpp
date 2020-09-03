////#include <iostream>
////#include <vector>
////#include <queue>
////#include <cmath>
////using namespace std;
////int n, m;
////double p, r;
////int main()
////{
////	cin >> n >> p >> r;
////	vector<vector<int>>people;
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> m;
////		vector <int>temp(m);
////		for (int i = 0; i < m; ++i)
////			cin >> temp[i];
////		people.push_back(temp);
////	}
////	queue<int>node;
////	node.push(0);
////	int num = 0, level = -1;
////	while (!node.empty())
////	{
////		queue<int>q;
////		while (!node.empty())
////		{
////			int root = node.front();
////			node.pop();
////			for (int i = 0; i < people[root].size(); ++i)
////				q.push(people[root][i]);
////			if (people[root].size() == 0)//ÁãÊÛÉÌ
////				num++;
////		}
////		level++;
////		if (num > 0)
////			break;
////		node = q;
////	}
////	printf("%0.4f %d\n", p*pow((1+r / 100), level), num);
////	return 0;
////}
//
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//int n, minLevel, nums = 1;
//double p, r,res = 0.0;
//vector<vector<int>>v;
//void DFS(int x, int level)
//{
//	if (v[x].size() == 0)
//	{
//		if (minLevel > level)
//		{
//			minLevel = level;
//			nums = 1;
//		}
//		else if (minLevel == level)
//			nums++;
//	}
//	for (int i = 0; i < v[x].size(); ++i)
//		DFS(v[x][i], level + 1);
//}
//int main()
//{
//	cin >> n >> p >> r;
//	v.resize(n);
//	minLevel = n + 1;
//	for (int i = 0; i < n; ++i)
//	{
//		int k, a;
//		cin >> k;
//		while (k--)
//		{
//			cin >> a;
//			v[i].push_back(a);
//		}		
//	}
//	DFS(0, 0);
//	printf("%.4f %d\n", p*pow((1.0 + r / 100.0), minLevel), nums);
//	return 0;
//}