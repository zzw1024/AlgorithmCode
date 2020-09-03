#include "_000库函数.h"

//使用动态规划
//  Ø d b b c a
//Ø T F F F F F
//a T F F F F F
//a T T T T T F
//b F T T F T F
//c F F T T T T
//c F F F T F T

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) return false;
		int n1 = s1.size(), n2 = s2.size();
		vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
		for (int i = 0; i <= n1; ++i) {
			for (int j = 0; j <= n2; ++j) {
				if (i == 0 && j == 0) {
					dp[i][j] = true;
				}
				else if (i == 0) {
					dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
				}
				else if (j == 0) {
					dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
				}
				else {
					dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
				}
			}
		}
		return dp[n1][n2];
	}
};

//使用带优化的DFS来做
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) return false;
		unordered_set<int> s;
		return helper(s1, 0, s2, 0, s3, 0, s);
	}
	bool helper(string& s1, int i, string& s2, int j, string& s3, int k, unordered_set<int>& s) {
		int key = i * s3.size() + j;
		if (s.count(key)) return false;
		if (i == s1.size()) return s2.substr(j) == s3.substr(k);
		if (j == s2.size()) return s1.substr(i) == s3.substr(k);
		if ((s1[i] == s3[k] && helper(s1, i + 1, s2, j, s3, k + 1, s)) ||
			(s2[j] == s3[k] && helper(s1, i, s2, j + 1, s3, k + 1, s))) return true;
		s.insert(key);
		return false;
	}
};

//使用BFS
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) return false;
		int n1 = s1.size(), n2 = s2.size(), n3 = s3.size(), k = 0;
		unordered_set<int> s;
		queue<int> q{ {0} };
		while (!q.empty() && k < n3) {
			int len = q.size();
			for (int t = 0; t < len; ++t) {
				int i = q.front() / n3, j = q.front() % n3; q.pop();
				if (i < n1 && s1[i] == s3[k]) {
					int key = (i + 1) * n3 + j;
					if (!s.count(key)) {
						s.insert(key);
						q.push(key);
					}
				}
				if (j < n2 && s2[j] == s3[k]) {
					int key = i * n3 + j + 1;
					if (!s.count(key)) {
						s.insert(key);
						q.push(key);
					}
				}
			}
			++k;
		}
		return !q.empty() && k == n3;
	}
};


void T097()
{
	Solution s;
	string s1, s2, s3;
	s1 = "aabcc";
	s2 = "dbbca";
	s3 = "aadbbcbcac";
	cout << s.isInterleave(s1, s2, s3) << endl;

	s1 = "aabcc";
	s2 = "dbbca";
	s3 = "aadbbbaccc";
	cout << s.isInterleave(s1, s2, s3) << endl;

	s1 = "aabaac";
	s2 = "aadaaeaaf";
	s3 = "aadaaeaabaafaac";
	cout << s.isInterleave(s1, s2, s3) << endl;

	s1 = "aa";
	s2 = "ab";
	s3 = "aaba";
	cout << s.isInterleave(s1, s2, s3) << endl;

	s1 = "aabc";
	s2 = "abad";
	s3 = "aabaabdc";
	cout << s.isInterleave(s1, s2, s3) << endl;

	s1 = "aacaac";
	s2 = "aacaaeaac";
	s3 = "aacaacaaeaacaac";
	cout << s.isInterleave(s1, s2, s3) << endl;
}

