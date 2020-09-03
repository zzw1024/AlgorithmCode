//#include "head.h"
//
//class Solution {
//public:
//	int StrToInt(string str) {
//		if (str.length() < 1)return 0;
//		long long int res = 0;
//		int flag = 1;
//		for (int i = 0; i < str.length(); ++i){
//			if (i == 0 && (str[i] == '+' || str[i] == '-'))
//				flag *= (str[i] == '-' ? -1 : 1);
//			else if (!isdigit(str[i]))
//				return 0;
//			else
//				res = res * 10 + str[i] - '0';
//		}
//		                                                                                                                                                                                                              
//	}
//};
//int main(){
//	Solution s;
//	cout << s.StrToInt("-2147483649") << endl;
//	cout << s.StrToInt("-2147483648") << endl;
//	cout << s.StrToInt("+1a251") << endl;
//	return 0;
//}