//#include "000库函数.h"
//
//与三道题类似
//唯一区别的就是怎样判断头尾指针移动方向
//
//
//class Solution {
//public:
//    int threeSumClosest(vector<int>& nums, int target) {
//        if (nums.size() < 3)return 0;
//        sort(nums.begin(),nums.end());
//        int res, dis;
//        res = nums[0] + nums[1] + nums[2];
//        dis = abs(res - target);
//        for (int k = 0; k < nums.size() - 2; ++k)
//        {
//            int i = k + 1, j = nums.size() - 1;
//            while (i < j)
//            {
//                int temp = nums[k] + nums[i] + nums[j] - target;
//                if (abs(temp) < dis)
//                {
//                    dis = abs(temp);
//                    res = nums[k] + nums[i] + nums[j];
//                }
//                if (temp > 0)--j;
//                else ++i;
//            }            
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int>v = {-1,2,1,-4};
//    cout << s.threeSumClosest(v, 1) << endl;
//    return 0;    
//}