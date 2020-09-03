////#include <iostream>
////using namespace std;
//////貌似有规律，因为数字为0-N-1，当有m个数字位于自己的位置上，则需要交换的次数为m-1
//////但得考虑0在不在0位上
////int m = 0, N, nums[100005], flag = 1, index = 1;
////int main()
////{
////	cin >> N;
////	for (int i = 0; i < N; ++i)
////		cin >> nums[i];
////
////	while (index<N)
////	{
////		while (nums[0] != 0)
////		{
////			swap(nums[0], nums[nums[0]]);
////			++m;
////		}
////		for (; index < N; ++index)//使用index，不用每次从0开始遍历
////		{
////			if (index != nums[index])
////			{
////				swap(nums[0], nums[index]);
////				++m;
////				break;
////			}
////		}		
////	}
////	cout << m << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, res = 0, pot = 1, position[100010] = { 0 };
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		int a;
//		cin >> a;
//		position[a] = i;
//
//	}
//	while(true)
//	{
//		while (position[0]!=0)
//		{
//			swap(position[0], position[position[0]]);
//			res++;
//		}
//		for (; pot < n; ++pot)
//			if (position[pot] != pot)
//			{
//				swap(position[0], position[pot]);
//				res++;
//				break;
//			}
//		if (pot ==n)
//			break;
//	}
//	cout << res << endl;
//	return 0;
//}
//
//
//
