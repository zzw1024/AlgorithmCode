////#include <iostream>
////using namespace std;
//////太简单了，竟然是按要求的顺序进行升降，一点都没有说进行时间优化？！
////int main()
////{
////	int N;
////	cin >> N;
////	int pre = 0, now,sum = 5 * N;//上一次停留在哪？现在要去的楼层，时间初始为要在 每一层的总停留时间
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> now;
////		if ((now - pre) > 0)//上
////			sum += (now - pre) * 6;
////		else if ((now - pre) < 0)//下
////			sum += (pre - now) * 4;
////		pre = now;//更新楼层
////	}
////	cout << sum << endl;
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//int n;
//int main()
//{
//	cin >> n;
//	int sum = 0, pre = 0, now = 0;
//	while (n--)
//	{
//		cin >> now;
//		sum += 5;//停留5s
//		if (now > pre)//上
//			sum += (now - pre) * 6;
//		else
//			sum += (pre - now) * 4;//下
//		pre = now;
//	}
//	cout << sum;
//	return 0;
//}