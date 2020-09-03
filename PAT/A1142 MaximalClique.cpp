//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, m, k;
//	cin >> n >> m;
//	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		v[a][b] = v[b][a] = 1;
//	}
//	cin >> k;
//	while (k--)
//	{
//		cin >> m;
//		vector<int>temp(m);
//		vector<bool>otherNum(n + 1, true);
//		for (int i = 0; i < m; ++i)
//		{
//			cin >> temp[i];
//			otherNum[temp[i]] = false;
//		}
//		bool flag = true, isMax = true;
//		for (int i = 0; i < m && flag; ++i)//判断查询的点是不是两两相连
//			for (int j = i + 1; j < m; ++j)
//				if (v[temp[i]][temp[j]] == 0)
//					flag = false;
//		if (flag == false)
//			cout << "Not a Clique" << endl;
//		else
//		{
//			for (int i = 1; i <= n && isMax; ++i)//判断查询之外的点与查询中的点是不是两两相连
//			{
//				if (otherNum[i] == false)continue;//在查询中的点不用判断
//				int nums = 0;
//				for (int j = 0; j < m; ++j)
//					if (v[i][temp[j]] == 1)
//						++nums;
//				if (nums == m)
//					isMax = false;
//			}
//			if (isMax)
//				cout << "Yes" << endl;
//			else
//				cout << "Not Maximal" << endl;
//		}
//	}
//	return 0;
//}