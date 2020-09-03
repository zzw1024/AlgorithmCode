#include "000库函数.h"

//自解；
//这道题 的突破口就是找到words的组合情况
//然后将所有组合一一查找是否存在子串，还要对答案去重、查找相同子串不同位置出现！！！
//超出时间限制^_^，悲催，做了一个小时
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		set<int> R;//可以对答案进行去重！
		vector<int>Res;
		vector<string>v;
		if (s.size() == 0)return Res;
		Permutation(v, words, 0, words.size() - 1);
		for (int i = 0; i < v.size(); ++i) {
			string sub;
			sub = v[i];
			int a = s.find(sub);
			while (a >= 0) {
				R.insert(a);
				if(a+1<s.size())
					a = s.find(sub,a+1);//向后查找！！
			}			
		}
		Res.assign(R.begin(), R.end());
		return Res;

	}


	void swap(vector<string>& words, int k, int i) {
		string s;
		s = words[k];
		words[k] = words[i];
		words[i] = s;	
	}

	void Permutation(vector<string>&v, vector<string>&words,int k, int m)//使用递归对words进行全排列
	{
		if (k == m)
		{
			static int num = 1;  //局部静态变量，用来统计全排列的个数
			string s = "";
			for (int i = 0; i < words.size(); ++i)
				s += words[i];
			v.push_back(s);
			cout << "第" << num++ << "个排列为： " << v[v.size() - 1] << endl;
		}
		else
		{
			for (int i = k; i <= m; i++)
			{
				swap(words, k,i);
				Permutation(v,words,k+1, m);
				swap(words, k, i);
			}
		}
	}


};

//博客答案
//这道题我们需要用到两个哈希表，第一个哈希表先把所有的单词存进去，
//然后从开头开始一个个遍历，停止条件为当剩余字符个数小于单词集里所有字符的长度。
//这时候我们需要定义第二个哈希表，然后每次找出给定单词长度的子串，看其是否在第一个哈希表里，
//如果没有，则break，如果有，则加入第二个哈希表，但相同的词只能出现一次，如果多了，也break。
//如果正好匹配完给定单词集里所有的单词，则把i存入结果中，具体参见代码如下：
//400ms
 
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (s.empty() || words.empty()) return res;
		int n = words.size(), m = words[0].size();
		unordered_map<string, int> m1;
		for (auto &a : words) ++m1[a];//将单词存入哈希表中
		for (int i = 0; i <= (int)s.size() - n * m; ++i) {//大大减少了循环次数
			unordered_map<string, int> m2;
			int j = 0;
			for (j = 0; j < n; ++j) {
				string t = s.substr(i + j * m, m);//从s的0位开始向后截取一个单词长度的子串
				if (m1.find(t) == m1.end()) break;//未找到
				++m2[t];//
				if (m2[t] > m1[t]) break;
			}
			if (j == n) res.push_back(i);
		}
		return res;
	}
};

//这道题还有一种O(n)时间复杂度的解法，设计思路非常巧妙，但是感觉很难想出来，博主目测还未到达这种水平。
//这种方法不再是一个字符一个字符的遍历，而是一个词一个词的遍历，比如根据题目中的例子，字符串s的长度n为18，
//words数组中有两个单词(cnt = 2)，每个单词的长度len均为3，那么遍历的顺序为0，3，6，8，12，15，
//然后偏移一个字符1，4，7，9，13，16，然后再偏移一个字符2，5，8，10，14，17，这样就可以把所有情况都遍历到，
//我们还是先用一个哈希表m1来记录words里的所有词，然后我们从0开始遍历，用left来记录左边界的位置，
//count表示当前已经匹配的单词的个数。然后我们一个单词一个单词的遍历，如果当前遍历的到的单词t在m1中存在，
//那么我们将其加入另一个哈希表m2中，如果在m2中个数小于等于m1中的个数，那么我们count自增1，如果大于了，
//那么需要做一些处理，比如下面这种情况, s = barfoofoo, words = { bar, foo, abc }, 我们给words中新加了一个abc，
//目的是为了遍历到barfoo不会停止，那么当遍历到第二foo的时候, m2[foo] = 2, 而此时m1[foo] = 1，这是后已经不连续了，
//所以我们要移动左边界left的位置，我们先把第一个词t1 = bar取出来，然后将m2[t1]自减1，如果此时m2[t1] < m1[t1]了，
//说明一个匹配没了，那么对应的count也要自减1，然后左边界加上个len，这样就可以了。如果某个时刻count和cnt相等了，
//说明我们成功匹配了一个位置，那么将当前左边界left存入结果res中，此时去掉最左边的一个词，同时count自减1，
//左边界右移len，继续匹配。如果我们匹配到一个不在m1中的词，那么说明跟前面已经断开了，我们重置m2，count为0，
//左边界left移到j + len，参见代码如下：


//此解法牛逼，80ms

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (s.empty() || words.empty()) return {};
		vector<int> res;
		int n = s.size(), cnt = words.size(), len = words[0].size();
		unordered_map<string, int> m1;
		for (string w : words) ++m1[w];
		for (int i = 0; i < len; ++i) {//总共一个单词的长度
			int left = i, count = 0;//count
			unordered_map<string, int> m2;
			for (int j = i; j <= n - len; j += len) {//分为n/len个点位进行比较
				string t = s.substr(j, len);
				if (m1.count(t)) {
					++m2[t];
					if (m2[t] <= m1[t]) {
						++count;
					}
					else {
						while (m2[t] > m1[t]) {
							string t1 = s.substr(left, len);
							--m2[t1];
							if (m2[t1] < m1[t1]) --count;
							left += len;
						}
					}
					if (count == cnt) {//计数等于单词个数，说明匹配成功
						res.push_back(left);
						--m2[s.substr(left, len)];
						--count;
						left += len;
					}
				}
				else {
					m2.clear();
					count = 0;
					left = j + len;
				}
			}
		}
		return res;
	}
};

void T030() {
	string s = "foobarfoobar";
	vector<string> words = { "foo", "bar" };
	vector<int>Res;
	Solution sol;
	Res = sol.findSubstring(s, words);
	for (auto i : Res)
		cout << i << endl;
	   
}