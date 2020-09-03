#include"_000库函数.h"


class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		if (nums.empty()) return {};
		vector<vector<int>> res(1);
		sort(nums.begin(), nums.end());
		int size = 1, last = nums[0];
		for (int i = 0; i < nums.size(); ++i) {
			if (last != nums[i]) {//去除重复数字
				last = nums[i];
				size = res.size();
			}
			int newSize = res.size();
			for (int j = newSize - size; j < newSize; ++j) {
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
	}
};

//使用二叉树递归
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &S) {
		if (S.empty()) return {};
		vector<vector<int>> res;
		vector<int> out;
		sort(S.begin(), S.end());
		getSubsets(S, 0, out, res);
		return res;
	}
	void getSubsets(vector<int> &S, int pos, vector<int> &out, vector<vector<int>> &res) {
		res.push_back(out);
		for (int i = pos; i < S.size(); ++i) {
			out.push_back(S[i]);
			getSubsets(S, i + 1, out, res);
			out.pop_back();
			while (i + 1 < S.size() && S[i] == S[i + 1]) ++i;//去除重复数据
		}
	}
};


void T090() {
	Solution s;
	vector<int>v = { 1,2,2 };
	vector<vector<int>> res;
	res = s.subsetsWithDup(v);
	for (auto &a : res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl;
}