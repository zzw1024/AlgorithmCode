#include"000库函数.h"
//一点头绪都没有
//然后就自己按自己的意思来一遍
//好像没有用算法
//16ms,让我激动一把

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() < 2)return 0;
		int s = 0;//起始点
		int e = 0;//终止点
		int v = 0;//接雨水量
		int t = 0;//计算中间掠过的柱子
		int i, j;
		for (i = 0; i < height.size()-1; ++i) {
			if (height[i] < 1)continue;
			s = height[i];//找到非0点为起始点
			for (j = i + 1; j < height.size(); ++j) {
				if (height[j] >= s) {//找到比起始点大或者相等的点
					e = height[j];
					break;
				}
				t += height[j];
				if (j == height.size() - 1) {//没有比起始点小的数了
					--s;//对s进行降高度
					j = i;//重新遍历
					t = 0;//重新计算中间掠过的柱子
				}				
			}
			v += (s < e ? s : e)*(j - i - 1) - t;//计算体积，记得减去中间的掠过体积
			t = 0;//下一步重新计算掠过的体积
			i = j - 1;//换过起始点（即终止点作为新的起始点）
		}
		return v;
	}
};

//下面是看够力扣题解之后的答案
//根据力扣上面的解题提示
//尝试着做一下
//使用暴力法进行解答
//484ms
class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		int size = height.size();
		for (int i = 1; i < size - 1; i++) {
			int max_left = 0, max_right = 0;
			for (int j = i; j >= 0; j--) { //Search the left part for max bar size
				max_left = max(max_left, height[j]);
			}
			for (int j = i; j < size; j++) { //Search the right part for max bar size
				max_right = max(max_right, height[j]);
			}
			ans += min(max_left, max_right) - height[i];
		}
		return ans;
	}
};
//
//
//使用动态规划20ms
//
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() == NULL)return 0;
		int ans = 0;
		int size = height.size();
		vector<int> left_max(size), right_max(size);
		left_max[0] = height[0];
		for (int i = 1; i < size; i++) {
			left_max[i] = max(height[i], left_max[i - 1]);
		}
		right_max[size - 1] = height[size - 1];
		for (int i = size - 2; i >= 0; i--) {
			right_max[i] = max(height[i], right_max[i + 1]);
		}
		for (int i = 1; i < size - 1; i++) {
			ans += min(left_max[i], right_max[i]) - height[i];
		}
		return ans;
	}
};
//
//
//使用堆栈法28ms
//
class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0, current = 0;
		stack<int> st;
		while (current < height.size()) {
			while (!st.empty() && height[current] > height[st.top()]) {
				int top = st.top();
				st.pop();
				if (st.empty())
					break;
				int distance = current - st.top() - 1;
				int bounded_height = min(height[current], height[st.top()]) - height[top];
				ans += distance * bounded_height;
			}
			st.push(current++);
		}
		return ans;
	}
};
//
//使用双指针法16ms
//
class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int ans = 0;
		int left_max = 0, right_max = 0;
		while (left < right) {
			if (height[left] < height[right]) {
				height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
				++left;
			}
			else {
				height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
				--right;
			}
		}
		return ans;
	}
};


void T042() {
	Solution s;
	vector<int>v;
	v = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << s.trap(v) << endl;
	v = { 4,2,1,2,4 };
	cout << s.trap(v) << endl;
	v = { 0,4,0,3,0,2};
	cout << s.trap(v) << endl;


}