#include "000�⺯��.h"


 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

 //��һӡ�������������Ϻϲ�
//ʧ�ܣ���Ϊ���ķ�Χ���ǰ�˳���
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

//��Ȼ���������ںϲ���˼��
//���ǸĽ��ˣ���ͷβ�ֿ�����
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
		 sort(s.begin(), s.end());//ͷ����
		 sort(e.begin(), e.end());//β����
		 Interval p;
		 p.start = s[0];
		 for (int i = 1; i < s.size(); ++i) {
			 if ((s[i] - e[i - 1]) < 1)continue;//�Ƚϴ�С
			 p.end = e[i - 1];
			 res.push_back(p);
			 p.start = s[i];
		 }
		 p.end = e[s.size() - 1];
		 res.push_back(p);
		 return res;
	 }
 };

 //�����������Ľ���ʹ���Զ���������
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


//����⻹����һ�ֽⷨ�����ڲ���Ĺ�����Ҳ�кϲ��Ĳ������������ǿ��Խ���һ���յļ��ϣ�
//Ȼ������伯��ÿһ�����䵱��һ���µ�����������У�Ҳ���Եõ��ϲ���Ľ����

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