//#include "head.h"
//
//void ReverseString(string& str, int L, int R)
//{
//	while (L < R)
//	{
//		swap(str[L], str[R]);
//		++L;
//		--R;
//	}
//}
//
//void Solution(string str)
//{
//	ReverseString(str, 0, str.size()-1);
//	int k = 0;
//	for (int i = 0; i < str.size(); ++i)
//	{
//		if (str[i] != ' ')continue;
//		ReverseString(str, k, i - 1);
//		k = i + 1;
//	}
//	ReverseString(str, k, str.size() - 1);//反转最后一个单词
//}
//
//int main()
//{
//	string str = "student. am I";
//	Solution(str);
//	return 0;
//	
//}