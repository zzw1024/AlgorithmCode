#pragma once
#include "000库函数.h"

//使用栈的思想，先进后出原则，因为出来的必须是与目前的括号形成一对
bool isValid(string s) {
	if (s.size() == 0)return true;
	if (s.size() == 1)return false;	
	stack<char>Temp;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '['|| s[i] == '{')
			Temp.push(s[i]);
		else {
			if (Temp.empty()) return false;//栈不为空
			if (s[i] == ')'&&Temp.top() != '(')return false;//不能匹配
			if (s[i] == ']'&&Temp.top() != '[')return false;//不能匹配
			if (s[i] == '}'&&Temp.top() != '{')return false;//不能匹配
			Temp.pop();//匹配成功
		}
		
	}
	if (Temp.empty())
		return true;
	else
		return false;

}

void T20() {
	string s;
	s = "()";
	cout << s << endl << isValid(s) << endl;
	s = "()[]{}";
	cout << s << endl << isValid(s) << endl;
	s = "([)]";
	cout << s << endl << isValid(s) << endl;
	s = "[{]";
	cout << s << endl << isValid(s) << endl;
	s = "((((((()))))))";
	cout << s << endl << isValid(s) << endl;
	s = "{[()]}";
	cout << s << endl << isValid(s) << endl;

}