//////靠，不需要是子排序，就是找数字就行
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int N;
////long long P;
////int main()
////{
////	cin >> N >> P;
////	vector<int>num(N);
////	for (int i = 0; i < N; ++i)
////		cin >> num[i];
////	sort(num.begin(), num.end());
////	int res = 0;
////	for(int L=0,R=0;L<=R && R<N;++R)
////	{
////		while (L <= R && num[R] > P * num[L])
////			L++;
////		res = res > R - L + 1 ? res : R - L + 1;		
////	}
////	cout << res << endl;
////	return 0;
////}
////
//
/////这道题就是傻逼，要求的不是子序列，只要满足条件的数越多越好
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, res = 0;
//	long long p;
//	cin >> n >> p;
//	vector<int>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end());
//	int L = 0, R = 0;
//	while (L <= R && R < n)
//	{
//		if (v[R]  <= p*v[L])
//		{
//			res = res > (R - L + 1) ? res : (R - L + 1);
//			R++;
//		}
//		else
//			L++;
//	}
//	cout << res;
//	return 0;
//}