//#include "head.h"
//
//class Solution01 {
//public:
//	int FirstNotRepeatingChar(string str) {
//		if (str.length() == 0)return -1;
//		vector<bool>v(str.length(), false);
//		vector<int>word(128, -1);
//		int res = 0;
//		for (int i = 0; i < str.length(); ++i)
//		{
//			if (word[str[i]] != -1)//�������ظ�
//			{
//				v[i] = v[word[str[i]]] = true;//��ǰ���ظ������ڵ���ĸ����
//				while (v[res] == true && res < i)res++;//�Ⱥ�Ѱ��û���ظ�����ĸ
//				if (res == i)res = -1;//���ظ���
//			}
//			else if (res == -1)//����������ĸ
//				res = i;
//			word[str[i]] = i;
//		}
//		return res;
//	}
//};
//class Solution02 {
//public:
//	int FirstNotRepeatingChar(string str) {
//		if (str.length() == 0)return -1;
//		int res = 0;
//		int word[128] = { 0 };
//		for (int i = str.length() - 1; i >= 0; --i)
//		{
//			if (word[str[i]] == 0)//δ�����ظ�
//				res = i;
//			else if (res != -1 && str[i] == str[res])//������ĸ�����ظ���
//			{
//				int k = res;
//				res = -1;
//				for (int i = k + 1; res == -1 && i < str.length(); ++i)//ǰ�����ĸ���ظ��ˣ���ôֻ�����Ѱ��ϣ����
//					if (word[str[i]] == 1)
//						res = i;
//			}
//			word[str[i]]++;
//		}
//		return res;
//	}
//};
//
//
//class Solution {
//public:
//	int FirstNotRepeatingChar(string str) {
//		if (str.length() == 0)return -1;
//		int word[128] = { 0 };
//		for (auto a : str)
//			word[a]++;
//		for (int i = 0; i < str.length(); ++i)
//			if (word[str[i]] == 1)
//				return i;
//		return -1;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	cout << s.FirstNotRepeatingChar("") << endl;
//	cout << s.FirstNotRepeatingChar("a") << endl;
//	cout << s.FirstNotRepeatingChar("abc") << endl;
//	cout << s.FirstNotRepeatingChar("abbac") << endl;
//	cout << s.FirstNotRepeatingChar("abcabc") << endl;
//	cout << s.FirstNotRepeatingChar("abccba") << endl;
//	cout << s.FirstNotRepeatingChar("abcvabc") << endl;
//	cout << s.FirstNotRepeatingChar("abcvcba") << endl;
//	cout << s.FirstNotRepeatingChar("abcabcv") << endl;
//	cout << s.FirstNotRepeatingChar("google") << endl;
//	return 0;
//}