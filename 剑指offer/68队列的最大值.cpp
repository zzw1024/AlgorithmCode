//#include "head.h"
//
//
////��������ԭ��ܼ򵥣����ǿ���һ�����У����������������½Ǳ�
////��ͷ��Զ��Ĵ�������β��С����һ�����ֱȶ�β��������򵯳���β��������ѹ�룬ʹ�Ӵ�С��˳�򲻱�
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
//			if (R == size)res.push_back(num[List.front()]);//��һ������
//			else {//��������
//				if (List.front() == L)List.pop_front();//���������ȥ������������ɾ������
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