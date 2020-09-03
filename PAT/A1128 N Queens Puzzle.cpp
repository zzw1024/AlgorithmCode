////#include <iostream>
////#include <vector>
////using namespace std;
////int queen[1005];
////int main()
////{
////	int k, n, a;
////	cin >> k;
////	while (k--)
////	{
////		fill(queen, queen + 1005, 0);
////		cin >> n;
////		bool res = true;
////		for (int i = 1; i <= n; ++i)
////		{
////			cin >> queen[i];//新一列存入queen
////			for (int t = 1; t < i; ++t)//判断前i-1列的queen是不是在同一行
////			{
////				if (queen[i] == queen[t] || abs(queen[i] - queen[t]) == abs(i - t))//是否存在相同行，和第t列的斜线位置
////				{
////					res = false;
////					break;
////				}
////			}
////		}
////		cout << (res == true ? "YES" : "NO") << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//int n, k;
//int main()
//{
//	cin >> n;
//	while (n--)
//	{
//		cin >> k;
//		vector<int>queue(k+1, 0);
//		bool flag = true;
//		for (int i = 1; i <= k; ++i)
//		{
//			cin >> queue[i];
//			for (int t = 1; t < i && flag; ++t)///同一列，，，相同斜方向
//				if (queue[i] == queue[t] || abs(queue[i] - queue[t]) == abs(i - t))
//					flag = false;		
//		}
//		if (flag)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;	
//}