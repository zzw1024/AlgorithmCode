//#include "head.h"
//
//class Solution {
//public:
//	int Add(int num1, int num2){
//		int sum, carry;
//		while (num2 != 0) {
//			sum = num1 ^ num2;//只现相加，不进位
//			carry = (num1&num2) << 1;//记录进位
//			num1 = sum;
//			num2 = carry;
//		}
//		return num1;
//	}
//};
//int main()
//{
//	Solution s;
//	while (1) {
//		int a, b;
//		cin >> a >> b;
//		cout << s.Add(a, b) << endl;
//	}
//}
