//////#include <iostream>
//////#include <vector>
//////#include <map>
//////using namespace std;
//////int N, M, L, res = -1, num;
//////vector<int>favor, dp;
//////map<int, int>colMap;
////////根据最长非递减数列问题，使用动态规划算法
//////int main()
//////{
//////	cin >> N;
//////	cin >> M;
//////	for (int i = 0; i < M; ++i)
//////	{
//////		cin >> num;
//////		colMap[num] = i;//为喜爱的颜色排序
//////	}
//////	cin >> L;
//////	dp.resize(L);
//////	for (int i = 0; i < L; ++i)
//////	{
//////		cin >> num;
//////		if (colMap.find(num) == colMap.end())//不是最喜爱的颜色
//////			colMap[num] = -1;
//////		if (colMap[num] >= 0)//为喜欢的颜色
//////			favor.push_back(colMap[num]);//到时候就是从这里去出最长子序列
//////	}
//////	for (int i = 0; i < favor.size(); ++i)
//////	{
//////		dp[i] = 1;//自身排序是1
//////		for (int j = 0; j < i; ++j)//向前问一下，i能不能排在前面数字中
//////			if (favor[j] <= favor[i] && dp[i] < dp[j] + 1)
//////				dp[i] = dp[j] + 1;
//////		res = res > dp[i] ? res : dp[i];
//////	}
//////	cout << res << endl;
//////	return 0;
//////}
////
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int book[205], a[10010], dp[10010];
////int main()
////{
////	int n, m, x, l, num = 0, maxn = 0;
////	cin >> n >> m;
////	for (int i = 1; i <= m; ++i)
////	{
////		cin >> x;
////		book[x] = i;//标记喜欢的颜色
////	}
////	cin >> l;
////	for (int i = 0; i < l; ++i)
////	{
////		cin >> x;
////		if (book[x] > 0)
////			a[num++] = book[x];
////	}
////	for (int i = 0; i < num; ++i)
////	{
////		dp[i] = 1;
////		for (int j = 0; j < i; ++j)
////			if (a[i] >= a[j])
////				dp[i] = max(dp[i], dp[j] + 1);
////		maxn = max(dp[i], maxn);
////	}
////	cout << maxn << endl;
////	return 0;
////}
////#include <iostream>
////using namespace std;
////int like[205], color[10010], dp[10010];
////int main()
////{
////	int n, m, k, t = 0, res = 0;
////	cin >> n >> m;
////	for (int i = 1; i <= m; ++i)
////	{
////		int a;
////		cin >> a;
////		like[a] = i;
////	}
////	cin >> k;
////	for (int i = 0; i < k; ++i)
////	{
////		int a;
////		cin >> a;
////		if (like[a] > 0)//排除不喜欢的颜色
////			color[t++] = like[a];
////	}
////	for (int i = 0; i < t; ++i)
////	{
////		dp[i] = 1;
////		for (int j = 0; j < i; ++j)
////			if (color[i] >= color[j])
////				dp[i] = dp[i] > (dp[j] + 1) ? dp[i] : (dp[j] + 1);
////		res = dp[i] > res ? dp[i] : res;
////	}
////	cout << res;
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//int like[205], color[10010], dp[10010];
//int main()
//{
//	int n, m, k, res = 0, x, nums = 0;
//	cin >> n >> m;
//	for(int i=1;i<=m;++i)//给自己喜欢颜色排序标号
//	{
//		cin >> x;
//		like[x] = i;		
//	}
//	cin >> k;
//	for (int i = 0; i < k; ++i)
//	{
//		cin >> x;
//		if (like[x] > 0)//删除不是喜欢颜色的变量
//			color[nums++] = like[x];//记住该颜色的标号
//	}
//	for (int i = 0; i < nums; ++i)
//	{
//		dp[i] = 1;//每种颜色单独拼接的长度为1
//		for (int j = 0; j < i; ++j)
//			if (color[j] <= color[i])//只要前面的颜色的序号比自己小，那么就可以和直接拼接
//				dp[i] = dp[i] > (dp[j] + 1) ? dp[i] : (dp[j] + 1);
//		res = res > dp[i] ? res : dp[i];
//	}
//	cout << res;
//	return 0;
//}
