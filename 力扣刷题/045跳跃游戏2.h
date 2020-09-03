#include "000库函数.h"


//考虑当前最远能到什么地方，例如2, 3, 1, 1, 4，
//首先只考虑a[0] = 2，即最远可以到a[2]，然后从1到2中找下一个可到的最远点，
//即a[1]可以到达a[4]，此时找到结果，步数记录为2。若接着考虑，
//下一次应该从3 - 4里面找一个最远即a[4]可达a[8]（4 + 4）, 
//再下一次从5 - 8中找最远
//20ms
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() < 2)return 0;
		int min = 0;
		int a = 0, b = 0 + nums[0];//第一步和下一步的坐标
		while (a < nums.size() - 1) {
			min++;	
			int s = MAX(nums, a + 1, b);	//在a,b中找到最远距离
			a = b;
			b = s;
		}
		return min;
	}
	int MAX(vector<int>& nums, int s, int t) {
		int max = s + nums[s];
		for (; s < nums.size() && s <= t; ++s) {
			if (max < s + nums[s])
				max = s + nums[s];
		}
		return max;
	}
};

//博客解法  20ms
//解法的思想一样，找到跳的最远的那个
class Solution {
public:
	int jump(vector<int>& nums) {
		int res = 0, n = nums.size(), i = 0, cur = 0;
		while (cur < n - 1) {
			++res;
			int pre = cur;
			for (; i <= pre; ++i) {
				cur = max(cur, i + nums[i]);
			}
			if (pre == cur) return -1; // May not need this
		}
		return res;
	}
};


class Solution {
public:
	int jump(vector<int>& nums) {
		int res = 0, n = nums.size(), last = 0, cur = 0;
		for (int i = 0; i < n - 1; ++i) {
			cur = max(cur, i + nums[i]);
			if (i == last) {
				last = cur;
				++res;
				if (cur >= n - 1) break;
			}
		}
		return res;
	}
};
void T045() {
	Solution s;
	vector<int>v;
	v = { 5,5,3,2,1,0,2,3,3,10,0,0 };
	cout << s.jump(v) << endl << "**************" << endl;
	v = { 2,0,2,4,6,0,0,3};
	cout << s.jump(v) << endl << "**************" << endl;
	v = { 2,3,0,1,4 };
	cout << s.jump(v) << endl << "**************" << endl;
	v = { 2,3,1,1,4 };
	cout << s.jump(v) << endl << "**************" << endl;
}