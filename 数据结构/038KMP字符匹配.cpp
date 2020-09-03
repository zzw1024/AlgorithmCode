//#include "000库函数.h"
////string text = "BBC ABCDAB ABCDABCDABDE";
////string pattern = "ABCDABD";
//string text = "substring searching algorithm";
//string pattern = "search";
////暴力算法
//int Violence()
//{
//	int i = 0, j = 0;
//	int slen = text.length(), plen = pattern.length();
//	while (i < slen && j < plen)
//	{
//		if (text[i] == pattern[j])
//		{
//			++i; 
//			++j;
//		}
//		else
//		{
//			i = i - j + 1;//回到当初的位置
//			j = 0;
//		}
//	}
//	if (j == plen)
//		return i - j;
//	else
//		return -1;
//}
//
////KMP
////next的数组的原理就是复制一次原数组，然后和原数组向后差一位进行匹配
//void getNext(vector<int>&next)
//{
//	int j = 0;
//	int k = -1;//k是关键，k=0就是求前缀数组，k=-1就是将前缀数组向后移一位
//	int len = pattern.length();
//	next[0] = -1;
//	while (j < len-1)
//	{
//		if (k == -1 || pattern[j] == pattern[k])//将复制数组与原数组匹配
//		{
//			++k;
//			++j;
//			next[j] = k;
//		}
//		else
//			k = next[k];//又从复制数组的头开始匹配，-1的位置
//	}
//}
//int KMP()
//{
//	int i = 0, j = 0;
//	int slen = text.length(), plen = pattern.length();
//	vector<int>next(pattern.length());
//	getNext(next);
//	while (i < slen && j < plen)
//	{
//		if (j == -1 || text[i] == pattern[j])//j==-1表示第一个字母都没有匹配上
//		{
//			++i;
//			++j;
//		}
//		else
//			j = next[j];//一旦没匹配，就跳next中的步数
//	}
//	if (j == plen)//匹配成功
//		return i - j;
//	else
//		return -1;
//}
//
//int Sunnday()
//{
//	int i = 0, j = 0;
//	int slen = text.length(), plen = pattern.length();
//	vector<int>local(128, -1);
//	for (int k = 0; k < plen; ++k)
//		local[pattern[k]] = k;//记住子串中每个字母的最靠右的位置
//	while (i < slen && j <plen)
//	{
//		if (text[i] == pattern[j])
//		{
//			++i;
//			++j;
//		}
//		else
//		{
//			int k = i + plen - j;//判断后面的一个字母
//			if (k >= slen)break;
//			if (local[text[k]] == -1)//不存在子串中
//			{
//				j = 0;
//				i = k+1;//再向后移一位
//			}
//			else//存在子串中
//			{
//				j = 0;
//				i = k - local[text[k]];
//			}
//		}
//	}
//	if (j == plen)
//		return i - j;
//	else
//		return -1;
//}
//
//int main()
//{
//	cout << KMP() << endl;
//	cout << Sunnday() << endl;
//	return 0;
//}