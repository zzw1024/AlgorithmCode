//#include "000¿âº¯Êý.h"
//
////¼òµ¥
//
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        if (strs.size() < 1)return "";
//        string res = "";
//        for (int i = 0; i < strs[0].length(); ++i)
//        {
//            for (int j = 1; j < strs.size(); ++j)
//            {
//                if (i >= strs[j].length() || strs[j][i] != strs[0][i])
//                    return res;
//            }
//            res += strs[0][i];
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<string>v = { "flower","flow","flight" };
//    cout << s.longestCommonPrefix(v) << endl;
//    v = { "dog","racecar","car" };
//    cout << s.longestCommonPrefix(v) << endl;
//    return 0;
//}