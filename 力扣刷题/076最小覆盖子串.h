
#include "_000�⺯��.h"

//����ʱ��
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		if (s.empty() || t.empty())return "";
//		string ttrs = t;
//		string temp = "";//���ڴ����ʱ���ַ���
//		string res = s+" ";//���ڴ�Ŵ�
//		int p = 0;
//		int flag = 0;//��ʼ��¼���ݱ�־
//		for (int i = p; i < s.size(); ++i) {
//			int ff = ttrs.find(s[i]);			
//			if (ff >= 0) {
//				flag = 1;
//				temp += s[i];
//				ttrs.erase(ff, 1);
//				if (ttrs.size() == t.size() - 2)
//					p = --i;//��¼��һ�α�����λ��
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


//ʹ������ӳ��
class Solution {
public:
	string minWindow(string s, string t) {
		if (s.empty() || t.empty())return "";
		string res = s + " ";//���ڴ�Ŵ�
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
		if (res.size() > s.size())return "";//������
		return res;
	}
};


//ʹ�û�������
//�����ʼ��ɨ��һ��T���Ѷ�Ӧ���ַ�������ֵĴ����浽 HashMap �С�
//
//- Ȼ��ʼ����S���Ͱѱ���������ĸ��Ӧ�� HashMap �е� value ��һ�������1���Դ��ڵ���0��cnt ����1��
//
//- ��� cnt ����T������ʱ����ʼѭ������¼һ���ִ���������С�ִ�ֵ��Ȼ���Ӵ��ڵ���߽������ƣ����ĳ���Ƴ�������ĸ��T���в���ȱ�ٵ���ĸ����ô cnt �Լ�1����ʾ��ʱT����û����ȫƥ�䡣
//
//�ⷨһ��

class Solution {
public:
	string minWindow(string s, string t) {
		string res = "";
		unordered_map<char, int> letterCnt;
		int left = 0, cnt = 0, minLen = INT_MAX;
		for (char c : t) ++letterCnt[c];//��¼�Ӵ��е���ͬ��ĸ����
		for (int i = 0; i < s.size(); ++i) {
			if (--letterCnt[s[i]] >= 0) ++cnt;
			while (cnt == t.size()) {
				if (minLen > i - left + 1) {
					minLen = i - left + 1;
					res = s.substr(left, minLen);
				}
				if (++letterCnt[s[left]] > 0) --cnt;//�����ظ�����ĸ
				++left;
			}
		}
		return res;
	}
};



//�����Ҳ���Բ��� HashMap��ֱ���ø� int �����������棬��Ϊ ASCII ֻ��256���ַ���
//�����ø���СΪ256��int���鼴�ɴ��� HashMap��������һ��������ĸ�����ַ�ֻ��128����
//����Ҳ����ֻ��128�����ಿ�ֵ�˼·��ȫ��ͬ����Ȼֻ����һ�����ݽṹ�����������ٶ������һ����
//˵�����黹�Ǳ� HashMap �찡���������£�


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
