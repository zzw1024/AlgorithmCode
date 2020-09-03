//#include "000库函数.h"
//
//- 若p为空，若s也为空，返回 true，反之返回 false。
//
//- 若p的长度为1，若s长度也为1，且相同或是p为 '.' 则返回 true，反之返回 false。
//
//- 若p的第二个字符不为 * ，若此时s为空返回 false，否则判断首字符是否匹配，
//  且从各自的第二个字符开始调用递归函数匹配。
//
//- 若p的第二个字符为 * ，进行下列循环，条件是若s不为空且首字符匹配（包括 p[0] 为点），
//  调用递归函数匹配s和去掉前两个字符的p（这样做的原因是假设此时的星号的作用是让前面
//  的字符出现0次，验证是否匹配），若匹配返回 true，否则s去掉首字母（因为此时首字母匹配了，
//  我们可以去掉s的首字母，而p由于星号的作用，可以有任意个首字母，所以不需要去掉），
//  继续进行循环。
//
//- 返回调用递归函数匹配s和去掉前两个字符的p的结果（这么做的原因是处理星号无法匹配的内容，
//  比如 s = "ab", p = "ab"，直接进入 while 循环后，我们发现 "ab" 和 "b" 不匹配，所以s变成 "b"，
//  那么此时跳出循环后，就到最后的 return 来比较 "b" 和 "b" 了，返回 true。再举个例子，
//  比如 s = "", p = "a"，由于s为空，不会进入任何的 if 和 while，只能到最后的 return 来比较了，
//  返回 true，正确）。
//
//
//
//class Solution {
//public:
//	bool isMatch(string s, string p) {
//		if (p.empty())return s.empty();
//		if (p.size() > 1 && p[1] == '*')//记住，‘*’打头没有任何用处
//		{
//			bool f1 = isMatch(s, p.substr(2));//即，将‘*’视为不起任何作用，直接匹配后面的字符
//			bool f2 = (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));//第一个匹配上了，之所以不去除p的第一个字母，是因为‘*’可以当作0个第一个字母匹配
//			return f1 || f2;
//			//return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
//		}
//		else//第二个字母不为‘*’，那么就一个个按要求匹配
//			return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));		
//	}
//};
//
//DP解法：
//	我们也可以用 DP 来解，定义一个二维的 DP 数组，
//	其中 dp[i][j] 表示 s[0, i) 和 p[0, j) 是否 match，
//	然后有下面三种情况：
//1.  dp[i][j] = dp[i - 1][j - 1]； if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//    即,字母不是为‘*’，且字符匹配上了,那就决定与前面的字符是否匹配上了
//2.  dp[i][j] = dp[i][j - 2]；if p[j - 1] == '*' and the pattern repeats for 0 times;
//	  即，前面的‘*’号作废，因为'*'前面的字符匹配上了
//3.  dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')；if p[j - 1] == '*' and the pattern repeats for at least 1 times.
//	  即，‘*’的前面字母与此时的字母匹配上了，那么就将‘*’前面的字母至少复制一次
//
//class Solution2 {
//public:
//	bool isMatch(string s, string p) {
//		if (p.empty())return s.empty();
//		int m = s.size(), n = p.size();
//		vector<vector<bool>>dp(m + 1, vector<bool>(n + 1, false));
//		dp[0][0] = true;//都为空时
//		for (int i = 0; i < m + 1; ++i)
//		{
//			for (int j = 1; j < n + 1; ++j)
//			{
//				if (p[j - 1] != '*')
//					dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
//				else
//					dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//			}
//		}
//		return dp[m][n];
//	}
//};
//
//
//
//int main()
//{
//	char c[] = "123456";
//	char *p = c;
//	int m = 0;
//	while (p[m] != '\0')++m;
//	int a = 0;
//
//}
//
//int maxMethodsDp(vector<int>arr, int aim)
//{
//	vector<vector<int>>dp(arr.size() + 1, vector<int>(aim + 1, 0));
//	dp[arr.size()][0] = 1;
//	for (int i = arr.size() - 1; i >= 0; --i)
//	{
//		for (int j = 0; j <= aim; ++j)
//		{
//			dp[i][j] = dp[i + 1][j];//i的面值取了0张
//			for (int subAim = j - arr[i]; subAim >= 0; subAim = subAim - arr[i])//i的面值取了1，2.。张
//				dp[i][j] = dp[i + 1][subAim];
//		}
//	}
//	return dp[0][aim];
//}
