//#include "000库函数.h"
//
//直接硬处理即可
//class Solution {
//public:
//	int myAtoi(string str) {
//		if (str.length() == 0)return 0;
//		double res = 0;//用来防止溢出的
//		bool isBegan = false; //是否开始了
//		int isMinus = 1;//是否是负数
//		for (int i = 0; i < str.length(); ++i)
//		{
//			if (!isBegan && str[i] == ' ')continue;//还没有开始
//			if (!isBegan && (str[i] == '-' || str[i] == '+'))//第一次遇到负号
//				isMinus = str[i] == '-' ? -1 : 1;//是负数
//			else if (isdigit(str[i]))
//				res = res * 10 + str[i] - '0';
//			else//不是数字
//				return res * isMinus;
//			isBegan = true;//开始了
//			//判断是否越界	
//			if ((res * isMinus) < INT_MIN)return INT_MIN;
//			else if (res * isMinus > INT_MAX)return INT_MAX;
//		}
//		return res * isMinus;
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.myAtoi("42") << endl;
//	cout << s.myAtoi("4193 with words") << endl;
//	cout << s.myAtoi("words and 987") << endl;
//	cout << s.myAtoi("-91283472332") << endl;
//	return 0;
//}