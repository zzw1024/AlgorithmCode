//#include "head.h"
//
//class Solution {
//public:
//	int Add(int num1, int num2){
//		int sum, carry;
//		while (num2 != 0) {
//			sum = num1 ^ num2;//ֻ����ӣ�����λ
//			carry = (num1&num2) << 1;//��¼��λ
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
