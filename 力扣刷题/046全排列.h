#include "000库函数.h"


//使用排序，感觉在作弊，但是题目没说不可以
//24ms
class solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>res;
		if (nums.empty())return res;
		sort(nums.begin(), nums.end());//排序
		do {
			res.push_back(nums);				
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};

//使用递归
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>Res;
		if (nums.empty())return Res;
		Combin(Res, nums, 0);//回溯
		return Res;
	}
	void Combin(vector<vector<int>>&Res, vector<int>v, int s) {
		if (s >= v.size()) //此处不return，在for中结束后自动结束
			Res.push_back(v);
			
		for (int i = s; i < v.size(); ++i) {
			swap(v[s], v[i]);//交换
			Combin(Res, v, s + 1);//回溯
			swap(v[s], v[i]);//换回来
		}
	}

};

////使用DFS递归
class Solution {
public:
	vector<vector<int>> permute(vector<int>& num) {
		vector<vector<int>> res;
		vector<int> out, visited(num.size(), 0);
		permuteDFS(num, 0, visited, out, res);
		return res;
	}
	void permuteDFS(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
		if (level == num.size()) { res.push_back(out); return; }//数字大小达到要求
		for (int i = 0; i < num.size(); ++i) {
			if (visited[i] == 1) continue;
			visited[i] = 1;//该数据已经选用
			out.push_back(num[i]);
			permuteDFS(num, level + 1, visited, out, res);
			out.pop_back();//回溯
			visited[i] = 0;
		}
	}
};

//当n = 1时，数组中只有一个数a1，其全排列只有一种，即为a1
//
//当n = 2时，数组中此时有a1a2，其全排列有两种，a1a2和a2a1，那么此时我们考虑和上面那种情况的关系，我们发现，其实就是在a1的前后两个位置分别加入了a2
//
//当n = 3时，数组中有a1a2a3，此时全排列有六种，分别为a1a2a3, a1a3a2, a2a1a3, a2a3a1, a3a1a2, 和 a3a2a1。那么根据上面的结论，实际上是在a1a2和a2a1的基础上在不同的位置上加入a3而得到的。
//
//_ a1 _ a2 _ : a3a1a2, a1a3a2, a1a2a3
//
//_ a2 _ a1 _ : a3a2a1, a2a3a1, a2a1a3
class Solution {
public:
	vector<vector<int>> permute(vector<int>& num) {
		vector<vector<int>> res;
		if (num.empty()) return res;		
		int first = num[0];
		num.erase(num.begin());//删除此数字
		vector<vector<int>> words = permute(num);
		for (auto &a : words) {
			for (int i = 0; i <= a.size(); ++i) {
				a.insert(a.begin() + i, first);
				res.push_back(a);
				a.erase(a.begin() + i);
			}
		}
		return res;
	}
};

void T046() {
	vector<int>n;
	Solution s;
	n = { 1,2,3 };
	for (auto &a : s.permute(n)) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}

}