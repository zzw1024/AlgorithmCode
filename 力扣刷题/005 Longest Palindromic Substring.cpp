//#include "000库函数.h"
//
//
////使用中将对称思路
////及从头开始遍历，对于每个字母进行左右向外扩散，判断是不是回文子串
////注意，向外扩散有两种方式，第一种，就是以该字母为中心向外扩散，第二种就是该字母和其右端的字母开始进行向外扩散
//
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		string res = "";
//		for (int i = 0; i < s.length(); ++i)
//		{
//			help(s, i - 1, i + 1, res);//奇数类型的中心向两边扩撒
//			help(s, i, i + 1, res);//偶数类型的中心向两边扩撒			
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
//	//字符串预处理
//	string newStr = "#";
//	for (auto c : str)
//		newStr = newStr + c + "#";
//	//回文半径记录数组
//	vector<int>rIndex(newStr.length(),0);
//	int C = -1;//回文中心id
//	int R = -1;//回文右边界 R位于回文对称右边界的右边一个字母mx
//	int maxL = INT32_MIN;//记录最长回文字长
//	int resId = 0;//记录最长子串的中心位置
//	for (int i = 0; i < newStr.length(); ++i)
//	{
//		//第一步直接取得可能的最短的回文半径，当i>R时，最短的回文半径是1，
//		//反之，最短的回文半径可能是i对应的i'的回文半径或者i到R的距离
//		if (R > i)
//			rIndex[i] = min(rIndex[2 * C - i], R - i);
//		else
//			rIndex[i] = 1;
//		//取最小值后开始从边界暴力匹配，匹配失败就直接退出
//		while (i + rIndex[i] < newStr.length() && i - rIndex[i] > -1)
//		{
//			if (newStr[i + rIndex[i]] == newStr[i - rIndex[i]])////向两边扩展，找回文字母
//				rIndex[i]++;
//			else
//				break;
//		}
//		//观察此时R和C是否能够更新
//		if (i + rIndex[i] > R)
//		{
//			R = i + rIndex[i];
//			C = i;
//		}
//		//更新最大回文半径的值
//		if (maxL < rIndex[i])
//		{
//			maxL = rIndex[i];
//			resId = i;
//		}
//	}
//	//这里解释一下为什么返回值是maxn-1，因为manacherstring的长度和原字符串不同，
//	//所以这里得到的最大回文半径其实是原字符串的最大回文子串长度加1，
//	//有兴趣的可以自己验证试试,-1是为了将后面的‘#’去掉
//	//return maxL - 1;
//	return str.substr(((resId - maxL)+1)/2, maxL - 1);
//}
//
//
