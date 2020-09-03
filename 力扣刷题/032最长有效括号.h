#pragma once
#include "000库函数.h"

//找到有效的最长括号，即返回最长有效括号的的字符长度
//自解法  
//一看,就想到用栈进栈出，然后字符长度-栈长就是最长括号长度了
//但是，想了想，不对，因为成对的括号还得是连对才行！不能中间个了失效的括号
//失败

//class Solution {
//public:
//	int longestValidParentheses(string s) {
//		if (s.size() < 2)return 0;//字符太短，无法组成括号
//		stack<char>str;
//		int count = 0;//用来计算最长有效括号的长度
//		int n1 = 0,n2 = 0;//计算局部成对的括号长度
//		for (int i = 0; i < s.size(); ++i) {
//			if (str.size() > 0 && s[i] == ')'&&'(' == str.top()) {//栈不空，遇到右括号，栈顶是左括号，匹配一个括号
//				str.pop();
//				n1 += 2;//因为括号是成对出现的
//			}
//			else if (s[i] == ')') {
//				if (str.empty()) n2 += n1;
//				count = count > n2 ? count : n2;// 存下最长匹配括号的子串
//				n2 = 0;////重新寻找最长子串
//				while (!str.empty())str.pop();
//			}
//			else {
//				if (!str.empty()) {
//					n2 += n1;
//					n1 = 0;
//				}
//				str.push(s[i]);//为左半括号，进栈
//			}
//			
//		}
//		if (!str.empty())
//			return count = count > n2 ? count : n2;
//		else
//			return count = count > n1 + n2 ? count : n1 + n2;		
//	}
//};

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() < 2)return 0;//字符太短，无法组成括号
		int start = 0, res = 0;
		stack<int>num;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(')num.push(i);
			else {
				if (num.empty())start = i + 1;
				else {
					num.pop();
					if (num.empty())res = res > i - start + 1 ? res : i - start + 1;
					else res = res > i - num.top() ? res : i - num.top();
				}
			}
		}
		return res;
	}
};

void T032() {
	string s;
	Solution sol;
	s = "(()";
	cout << s << endl;
	cout << sol.longestValidParentheses(s) << endl;
	s = ")()())";
	cout << s << endl;
	cout << sol.longestValidParentheses(s) << endl;
	s = ")((())()()((()))";
	cout << s << endl;
	cout << sol.longestValidParentheses(s) << endl;
}