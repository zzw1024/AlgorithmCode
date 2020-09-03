#include "000库函数.h"

//第一眼，感觉没什么考虑算法的，就普通做就好了
//又因为是有序 的，故使用二分法最好了【别再太真爱用遍历，傻子才会一上来就遍历】    12ms
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0 || target < nums[0])return 0;//为空或者是太小，则在首位插入
		if (target > nums[nums.size() - 1])return nums.size();//太大在尾部插入
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)return mid;
			if (nums[mid] < target) left = mid + 1;//使用这种判断，会找到最左边的目标值
			else right = mid;
		}		
		return right;
	}
};

void T035() {
	Solution s;
	vector<int> nums = { 1,3,5,5,6 };
	cout << "*********************************" << endl;
	cout << s.searchInsert(nums, 4) << endl;
	cout << s.searchInsert(nums, 3) << endl;
	cout << s.searchInsert(nums, 5) << endl;
	cout << s.searchInsert(nums, 6) << endl;
	cout << s.searchInsert(nums, 7) << endl;

}


[[".", ".", ".", ".", "5", ".", ".", "1", "."],
[".", "4", ".", "3", ".", ".", ".", ".", "."],
[".", ".", ".", ".", ".", "3", ".", ".", "1"],
["8", ".", ".", ".", ".", ".", ".", "2", "."],
[".", ".", "2", ".", "7", ".", ".", ".", "."],
[".", "1", "5", ".", ".", ".", ".", ".", "."],
[".", ".", ".", ".", ".", "2", ".", ".", "."],
[".", "2", ".", "9", ".", ".", ".", ".", "."],
[".", ".", "4", ".", ".", ".", ".", ".", "."]]