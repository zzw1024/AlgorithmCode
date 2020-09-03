////#include <iostream>
//////#include <vector>
////#include <map>
////#include <stack>
////using namespace std;
////
////int main()
////{
////	map<double, double,greater<double>>data;//从大到小排序
////	for (int i = 0; i < 2; ++i)//输入两组数据
////	{
////		int k;
////		cin >> k;
////		for (int j = 0; j < k; ++j)//接受每组数据
////		{
////			double a, b;
////			cin >> a >> b;
////			data[a] += b;
////			if (data[a] == 0)//系数为0则删除
////				data.erase(a);
////		}
////	}
////	cout << data.size();
////	for (auto ptr = data.begin(); ptr != data.end(); ++ptr)
////	{
////		cout << " " << ptr->first << " ";
////		printf("%.1f", ptr->second);
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <map>
//#include <cmath>
//using namespace std;
//int main()
//{
//	int k, n;
//	double num;
//	map<int, double, greater<int>>v;
//	for (int i = 0; i < 2; ++i)
//	{
//		cin >> k;
//		while (k--)
//		{
//			cin >> n >> num;
//			v[n] += num;
//			if (abs(v[n])<1e-8)//系数为0
//				v.erase(n);
//		}
//	}
//	cout << v.size();
//	for (auto ptr = v.begin(); ptr != v.end(); ++ptr)
//		printf(" %d %.1f", ptr->first, ptr->second);
//	
//	return 0;
//}
