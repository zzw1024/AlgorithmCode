////#include <iostream>
////#include <vector>
////#include <queue>
////using namespace std;
////int N, nums[100100], minN[100100], maxN[100100], res = 0, resNum[100100];//左边最大值（包括自己），右边最小值
////int main()
////{
////	cin >> N;
////	for (int i = 0; i < N; ++i)
////		cin >> nums[i];
//// 	for (int i = 1; i < N; ++i)//找到每个位置左边最大的值，不包括自己
////		maxN[i] = max(maxN[i - 1], nums[i - 1]);
////	minN[N - 1] = 9999999999;
////	for (int i = N-2; i >= 0; --i)//找到每个位置右边最小的值，不包括自己
////		minN[i] = min(minN[i + 1], nums[i + 1]);
////	for (int i = 0; i < N; ++i)
////		if (nums[i] > maxN[i] && nums[i] < minN[i])
////			resNum[res++] = nums[i];			
////	cout << res << endl;
////	for (int i = 0; i < res; ++i)
////		cout << resNum[i] << (i == res - 1 ? "" : " ");
////	cout << endl;
////	return 0;
////}
//
//
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n,  minN = INT32_MAX, maxN = INT32_MIN;
//	cin >> n;
//	vector<int>nums(n), maxL(n), minR(n), res;
//	for (int i = 0; i < n; ++i)
//		cin >> nums[i];
//	maxL[0] = nums[0] - 1, minR[n - 1] = nums[n - 1] + 1;
//	for (int i = 1, j = n - 2; i < n&& j >= 0; ++i, --j)
//	{
//		if (maxN < nums[i - 1])
//			maxN = nums[i - 1];
//		if (minN > nums[j + 1])
//			minN = nums[j + 1];
//		maxL[i] = maxN;
//		minR[j] = minN;
//	}
//	for (int i = 0; i < n; ++i)
//		if (maxL[i] <= nums[i] && nums[i] <= minR[i])
//			res.push_back(nums[i]);
//	sort(res.begin(), res.end());
//	cout << res.size() << endl;
//	for (int i = 0; i < res.size(); ++i)
//		cout << (i == 0 ? "" : " ") << res[i];
//	cout << endl;
//	return 0;
//}