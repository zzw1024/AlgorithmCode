
#include "_000库函数.h"

//超出时长
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		if (s.empty() || t.empty())return "";
//		string ttrs = t;
//		string temp = "";//用于存放临时的字符串
//		string res = s+" ";//用于存放答案
//		int p = 0;
//		int flag = 0;//开始记录数据标志
//		for (int i = p; i < s.size(); ++i) {
//			int ff = ttrs.find(s[i]);			
//			if (ff >= 0) {
//				flag = 1;
//				temp += s[i];
//				ttrs.erase(ff, 1);
//				if (ttrs.size() == t.size() - 2)
//					p = --i;//记录下一次遍历的位置
//				if (ttrs.empty()) {
//					i = p;
//					if (res.size() > temp.size())
//						res = temp;
//					temp = "";
//					flag = 0;
//					ttrs = t;
//				}
//			}
//			if (ff == -1 && flag)temp += s[i];
//		}
//		if (res.size() <= s.size())
//			return res;
//		return "";
//	}
//};


//使用数组映射
class Solution {
public:
	string minWindow(string s, string t) {
		if (s.empty() || t.empty())return "";
		string res = s + " ";//用于存放答案
		vector<int>v(t.size(), -1);
		for (int i = 0; i < s.size(); ++i) {
			int pose = t.find(s[i]);
			if (pose == -1)continue;
			v[pose] = i;
			vector<int>temp = v;
			sort(temp.begin(), temp.end());
			if (temp[0] > -1) {
				int n = temp.back() - temp[0] + 1;
				if (n < res.size())
					res.assign(s, temp[0], n);
			}
		}
		if (res.size() > s.size())return "";//不存在
		return res;
	}
};


//使用滑动窗口
//我们最开始先扫描一遍T，把对应的字符及其出现的次数存到 HashMap 中。
//
//- 然后开始遍历S，就把遍历到的字母对应的 HashMap 中的 value 减一，如果减1后仍大于等于0，cnt 自增1。
//
//- 如果 cnt 等于T串长度时，开始循环，纪录一个字串并更新最小字串值。然后将子窗口的左边界向右移，如果某个移除掉的字母是T串中不可缺少的字母，那么 cnt 自减1，表示此时T串并没有完全匹配。
//
//解法一：

class Solution {
public:
	string minWindow(string s, string t) {
		string res = "";
		unordered_map<char, int> letterCnt;
		int left = 0, cnt = 0, minLen = INT_MAX;
		for (char c : t) ++letterCnt[c];//记录子串中的相同字母个数
		for (int i = 0; i < s.size(); ++i) {
			if (--letterCnt[s[i]] >= 0) ++cnt;
			while (cnt == t.size()) {
				if (minLen > i - left + 1) {
					minLen = i - left + 1;
					res = s.substr(left, minLen);
				}
				if (++letterCnt[s[left]] > 0) --cnt;//还有重复的字母
				++left;
			}
		}
		return res;
	}
};



//这道题也可以不用 HashMap，直接用个 int 的数组来代替，因为 ASCII 只有256个字符，
//所以用个大小为256的int数组即可代替 HashMap，但由于一般输入字母串的字符只有128个，
//所以也可以只用128，其余部分的思路完全相同，虽然只改了一个数据结构，但是运行速度提高了一倍，
//说明数组还是比 HashMap 快啊，代码如下：


class Solution {
public:
	string minWindow(string s, string t) {
		string res = "";
		vector<int> letterCnt(128, 0);
		int left = 0, cnt = 0, minLen = INT_MAX;
		for (char c : t) ++letterCnt[c];
		for (int i = 0; i < s.size(); ++i) {
			if (--letterCnt[s[i]] >= 0) ++cnt;
			while (cnt == t.size()) {
				if (minLen > i - left + 1) {
					minLen = i - left + 1;
					res = s.substr(left, minLen);
				}
				if (++letterCnt[s[left]] > 0) --cnt;
				++left;
			}
		}
		return res;
	}
};


void T076() {
	Solution sl;
	string s, t;
	s = "ADOBECODEBANC";
	t = "ABC";
	cout << sl.minWindow(s, t) << endl;
	s = "aaabbbbbbccccc";
	t = "abc";
	cout << sl.minWindow(s, t) << endl;
	s = "abbbca";
	t = "abc";
	cout << sl.minWindow(s, t) << endl;
	s = "aa";
	t = "aa";
	cout << sl.minWindow(s, t) << endl;
	s = "bba";
	t = "ab";
	cout << sl.minWindow(s, t) << endl;

}
