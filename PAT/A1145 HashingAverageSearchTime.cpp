//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//bool isPrime(int x)
//{
//	for (int i = 2; i*i <= x; ++i)
//		if (x%i == 0)
//			return false;
//	return true;
//}
//int main()
//{
//	int n, m, k, x;
//	cin >> n >> m >> k;
//	while (!isPrime(n))++n;
//	vector<int>v(n, 0);
//	while (m--)
//	{
//		cin >> x;
//		bool flag = false;
//		for (int i = 0; i < n && flag == false; ++i)
//		{
//			if (v[(x + i * i) % n] == 0)
//			{
//				v[(x + i * i) % n] = x;
//				flag = true;
//			}
//		}
//		if (flag == false)
//			printf("%d cannot be inserted.\n", x);
//	}
//	double cnt = 0;
//	for (int i = 0; i < k; ++i)
//	{
//		cin >> x;
//		for (int j = 0; j <= n; ++j)
//		{
//			++cnt;
//			if (v[(x + j * j) % n] == x || v[(x + j * j) % n] == 0)//==0表示不存在，我就死在这点上了
//				break;
//		}
//	}
//	printf("%.1f", cnt / k);
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//bool isPrime(int x)
//{
//	if (x < 3)	return x > 0;
//	for (int i = 2; i*i <= x; ++i)
//		if (x%i == 0)return false;
//	return true;
//}
//int main()
//{
//	int size, n, m, b;
//	cin >> size >> n >> m;
//	while (!isPrime(size))++size;
//	vector<int>v(size, 0);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> b;
//		int k = 0;
//		for (k = 0; k < size; ++k)
//			if (v[(b + k * k) % size] == 0)
//				break;
//		if (k >= size)
//			printf("%d cannot be inserted.\n", b);
//		else
//			v[(b + k * k) % size] = b;
//	}
//	double res = 0.0;
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> b;
//		int k = 0;
//		for (; k < size; ++k)
//			if (v[(b + k * k) % size] == b || v[(b + k * k) % size] == 0)
//				break;
//		res += k + 1;
//	}
//	printf("%.1f\n", res / m);
//	return 0;
//}