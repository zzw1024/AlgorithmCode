//#include "000�⺯��.h"
//
////ʹ��unordered_map����¼�ظ���ĸ���ֵ����Ҷ�λ�ã�Ȼ��ʹ�����ڵ�λ�ü�ȥ�ظ���ĸλ�ã��м����û���ظ���ĸ���Ӵ���
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {			   
//		int res = 0, L = -1;
//		unordered_map<char, int>map;//������¼��ĸ���ֵ����Ҷ�λ��
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