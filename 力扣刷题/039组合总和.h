#include "000库函数.h"

//第一感觉使用回溯比较快
//好激动，第一次使用回溯成功 96ms,37.1M


class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>>Res;
		if (candidates.size() == 0)return Res;			
		vector<int>v;//临时存放解			
		Combin(candidates, Res,v, target, 0, 0);		
		return Res;
	}

	void Combin(vector<int>candidates, vector<vector<int>>&Res, vector<int>&v, int target, int start, int sum) {
		if (sum == target) {
			Res.push_back(v);
			return;
		}
		else if (sum > target)
			return;
		for (int i = start; i < candidates.size(); ++i) {
			v.push_back(candidates[i]);
			Combin(candidates, Res, v, target, i, sum + candidates[i]);
			v.pop_back();//将数字退出
		}
	}

};


//博客答案
//解法一
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		for (int i = 0; i < candidates.size(); ++i) {
			if (candidates[i] > target) break;
			if (candidates[i] == target) { res.push_back({ candidates[i] }); break; }
			vector<int> vec = vector<int>(candidates.begin() + i, candidates.end());
			vector<vector<int>> tmp = combinationSum(vec, target - candidates[i]);
			for (auto a : tmp) {
				a.insert(a.begin(), candidates[i]);
				res.push_back(a);
			}
		}
		return res;
	}
};

//解法二
//建立一个三维数组dp，这里dp[i]表示目标数为i的所有解法集合。
//这里的i就从1遍历到target即可，对于每个i，我们都新建一个二维数组cur，
//然后遍历candidates数组，如果遍历到的数字大于i，说明当前及之后的数字都无法组成i，
//直接break掉。否则如果相等，那么把当前数字自己组成一个数组，并且加到cur中。
//否则就遍历dp[i - candidates[j] - 1] 中的所有数组，如果当前数字大于数组的首元素，
//则跳过，因为我们的结果要求是要有序的。否则就将当前数字加入数组的开头，
//并且将数组放入cur之中即可，参见代码如下：

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<vector<int>>> dp;
		sort(candidates.begin(), candidates.end());
		for (int i = 1; i <= target; ++i) {
			vector<vector<int>> cur;
			for (int j = 0; j < candidates.size(); ++j) {
				if (candidates[j] > i) break;
				if (candidates[j] == i) { cur.push_back({ candidates[j] }); break; }
				for (auto a : dp[i - candidates[j] - 1]) {
					if (candidates[j] > a[0]) continue;
					a.insert(a.begin(), candidates[j]);
					cur.push_back(a);
				}
			}
			dp.push_back(cur);
		}
		return dp[target - 1];
	}
};

void T039() {
	vector<int> v;	
	vector<vector<int>>Res;
	Solution s;
	v = { 2, 3, 6, 7 };
	Res = s.combinationSum(v, 7);
	for (auto &a : Res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl<<"*********"<< endl;
	v = { 2, 3,5 };
	Res = s.combinationSum(v, 8);
	for (auto &a : Res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl << "*********" << endl;



}