//#include "head.h"
//
//
//class Solution {
//public:
//	string ReverseSentence(string str) {
//		if (str.length() < 2)return str;
//		stack<string>s;
//		int i = 0;
//		while(i<str.length()){
//			string temp = "";
//			while (i < str.length() && str[i] != ' ')temp += str[i++];
//			s.push(temp);
//			++i;
//		}
//		string res = "";
//		while (!s.empty()){
//			res += s.top() + (s.size() > 1 ? " " : "");
//			s.pop();
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.ReverseSentence("student. a am I") << endl;
//	return 0;
//}