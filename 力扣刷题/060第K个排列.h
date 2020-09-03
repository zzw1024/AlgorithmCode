#include "_000库函数.h"

//一打眼看到题目描述，就想起用排列算法
//时间有点长588ms

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int>v;
		for (int i = 1; i <= n; ++i)
			v.push_back(i);
		--k;
		while (next_permutation(v.begin(), v.end()) && --k);
		string s = "";
		for (auto a : v)
			s += a + '0';
		return s;
	}
};

//用一下递归
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int>v;
		for (int i = 1; i <= n; ++i)
			v.push_back(i);
		Combin(v, 1, 0);
		string s = "";
		for (auto a : v)
			s += a + '0';
		return s;
	}
	void Combin(vector<int>&v, int k, int s) {
		if (!k)return;
		if (s >= v.size())--k;		
		for (int i = s; i < v.size(); ++i) {
			swap(v[i], v[s]);
			Combin(v, k, s + 1);
			swap(v[i], v[s]);
		}
	}
};
	
//博客答案，没怎么看懂
//后期看懂再更新
//12ms
class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		string num = "123456789";
		vector<int> f(n, 1);
		for (int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
		--k;
		for (int i = n; i >= 1; --i) {
			int j = k / f[i - 1];
			k %= f[i - 1];
			res.push_back(num[j]);
			num.erase(j, 1);
		}
		return res;
	}
};


void T060() {
	Solution s;
	cout << s.getPermutation(3, 3) << endl;
	cout << s.getPermutation(4, 9) << endl;
}