//#include "head.h"
//
//
////滑动窗口原理很简单，就是开辟一个队列，队列里面存数组的下角标
////队头永远存的大数，队尾是小数，一旦出现比队尾大的数，则弹出队尾，将大数压入，使从大到小的顺序不变
//class Solution {
//public:
//	vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
//		if (num.size() == 0 || size <= 0 || size > num.size())return {};
//		vector<int>res;
//		deque<int>List;
//		int L = 0, R = 0;
//		while (R < num.size()) {
//			while (!List.empty() && num[List.back()] < num[R])List.pop_back();
//			List.push_back(R);
//			++R;
//			if (R < size)continue;
//			if (R == size)res.push_back(num[List.front()]);//第一个窗口
//			else {//其他窗口
//				if (List.front() == L)List.pop_front();//最大数就是去除的左数，则删除该数
//				++L;
//				res.push_back(num[List.front()]);
//			}
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int>v = s.maxInWindows({ 6,4,3,1,2,8,5,1,4,2,6,5 }, 3);
//	for (auto a : v)
//		cout << a << " ";
//	return 0;
//}