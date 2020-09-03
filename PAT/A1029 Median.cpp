////#include <iostream>
////using namespace std;
////int main()
////{
////	int res[200005], m, n, i, j, a, index = 0;
////	cin >> m;
////	for (i = 1; i <= m; ++i)
////		cin >> res[i];
////	cin >> n;
////	for (i = 1,j=1; i <= n; ++i)
////	{
////		cin >> a;
////		while (j <= m && a > res[j])
////		{
////			++index;
////			if (index == (m + n + 1) / 2)
////			{
////				cout << res[j] << endl;
////				return 0;
////			}
////			++j;
////		}
////		++index;
////		if (index == (m + n + 1) / 2)
////		{
////			cout << a << endl;
////			return 0;
////		}
////	}
////	while(j <= m)
////	{
////		++index;
////		if (index == (m + n + 1) / 2)
////		{
////			cout << res[j] << endl;
////			return 0;
////		}
////		++j;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<long int>v1, v2;
//long int getMedian()
//{
//	int i = 0, j = 0, s = 0;
//	long int res = 0;
//	while (i < v1.size() && j < v2.size())
//	{
//		if (v1[i] <= v2[j])
//		{
//			res = v1[i];
//			i++;
//			
//		}
//		else
//		{
//			res = v2[j];
//			j++;			
//		}
//		s++;
//		if (s == (v1.size() + v2.size() + 1) / 2)
//			return res;
//	}
//	while (i < v1.size())
//	{
//		i++; 
//		s++;
//		if (s == (v1.size() + v2.size() + 1) / 2)
//			return v1[i - 1];
//	}
//	while (j < v2.size())
//	{
//		j++;
//		s++;
//		if (s == (v1.size() + v2.size() + 1) / 2)
//			return v2[j - 1];
//	}
//	return res;
//}
//int main()
//{
//	int n, m;
//	
//	cin >> n;
//	while (n--)
//	{
//		cin >> m;
//		v1.push_back(m);
//	}
//	cin >> n;
//	while (n--)
//	{
//		cin >> m;
//		v2.push_back(m);
//	}
//	cout << getMedian() << endl;
//	return 0;
//}
//
