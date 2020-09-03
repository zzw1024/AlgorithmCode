//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//int main()
//{
//	int k, n, m, t;
//	cin >> k >> n >> m;
//	vector<int>call(n + 1, 0), back(n + 1, 0);//短电话打出去的记录和这些人打回进来的记录
//	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));//电话记录,记住记录的是累计的通话时间
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		v[a][b] += c;//算累加通话时间的
//	}
//	for (int i =1; i <= n; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//		{
//			if (v[i][j]>0 && v[i][j] <= 5)//这通话时间算是短电话
//			{
//				++call[i];//计算i打出去的人数
//				if (v[j][i] > 0)//这是j回给了i的
//					++back[i];//计算回给i的人数
//			}			
//		}
//	}	
//	vector<int>suspect, team(n + 1, 0);//统计诈骗犯的人数和初始化他们的团队号
//	for (int i = 1; i <= n; ++i)
//	{
//		if (call[i] > k && call[i] >= back[i]*5)//打出去的人数大于阈值k，回电话的人数不多于打出去的20%,注意
//		{
//			team[i] = i;//用来算同谋的
//			suspect.push_back(i);
//		}
//	}	
//	for (int i = 0; i < suspect.size(); ++i)//这里虽然是双重循环，但是诈骗犯的数量级很小的，所以这里应该不会超时间的，当然，超了的话，就用DFS即可
//		for (int j = i + 1; j < suspect.size(); ++j)
//			if (v[suspect[i]][suspect[j]] > 0 && v[suspect[j]][suspect[i]] > 0)//这两个诈骗人相互打过电话
//				team[suspect[j]] = team[suspect[i]];
//	map<int, vector<int>>res;
//	for (int i = 1; i <= n; ++i)
//		if (team[i] > 0)
//			res[team[i]].push_back(i);//将属于同一伙的诈骗犯放一组
//	if (suspect.size() == 0)
//		printf("None");
//	else
//	{
//		for (auto ptr = res.begin(); ptr != res.end(); ++ptr)
//		{
//			for (int i = 0; i < ptr->second.size(); ++i)//由于遍历是从小到大的，所以不用排序
//				printf("%s%d", i == 0 ? "" : " ", ptr->second[i]);
//			printf("\n");
//		}
//	}
//	return 0;
//}