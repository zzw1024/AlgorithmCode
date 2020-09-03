//#include "000库函数.h"
//
//使用栈就行
//class Solution {
//public:
//	bool isValid(string s) {
//		stack<char>st;
//		for (int i = 0; i < s.length(); ++i)
//		{
//			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//				st.push(s[i]);
//			else if (st.empty())
//				return false;
//			else if (s[i] == ')'&&st.top() == '(' ||
//				s[i] == ']'&&st.top() == '[' ||
//				s[i] == '}'&&st.top() == '{')
//				st.pop();
//			else
//				return false;
//		}
//		return st.empty();			
//
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.isValid("]") << endl;
//	return 0;
//}