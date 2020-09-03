#pragma once
#include "000�⺯��.h"

//�ҵ���Ч������ţ����������Ч���ŵĵ��ַ�����
//�Խⷨ  
//һ��,���뵽��ջ��ջ����Ȼ���ַ�����-ջ����������ų�����
//���ǣ������룬���ԣ���Ϊ�ɶԵ����Ż��������Բ��У������м����ʧЧ������
//ʧ��

//class Solution {
//public:
//	int longestValidParentheses(string s) {
//		if (s.size() < 2)return 0;//�ַ�̫�̣��޷��������
//		stack<char>str;
//		int count = 0;//�����������Ч���ŵĳ���
//		int n1 = 0,n2 = 0;//����ֲ��ɶԵ����ų���
//		for (int i = 0; i < s.size(); ++i) {
//			if (str.size() > 0 && s[i] == ')'&&'(' == str.top()) {//ջ���գ����������ţ�ջ���������ţ�ƥ��һ������
//				str.pop();
//				n1 += 2;//��Ϊ�����ǳɶԳ��ֵ�
//			}
//			else if (s[i] == ')') {
//				if (str.empty()) n2 += n1;
//				count = count > n2 ? count : n2;// �����ƥ�����ŵ��Ӵ�
//				n2 = 0;////����Ѱ����Ӵ�
//				while (!str.empty())str.pop();
//			}
//			else {
//				if (!str.empty()) {
//					n2 += n1;
//					n1 = 0;
//				}
//				str.push(s[i]);//Ϊ������ţ���ջ
//			}
//			
//		}
//		if (!str.empty())
//			return count = count > n2 ? count : n2;
//		else
//			return count = count > n1 + n2 ? count : n1 + n2;		
//	}
//};

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() < 2)return 0;//�ַ�̫�̣��޷��������
		int start = 0, res = 0;
		stack<int>num;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(')num.push(i);
			else {
				if (num.empty())start = i + 1;
				else {
					num.pop();
					if (num.empty())res = res > i - start + 1 ? res : i - start + 1;
					else res = res > i - num.top() ? res : i - num.top();
				}
			}
		}
		return res;
	}
};

void T032() {
	string s;
	Solution sol;
	s = "(()";
	cout << s << endl;
	cout << sol.longestValidParentheses(s) << endl;
	s = ")()())";
	cout << s << endl;
	cout << sol.longestValidParentheses(s) << endl;
	s = ")((())()()((()))";
	cout << s << endl;
	cout << sol.longestValidParentheses(s) << endl;
}