//#include "000¿âº¯Êý.h"
//
//
//class Solution {
//public:
//    vector<string> letterCombinations(string digits) {
//        if (digits.length() == 0)return{};
//        vector<string>res;
//        unordered_map<char, string>map = { {'2',"abc"},{'3',"def"},{'4',"ghi"},
//                     {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
//        getHelp(0, "", digits, map, res);
//        return res;
//    }
//    void getHelp(int index,string out,const string digits, unordered_map<char, string>map, vector<string>& res)
//    {
//        if (index == digits.length()) 
//        {
//            res.push_back(out);
//            return;
//        }
//
//        string str = map[digits[index]];
//        for (int i = 0; i < str.length(); ++i)
//            getHelp(index + 1, out + str[i], digits, map, res);
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<string>res;
//    res = s.letterCombinations("234");
//    for (string s : res)
//        cout << s << endl;
//    return 0;
//}

