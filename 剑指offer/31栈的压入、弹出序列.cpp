//#include "head.h"
//
//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		if (pushV.size() != popV.size())return false;
//		stack<int>s;
//		int p1 = 0, p2 = 0;
//		while (p2<popV.size())
//		{
//			if (p1 < pushV.size() && s.empty())
//				s.push(pushV[p1++]);
//			if (!s.empty() && s.top() == popV[p2])
//			{
//				s.pop();
//				p2++;
//			}
//			else if (p1 < pushV.size())
//				s.push(pushV[p1++]);
//			else
//				return false;
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int>v1 = { 1,2,3,4,5 }, v2 = {6,7,8,9,10};
//	cout << s.IsPopOrder(v1, v2) << endl;
//	while (1);
//}