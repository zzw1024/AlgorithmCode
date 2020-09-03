#include "000库函数.h"


 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

 //第一印象就是排序再组合合并
//失败，因为给的范围不是按顺序的
//class Solution {
//public:
//	vector<Interval> merge(vector<Interval>& intervals) {
//		if (intervals.empty())return {};
//		vector<Interval>res;
//		Interval p;
//		p.start = intervals[0].start;
//		for (int i = 1; i < intervals.size(); ++i) {
//			if ((intervals[i].start - intervals[i-1].end) < 1)
//				continue;
//			p.end = intervals[i-1].end;
//			res.push_back(p);
//			p.start = intervals[i].start;
//		}
//		p.end = intervals[intervals.size()-1].end;
//		res.push_back(p);
//		return res;
//	}
//};

//仍然是先排序在合并的思想
//但是改进了，将头尾分开排序
//20ms
 class Solution {
 public:
	 vector<Interval> merge(vector<Interval>& intervals) {
		 if (intervals.empty())return {};
		 vector<Interval>res;
		 vector<int>s, e;
		 for (int i = 0; i < intervals.size(); ++i) {
			 s.push_back(intervals[i].start);
			 e.push_back(intervals[i].end);
		 }
		 sort(s.begin(), s.end());//头排序
		 sort(e.begin(), e.end());//尾排序
		 Interval p;
		 p.start = s[0];
		 for (int i = 1; i < s.size(); ++i) {
			 if ((s[i] - e[i - 1]) < 1)continue;//比较大小
			 p.end = e[i - 1];
			 res.push_back(p);
			 p.start = s[i];
		 }
		 p.end = e[s.size() - 1];
		 res.push_back(p);
		 return res;
	 }
 };

 //将上述方法改进，使用自定义排序函数
 class Solution {
 public:
	 vector<Interval> merge(vector<Interval>& intervals) {
		 if (intervals.empty()) return {};
		 sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {return a.start < b.start; });
		 vector<Interval> res{ intervals[0] };
		 for (int i = 1; i < intervals.size(); ++i) {
			 if (res.back().end < intervals[i].start) {
				 res.push_back(intervals[i]);
			 }
			 else {
				 res.back().end = max(res.back().end, intervals[i].end);
			 }
		 }
		 return res;
	 }
 };


//这道题还有另一种解法，由于插入的过程中也有合并的操作，所以我们可以建立一个空的集合，
//然后把区间集的每一个区间当做一个新的区间插入结果中，也可以得到合并后的结果，

 class Solution {
 public:
	 vector<Interval> merge(vector<Interval>& intervals) {
		 vector<Interval> res;
		 for (int i = 0; i < intervals.size(); ++i) {
			 res = insert(res, intervals[i]);
		 }
		 return res;
	 }
	 vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		 vector<Interval> res;
		 int n = intervals.size(), cur = 0;
		 for (int i = 0; i < n; ++i) {
			 if (intervals[i].end < newInterval.start) {
				 res.push_back(intervals[i]);
				 ++cur;
			 }
			 else if (intervals[i].start > newInterval.end) {
				 res.push_back(intervals[i]);
			 }
			 else {
				 newInterval.start = min(newInterval.start, intervals[i].start);
				 newInterval.end = max(newInterval.end, intervals[i].end);
			 }
		 }
		 res.insert(res.begin() + cur, newInterval);
		 return res;
	 }
 };



void T056() {
	Solution s;
	vector<Interval>v;
	vector<int>nums;
	Interval p;
	nums = { 1,3,2,6,8,10,15,18 };
	for (int i = 0; i < nums.size(); i += 2) {
		p.start = nums[i];
		p.end = nums[i + 1];
		v.push_back(p);
	}
	v = s.merge(v);
	for (auto a : v)
		cout << a.start << ", " << a.end << ";  ";
	cout << endl;

	v.resize(0);
	nums = { 1,4,4,5 };
	for (int i = 0; i < nums.size(); i += 2) {
		p.start = nums[i];
		p.end = nums[i + 1];
		v.push_back(p);
	}
	v = s.merge(v);
	for (auto a : v)
		cout << a.start << ", " << a.end << ";  ";
	cout << endl;

	v.resize(0);
	nums = { 1,4,0,4 };
	for (int i = 0; i < nums.size(); i += 2) {
		p.start = nums[i];
		p.end = nums[i + 1];
		v.push_back(p);
	}
	v = s.merge(v);
	for (auto a : v)
		cout << a.start << ", " << a.end << ";  ";
	cout << endl;

}