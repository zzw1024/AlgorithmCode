//#include "000�⺯��.h"
//
//��3Sum�������ƣ�ֻ��������һ��ѭ��
//ʹ��3��ָ�룬��������ѭ����
//Ψһ���ѵ���ȥ�أ�
//����ʹ��set������ȥ�أ�Ҳ����ֱ�������ظ���ϡ�
//
//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        if (nums.size() < 4)return{  };
//        vector<vector<int>>res;
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size() - 3; ++i)
//        {
//            if (i > 0 && nums[i] == nums[i - 1])continue;//�����ظ�ֵ
//            for (int j = i+1; j < nums.size() - 2; ++j)
//            {           
//                if (j > i + 1 && nums[j] == nums[j - 1])continue;//�����ظ�ֵ
//                int L = j + 1, R = nums.size() - 1;
//                while (L < R)
//                {
//                    int s = nums[i] + nums[j] + nums[L] + nums[R];
//                    if (s == target)
//                    {
//                        res.push_back({ nums[i],nums[j],nums[L],nums[R] });
//                        while (L < R && nums[L] == nums[L+1])++L;//ȥ��
//                        while (L < R && nums[R] == nums[R - 1])--R;
//                        ++L;
//                        --R;
//                    }
//                    else if (s > target)--R;
//                    else ++L;
//                }
//            }
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int>v = { 1,1,1,1,0,0,0,-1,-1,-1,-1,0,-2,-2,-2,-2,2,2,2,2 };
//    vector<vector<int>>res = s.fourSum(v, 0);
//    for (auto& a : res)
//    {
//        for (auto b : a)
//            cout << b << " ";
//        cout << endl;
//    }
//    return 0;
//}