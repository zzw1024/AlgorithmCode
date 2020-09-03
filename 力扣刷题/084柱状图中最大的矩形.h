#include "_000�⺯��.h"

//ͷβָ�룬Ȼ����Ѱ��ͷβָ���м���̵�ֵ
//ò�Ƹ��Ӷ�Ϊn^2�е��
//����ʱ������
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty())return 0;
		if (heights.size() == 1)return heights[0];
		int max = -1;
		for (int left = 0; left < heights.size(); ++left) {
			int min = heights[left];
			for (int right = left; right < heights.size(); ++right) {
				min = min < heights[right] ? min : heights[right];
				max = max > (min*(right - left + 1)) ? max : (min*(right - left + 1));
			}				
		}		
		return max;
	}
};


//ʹ�þֲ���ֵ�����������ں�һ�������Ǿֲ���ֵ��
//Ȼ�����ǰ�����е�����

// Pruning optimize
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int res = 0;
		for (int i = 0; i < height.size(); ++i) {
			if (i + 1 < height.size() && height[i] <= height[i + 1]) {
				continue;
			}
			int minH = height[i];
			for (int j = i; j >= 0; --j) {
				minH = min(minH, height[j]);
				int area = minH * (i - j + 1);
				res = max(res, area);
			}
		}
		return res;
	}
};

//ʹ��ջ
//ջֻ��������½Ǳ�
//������ջ������С�������ó������д���
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int res = 0;
		stack<int> st;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); ++i) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				int cur = st.top(); 
				st.pop();
				res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
			}
			st.push(i);
		}
		return res;
	}
};

void T084() {
	Solution s;
	vector<int>v;
	v = { 2,1,5,6,2,3 };
	cout << s.largestRectangleArea(v) << endl;
	v = { 0,9};
	cout << s.largestRectangleArea(v) << endl;
}