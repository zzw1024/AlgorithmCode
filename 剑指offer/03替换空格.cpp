//#include "head.h"
//
//
//class Solution {
//public:
//	void replaceSpace(char *str, int length) {
//		if (str == nullptr || length <= 0)
//			return;
//		int strLen = 0, spaceNum = 0, newLenght = 0;
//		for (strLen = 0; str[strLen] != '\0'; ++strLen)
//			if (str[strLen] == ' ')
//				spaceNum++;
//		newLenght = strLen + spaceNum * 2;
//		for (int i = newLenght, j = strLen; i >= 0; --j)
//			if (str[j] == ' ')
//			{
//				str[i--] = '0';
//				str[i--] = '2';
//				str[i--] = '%';
//			}
//			else
//				str[i--] = str[j];
//	}
//};
//
//int main()
//{
//	char c[] = "We Are Happy";
//	Solution S;
//	S.replaceSpace(c, 200);
//	cout << c << endl;
//	while (1);
//}