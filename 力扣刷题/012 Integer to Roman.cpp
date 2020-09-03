//#include "000¿âº¯Êý.h"
//
//class Solution {
//public:
//	string intToRoman(int num) {
//		vector<int>values = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
//		vector<string>reps = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
//		string res = "";
//		for (int i = 0; i < values.size(); ++i) {
//			while (num >= values[i]) {
//				num -= values[i];
//				res += reps[i];
//			}
//		}
//		return res;
//	}
//};
//
//int main()
//{
//    Solution s;
//    cout << s.intToRoman(3) << endl;
//    cout << s.intToRoman(4) << endl;
//    cout << s.intToRoman(9) << endl;
//    cout << s.intToRoman(58) << endl;
//    cout << s.intToRoman(1994) << endl;
//    return 0;
//}