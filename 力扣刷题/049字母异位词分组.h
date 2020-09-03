#include "000�⺯��.h"


//��������ѭ��������
//�Ƚ�ÿ����ĸ���б������������������Ϳ���ȷ�����м����ַ�����Ȼ��Ϳ��Կ��ٿռ���
//Ȼ���ÿ���ַ���������λ��
//��������ʱ��� 864ms  ���ڴ��17.4M
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>>Res;
		vector<string>st;
		set<string>s;		
		for (auto a : strs) {
			sort(a.begin(), a.end());//��ÿ���ַ�����
			s.insert(a);//ȥ����ͬ��ĸ�����
		}				
		st.assign(s.begin(), s.end());//������ͬ���ַ�����������
		Res.resize(s.size());//��Res���ٿռ�

		for (auto a : strs) {
			auto b = a;
			sort(b.begin(), b.end());//��ÿ���ַ�����
			for (int i = 0; i < st.size(); ++i)
				if (st[i] == b)
					Res[i].push_back(a);		
		}
		return Res;

	}
};

//˼·������һ����������㣬������ѭ������
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

//���ֵ����
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


//�������ֽⷨû���õ�����������һ����СΪ26��int������ͳ��ÿ���������ַ����ֵĴ�����
//Ȼ��int����תΪһ��Ψһ���ַ��������ַ����������ӳ�䣬�������ǾͲ��ø��ַ��������ˣ�
//�������£�
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> m;
		for (string str : strs) {
			vector<int> cnt(26, 0);
			string t = "";
			for (char c : str) ++cnt[c - 'a'];
			for (int d : cnt) t += to_string(d) + "/";//������ת��Ϊ��ĸ��������˼�����ƣ�t��Ϊ��������ַ���
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