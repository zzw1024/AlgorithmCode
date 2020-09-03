////寻找无序数组中，每个元素后面比他大的是一个数，O(N)
//
//#include "head.h"
//
//vector<int> findMax(vector<int>&v)
//{
//	if (v.size() == 0)return v;
//	vector<int>res(v.size());
//	stack<int>index;
//	int i = 0;
//	while(i<v.size())
//	{
//		if (index.empty() || v[index.top()] >= v[i])
//			index.push(i++);
//		else
//		{
//			res[index.top()] = v[i];
//			index.pop();
//		}
//	}
//	while (!index.empty())
//	{
//		res[index.top()] = INT32_MAX;
//		index.pop();
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int>v = { 4,7,5,6,3,1,2 };
//	v = findMax(v);
//	for (auto a : v)
//		cout << a << " ";
//	return 0;
//}