//#include "000¿âº¯Êý.h"
//
//class Solution {
//public:
//	int evalRPN(vector<string> &tokens) {
//		if (tokens.size() == 0)return 0;
//		stack<int>s;
//		for (auto a : tokens)
//		{
//			if (a == "+" || a == "-" || a == "*" || a == "/")
//			{
//				int num2 = s.top();
//				s.pop();
//				int num1 = s.top();
//				s.pop();
//				int res = 0;
//				if (a == "+")
//					res = num1 + num2;
//				else if (a == "-")
//					res = num1 - num2;
//				else if (a == "*")
//					res = num1 * num2;
//				else
//					res = num1 / num2;
//				s.push(res);
//			}
//			else
//				s.push(atoi(a.c_str()));
//		}
//		return s.top();
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<string>v = { "2", "1", "+", "3", "*" };
//	cout << s.evalRPN(v) << endl;
//	v = { "4", "13", "5", "/", "+" };
//	cout << s.evalRPN(v) << endl;
//	v = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
//	cout << s.evalRPN(v) << endl;
//	while (1);
//
//}