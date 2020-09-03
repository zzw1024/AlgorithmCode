#include "000库函数.h"


//笨方法，循环，遍历
//先将每个字母进行遍历，并给排序，这样就可以确定出有几种字符串，然后就可以开辟空间了
//然后给每个字符串进行找位子
//笨方法，时间久 864ms  ，内存大17.4M
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>>Res;
		vector<string>st;
		set<string>s;		
		for (auto a : strs) {
			sort(a.begin(), a.end());//给每个字符排序
			s.insert(a);//去除相同字母的组合
		}				
		st.assign(s.begin(), s.end());//将不相同的字符串储存下来
		Res.resize(s.size());//给Res开辟空间

		for (auto a : strs) {
			auto b = a;
			sort(b.begin(), b.end());//给每个字符排序
			for (int i = 0; i < st.size(); ++i)
				if (st[i] == b)
					Res[i].push_back(a);		
		}
		return Res;

	}
};

//思路和上面一样，代码简便点，减少了循环次数
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, int> mp;
		for (int i = 0, j = 0; i < strs.size(); i++) {
			string st = strs[i];
			sort(st.begin(), st.end());
			if (mp.find(st) != mp.end()) {
				res[mp[st]].push_back(strs[i]);
			}
			else {
				vector<string> tmp{ strs[i] };
				res.push_back(tmp);
				mp[st] = j++;
			}
		}
		return res;
	}
};

//用字典最好
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> m;
		for (string str : strs) {
			string t = str;
			sort(t.begin(), t.end());
			m[t].push_back(str);
		}
		for (auto a : m) {
			res.push_back(a.second);
		}
		return res;
	}
};


//下面这种解法没有用到排序，我们用一个大小为26的int数组来统计每个单词中字符出现的次数，
//然后将int数组转为一个唯一的字符串，跟字符串数组进行映射，这样我们就不用给字符串排序了，
//代码如下：
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> m;
		for (string str : strs) {
			vector<int> cnt(26, 0);
			string t = "";
			for (char c : str) ++cnt[c - 'a'];
			for (int d : cnt) t += to_string(d) + "/";//将数字转换为字母，与相面思想类似，t即为排了序的字符串
			m[t].push_back(str);
		}
		for (auto a : m) {
			res.push_back(a.second);
		}
		return res;
	}
};

void T049() {
	Solution s;
	vector<vector<string>>Res;
	vector<string>v;
	v = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Res = s.groupAnagrams(v);
	for (auto &a : Res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
}