//#include "000库函数.h"
////
////使用三指针的方法，一个固定，其他两个为首尾指针
////复杂度为n^2
////注意去重
//
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>>res;
//        sort(nums.begin(), nums.end());
//        if (nums.size() < 3 || nums.front() > 0 || nums.back() < 0)return{};
//        for (int k = 0; k < nums.size() - 2; ++k)
//        {
//            if (nums[k] > 0)break;
//            if (k > 0 && nums[k] == nums[k - 1])continue;//去重
//            int i = k + 1, j = nums.size() - 1;
//            while (i < j)
//            {
//                if (nums[i] + nums[j] + nums[k] == 0)
//                {
//                    res.push_back({ nums[k],nums[i],nums[j] });
//                    while (i < j && nums[i] == nums[i + 1])++i;
//                    while (i < j && nums[j] == nums[j - 1])--j;
//                    ++i;
//                    --j;
//                }
//                else if (nums[i] + nums[j] + nums[k] < 0)
//                    ++i;
//                else
//                    --j;
//            }
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int>v = { -2,0,1,1,2 };
//    for (auto a : s.threeSum(v))
//    {
//        for (auto b : a)
//            cout << b << " ";
//        cout << endl;
//    }
//    return 0;
//}