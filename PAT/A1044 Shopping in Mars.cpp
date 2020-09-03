////#include <iostream>
////#include <vector>
////using namespace std;
//////暴力解法，复杂度为O(N)，没通过测试，超时
////int N, M;
////vector<int>value,sum;
////vector<pair<int, int>>res, minRes;//res存刚好切割值等于付款值，min存切割值为最小的
////void Way1()
////{
////	int minV = M;
////	for (int i = 1; i <= N; ++i)
////	{
////		int s = 0;
////		for (int j = i; j <= N; ++j)
////		{
////			s += value[j];
////			if (s < M)continue;
////			else if (s == M)
////				res.push_back(make_pair(i, j));
////			else if (s > M)
////			{
////				if (minV == (s - M))
////					minRes.push_back(make_pair(i, j));
////				else if (minV > (s - M))
////				{
////					minV = s - M;
////					minRes.clear();
////					minRes.push_back(make_pair(i, j));
////				}
////			}
////			break;
////		}
////	}	
////}
//////方法二，使用二分法
////int upper_bound(int L, int &tempS)
////{
////	int left = L, right = N, mid;
////	while (left < right)
////	{
////		mid = (left + right) / 2;
////		if (sum[mid]-sum[L-1] >= M)
////			right = mid;
////		else
////			left = mid + 1;
////	}
////	tempS = sum[right] - sum[L - 1];
////	return right;
////}
////
////void Way2()
////{
////	int minV = sum[N], tempS;
////	for (int i = 1; i <= N; ++i)//左端
////	{
////		int j = upper_bound(i, tempS);
////		if (tempS >minV)continue;
////		else if (tempS >= M)
////		{
////			if (tempS < minV)
////			{
////				res.clear();
////				minV = tempS;
////			}
////			res.push_back(make_pair(i, j));
////		}
////	}
////}
////
////int main()
////{
////	cin >> N >> M;
////	value.resize(N + 1);
////	sum.resize(N + 1);
////	for (int i = 1; i <= N; ++i)
////	{
////		cin >> value[i];
////		sum[i] = sum[i - 1] + value[i];
////	}
////	Way2();
////	if (res.size() > 0)
////		for (auto a : res)
////			cout << a.first << "-" << a.second << endl;
////	else
////		for (auto a : minRes)
////			cout << a.first << "-" << a.second << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, w, minW = INT32_MAX;
//	cin >> n >> w;
//	vector<int>v(n + 1);
//	vector<pair<int, int>>res, more;
//	for (int i = 1; i <= n; ++i)
//		cin >> v[i];
//	int l = 1, r = 1, sum = v[1];
//	while (l <= r && r <= n)
//	{
//		if (sum < w)
//		{
//			r++;
//			if (r > n)break;
//			sum += v[r];
//		}
//		else if (sum == w)
//		{
//			res.push_back(make_pair(l, r));
//			sum -= v[l];
//			l++;
//		}
//		else
//		{
//			if (sum < minW)
//			{
//				minW = sum;
//				more.clear();
//				more.push_back(make_pair(l, r));
//			}
//			else if (sum == minW)
//				more.push_back(make_pair(l, r));
//			if (l == r)//这个数>w
//			{
//				r++;				
//				if (r > n)break;
//				sum += v[r];
//			}
//			else
//			{
//				sum -= v[l];
//				l++;
//			}
//		}
//	}
//	if (res.size() == 0)
//		res = more;
//	for (auto a : res)
//		cout << a.first << "-" << a.second << endl;
//	return 0;
//}