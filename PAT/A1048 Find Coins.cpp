////#include <iostream>
////#include <algorithm>
////#include <vector>
////#include <cstdlib>
////using namespace std;
////int N, M;
//////放法一，使用窗口函数
////int main()
////{
////	cin >> N >> M;
////	vector<int>nums(N);
////	vector<pair<int, int>>res;
////	for (int i = 0; i < N; ++i)
////		cin >> nums[i];
////	sort(nums.begin(), nums.end(), [](int a, int b) {return a < b; });
////	int l = 0, r = N - 1, m;
////	while (l < r)//找到中间的数刚好与M/2最接近
////	{
////		m = (l + r) / 2;
////		if (nums[m] <= M / 2 && nums[m + 1] > M / 2)
////			break;
////		if (nums[m] > M / 2)
////			r = m - 1;
////		else
////			l = m + 1;
////	}
////	r = m + 1;
////	l = m;
////	while(l>=0 && r<N)//然后使用窗口函数，进行左右移动
////	{ 
////		if (nums[l] + nums[r] == M)
////		{
////			res.push_back(make_pair(nums[l], nums[r]));
////			r++;
////		}
////		else if (nums[l] + nums[r] < M)
////			r++;
////		else
////			l--;
////	}
////	sort(res.begin(), res.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });
////	if (res.size() == 0)
////		cout << "No Solution" << endl;
////	else
////		cout << res[0].first << " " << res[0].second << endl;
////	return 0;
////}
////
//////方法二，使用数找数原理
////int main()
////{
////	cin >> N >> M;
////	int nums[1001], t;//根据题目要新建的数组大小
////	memset(nums, 0, sizeof(int) * 1001);
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> t;
////		nums[t]++;//统计个数
////	}
////	for (int i = 0; i < 1001; ++i)
////	{
////		if (nums[i] > 0)//个数大于0
////		{
////			nums[i]--;//使用掉一个数字
////			if (M > i && nums[M - i] > 0)
////			{
////				cout << i << " " << M - i << endl;//由最小值开始遍历，故为最优答案
////				return 0;
////			}
////			nums[i]++;//没有使用，还回去
////		}
////	}
////	cout << "No Solution" << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end());
//	int v1, v2, l = 0, r = n - 1;
//	while (l < r)
//	{
//		v1 = v[l];
//		v2 = v[r];
//		if (v1 + v2 == m)
//			break;
//		if (v1 + v2 > m)
//			r--;
//		else
//			l++;
//	}
//	if (v1 + v2 == m)
//		cout << v1 << " " << v2 << endl;
//	else
//		cout << "No Solution" << endl;
//	return 0;
//}