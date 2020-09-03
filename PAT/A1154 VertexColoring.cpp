//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//int main()
//{
//	int n, m, k;
//	cin >> n >> m;
//	vector <vector<int>>path(n);	
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		path[a].push_back(b);
//		path[b].push_back(a);
//	}
//	cin >> k;
//	while (k--)
//	{
//		vector<int>color(n, 0);
//		unordered_set<int>nums;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> color[i];
//			nums.insert(color[i]);
//		}
//		bool flag = true;
//		for (int i = 0; i < n && flag; ++i)
//		{
//			for (auto j : path[i])
//			{
//				if (color[i] == color[j])
//				{
//					flag = false;
//					break;
//				}
//			}
//		}
//		if (flag)
//			printf("%d-coloring\n", nums.size());
//		else
//			printf("No\n");		
//	}
//	return 0;
//}
//
