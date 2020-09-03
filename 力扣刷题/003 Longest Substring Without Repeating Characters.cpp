//#include "000库函数.h"
//
////使用unordered_map来记录重复字母出现的最右端位置，然后使用现在的位置减去重复字母位置，中间就是没有重复字母的子串了
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {			   
//		int res = 0, L = -1;
//		unordered_map<char, int>map;//用来记录字母出现的最右端位置
//		for (int i = 0; i < s.length(); ++i)
//		{
//			if (map.find(s[i]) != map.end())
//				L = max(L, map[s[i]]);
//			map[s[i]] = i;
//			res = max(res, i - L);
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	Solution p;
//	string s;
//	s = "abba";
//	cout << p.lengthOfLongestSubstring(s) << endl;
//	s = "bbbbbb";
//	cout << p.lengthOfLongestSubstring(s) << endl;
//	s = "pwwkew";
//	cout << p.lengthOfLongestSubstring(s) << endl;
//	s = " ";
//	cout << p.lengthOfLongestSubstring(s) << endl;
//	s = "abc";
//	cout << p.lengthOfLongestSubstring(s) << endl;
//	return 0;
//}