////#include <iostream>
////#include <set>
////#include <string>
////using namespace std;
////int main()
////{
////	int n;
////	string s;
////	set<int>res;
////	cin >> n;
////	while (n--)
////	{
////		cin >> s;
////		int sum = 0;
////		for (auto a : s)
////			sum += a - '0';
////		res.insert(sum);
////	}
////	cout << res.size() << endl;
////	for (auto a : res)
////		cout << (a == *(res.begin()) ? "" : " ") << a;
////	cout << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <set>
//using namespace std;
//int main()
//{
//	int n, nums, sum;
//	cin >> n;
//	set<int>res;
//	while (n--)
//	{
//		cin >> nums;
//		sum = 0;
//		while (nums)
//		{
//			sum += nums % 10;
//			nums /= 10;
//		}
//		res.insert(sum);
//	}
//	cout << res.size() << endl;
//	for (auto ptr = res.begin(); ptr != res.end(); ++ptr)
//		cout << (ptr == res.begin() ? "" : " ") << *ptr;
//	return 0;
//}
