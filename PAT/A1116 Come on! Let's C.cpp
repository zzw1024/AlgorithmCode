////#include <iostream>
////#include <cmath>
////using namespace std;
////int rankList[10000] = {0};//存储排名
////bool check[10000] = { false };//是否已经查询过
////int n, k, id;
////bool isPrime(int x)
////{
////	if (x <= 3)
////		return x > 1;
////	for (int i = 2; i*i <= x; ++i)
////		if (x%i == 0)
////			return false;
////	return true;
////}
////int main()
////{
////	cin >> n;
////	for (int i = 1; i <= n; ++i)
////	{
////		cin >> id;
////		rankList[id] = i;
////	}
////	cin >> k;
////	while (k--)
////	{
////		cin >> id;
////		if (rankList[id] == 0)
////			printf("%04d: Are you kidding?\n", id);
////		else if (check[id] == true)
////			printf("%04d: Checked\n", id);
////		else if (rankList[id] == 1)
////			printf("%04d: Mystery Award\n", id);
////		else if (isPrime(rankList[id]))
////			printf("%04d: Minion\n", id);
////		else
////			printf("%04d: Chocolate\n", id);
////		check[id] = true;
////	}
////	return 0;
////}
//
//
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//bool isPrime(int x)
//{
//	if (x < 2)
//		return false;
//	for (int i = 2; i*i <= x; ++i)
//		if (x%i == 0)
//			return false;
//	return true;
//}
//int main()
//{
//	int n, id;
//	cin >> n;
//	int student[10010] = { 0 };
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> id;
//		student[id] = i;
//	}
//	cin >> n;
//	while (n--)
//	{
//		cin >> id;
//		if (student[id] > 0)
//		{
//			if (student[id] == 1)
//				printf("%04d: Mystery Award\n", id);
//			else if (isPrime(student[id]))
//				printf("%04d: Minion\n", id);
//			else
//				printf("%04d: Chocolate\n", id);
//			student[id] = -1;
//		}
//		else if (student[id] == -1)
//			printf("%04d: Checked\n", id);
//		else
//			printf("%04d: Are you kidding?\n", id);
//	}
//	return 0;
//}