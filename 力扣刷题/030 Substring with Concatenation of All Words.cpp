//#include "000�⺯��.h"
//
//
////���뵽���ǣ��Ȱ�words�еĵ������������Ȼ����һ��һ�������Աȣ���ϧ����ʱ��
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
////ÿ�ν�ȡ�ַ������ַ���words�е��ַ����жԱ�
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
//			for (j = 0; j < n; ++j)//��Ҫlen��һ�鵥�ʽ���ƥ��n��
//			{
//				string str = s.substr(i + j * len, len);//��ȡ����
//				if (wordCnt[str] <= 0)break;//һ�����ڲ���ƥ�䣬�����˳�
//				++strCnt[str];//ͳ��ÿ�ֵ��ʵ�ƥ�����
//				if (strCnt[str] > wordCnt[str])break;//ƥ���������ڵĵ��ʸ�����ƥ��ʱ��ֱ���˳�
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