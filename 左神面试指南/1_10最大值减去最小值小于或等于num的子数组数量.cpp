//#include <iostream>
//#include <vector>
//#include <list>
//
//using namespace std;
//
////【题目】
////给定数组arr和整数num，共返回有多少个子数组满足如下情况：
////max（arr[i.j]） - min（arr[i.j]） <= num max（arfi.j]）表示子数组ar[ij]中的最大值，min（arli.j]）表示子数组arr[i.j]中的最小值。
////【要求】
////如果数组长度为N，请实现时间复杂度为O（N）的解法。
////【题解】
////使用两个单调栈，一个栈维持从大到小的排序，头部永远是最大值
////一个维持从小到大的排序，头部永远都是最小值
////然后使用窗口进行数据移动
////当右移后，最大最小差超过num时，计算这段数组可以组成的子数组数量，因为长数组满足要求，
////那么里面的短数组更满足要求，
////然后进行左移，是最大最小差满足要求
//
//int getSubArrayNum(vector<int>v, int num)
//{
//	int l, r, res = 0;
//	list<int>maxl, minl;
//	for (l=-1,r=0;l<r && r<v.size();++r)
//	{
//		while (!maxl.empty() && v[r] > v[maxl.back()])			
//			maxl.pop_back();
//		while (!minl.empty() && v[r] < v[minl.back()])
//			minl.pop_back();
//		maxl.push_back(r);
//		minl.push_back(r);
//		if (v[maxl.front()] - v[minl.front()] > num)
//			res += r - l;
//		while(v[maxl.front()] - v[minl.front()] > num)
//		{
//			++l;
//			if (maxl.front() == l)
//				maxl.pop_front();
//			if (minl.front() == l)
//				minl.pop_front();
//		}
//	}
//	res += r - l;
//	return res;
//}
//
//
//int main()
//{
//	vector<int>v = { 8,5,4,6,9,1,4,5,7,8,6,3,4,5,9,8 };
//	int num = 4;
//	cout << getSubArrayNum(v, num) << endl;
//	return 0;
//}