//#include "head.h"
//
//class Solution {
//public:
//	void push(int value) {
//		dataS.push(value);
//		if (dataMin.empty() || dataMin.top() >= value)
//			dataMin.push(value);
//	}
//	void pop() {
//		if (dataS.top() == dataMin.top())
//			dataMin.pop();
//		dataS.pop();
//	}
//	int top() {
//		return dataS.top();
//	}
//	int min() {
//		return dataMin.top();
//	}
//private:
//	stack<int>dataS, dataMin;
//};