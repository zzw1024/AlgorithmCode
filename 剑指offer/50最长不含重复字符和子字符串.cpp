//#include "head.h"
//
//
////����һ��ʹ���ƶ�����
//string getLenghtSubstr(const string &str)
//{
//	if (str.length() < 2)return str;
//	string res, temp;
//	int L = 0, R = 1;
//	res.assign(str.begin() + L, str.begin() + R);
//	temp = res;
//	while (R < str.length())
//	{
//		if (temp.find(str[R])!=-1)
//		{
//			res = res.length() >= temp.length() ? res : temp;
//			L = R;
//			temp = "";
//		}
//		temp += str[R];
//		R++;
//	}
//	return res.length() >= temp.length() ? res : temp;
//}
//
////��������ʹ�ö�̬�滮
////���ƶ����ں������ƣ�ֻ�����������������string.find
//string DP(const string &str)
//{
//	if (str.length() <= 1)return str;
//	vector<int>word(26, -1);
//	string curStr = "", maxStr = "";
//	//int curL = 0, maxL = 0;
//	for (int i = 0; i < str.length(); ++i)
//	{
//		int index = word[str[i] - 'a'];
//		if (index<0 || i - index>curStr.length())//���û���ֹ������߳��ֵ�λ������Ŀǰ��¼���Ӵ���ǰ�棬��ô��i����ĸ�ҿ������
//			curStr += str[i];  //++curL
//		else //��i����ĸ�ظ�����Ŀǰ��¼���Ӵ���
//		{
//			maxStr = curStr.length() > maxStr.length() ? curStr : maxStr;//�ȸ���
//			//maxL = curL > maxL ? curL : maxL;
//			curStr += str[i];
//			curStr.erase(0, curStr.length() - (i - index));//ɾ���ظ��ڵ�
//			//curL = i-index;
//		}
//		word[str[i] - 'a'] = i;
//	}
//	return curStr.length() > maxStr.length() ? curStr : maxStr;
//	//return curL > maxL�� curL :maxL;
//}
//
//int main()
//{
//	cout << DP("a") << endl;
//	cout << DP("abcde") << endl;
//	cout << DP("arabcacfr") << endl;
//	return 0;
//}