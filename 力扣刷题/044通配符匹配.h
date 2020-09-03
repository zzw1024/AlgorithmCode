#include "000库函数.h"

//此为博客讲解
//p串中星号的位置很重要，用jStar来表示，还有星号匹配到s串中的位置，
//使用iStart来表示，这里 iStar 和 jStar 均初始化为 - 1，表示默认情况下是没有星号的。
//然后再用两个变量i和j分别指向当前s串和p串中遍历到的位置。
//
//开始进行匹配，若i小于s串的长度，进行while循环。若当前两个字符相等，
//或着p中的字符是问号，则i和j分别加1。若p[j] 是星号，那么我们要记录星号的位置，
//pStar赋为j，此时j再自增1，iStar赋为i。若当前p[j] 不是星号，并且不能跟p[i] 匹配上，
//那么此时就要靠星号了，若之前星号没出现过，那么就直接跪，比如 s = "aa" 和 p = "c*"，
//此时 s[0] 和 p[0] 无法匹配，虽然p[1] 是星号，但还是跪。如果星号之前出现过，可以强行续一波命，
//比如 s = "aa" 和 p = "*c"，当发现 s[1] 和 p[1] 无法匹配时，但是好在之前 p[0] 出现了星号，
//我们把 s[1] 交给 p[0] 的星号去匹配。至于如何知道之前有没有星号，这时就能看出 iStar 的作用了，
//因为其初始化为 - 1，而遇到星号时，其就会被更新为i，那么我们只要检测 iStar 的值，
//就能知道是否可以使用星号续命。虽然成功续了命，匹配完了s中的所有字符，但是之后我们还要检查p串，
//此时没匹配完的p串里只能剩星号，不能有其他的字符，将连续的星号过滤掉，如果j不等于p的长度，
//则返回false，参见代码如下：


//60ms
class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, iStar = -1, jStar = -1;
		while (i < s.size()) {
			if (s[i] == p[j] || p[j] == '?') {
				++i; ++j;
			}
			else if (p[j] == '*') {
				iStar = i;
				jStar = j++;
			}
			else if (iStar >= 0) {
				i = ++iStar;
				j = jStar + 1;
			}
			else return false;
		}
		while (p[j] == '*') ++j;
		return j == p.size();
	}
};


//使用动态规划
//260ms
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= n; ++i) {
			if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
				else {
					dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};

//使用递归思想
//有三种不同的状态，返回0表示匹配到了s串的末尾，但是未匹配成功；
//返回1表示未匹配到s串的末尾就失败了；返回2表示成功匹配。
//那么只有返回值大于1，才表示成功匹配。至于为何失败的情况要分类，
//就是为了进行剪枝。在递归函数中，若s串和p串都匹配完成了，返回状态2。
//若s串匹配完成了，但p串但当前字符不是星号，返回状态0。若s串未匹配完，
//p串匹配完了，返回状态1。若s串和p串均为匹配完，且当前字符成功匹配的话，
//对下一个位置调用递归。否则若p串当前字符是星号，那么我们首先跳过连续的星号
//。然后我们分别让星号匹配空串，一个字符，两个字符，....，直到匹配完整个s串
//，对每种情况分别调用递归函数，接下来就是最大的亮点了，也是最有用的剪枝，
//当前返回值为状态0或者2的时候，返回，否则继续遍历。如果我们仅仅是状态2的时候才返回，
//因为当返回值为状态0的时候，已经没有继续循环下去的必要了，非常重要的一刀剪枝，参见代码如下：


class Solution {
public:
	bool isMatch(string s, string p) {
		return helper(s, p, 0, 0) > 1;
	}
	int helper(string& s, string& p, int i, int j) {
		if (i == s.size() && j == p.size()) return 2;
		if (i == s.size() && p[j] != '*') return 0;
		if (j == p.size()) return 1;
		if (s[i] == p[j] || p[j] == '?') {
			return helper(s, p, i + 1, j + 1);
		}
		if (p[j] == '*') {
			if (j + 1 < p.size() && p[j + 1] == '*') {
				return helper(s, p, i, j + 1);
			}
			for (int k = 0; k <= (int)s.size() - i; ++k) {
				int res = helper(s, p, i + k, j + 1);
				if (res == 0 || res == 2) return res;
			}
		}
		return 1;
	}
};

class Solution {
public:
	bool isMatch(string s, string p) {
		int sIndex = 0, pIndex = 0;
		int sLength = s.size();
		int pLength = p.size();
		int match = 0;//记录遇到*号时，已经匹配到的下标位置
		int star = -1;//标记*号的位置
		//扫描s串
		while (sIndex < sLength) {
			if (pIndex < pLength && (s[sIndex] == p[pIndex] || p[pIndex] == '?')) {
				++sIndex;//遇到字符相同，或者？号
				++pIndex;
			}
			else if (pIndex < pLength && p[pIndex] == '*') {
				star = pIndex;//遇到*号，标记*号的位置
				match = sIndex;//记录已经匹配到s串的下标位置
				++pIndex;//首先当做匹配空字符串
			}
			else if (star != -1) {//如果标记到了*号，执行到此说一次没有匹配成功，此处将再次对*号处理的方法进行更换
				pIndex = star + 1;
				++match;//此处match每次自增一次，表示*号匹配的字符增加了一个，并进行下一次的尝试
				sIndex = match;//更新sIndex为*号匹配n个字符
			}
			else {
				return false;
			}
		}
		//处理多余的*号
		while (pIndex < p.length() && p[pIndex] == '*') {
			++pIndex;
		}
		return pIndex == pLength;
	}
};
-------------------- -
作者：hestyle
来源：CSDN
原文：https ://blog.csdn.net/qq_41855420/article/details/86772299 
版权声明：本文为博主原创文章，转载请附上博文链接！
void T044() {
	Solution sl;
	string s, p;
	s = "abefcdgiescdfimde";
	p = "ab*cd?i*de";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;

	s = "cb";
	p = "?a";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;
	s = "adceb";
	p = "*a*b";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;
	s = "aa";
	p = "a";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;
	s = "aa";
	p = "*";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;
	s = "acdcb";
	p = "a*c?b";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;

}