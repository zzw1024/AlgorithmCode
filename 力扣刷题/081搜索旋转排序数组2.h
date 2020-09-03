#include "_000库函数.h"

//mmp,没读懂题目，跟旋转有半毛钱关系呀？
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty())return false;
		for (auto a : nums)
			if (target == a)return true;
		return false;
	}
};

//看了博客才知道，所谓的旋转就是让你确定旋转位置后使用二分法进行查找
//因为使用普通的遍历复杂度太大
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty())return false;
		//首先使用二分法找到旋转点，
		//再使用二分法进行数字查找
		int left = 0, right = nums.size(), mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] == target)return true;
			if (nums[mid] < nums[right]) {
				if (nums[mid] < target && nums[right] >= target)left = mid + 1;
				else right = mid - 1;
			}
			else if (nums[mid] > nums[right]) {
				if (nums[left] <= target && nums[mid] > target)right = mid - 1;
				else left = mid + 1;
			}
			else --right;
		}

	}
};
