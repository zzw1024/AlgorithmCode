#pragma once
#include "000�⺯��.h"

//ʹ��ջ��˼�룬�Ƚ����ԭ����Ϊ�����ı�������Ŀǰ�������γ�һ��
bool isValid(string s) {
	if (s.size() == 0)return true;
	if (s.size() == 1)return false;	
	stack<char>Temp;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '['|| s[i] == '{')
			Temp.push(s[i]);
		else {
			if (Temp.empty()) return false;//ջ��Ϊ��
			if (s[i] == ')'&&Temp.top() != '(')return false;//����ƥ��
			if (s[i] == ']'&&Temp.top() != '[')return false;//����ƥ��
			if (s[i] == '}'&&Temp.top() != '{')return false;//����ƥ��
			Temp.pop();//ƥ��ɹ�
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