//#include "000库函数.h"
//
////这道题让我们求下一个排列顺序，由题目中给的例子可以看出来，
////如果给定数组是降序，则说明是全排列的最后一种情况，则下一个排列就是最初始情况，
////有如下的一个数组
////1　　2　　7　　4　　3　　1
////下一个排列为：
////1　　3　　1　　2　　4　　7
////那么是如何得到的呢，我们通过观察原数组可以发现，
////如果从末尾往前看，数字逐渐变大，到了2时才减小的，
////然后再从后往前找第一个比2大的数字，是3，那么我们交换2和3，
////再把此时3后面的所有数字转置一下即可，步骤如下：
//
//
//class Solution {
//public:
//	void nextPermutation(vector<int>& nums) {
//		if (nums.size() < 2)return;
//		int n = nums.size(), minN = n - 2, maxN = n - 1;
//		while (minN >= 0 && nums[minN] >= nums[minN + 1])
//			--minN;//找到从后向前不是递增的位置
//		if (minN<0)//原序列为倒序
//		{
//			sort(nums.begin(), nums.end());
//			return;
//		}
//		while (maxN >= 0 && nums[maxN] <= nums[minN])--maxN;
//		swap(nums[minN], nums[maxN]);
//		for (int i = minN + 1, j = n - 1; i <= j; ++i, --j)//反转后面的数字
//			swap(nums[i], nums[j]);
//	}
//};
//
//
////更简洁的版本
//class Solution {
//public:
//	void nextPermutation(vector<int>& nums) {
//		int n = nums.size(), minN = n - 2, maxN = n - 1;
//		while (minN >= 0 && nums[minN] >= nums[minN + 1])
//			--minN;//找到从后向前不是递增的位置
//		if (minN >= 0)
//		{
//			while (maxN >= 0 && nums[maxN] <= nums[minN])--maxN;
//			swap(nums[minN], nums[maxN]);
//		}
//		reverse(nums.begin() + minN + 1, nums.end());
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	vector<int>v = { 1,1 };
//	s.nextPermutation(v);
//	for (auto a : v)
//		cout << a << " ";
//	return 0;
//}