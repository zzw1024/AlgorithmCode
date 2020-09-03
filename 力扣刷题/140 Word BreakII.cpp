//#include "000库函数.h"
//
////使用递归
//class Solution {
//public:
//	unordered_map<string, vector<string>>map;
//	vector<string> wordBreak(string s, unordered_set<string> &dict) {
//		if (map.find(s) != map.end())return map[s];
//		if (s.empty())return { "" };
//		vector<string>res;
//		for (auto word : dict)
//		{
//			if (s.substr(0, word.size()) != word)continue;
//			vector<string>rem = wordBreak(s.substr(word.size()), dict);
//			for (auto str : rem)
//				res.push_back(word + (str.empty() ? "" : " ") + str);
//		}
//		return map[s] = res;
//	}
//};
//
////使用动态规划
//class Solution {
//public:
//	vector<string> wordBreak(string s, unordered_set<string> &dict) {
//		vector<string>dp(s.size() + 1);
//		string inital = "";
//		dp[0] = inital;
//		for (int i = 1; i <= s.length(); ++i)
//		{
//			string str = "";
//			for (int j = 0; j < i; ++j)
//				if (dp[j].size() > 0 && dict.count(s.substr(j, i - j)))
//					for()
//		}
//	}
//};
//
//
//
//class Solution {
//public:
//	vector<string> wordBreak(string s, unordered_set<string> &dict) {
//		int len = s.length();
//		dp = new vector<bool>[len];
//		for (int pos = 0; pos < len; pos++) {
//			for (int i = 1; i < len - pos + 1; i++) {
//				if (dict.find(s.substr(pos, i)) != dict.end())
//					dp[pos].push_back(true);
//				else
//					dp[pos].push_back(false);
//			}
//		}
//		dfs(s, len - 1);
//		return res;
//	}
//	void dfs(string s, int n) {
//		if (n >= 0) {
//			for (int i = n; i >= 0; i--) {
//				if (dp[i][n - i]) {
//					mid.push_back(s.substr(i, n - i + 1));
//					dfs(s, i - 1);
//					mid.pop_back();
//				}
//			}
//		}
//		else {
//			string r;
//			for (int j = mid.size() - 1; j >= 0; j--) {
//				r += mid[j];
//				if (j > 0)
//					r += " ";
//			}
//			res.push_back(r);
//		}
//	}
//	vector<bool> *dp;
//	vector<string> res;
//	vector<string> mid;
//};
