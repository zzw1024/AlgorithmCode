#include "_000�⺯��.h"


//һ��ʼ��֪���Ӻ�����
//�о�����ջ��������vector������ջ

class Solution {
public:
	string simplifyPath(string path) {
		vector<string>v;
		string s = "";//������¼��ʱ·��
		int n = 0;//��¼��.���ĸ���
		for (int i = 0; i < path.size(); ++i) {
			if (path[i] == '.')
				++n;
			else if (path[i] != '/') {//��¼�μ�Ŀ¼
				s.insert(s.end(), n, '.');//��ֹ��ЩĿ¼������.��ͷ����
				n = 0;
				s += path[i];
			}
			else {//path[i] == '/'
				if (n > 2)
					s.insert(s.end(), n, '.');
				else if (n == 2 && !v.empty())//ȷ�������ڸ�Ŀ¼		
					v.pop_back();// ������һ��

				n = 0;
				if (s.size() > 0)
					v.push_back(s);
				s = "";
			}

		}
		if (n > 2)
			s.insert(s.end(), n, '.');
		else if (n == 2 && !v.empty())//ȷ�������ڸ�Ŀ¼		
			v.pop_back();// ������һ��
		if (s.size() > 0)
			v.push_back(s);
		s = "";
		for (int i = 0; i < v.size(); ++i)//֮���Դ�1��ʼ����ȥ����Ŀ¼�ġ�/��
			s = s + "/" + v[i];
		if (!s.empty())return s;
		return "/";
	}
};

//C++����ר�Ŵ����ַ����Ļ��ƣ����ǿ���ʹ��stringstream���ָ��ַ�����
//Ȼ���ÿһ�ηֱ���˼·������ķ������ƣ��μ��������£�
//

class Solution {
public:
	string simplifyPath(string path) {
		string res, t;
		stringstream ss(path);
		vector<string> v;
		while (getline(ss, t, '/')) {
			if (t == "" || t == ".") continue;
			if (t == ".." && !v.empty()) v.pop_back();
			else if (t != "..") v.push_back(t);
		}
		for (string s : v) res += "/" + s;
		return res.empty() ? "/" : res;
	}
};



void T071() {
	Solution s;
	string str;
	str = "/home/";
	cout << "���룺" << str << endl << "�����" << s.simplifyPath(str) << endl;
	str = "/../";
	cout << "���룺" << str << endl << "�����" << s.simplifyPath(str) << endl;
	str = "/home//foo/";
	cout << "���룺" << str << endl << "�����" << s.simplifyPath(str) << endl;
	str = "/a/./b/../../c/";
	cout << "���룺" << str << endl << "�����" << s.simplifyPath(str) << endl;
	str = "/a/../../b/../c//.//";
	cout << "���룺" << str << endl << "�����" << s.simplifyPath(str) << endl;
	str = "/a//b////c/d//././/..";
	cout << "���룺" << str << endl << "�����" << s.simplifyPath(str) << endl;
	str = "/...";
	cout << "���룺" << str << endl << "�����" << s.simplifyPath(str) << endl;
	
}