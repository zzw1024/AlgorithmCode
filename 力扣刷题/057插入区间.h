#include "000库函数.h"



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
//与上题合并区间没什么区别
//只不过将区间加入进去而已

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if (intervals.empty())return { newInterval };
		vector<Interval>res;
		vector<int>s, e;
		for (int i = 0; i < intervals.size(); ++i) {
			s.push_back(intervals[i].start);
			e.push_back(intervals[i].end);
		}
		s.push_back(newInterval.start);
		e.push_back(newInterval.end);
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


//题目中确保原来的区间是按起始端且无重叠，则复杂度较上题更小
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		int n = intervals.size(), cur = 0;
		while (cur < n && intervals[cur].end < newInterval.start) {
			res.push_back(intervals[cur++]);
		}
		while (cur < n && intervals[cur].start <= newInterval.end) {
			newInterval.start = min(newInterval.start, intervals[cur].start);
			newInterval.end = max(newInterval.end, intervals[cur].end);
			++cur;
		}
		res.push_back(newInterval);
		while (cur < n) {
			res.push_back(intervals[cur++]);
		}
		return res;
	}
};






void T057() {
	Solution s;
	vector<Interval>v;
	Interval newInterval;
	vector<int>nums;
	Interval p;
	nums = { 1,4,8,10 };
	for (int i = 0; i < nums.size(); i += 2) {
		p.start = nums[i];
		p.end = nums[i + 1];
		v.push_back(p);
	}
	newInterval.start = 5;
	newInterval.end = 7;
	v = s.insert(v, newInterval);
	for (auto a : v)
		cout << a.start << ", " << a.end << ";  ";
	cout << endl;

	v.clear();
	nums = { 1,4,8,10 };
	for (int i = 0; i < nums.size(); i += 2) {
		p.start = nums[i];
		p.end = nums[i + 1];
		v.push_back(p);
	}
	newInterval.start = 3;
	newInterval.end = 5;
	v = s.insert(v, newInterval);
	for (auto a : v)
		cout << a.start << ", " << a.end << ";  ";
	cout << endl;

	v.clear();
	nums = { 1,4,8,10 };
	for (int i = 0; i < nums.size(); i += 2) {
		p.start = nums[i];
		p.end = nums[i + 1];
		v.push_back(p);
	}
	newInterval.start = 0;
	newInterval.end = 7;
	v = s.insert(v, newInterval);
	for (auto a : v)
		cout << a.start << ", " << a.end << ";  ";
	cout << endl;

	v.clear();
	nums = { 1,4,8,10 };
	for (int i = 0; i < nums.size(); i += 2) {
		p.start = nums[i];
		p.end = nums[i + 1];
		v.push_back(p);
	}
	newInterval.start = 2;
	newInterval.end = 9;
	v = s.insert(v, newInterval);
	for (auto a : v)
		cout << a.start << ", " << a.end << ";  ";
	cout << endl;

	
}