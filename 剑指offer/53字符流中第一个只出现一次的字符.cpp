//#include "head.h"
//
//class Solution
//{
//public:
//	//Insert one char from stringstream
//	void Insert(char ch)
//	{
//		str += ch;
//		word[ch]++;
//		if (res == '#' && word[ch] == 1)//�µ���ĸ
//			res = ch;
//		if (word[res] > 1)//�ظ���
//		{
//			res = '#';
//			for (int i = index; i < str.length(); ++i)//�Ⱥ�Ѱ��δ�ظ�����ĸ
//			{
//				if (word[str[i]] == 1)
//				{
//					res = str[i];
//					index = i;
//					break;
//				}
//			}
//		}
//	}
//	//return the first appearence once char in current stringstream
//	char FirstAppearingOnce()
//	{
//		return res;
//	}
//private:
//	string str = "";
//	int word[256] = { 0 };
//	int index = 0;
//	char res = '#';
//};
//
//int main()
//{
//	Solution s;
//	while (1)
//	{
//		char c;
//		cin >> c;
//		s.Insert(c);
//		cout << s.FirstAppearingOnce() << endl;
//	}
//}
