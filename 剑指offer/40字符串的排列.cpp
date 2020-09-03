//#include "head.h"
//
//
//class Solution01 {
//public:
//	vector<string> Permutation(string str) {
//		if (str.size() == 0)return {};
//		set<string>res;
//		DFS(str, 0, res);
//		vector<string>resV;
//		resV.assign(res.begin(), res.end());
//		return resV;
//	}
//	void DFS(string str, int index, set<string>&res)
//	{
//		if (index >= str.length())
//			res.insert(str);
//		for (int i = index; i < str.length(); ++i)
//		{
//			swap(str[i], str[index]);
//			DFS(str, index + 1, res);
//			swap(str[i], str[index]);
//		}
//	}
//};
//
//class Solution02 {
//public:
//	vector<string> Permutation(string str) {
//		if (str.size() == 0)return {};
//		set<string>res;
//		string s = "";
//		vector<bool>v(str.length(), false);
//		DFS(str, s, v, res);
//		vector<string>resV;
//		resV.assign(res.begin(), res.end());
//		return resV;
//	}
//	void DFS(const string str,string s, vector<bool>&v,set<string>&res)
//	{
//		if (s.length() == str.length())
//		{
//			res.insert(s);
//			return;
//		}		
//		for (int i = 0; i < str.length(); ++i)
//		{
//			if (v[i] == false)
//			{
//				v[i] = true;
//				s += str[i];
//				DFS(str,s, v, res);
//				s.erase(s.length() - 1);
//				v[i] = false;
//			}
//		}
//	}
//};
//
//int main()
//{
//	Solution s;
//	string str = "abs";
//	vector<string>res = s.Permutation(str);
//	for (auto a : res)
//		cout << a << endl;
//	return 0;
//}