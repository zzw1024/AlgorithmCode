#include "000库函数.h"


//自解，就遍历数数  8ms
class Solution {
public:
	string countAndSay(int n) {
		if (n == 0)return "";
		string str = "1";
		string s;
		for (int i = 1; i < n; ++i) {
			s = "";
			int n = 0;
			char a = str[0];
			for (int j = 0; j < str.size(); ++j) {
				if (str[j] == a)
					++n;
				else {
					s += n + '0';
					s += a;
					a = str[j];
					n = 1;
				}
			}
			s += n + '0';
			s += a;
			str = s;
		}
		return str;
	}
};

void T038() {
	Solution s;
	string str;
	str = s.countAndSay(4);
	cout << str << endl;
	str = s.countAndSay(1);
	cout << str << endl;
	str = s.countAndSay(5);
	cout << str << endl;
}