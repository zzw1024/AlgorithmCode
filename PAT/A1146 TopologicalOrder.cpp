//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//
//int main()
//{	
//	int n, m, k;
//	cin >> n >> m;
//	vector<vector<int>>v(n + 1);
//	vector<int>in(n + 1, 0), temp, res;//节点的入度
//	for (int i = 0; i < m; ++i)
//	{
//		int a, b;
//		cin >> a >> b;
//		v[a].push_back(b);
//		in[b]++;
//	}
//	cin >> k;
//	for (int i = 0; i < k; ++i)
//	{
//		bool flag = true;
//		temp = in;		
//		for (int j = 0; j < n; ++j)
//		{
//			int x;
//			cin >> x;
//			if (temp[x] != 0)flag = false;
//			for (auto a : v[x])--temp[a];//出现一次入度减一
//		}
//		if (!flag)
//			res.push_back(i);
//	}
//	for (int i = 0; i < res.size(); ++i)
//		cout << (i == 0 ? "" : " ") << res[i];	
//	return 0;
//}
//
//

//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, m, k;
//	cin >> n >> m;
//	vector<int>inN(n + 1, 0);
//	vector<vector<int>>v(n + 1);
//	for (int i = 0; i < m; ++i)
//	{
//		int a, b;
//		cin >> a >> b;
//		++inN[b];//计算入度
//		v[a].push_back(b);
//	}
//	cin >> k;
//	vector<int>temp, res;
//	for (int j = 0; j < k; ++j)
//	{
//		temp = inN;
//		bool isTrue = true;
//		int b;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> b;
//			if (temp[b] != 0)
//				isTrue = false;
//			for (auto a : v[b])
//				--temp[a];//入度减一
//		}
//		if (!isTrue)
//			res.push_back(j);
//	}
//	for (int i = 0; i < res.size(); ++i)
//		cout << (i == 0 ? "" : " ") << res[i];
	/*return 0;
}*/