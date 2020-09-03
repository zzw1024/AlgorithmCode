//#include "000库函数.h"
//
//
////我想到的是，先把words中的单词组合起来，然后再一个一个遍历对比，可惜，超时了
//class Solution1 {
//public:
//	vector<int> findSubstring(string s, vector<string>& words) {
//		if (words.empty() || s.empty())return {};
//		vector<int>res;
//		unordered_map<string,bool>combins;
//		GetCombins(combins, words, 0);
//		int len = words[0].size()*words.size();
//		for (int i = 0; i < s.length(); ++i)
//		{
//			string str = s.substr(i, len);
//			if (combins[str])
//				res.push_back(i);
//		}
//		return res;
//	}
//	void GetCombins(unordered_map<string, bool>&combins, vector<string>& words,int index)
//	{
//		if (index >= words.size())
//		{
//			string str = "";
//			for (auto a : words)
//				str += a;
//			combins[str] = true;
//		}
//		for (int i = index; i < words.size(); ++i)
//		{
//			swap(words[i], words[index]);
//			GetCombins(combins, words, index + 1);
//			swap(words[i], words[index]);
//		}
//	}
//};
//
////每次截取字符串的字符对words中的字符进行对比
//class Solution {
//public:
//	vector<int> findSubstring(string s, vector<string>& words) {
//		if (s.empty() || words.empty())return{};
//		vector<int>res;
//		int n = words.size(), len = words[0].size();
//		unordered_map<string, int>wordCnt;
//		for (auto a : words)
//			wordCnt[a]++;
//		for (int i = 0; i <= (int)s.length() - n * len; ++i)
//		{
//			unordered_map<string, int>strCnt;
//			int j = 0;
//			for (j = 0; j < n; ++j)//需要len个一组单词进行匹配n次
//			{
//				string str = s.substr(i + j * len, len);//截取单词
//				if (wordCnt[str] <= 0)break;//一旦存在并不匹配，立即退出
//				++strCnt[str];//统计每种单词的匹配次数
//				if (strCnt[str] > wordCnt[str])break;//匹配次数与存在的单词个数不匹配时，直接退出
//			}
//			if (j == n)
//				res.push_back(i);
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<string>v = { "foo","bar" };
//	vector<int>res;
//	res = s.findSubstring("barfoothefoobarman",v);
//	for (auto a : res)
//		cout << a << " " << endl;
//	return 0;
//}