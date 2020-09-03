//#include "000¿âº¯Êý.h"
//
//class Solution {
//public:
//	vector<string> generateParenthesis(int n) {
//		vector<string>v;
//		permute(n, n, "", v);
//		return v;
//	}
//	void permute(int L, int R, string str, vector<string>&v)
//	{
//		if (L > R)return;
//		if (L == 0 && R == 0)v.push_back(str);
//		else
//		{
//			if (L > 0)permute(L - 1, R, str + '(', v);
//			if (R > 0)permute(L, R - 1, str + ')', v);
//		}
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	vector<string>res;
//	res = s.generateParenthesis(3);
//	for (auto a : res)
//		cout << a << endl;
//	return 0;
//
//
//}