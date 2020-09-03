//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<string>names(n + 1, "");
//	vector<vector<int>>v(k + 1);
//	for (int i = 1; i <= n; ++i)
//	{
//		string name;
//		int m, a;
//		cin >> name >> m;
//		names[i] = name;
//		while (m--)
//		{
//			cin >> a;
//			v[a].push_back(i);
//		}
//	}
//	for (int i = 1; i <= k; ++i)
//	{
//		cout << i << " " << v[i].size() << endl;
//		sort(v[i].begin(), v[i].end(), [=](const int a, const int b) {return names[a] < names[b]; });
//		for (auto s : v[i])
//			cout << names[s] << endl;
//	}
//	return 0;
//}