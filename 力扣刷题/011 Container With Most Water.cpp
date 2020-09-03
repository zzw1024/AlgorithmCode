//#include "000库函数.h"
//
//水桶原理，即水桶的容量取决于最短的那块木板。
//左右不停的寻找最高边缘即可。
//
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int i = 0, j = height.size() - 1, maxV = 0;
//        while (i < j)
//        {
//            maxV = max(maxV, min(height[i], height[j]) * (j - i));
//            if (height[i] < height[j]) ++i;
//            else --j;
//        }
//        return maxV;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int>H = { 1,8,6,2,5,4,8,3,7 };
//    cout << s.maxArea(H) << endl;
//    return 0;
//}