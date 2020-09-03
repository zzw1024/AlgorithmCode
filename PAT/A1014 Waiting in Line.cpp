//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, m, k, q, time;
//	cin >> n >> m >> k >> q;
//	vector<int>res(k + 1);
//	queue<int>windows[25];
//	vector<bool>sorry(k + 1, false);
//	for (int i = 0; i < k; ++i)
//	{
//		cin >> time;
//		if (i < n*m)
//		{
//			if (windows[i%n].size() == 0)
//			{
//				windows[i%n].push(time);
//			}
//			else
//			{
//				if (windows[i%n].back() >= (17 - 8) * 60)//前者结束时间超过下班时间，本人排不上号
//					sorry[i + 1] = true;
//				windows[i%n].push(windows[i%n].back() + time);
//			}
//			res[i + 1] = windows[i%n].back();//结束时间
//		}
//		else
//		{
//			int minTime = windows[0].front(), index = 0;
//			for (int j = 0; j < n; ++j)
//			{
//				if (windows[j].front() < minTime)
//				{
//					minTime = windows[j].front();
//					index = j;
//				}
//			}
//			if(windows[index].back() >= (17 - 8) * 60)//前者结束时间超过下班时间，本人排不上号
//				sorry[i + 1] = true;
//			windows[index].pop();
//			windows[index].push(windows[index].back() + time);
//			res[i + 1] = windows[index].back();
//		}
//	}
//	while (q--)
//	{
//		cin >> time;
//		if (sorry[time] == true)
//			printf("Sorry\n");
//		else
//			printf("%02d:%02d\n", res[time] / 60 + 8, res[time] % 60);
//	}
//	return 0;
//}