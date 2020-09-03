//#include "000�⺯��.h"
//
//����һ���Ƚϱ����������е���Ϸ�ʽ��
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
//���������������ֵĹ��ɣ���ǰ����С�ں����������Ϊ���������ǰ��������ϣ�Ҳ���Ǻ��������ȥǰ�������
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