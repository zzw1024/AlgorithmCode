//#include "head.h"
//
//class Solution {
//public:
//	bool match(char* str, char* pattern)
//	{
//		if (str == nullptr || pattern == nullptr)return false;
//		return matchCore(str, pattern);
//	}
//	bool matchCore(const char *str, const char *pattern)
//	{
//		if (*str == '\0' && *pattern == '\0')return true;
//		if (*str != '\0'&& *pattern == '\0')return false;
//		if (*(pattern + 1) == '*')
//		{
//			if (*pattern == *str || (*pattern == '.' && *str != '\0'))
//				return matchCore(str + 1, pattern + 2) || //移动到下一个位置
//				matchCore(str + 1, pattern) || // 待在自己的位置不动
//				matchCore(str, pattern + 2);//忽略一个‘*’
//			else
//				return matchCore(str, pattern + 2);//忽略一个'*'
//		}
//		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
//			return matchCore(str + 1, pattern + 1);
//		return false;
//	}
//};