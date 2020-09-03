////#include "000库函数.h"
////
////
//////使用二分法
////
////class Solution {
////public:
////	int search(vector<int>& nums, int target) {
////		int left = 0, right = nums.size() - 1;
////		while (left <= right)
////		{
////			int mid = left + (right - left) / 2;
////			if (nums[mid] == target)
////				return mid;
////			if (nums[left] <= nums[mid])//左边有序,记住，一定带等号，否则当有两个数的时候会出错
////			{
////				if (nums[left] <= target && nums[mid] > target)//目标在中间
////					right = mid - 1;
////				else
////					left = mid + 1;
////			}
////			else//右边有序
////			{
////				if (nums[mid] < target && nums[right] >= target)//在中间
////					left = mid + 1;
////				else
////					right = mid - 1;
////			}
////		}
////		return -1;
////	}
////};
////
////int main()
////{
////	Solution s;
////	vector<int>v;
////	v= { 1};
////	cout << s.search(v,3) << endl;
////	v = { 6,7,0,1,2,4,5 };
////	cout << s.search(v, 2) << endl;
////	return 0;
////}
//#include "000库函数.h"
//#include <Windows.h>
//int main()
//{
//	int L = 0, R = 10;
//	while (1)
//	{
//		int p = round(1.0*rand() / RAND_MAX * (R - L) + L);
//		int z = round(1.0*rand()/RAND_MAX*(R - L) + L);
//		int a = RAND_MAX;
//		cout << z << endl;
//		cout << p << endl;
//		Sleep(1000);
//	}
//	return 0;
//}