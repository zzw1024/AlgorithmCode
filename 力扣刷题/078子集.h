#include "_000库函数.h"


//这道题就是求不同的子集问题
class solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty())return { {} };
		vector<vector<int>>res;
		res.push_back({});		
		for (int i = 1; i <= nums.size(); ++i) {
			vector<int>v;
			helper(nums, i, 0, v, res);//求不同个数的子集
		}
		return res;
	}

	void helper(vector<int>& nums, int k, int level, vector<int>&v, vector<vector<int>>&res) {
		if (v.size() == k) {
			res.push_back(v);
			return;
		}
		for (int i = level; i < nums.size(); ++i) {
			v.push_back(nums[i]);
			helper(nums, k, i + 1, v, res);
			v.pop_back();
		}
	}
	
};

//使用叠加方法
//每次在原数组的基础上加入后面的数字
//比如对于题目中给的例子[1, 2, 3]来说，最开始是空集，
//那么我们现在要处理1，就在空集上加1，为[1]，现在我们有两个自己[]和[1]，
//下面我们来处理2，我们在之前的子集基础上，每个都加个2，可以分别得到[2]，[1, 2]，
//那么现在所有的子集合为[], [1], [2], [1, 2]，同理处理3的情况可得[3], [1, 3], [2, 3], [1, 2, 3],
//再加上之前的子集就是所有的子集合了，代码如下：
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty())return { {} };
		vector<vector<int>>res;
		res.push_back({});
		for (int i = 0; i < nums.size(); ++i) {
			int n = res.size();
			for (int j = 0; j < n; ++j) {
				vector<int>v = res[j];
				v.push_back(nums[i]);//添加新的数据
				res.push_back(v);
			}
		}
		return res;
	}
};


void T078() {
	Solution s;
	vector<int>n = { 1,2,3 };
	vector<vector<int>>v;
	v = s.subsets(n);
	for (auto a : v) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
}