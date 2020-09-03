//#include "head.h"
//
//class Solution
//{
//public:
//	vector<string>conbine(const string str)
//	{
//		vector<string>res;
//		string word[10] = { "","abc","def","ghi","jkl","mno", "pqrs","tuv","wxyz","" };
//		string s = "";
//		helper(res, str, word, 0, s);
//		return res;
//	}
//
//	void helper(vector<string>&res, const string str, string word[], int index,string s)
//	{
//		if (index >= str.length())
//		{
//			res.push_back(s);
//			return;
//		}
//		for (int i = 0; i < word[str[index]-'0'].length(); ++i)
//		{
//			s += word[str[index] - '0'][i];
//			helper(res, str, word, index + 1, s);
//			s.erase(s.end()-1);
//		}
//	}
//
//};
//
//int main()
//{
//	Solution s;
//	vector<string>res;
//	res = s.conbine("12");
//	for (auto a : res)
//		cout << a << endl;
//
//	return 0;
//}#include "head.h"
//
//class Solution
//{
//public:
//	vector<string>conbine(const string str)
//	{
//		vector<string>res;
//		string word[10] = { "","abc","def","ghi","jkl","mno", "pqrs","tuv","wxyz","" };
//		string s = "";
//		helper(res, str, word, 0, s);
//		return res;
//	}
//
//	void helper(vector<string>&res, const string str, string word[], int index,string s)
//	{
//		if (index >= str.length())
//		{
//			res.push_back(s);
//			return;
//		}
//		for (int i = 0; i < word[str[index]-'0'].length(); ++i)
//		{
//			s += word[str[index] - '0'][i];
//			helper(res, str, word, index + 1, s);
//			s.erase(s.end()-1);
//		}
//	}
//
//};
//
//int main()
//{
//	Solution s;
//	vector<string>res;
//	res = s.conbine("12");
//	for (auto a : res)
//		cout << a << endl;
//
//	return 0;
//}