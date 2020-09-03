#include "000库函数.h"




//使用回溯法，当左括号数量大于右括号数量，则可以放置右括号
void recall(vector<string>&bracket, string s, int left, int right) {//bracket使用引用，确保其变化会被保留
	if (left > right)return;
	if (left == 0 && right == 0)bracket.push_back(s);
	else {
		if (left > 0)recall(bracket, s + '(', left-1, right);
		if (right > 0)recall(bracket, s + ')', left, right-1);
	}
	
}

vector<string> generateParenthesis(int n) {
	vector<string>bracket;
	if (n < 1)return bracket;
	recall(bracket, "",n, n);
	return bracket;
		
}

每找到一个左括号，就在其后面加一个完整的括号，最后再在开头加一个()，就形成了所有的情况，
需要注意的是，有时候会出现重复的情况，所以我们用set数据结构，好处是如果遇到重复项，不会加入到结果中
最后我们再把set转为vector即可

vector<string> generateParenthesis(int n) {
	set<string>t;
	if (n == 0)t.insert("");
	else {
		vector<string>pre = generateParenthesis(n - 1);
		for (auto a : pre) {
			for (int i = 0; i < a.size(); ++i) {
				if (a[i] == '(') {
					a.insert(a.begin() + i + 1, '(');
					a.insert(a.begin() + i + 2, '）');
					t.insert(a);
					a.erase(a.begin() + i + 1, a.begin() + i + 3);
				}
			}
			t.insert("()" + a);
		}
		
	}
	return vector<string>(t.begin(), t.end());//强制类型转换

}


void T022() {
	vector<string>Res;
	Res = generateParenthesis(3);
	for (int i = 0; i < Res.size(); ++i)
		cout << Res[i] << endl;

}
