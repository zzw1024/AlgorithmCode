//#include "000�⺯��.h"
////
////ʹ����ָ��ķ�����һ���̶�����������Ϊ��βָ��
////���Ӷ�Ϊn^2
////ע��ȥ��
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
//            if (k > 0 && nums[k] == nums[k - 1])continue;//ȥ��
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