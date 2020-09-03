#include "_000库函数.h"


//一开始不知道从何下手
//感觉是用栈，所以用vector来代替栈

class Solution {
public:
	string simplifyPath(string path) {
		vector<string>v;
		string s = "";//用来记录临时路径
		int n = 0;//记录‘.’的个数
		for (int i = 0; i < path.size(); ++i) {
			if (path[i] == '.')
				++n;
			else if (path[i] != '/') {//记录次级目录
				s.insert(s.end(), n, '.');//防止有些目录名是以.开头！！
				n = 0;
				s += path[i];
			}
			else {//path[i] == '/'
				if (n > 2)
					s.insert(s.end(), n, '.');
				else if (n == 2 && !v.empty())//确保不是在根目录		
					v.pop_back();// 跳到上一级

				n = 0;
				if (s.size() > 0)
					v.push_back(s);
				s = "";
			}

		}
		if (n > 2)
			s.insert(s.end(), n, '.');
		else if (n == 2 && !v.empty())//确保不是在根目录		
			v.pop_back();// 跳到上一级
		if (s.size() > 0)
			v.push_back(s);
		s = "";
		for (int i = 0; i < v.size(); ++i)//之所以从1开始，是去除根目录的‘/’
			s = s + "/" + v[i];
		if (!s.empty())return s;
		return "/";
	}
};

//C++中有专门处理字符串的机制，我们可以使用stringstream来分隔字符串，
//然后对每一段分别处理，思路和上面的方法相似，参见代码如下：
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
	cout << "输入：" << str << endl << "输出：" << s.simplifyPath(str) << endl;
	str = "/../";
	cout << "输入：" << str << endl << "输出：" << s.simplifyPath(str) << endl;
	str = "/home//foo/";
	cout << "输入：" << str << endl << "输出：" << s.simplifyPath(str) << endl;
	str = "/a/./b/../../c/";
	cout << "输入：" << str << endl << "输出：" << s.simplifyPath(str) << endl;
	str = "/a/../../b/../c//.//";
	cout << "输入：" << str << endl << "输出：" << s.simplifyPath(str) << endl;
	str = "/a//b////c/d//././/..";
	cout << "输入：" << str << endl << "输出：" << s.simplifyPath(str) << endl;
	str = "/...";
	cout << "输入：" << str << endl << "输出：" << s.simplifyPath(str) << endl;
	
}