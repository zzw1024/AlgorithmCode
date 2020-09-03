#include "_000¿âº¯Êý.h"

class Solution {
public:
	bool isNumber(string s) {
		bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (s[i] == ' ') {
				if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign)) return false;
			}
			else if (s[i] == '+' || s[i] == '-') {
				if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') return false;
				sign = true;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				num = true;
				numAfterE = true;
			}
			else if (s[i] == '.') {
				if (dot || exp) return false;
				dot = true;
			}
			else if (s[i] == 'e') {
				if (exp || !num) return false;
				exp = true;
				numAfterE = false;
			}
			else return false;
		}
		return num && numAfterE;
	}
};

void T065() {
	Solution s;
	string str;
	str = "0";
	cout << str << endl << s.isNumber(str) << endl;
	str = " 0.1";
	cout << str << endl << s.isNumber(str) << endl;
	str = "abc";
	cout << str << endl << s.isNumber(str) << endl;
	str = "1 a";
	cout << str << endl << s.isNumber(str) << endl;
	str = "2e10";
	cout << str << endl << s.isNumber(str) << endl;
	str = " ";
	cout << str << endl << s.isNumber(str) << endl;
	str = "1 ";
	cout << str << endl << s.isNumber(str) << endl;
	str = "1 2";
	cout << str << endl << s.isNumber(str) << endl;
	str = "1 j";
	cout << str << endl << s.isNumber(str) << endl;
}