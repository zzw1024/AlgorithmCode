//#include "000�⺯��.h"
//
//
////�ݹ鱩���ⷨ
//class Solution {
//public:
//	bool wordBreak(string s, unordered_set<string> &dict) {
//		vector<int>memo(s.size(),-1);
//		return check(s, dict, 0, memo);
//	}
//	bool check(string s, unordered_set<string>&dict, int index, vector<int>&memo)
//	{
//		if (index >= s.size())return true;
//		if (memo[index] != -1)return memo[index];
//		for (int i = index + 1; i <= s.size(); ++i)
//			if (dict.count(s.substr(index, i - index)) && check(s, dict, i, memo))//��֤��0��ʼ��ֵĵ��������ĵ����Ƿ�����ֵ���
//				return memo[index] = 1;
//		return memo[index] = 0;
//	}	
//};
//
////ʹ�ö���
//class Solution {
//public:
//	bool wordBreak(string s, unordered_set<string> &dict) {
//		vector<string> wordDict;
//		unordered_set<string>dict;
//		for (auto a : wordDict)
//			dict.insert(a);
//		vector<bool>dp(s.size() + 1, false);
//		dp[0] = true;//�߽�
//		for(int i=0;i<dp.size();++i)
//			for(int j=0;j<i;++j)
//				if (dp[j] && dict.count(s.substr(j, i - j)))//״̬ת�Ʒ���
//				{
//					dp[i] = true;
//					break;
//				}
//		return dp.back();
//	}
//};
//
//
