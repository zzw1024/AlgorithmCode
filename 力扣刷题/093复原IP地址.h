#include "_000库函数.h"


//暴力搜索
//一共分为4组
//每组数据不超过三位
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string>res;
		for(int a = 1; a<4;++a)
			for(int b=1;b<4;++b)
				for(int c =1;c<4;++c)
					for(int d=1;d<4;++d)
						if (a + b + c + d == s.size()) {
							int A = stoi(s.substr(0, a));//取子串并转为数组
							int B = stoi(s.substr(a, b));
							int C = stoi(s.substr(a+b, c));
							int D = stoi(s.substr(a+b+c, d));
							if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
								string str = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
								if (str.size() == (s.size() + 3))//去除010这种组合
									res.push_back(str);
							}
						}
		return res;

	}
};


//使用递归
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string>res;
		helper(s, 0, "",res);
		return res;
	}
	void helper(string s, int n, string out, vector<string>&res) {
		if (n == 4) {
			if (s.empty())res.push_back(out);//全部组合4组IP完毕
		}
		else {
			for (int k = 1; k < 4; ++k) {
				if (s.size() < k)break;
				int val = stoi(s.substr(0, k));//取子串转化为数字
				if (val > 255 || k != to_string(val).size())//当数字大于255或出现010，不满足
					continue;
				helper(s.substr(k), n + 1, out + s.substr(0, k) + (n == 3 ? "" : "."), res);
			}
		}
	}
};


void T093() {
	Solution s;
	string str;
	vector<string>v;
	str = "11111";
	v = s.restoreIpAddresses(str);
	for (auto a : v)
		cout << a << endl;
	cout << "************************" << endl;

	str = "101010101";
	v = s.restoreIpAddresses(str);
	for (auto a : v)
		cout << a << endl;
	cout << "************************" << endl;


}