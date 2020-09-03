//#include "head.h"
//
//class Solution01 {
//public:
//	int FirstNotRepeatingChar(string str) {
//		if (str.length() == 0)return -1;
//		vector<bool>v(str.length(), false);
//		vector<int>word(128, -1);
//		int res = 0;
//		for (int i = 0; i < str.length(); ++i)
//		{
//			if (word[str[i]] != -1)//出现了重复
//			{
//				v[i] = v[word[str[i]]] = true;//把前面重复和现在的字母毙了
//				while (v[res] == true && res < i)res++;//先后寻找没有重复的字母
//				if (res == i)res = -1;//都重复了
//			}
//			else if (res == -1)//出现了新字母
//				res = i;
//			word[str[i]] = i;
//		}
//		return res;
//	}
//};
//class Solution02 {
//public:
//	int FirstNotRepeatingChar(string str) {
//		if (str.length() == 0)return -1;
//		int res = 0;
//		int word[128] = { 0 };
//		for (int i = str.length() - 1; i >= 0; --i)
//		{
//			if (word[str[i]] == 0)//未出现重复
//				res = i;
//			else if (res != -1 && str[i] == str[res])//所有字母都是重复的
//			{
//				int k = res;
//				res = -1;
//				for (int i = k + 1; res == -1 && i < str.length(); ++i)//前面的字母都重复了，那么只能向后寻找希望了
//					if (word[str[i]] == 1)
//						res = i;
//			}
//			word[str[i]]++;
//		}
//		return res;
//	}
//};
//
//
//class Solution {
//public:
//	int FirstNotRepeatingChar(string str) {
//		if (str.length() == 0)return -1;
//		int word[128] = { 0 };
//		for (auto a : str)
//			word[a]++;
//		for (int i = 0; i < str.length(); ++i)
//			if (word[str[i]] == 1)
//				return i;
//		return -1;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	cout << s.FirstNotRepeatingChar("") << endl;
//	cout << s.FirstNotRepeatingChar("a") << endl;
//	cout << s.FirstNotRepeatingChar("abc") << endl;
//	cout << s.FirstNotRepeatingChar("abbac") << endl;
//	cout << s.FirstNotRepeatingChar("abcabc") << endl;
//	cout << s.FirstNotRepeatingChar("abccba") << endl;
//	cout << s.FirstNotRepeatingChar("abcvabc") << endl;
//	cout << s.FirstNotRepeatingChar("abcvcba") << endl;
//	cout << s.FirstNotRepeatingChar("abcabcv") << endl;
//	cout << s.FirstNotRepeatingChar("google") << endl;
//	return 0;
//}