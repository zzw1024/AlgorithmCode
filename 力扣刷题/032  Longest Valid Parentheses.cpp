//#include "000库函数.h"
//
//
////一看到括号我就想到栈了
//class Solution {
//public:
//	int longestValidParentheses(string s) {
//		stack<int>st;
//		int res = 0, start = 0, n = s.length();
//		for (int i = 0; i < n; ++i)
//		{
//			if (s[i] == '(')
//				st.push(i);
//			else
//			{
//				if (st.empty())
//					start = i + 1;//从下一位开始
//				else
//				{
//					st.pop();
//					res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());//这一步处理得很好
//				}
//			}
//		}
//		return res;
//	}
//};
//
////还有一种就是通过使用左右括号个数来统计配对括号的个数
////，使用了两个变量 left 和 right，分别用来记录到当前位置时左括号和右括号的出现次数，
////当遇到左括号时，left 自增1，右括号时 right 自增1。对于最长有效的括号的子串，
////一定是左括号等于右括号的情况，此时就可以更新结果 res 了，一旦右括号数量超过左括号数量了，
////说明当前位置不能组成合法括号子串，left 和 right 重置为0。但是对于这种情况 "(()" 时，
////在遍历结束时左右子括号数都不相等，此时没法更新结果 res，但其实正确答案是2，
////怎么处理这种情况呢？答案是再反向遍历一遍，采取类似的机制，稍有不同的是此时若 left 
////大于 right 了，则重置0，这样就可以 cover 所有的情况了
//
//class Solution {
//public:
//	int longestValidParentheses(string s) {
//		int res = 0, left = 0, right = 0, n = s.size();
//		for (int i = 0; i < n; ++i) {
//			(s[i] == '(') ? ++left : ++right;
//			if (left == right) res = max(res, 2 * right);
//			else if (right > left) left = right = 0;
//		}
//		left = right = 0;
//		for (int i = n - 1; i >= 0; --i) {
//			(s[i] == '(') ? ++left : ++right;
//			if (left == right) res = max(res, 2 * left);
//			else if (left > right) left = right = 0;
//		}
//		return res;
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.longestValidParentheses("(()") << endl;
//	cout << s.longestValidParentheses(")()())") << endl;
//	return 0;
//}