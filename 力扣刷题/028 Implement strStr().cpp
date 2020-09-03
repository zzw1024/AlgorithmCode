//#include "000库函数.h"
//
//
////这道题应该不需要使用KMP,使用最笨的字符匹配
//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		int n = haystack.length(), m = needle.length();
//		if (m == 0)return 0;//要匹配的字符为空时也算
//		for (int i = 0; i < n; ++i)
//		{
//			if (n - i < m)return -1;//太短直接跳出
//			int k = i, j = 0;
//			while (k < n && j < m && needle[j] == haystack[k])
//			{
//				++k;
//				++j;
//			}
//			if (j == m)
//				return i;
//		}
//		return -1;
//	}
//};
//
//class Solution1 {
//public:
//	char *strStr(char *haystack, char *needle) {
//		if (needle == nullptr)return 0;//要匹配的字符为空时也算
//		while (*haystack != '\0')
//		{
//			char *p = haystack, *q = needle;
//			while (*p != '\0' && *q != '\0' && *p == *q)
//			{
//				++p;
//				++q;
//			}
//			if (*q == '\0')
//				return haystack;
//			++haystack;
//		}
//		return nullptr;
//	}
//};
//
//int main()
//{
//	//Solution s;
//	//cout << s.strStr("aaa","aaabb");
//	Solution1 s;
//	char *res;
//	char a[]="hello";
//	char b[] = "ll";
//	res = a;
//	res = s.strStr(a, b);
//	return 0;
//}