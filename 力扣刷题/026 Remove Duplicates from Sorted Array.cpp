//#include "000库函数.h"
//
////使用vector的删除函数
//class Solution2 {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		for (int i = 1; i < nums.size(); ++i)
//			if (nums[i] == nums[i - 1])
//			{
//				nums.erase(nums.begin() + i);
//				--i;
//			}
//		return nums.size();
//	}
//};
//
////由于不能申请额外空间，所以，使用插入排序思想
//class Solution1 {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		int res = 0, n = nums.size();
//		for (int i = 1; i < n - res; ++i)
//		{
//			if (nums[i] == nums[i - 1])
//			{
//				++res;//统计重复的数字
//				int temp = nums[i], j = i + 1;
//				while (j < n - res + 1)//将重复的数字先后移动
//				{
//					nums[j - 1] = nums[j];
//					++j;
//				}
//				nums[j - 1] = temp;
//				--i;
//			}
//		}
//		nums.erase(nums.begin() + (n-res), nums.end());
//		return n - res;
//	}
//};
//
////弄了半天，不用删除nums的重复数字！！！
////只不过需要将不重复的数字放在前面
////使用双指针
//class Solution {
//public:
	//int removeDuplicates(vector<int>& nums) {
	//	int pre = 0, cur = 0, res = 0;
	//	while (cur < nums.size())
	//	{
	//		if (nums[pre] == nums[cur])
	//			++cur;
	//		else
	//		{
	//			nums[++res] = nums[cur];//将不同的数字移动到前面
	//			pre = cur;
	//		}
	//	}
	//	return nums.empty() ? 0 : res + 1;
	//}
//};
//
//
//int main()
//{
//	Solution s;
//	vector<int>v = { 1,1,1,2,2,3,3,3,3 };
//	cout << s.removeDuplicates(v) << endl;
//	for (auto a : v)
//		cout << a << " ";
//	return 0;
//}
