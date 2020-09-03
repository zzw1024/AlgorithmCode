#include "000库函数.h"

//这与前面的跳跃游戏类似
//每次跳跃找出跳跃最远的位子，若能跳出，就一定能跳出
//运行成功16ms
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int left=0, right=nums[0]+0;
		while (right < n-1) {		
			int maxN = right;
			for (int k = left + 1; k <= right; ++k)//在之间找能跳出的最远位置
				maxN = maxN > (nums[k] + k) ? maxN : (nums[k] + k);
			left = right;
			right = maxN;
			if (left >= right)
				return false;
		}	
		return true;
	}

};

//与上题类似，但更简便
//只关心能跳到最远的位置
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size(), reach = 0;
		for (int i = 0; i < n; ++i) {
			if (i > reach || reach >= n - 1) break;
			reach = max(reach, i + nums[i]);
		}
		return reach >= n - 1;
	}
};

//使用动态规划
//到达当前位置的剩余步数跟什么有关呢，其实是跟上一个位置的剩余步数和上一个位置的跳力有关，
//这里的跳力就是原数组中每个位置的数字，因为其代表了以当前位置为起点能到达的最远位置。
//所以当前位置的剩余步数（dp值）和当前位置的跳力中的较大那个数决定了当前能到的最远距离，
//而下一个位置的剩余步数（dp值）就等于当前的这个较大值减去1，因为需要花一个跳力到达下一个位置，
//所以我们就有状态转移方程了：dp[i] = max(dp[i - 1], nums[i - 1]) - 1，
//如果当某一个时刻dp数组的值为负了，说明无法抵达当前位置，则直接返回false，
//最后循环结束后直接返回true即可，代码如下：
class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		for (int i = 1; i < nums.size(); ++i) {
			dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
			if (dp[i] < 0) return false;
		}
		return true;
	}
};



void T055() {
	Solution s;
	vector<int>v;
	v = { 0,1 };
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.canJump(v) << endl;
	v = { 3,4,0,1,0,0,3,0 };
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.canJump(v) << endl;
	v = { 3,4,2,1,0,7,5,2,8 };
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.canJump(v) << endl;
	v = { 2,3,1,1,4 };
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.canJump(v) << endl;
	v = { 3,2,1,8,4};
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.canJump(v) << endl;
}
