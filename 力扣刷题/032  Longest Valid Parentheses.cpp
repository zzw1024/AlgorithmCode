//#include "000�⺯��.h"
//
//
////һ���������Ҿ��뵽ջ��
//class Solution {
//public:
//	int longestValidParentheses(string s) {
//		stack<int>st;
//		int res = 0, start = 0, n = s.length();
//		for (int i = 0; i < n; ++i)
//		{
//			if (s[i] == '(')
//				st.push(i);
//			else
//			{
//				if (st.empty())
//					start = i + 1;//����һλ��ʼ
//				else
//				{
//					st.pop();
//					res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());//��һ������úܺ�
//				}
//			}
//		}
//		return res;
//	}
//};
//
////����һ�־���ͨ��ʹ���������Ÿ�����ͳ��������ŵĸ���
////��ʹ������������ left �� right���ֱ�������¼����ǰλ��ʱ�����ź������ŵĳ��ִ�����
////������������ʱ��left ����1��������ʱ right ����1���������Ч�����ŵ��Ӵ���
////һ���������ŵ��������ŵ��������ʱ�Ϳ��Ը��½�� res �ˣ�һ���������������������������ˣ�
////˵����ǰλ�ò�����ɺϷ������Ӵ���left �� right ����Ϊ0�����Ƕ���������� "(()" ʱ��
////�ڱ�������ʱ������������������ȣ���ʱû�����½�� res������ʵ��ȷ����2��
////��ô������������أ������ٷ������һ�飬��ȡ���ƵĻ��ƣ����в�ͬ���Ǵ�ʱ�� left 
////���� right �ˣ�������0�������Ϳ��� cover ���е������
//
//class Solution {
//public:
//	int longestValidParentheses(string s) {
//		int res = 0, left = 0, right = 0, n = s.size();
//		for (int i = 0; i < n; ++i) {
//			(s[i] == '(') ? ++left : ++right;
//			if (left == right) res = max(res, 2 * right);
//			else if (right > left) left = right = 0;
//		}
//		left = right = 0;
//		for (int i = n - 1; i >= 0; --i) {
//			(s[i] == '(') ? ++left : ++right;
//			if (left == right) res = max(res, 2 * left);
//			else if (left > right) left = right = 0;
//		}
//		return res;
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.longestValidParentheses("(()") << endl;
//	cout << s.longestValidParentheses(")()())") << endl;
//	return 0;
//}