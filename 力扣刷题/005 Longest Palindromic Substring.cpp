//#include "000�⺯��.h"
//
//
////ʹ���н��Գ�˼·
////����ͷ��ʼ����������ÿ����ĸ��������������ɢ���ж��ǲ��ǻ����Ӵ�
////ע�⣬������ɢ�����ַ�ʽ����һ�֣������Ը���ĸΪ����������ɢ���ڶ��־��Ǹ���ĸ�����Ҷ˵���ĸ��ʼ����������ɢ
//
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		string res = "";
//		for (int i = 0; i < s.length(); ++i)
//		{
//			help(s, i - 1, i + 1, res);//�������͵���������������
//			help(s, i, i + 1, res);//ż�����͵���������������			
//		}
//		return res;
//	}
//	void help(const string &s, int L, int R, string &res)
//	{
//		while (L >= 0 && R < s.length())
//		{
//			if (s[L] != s[R])break;
//			--L;
//			++R;
//		}
//		if (R - L - 1 > res.length())
//			res = s.substr(L + 1, R - L - 1);
//	}
//};
//
//
//
//int maxPalindromeLength(string str) {
//	string charArr = str;
//	vector<int>pArr(charArr.length(), 0);
//	int R = -1, C = -1, maxLen = INT32_MIN;
//
//	for (int i = 0; i < charArr.length(); ++i)
//	{
//		pArr[i] = i > R ? 1 : min(pArr[C * 2 - i], R - i);
//		while (i + pArr[i] - 1)
//		{
//			if (charArr[i + pArr[i]] == charArr[i - pArr[i]])
//				++pArr[i];
//			else
//				break;
//		}
//		if (R < i + pArr[i])
//		{
//			R = i + pArr[i] - 1;
//			C = i;
//		}
//		maxLen = max(maxLen, pArr[i]);
//	}
//	return maxLen - 1;
//}
//
//
//string Manacher(string str)
//{
//	//�ַ���Ԥ����
//	string newStr = "#";
//	for (auto c : str)
//		newStr = newStr + c + "#";
//	//���İ뾶��¼����
//	vector<int>rIndex(newStr.length(),0);
//	int C = -1;//��������id
//	int R = -1;//�����ұ߽� Rλ�ڻ��ĶԳ��ұ߽���ұ�һ����ĸmx
//	int maxL = INT32_MIN;//��¼������ֳ�
//	int resId = 0;//��¼��Ӵ�������λ��
//	for (int i = 0; i < newStr.length(); ++i)
//	{
//		//��һ��ֱ��ȡ�ÿ��ܵ���̵Ļ��İ뾶����i>Rʱ����̵Ļ��İ뾶��1��
//		//��֮����̵Ļ��İ뾶������i��Ӧ��i'�Ļ��İ뾶����i��R�ľ���
//		if (R > i)
//			rIndex[i] = min(rIndex[2 * C - i], R - i);
//		else
//			rIndex[i] = 1;
//		//ȡ��Сֵ��ʼ�ӱ߽籩��ƥ�䣬ƥ��ʧ�ܾ�ֱ���˳�
//		while (i + rIndex[i] < newStr.length() && i - rIndex[i] > -1)
//		{
//			if (newStr[i + rIndex[i]] == newStr[i - rIndex[i]])////��������չ���һ�����ĸ
//				rIndex[i]++;
//			else
//				break;
//		}
//		//�۲��ʱR��C�Ƿ��ܹ�����
//		if (i + rIndex[i] > R)
//		{
//			R = i + rIndex[i];
//			C = i;
//		}
//		//���������İ뾶��ֵ
//		if (maxL < rIndex[i])
//		{
//			maxL = rIndex[i];
//			resId = i;
//		}
//	}
//	//�������һ��Ϊʲô����ֵ��maxn-1����Ϊmanacherstring�ĳ��Ⱥ�ԭ�ַ�����ͬ��
//	//��������õ��������İ뾶��ʵ��ԭ�ַ������������Ӵ����ȼ�1��
//	//����Ȥ�Ŀ����Լ���֤����,-1��Ϊ�˽�����ġ�#��ȥ��
//	//return maxL - 1;
//	return str.substr(((resId - maxL)+1)/2, maxL - 1);
//}
//
//
