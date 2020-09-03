//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//int nums, k, m, n;
//vector<pair<int, int>>res;
//int divisor(int a, int b)//�����Լ��
//{
//	if (a%b == 0)
//		return b;
//	return divisor(b, a % b);
//}
//bool isPrime(int x)//�ж��ǲ��Ǵ��ڵ�����
//{
//	if (x <= 2)return false;
//	for (int i = 2; i*i <= x; ++i)
//		if (x%i == 0)return false;
//	return true;
//}
//int getSum(int x)
//{
//	int sum = 0;
//	while (x)
//	{
//		sum += x % 10;
//		x /= 10;
//	}
//	return sum;
//}
//bool check(int a)
//{	
//	int b = a + 1;
//	n = 0;
//	while (b)
//	{
//		n += b % 10;
//		b /= 10;
//	}
//	if (isPrime(divisor(m, n)))
//		return true;
//	else
//		return false;
//}
//void DFS(string &str, int index, int digit, int sum)
//{
//	if (index >= k || sum > m)return;//���ܳ���kλ����0��ʼ
//	if (sum + 9 * (k - index - 1) < m)return;//��index����̫С������������λ��ȫ����9��Ͷ��ﲻ��m
//	str[index] = digit + '0';//�ⲽҪд��ǰŶ����Ϊsum�Ѿ�������
//	if (sum == m && index == k - 1)//����Ҫ��
//	{
//		int a = stoi(str.c_str());
//		if (check(a))
//			res.push_back(make_pair(n, a));
//		return;
//	}
//	for (int i = 0; i < 10; ++i)
//		DFS(str, index + 1, i, sum + i);	
//}
//int main()
//{	
//	cin >> nums;
//	for (int i = 1; i <= nums; ++i)
//	{
//		cin >> k >> m;
//		res.clear();
//		string str(k, '0');
//		for (int j = 1; j < 10; ++j)
//			DFS(str, 0, j, j);//��һλ����Ϊ0
//		sort(res.begin(), res.end(), [](pair<int, int>v1, pair<int, int>v2) {//����
//			if (v1.first == v2.first)
//				return v1.second < v2.second;
//			return v1.first < v2.first;
//			});
//		printf("Case %d\n", i);
//		if (res.size() > 0)
//			for (auto a : res)
//				cout << a.first << " " << a.second << endl;
//		else
//			printf("No Solution\n");
//	}
//	return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//int cases, n, m, k;
//string str;
//vector<pair<int, int>>res;
//int gcd(int a, int b)
//{
//	return a % b == 0 ? b : gcd(b, a%b);
//}
//bool isPrime(int x)
//{
//	if (x < 3)return false;
//	for (int i = 2; i*i <= x; ++i)
//		if (x%i == 0)return false;
//	return true;
//}
//void DFS(int index,int digit, int sum)
//{
//	if (index >= k || sum > m || (sum + 9 * (k - index - 1)) < m)return;
//	str[index] = digit + '0';
//	if (index == k - 1 && sum == m)
//	{
//		int A = atoi(str.c_str());
//		int A1 = A + 1;
//		n = 0;
//		while (A1)
//		{
//			n += A1 % 10;
//			A1 /= 10;
//		}
//		if (isPrime(gcd(n, m)))
//			res.push_back(make_pair(n, A));		
//	}
//	for (int i = 0; i <= 9; ++i)
//		DFS(index + 1, i, sum + i);
//}
//int main()
//{
//	cin >> cases;
//	for (int i = 1; i <= cases; ++i)
//	{
//		printf("Case %d\n", i);
//		cin >> k >> m;
//		str.assign(k, '9');
//		res.clear();
//		for (int j = 1; j <= 9; ++j)
//			DFS(0, j, j);
//		sort(res.begin(), res.end(), [](pair<int, int>a, pair<int, int>b) {
//			if (a.first == b.first)
//				return a.second < b.second;
//			else
//				return a.first < b.first; });
//		if (res.size() > 0)
//			for (auto a : res)
//				printf("%d %d\n", a.first, a.second);
//		else
//			printf("No Solution\n");
//	}
//	return 0;
//}

//
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//int n, m, k, nums;
//string str;
//vector<pair<int, int>>res;
//int gcd(int a, int b)
//{
//	return a % b == 0 ? b : gcd(b, a%b);
//}
//bool isPrime(int x)
//{
//	if (x < 3)return false;
//	for (int i = 2; i*i <= x; ++i)
//		if (x%i == 0)return false;
//	return true;
//}
//void DFS(int index, int digit, int sum)
//{
//	if (index >= k || sum > m || sum + 9 * (k - index - 1) < m)return;
//	str[index] = digit + '0';
//	if (index == k - 1 && sum == m)
//	{
//		int n = 0;
//		int A = atoi(str.c_str());
//		int A1 = A + 1;
//		while (A1)
//		{
//			n += A1 % 10;
//			A1 /= 10;
//		}
//		if (isPrime(gcd(n, m)))
//			res.push_back(make_pair(n, A));
//	}
//	for (int i = 0; i <= 9; ++i)
//		DFS(index + 1, i, sum + i);
//}
//int main()
//{
//	cin >> nums;
//	for (int i = 1; i <= nums; ++i)
//	{
//		printf("Case %d\n", i);
//		cin >> k >> m;
//		res.clear();
//		str.assign(k, '1');
//		for (int j = 1; j <= 9; ++j)
//			DFS(0, j, j);
//		sort(res.begin(), res.end(), [](pair<int, int>a, pair<int, int>b) {
//			if (a.first == b.first)
//				return a.second < b.second;
//			else
//				return a.first < b.first; });
//		if (res.size() > 0)
//			for (auto a : res)
//				printf("%d %d\n", a.first, a.second);
//		else
//			printf("No Solution\n");
//	}
//	return 0;
//}