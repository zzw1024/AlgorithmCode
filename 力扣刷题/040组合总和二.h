#include "000库函数.h"

//第一感觉使用回溯比较快
//96ms


class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>>R;
		sort(candidates.begin(), candidates.end());
		if (candidates.size() == 0)return R;
		vector<int>v;//临时存放解	
		Combin(candidates, R, v, target, 0, 0);		
		return R;
	}

	void Combin(vector<int>candidates, vector<vector<int>>&Res, vector<int>&v, int target, int start, int sum) {
		if (sum == target) {
			//sort(v.begin(), v.end());
			Res.push_back(v);
			return;
		}
		else if (sum > target)
			return;

		for (int i = start; i < candidates.size(); ++i) {
			if (i > start&&candidates[i] == candidates[i - 1])continue;//去除重复的组合			
			v.push_back(candidates[i]);
			Combin(candidates, Res, v, target, i + 1, sum + candidates[i]);//i+1是与上题的不同之处，不会出现重复使用元素
			v.pop_back();//将数字退出				
		}
	}

};

void T040() {
	vector<int> v;
	vector<vector<int>>Res;
	Solution s;
	v = {10,1,2,7,6,1,5 };
	Res = s.combinationSum2(v, 8);
	for (auto &a : Res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl << "*********" << endl;
	/*v = { 2, 3,5 };
	Res = s.combinationSum(v, 8);
	for (auto &a : Res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	cout << endl << "*********" << endl;
*/


}