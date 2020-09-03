////#include <iostream>
////#include <vector>
////#include <cmath>
////using namespace std;
////int M, N;
////bool isPrime(int num)
////{
////	if (num <= 3)
////		return num > 1;
////	if (num % 6 != 1 && num % 6 != 5)
////		return false;
////	int s = (int)sqrt(num);
////	for (int i = 5; i <= s; ++i)
////		if (num % i == 0)
////			return false;
////	return true;
////}
////int main()
////{
////	cin >> M >> N;
////	while (!isPrime(M++));//找到素数
////	M--;
////	vector<int>table(M, 0);
////	int num, index;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> num;
////		index = num % M;
////		if (table[index] > 0)//存在冲突
////		{
////			for (int i = 1; i <= M; ++i)
////			{
////				index = (num + i * i) % M;
////				if (table[index] == 0)
////					break;		
////			}
////		}
////		if(table[index] == 0)//不存在冲突
////		{
////			table[index]++;
////			cout << index;
////		}
////		else
////			cout << "-";
////		if (i < N - 1)
////			cout << " ";
////	}
////	return 0;
////}
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
//	int n, m, num;
//	cin >> n >> m;
//	while (!isPrime(n))n++;
//	vector<bool>v(n, false);
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> num;
//		cout << (i == 0 ? "" : " ");
//		int flag = 1, index = num % n;
//		for (int i = 0; i <= n; ++i)
//		{
//			int index = (num + i * i) % n;
//			if (v[index] == false)
//			{
//				cout << index;
//				v[index] = true;
//				break;
//			}
//			else if (i == n)
//				cout << "-";
//		}
//	}
//	return 0;
//}