//#include "000库函数.h"
//
//
////与上一题大同小异，只不过不是排序数组
////同样使用双指针
//class Solution {
//public:
//	int removeElement(vector<int>& nums, int val) {
//		int pre = 0, cur = 0;
//		while (cur < nums.size())
//		{
//			if (nums[cur] == val)++cur;
//			else nums[pre++] = nums[cur++];
//		}
//		return pre;
//	}
//};
//
//class Solution {
//public:
//	int removeElement(int A[], int n, int elem) {
//		
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int>v = { 2,3,4 };
//	cout << s.removeElement(v,2) << endl;
//	for (auto a : v)
//		cout << a << " ";
//	return 0;
//}
