//#include "head.h"
//
//class Solution {
//public:
//	string PrintMinNumber(vector<int> numbers) {
//		if (numbers.size() == 0)return "";
//		vector<string>v;
//		for (auto a : numbers)
//			v.push_back(to_string(a));
//		sort(v.begin(), v.end(), [](string a, string b) {return a + b < b + a; });
//		string res = "";
//		for (auto s : v)
//			res += s;
//		while (res.size() > 0 && res[0] == '0')
//			res.erase(0, 1);
//		return res;
//	}
//};