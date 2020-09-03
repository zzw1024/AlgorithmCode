//////#include <iostream>
//////#include <vector>
//////#include <algorithm>
//////using namespace std;
//////int N, M;
//////int coins[10010], dp[10010];
//////bool visit[10010][110];
//////int main()
//////{
//////	cin >> N >> M;	
//////	for (int i = 1; i <= N; ++i)
//////		cin >> coins[i];
//////	sort(coins + 1, coins + N + 1, [](int a, int b) {return a > b; });
//////	for (int i = 1; i <= N; ++i)
//////	{
//////		for (int j = M; j >= coins[i]; --j)//目标递减
//////		{
//////			if (dp[j] <= dp[j - coins[i]] + coins[i])
//////			{
//////				dp[j] = dp[j - coins[i]] + coins[i];
//////				visit[i][j] = true;//取
//////			}
//////		}
//////	}
//////	if (dp[M] != M)
//////		cout << "No Solution" << endl;
//////	else
//////	{
//////		vector<int>res;
//////		int v = M, index = N;
//////		while (v > 0)
//////		{
//////			if (visit[index][v] == true)
//////			{
//////				res.push_back(coins[index]);
//////				v -= coins[index];
//////			}
//////			--index;
//////		}
//////		for (int i = 0; i < res.size(); ++i)
//////			cout << res[i] << (i == res.size() - 1 ? "" : " ");
//////	}
//////	return 0;
//////}
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int main()
////{
////	int n, m;
////	cin >> n >> m;
////	vector<int>dp(m + 1, 0), v(n + 1, 0);
////	vector<vector<bool>>choice(n + 1, vector<bool>(m + 1, false));
////	for (int i = 1; i <= n; ++i)
////		cin >> v[i];
////	sort(v.begin()+1, v.end(), [](int a, int b) {return a > b; });
////	for (int i = 1; i <= n; ++i)
////	{
////		for (int j = m; j >= v[i]; --j)
////		{
////			if (dp[j] <= dp[j - v[i]] + v[i])
////			{
////				choice[i][j] = true;
////				dp[j] = dp[j - v[i]] + v[i];
////			}
////		}
////	}
////	if (dp[m] != m)cout << "No Solution" << endl;
////	else
////	{
////		vector<int>arr;
////		int u = m, index = n;
////		while (u > 0)
////		{
////			if (choice[index][u] == true)
////			{
////				arr.push_back(v[index]);
////				u -= v[index];
////			}
////			index--;
////		}
////		for (int i = 0; i < arr.size(); ++i)
////			cout << (i == 0 ? "" : " ") << arr[i];
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int>coins(n + 1, 0), dp(m + 1, 0);
//	vector<vector<bool>>choose(n + 1, vector<bool>(m + 1, false));
//	for (int i = 1; i <= n; ++i)
//		cin >> coins[i];
//	sort(coins.begin() + 1, coins.end(), [](int a, int b) {return a > b; });
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = m; j >= coins[i]; --j)//必须是逆序，因为用的是0-1背包问题中的一维数组求解
//		{
//			if (dp[j] <= dp[j - coins[i]] + coins[i])//当选择coins与dp[j]组合的值未超出dp[j]的值时，可以进行选择
//			{
//				choose[i][j] = true;
//				dp[j] = dp[j - coins[i]] + coins[i];
//			}
//		}
//	}
//	if (dp[m] != m)
//	{
//		cout << "No Solution" << endl;
//		return 0;
//	}
//	vector<int>res;
//	int u = m, v = n;
//	while (u > 0)
//	{
//		if (choose[v][u] == true)//因为coins是逆序存放的，所以从v=n开始计算
//		{
//			res.push_back(coins[v]);
//			u -= coins[v];
//		}
//		--v;
//	}
//	for (int i = 0; i < res.size(); ++i)
//		cout << (i == 0 ? "" : " ") << res[i];
//	return 0;
//}
//
