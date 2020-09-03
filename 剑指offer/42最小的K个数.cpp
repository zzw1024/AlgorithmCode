//#include "head.h"
//
//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		if (input.size() < k)return {};
//		set<int>res;
//		for (auto a : input)
//		{
//			if (res.size() < k)
//				res.insert(a);
//			else if(a<*(--res.end()))
//			{
//				res.erase(--res.end());
//				res.insert(a);
//			}
//		}
//		vector<int>v;
//		v.assign(res.begin(), res.end());
//		return v;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int>v = s.GetLeastNumbers_Solution({ 4,5,1,6,2,7,3,8 }, 4);
//	return 0;
//	
//}