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
////			cin >> queen[i];//��һ�д���queen
////			for (int t = 1; t < i; ++t)//�ж�ǰi-1�е�queen�ǲ�����ͬһ��
////			{
////				if (queen[i] == queen[t] || abs(queen[i] - queen[t]) == abs(i - t))//�Ƿ������ͬ�У��͵�t�е�б��λ��
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
//			for (int t = 1; t < i && flag; ++t)///ͬһ�У�������ͬб����
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