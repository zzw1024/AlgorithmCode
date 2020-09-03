#include "000库函数.h"


//自解1：
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)return 0;
		int j = 0;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != val)
				nums[j++] = nums[i];
		return j;
	}
};

/*****************************博客解******************/
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != val) nums[res++] = nums[i];
		}
		return res;
	}
};

void T027() {
	vector<int>nums = { 0,1,2,3,0,4,2 };
	Solution s;
	cout << s.removeElement(nums,2) << endl;
	for (int i = 0; i < s.removeElement(nums, 2); ++i)
		cout << nums[i] << '\t';
	cout << endl;
}