//#include "000库函数.h"
//
//方法一，比较笨，考虑所有的组合方式。
//
//class Solution {
//public:
//    int romanToInt(string s) {
//        unordered_map<string, int>map;
//        map["M"] = 1000;
//        map["CM"] = 900;
//        map["D"] = 500;
//        map["CD"] = 400;
//        map["C"] = 100;
//        map["XC"] = 90;
//        map["L"] = 50;
//        map["XL"] = 40;
//        map["X"] = 10;
//        map["IX"] = 9;
//        map["V"] = 5;
//        map["IV"] = 4;
//        map["I"] = 1;
//        int res = 0;
//        for (int i = 0; i < s.length(); ++i)
//        {
//            string temp = "";     
//            temp = s[i];
//            if (i + 1 < s.length())
//            {
//                if (map[temp + s[i + 1]] > 0)
//                {
//                    res += map[temp + s[i + 1]];
//                    ++i;
//                }
//                else
//                    res += map[temp];
//            }
//            else 
//                res += map[temp];
//        }
//        return res;
//    }
//};
//
//
//方法二：罗马数字的规律，即前面数小于后面的数，则为后面的数与前面数的组合，也就是后面的数减去前面的数。
//class Solution {
//public:
//    int romanToInt(string s) {
//        int res = 0;
//        unordered_map<char, int>map = { {'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1} };
//        for (int i = 0; i < s.length(); ++i)
//        {
//            if (i + 1 < s.length() && map[s[i]] < map[s[i + 1]])res -= map[s[i]];
//            else res += map[s[i]];
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    Solution s;
//    cout << s.romanToInt("III") << endl;
//    cout << s.romanToInt("IV") << endl;
//    cout << s.romanToInt("IX") << endl;
//    cout << s.romanToInt("LVIII") << endl;
//    cout << s.romanToInt("MCMXCIV") << endl;
//    return 0;
//}