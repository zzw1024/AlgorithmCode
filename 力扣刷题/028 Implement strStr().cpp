//#include "000�⺯��.h"
//
//
////�����Ӧ�ò���Ҫʹ��KMP,ʹ������ַ�ƥ��
//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		int n = haystack.length(), m = needle.length();
//		if (m == 0)return 0;//Ҫƥ����ַ�Ϊ��ʱҲ��
//		for (int i = 0; i < n; ++i)
//		{
//			if (n - i < m)return -1;//̫��ֱ������
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
//		if (needle == nullptr)return 0;//Ҫƥ����ַ�Ϊ��ʱҲ��
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