#include "000库函数.h"


//使用回溯法来计算
//经典解法为回溯递归，一层一层的向下扫描，需要用到一个pos数组，
//其中pos[i]表示第i行皇后的位置，初始化为 - 1，然后从第0开始递归，
//每一行都一次遍历各列，判断如果在该位置放置皇后会不会有冲突，以此类推，
//当到最后一行的皇后放好后，一种解法就生成了，将其存入结果res中，
//然后再还会继续完成搜索所有的情况，代码如下：17ms
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {		
		vector<vector<string>>res;
		vector<int>pos(n, -1);
		NQueue(res, pos, 0);
		return res;
	}
	
	void NQueue(vector<vector<string>>&res, vector<int>&pos, int t) {
		int n = pos.size();
		if (t == n) {//组合成功
			vector<string>v(n, string(n, '.'));//这初始化绝逼了
			for (int i = 0; i < n; ++i)
				v[i][pos[i]] = 'Q';
			res.push_back(v);
		}
		else
			for (int k = 0; k < n; ++k)
				if (Danger(pos, t, k)) {
					pos[t] = k;
					NQueue(res, pos, t + 1);
					pos[t] = -1;//切记，关键点，回溯
				}
	}

	bool Danger(vector<int>pos, int t, int k) {
		for (int i = 0; i < t; ++i)
			if (pos[i] == k || abs(t - i) == abs(pos[i] - k))
				return false;
		return true;
	}

};


//通过使用排列进行判断是否可行进行求解
//但是太耗时了，还是用回溯法吧
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>>res;
		vector<int>nums;
		for (int i = 0; i < n; ++i)
			nums.push_back(i);

		if (Danger(nums)) {
			vector<string>v;
			for (int i = 0; i < n; ++i) {
				string s = "";
				for (int k = 0; k < nums[i]; ++k)
					s += '.';
				s += 'Q';
				for (int k = nums[i] + 1; k < n; ++k)
					s += '.';
				v.push_back(s);
			}
			res.push_back(v);
		}
		while (next_permutation(nums.begin(), nums.end())) {
			if (Danger(nums)) {
				vector<string>v;
				for (int i = 0; i < n; ++i) {
					string s = "";
					for (int k = 0; k < nums[i]; ++k)
						s += '.';
					s += 'Q';
					for (int k = nums[i] + 1; k < n; ++k)
						s += '.';
					v.push_back(s);
				}
				res.push_back(v);
			}
		}
		return res;
	}
				


	bool Danger(vector<int>nums) {//用来判断是否可行
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < nums.size(); ++j) {
				if (j == i)continue;
				if ((j + nums[j]) == (i + nums[i]) || (i - nums[i]) == (j - nums[j]))
					return false;
			}
		}
		return true;
	}
					

};


void T051() {
	Solution s;
	vector<vector<string>>v;
	int n;
	n = 5;
	v = s.solveNQueens(n);
	for (auto &a : v) {
		for (auto b : a)
			cout << b << endl;
		cout << "//////////////////////////" << endl;
	}
	
}