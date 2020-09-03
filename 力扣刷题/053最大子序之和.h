#include "000库函数.h"

//一想到又是遍历
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res=nums[0];
		for (int i = 0; i < nums.size(); ++i) {
			int sum = nums[i];
			res = res > sum ? res : sum;
			for (int j = i + 1; j < nums.size(); ++j) {
				sum += nums[j];
				res = res > sum ? res : sum;
			}
		}
		return res;
	}
};

//使用滑窗来做
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = nums[0];
		int sum = -1;
		for (auto a : nums) {
			sum = max(a, sum + a);
			res = max(res, sum);
		}
		return res;
	}
};



//用分治法来计算，将数组一分为二，从中间来开始遍历

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
	int helper(vector<int>nums, int left, int right) {
		if (left >= right)return nums[left];
		int mid = (left + right) / 2;
		int lmax = helper(nums, left, mid - 1);//左移
		int rmax = helper(nums, mid + 1, right);//右移
		int mmax = nums[mid], t = mmax;
		for (int i = mid - 1; i >= left; --i) {//左移计算
			t += nums[i];
			mmax = mmax > t ? mmax : t;
		}
		t = mmax;
		for (int i = mid + 1; i <= right; ++i) {
			t += nums[i];
			mmax = mmax > t ? mmax : t;
		}
		return mmax > (rmax > lmax ? rmax : lmax) ? mmax : (rmax > lmax ? rmax : lmax);
	}
};

void T053() {
	Solution s;
	vector<int>v;
	v = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << s.maxSubArray(v) << endl;
}