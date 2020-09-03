#include "_000库函数.h"

//自解  68ms  弱爆了
//先找到最大值，然后确定目标值在最大值的左边还是右边
//最后使用折中寻找法，找到目标值的位置,此方法应该满足复杂度不超过logn的要求
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)return -1;

		int maxValue = *max_element(nums.begin(), nums.end());//最大值
		int maxPosition = max_element(nums.begin(), nums.end()) - nums.begin();//最大值的位置 
		if (target > maxValue)return -1;
		if (target == maxValue)return maxPosition;
		int i, j, t;
		if (target >= nums[0]) {
			i = 0;
			j = maxPosition;
		}
		else {
			i = maxPosition+1;
			j = nums.size() - 1;
		}		
		while (i <= j) {
			t = (i + j) / 2;
			if (target == nums[t])
				return t;
			else if (target > nums[t])
				i = t + 1;
			else
				j = t - 1;
		}
		return -1;
	}
};

//这道题的关键在与，找到哪一部分是升序的
//旋转数组有个特点，中间数的左右两边有一边一定是升序的，另一边就不一定了
//此种解法满足复杂度logn的要求  20ms
/*

0　　1　　2　　 4　　5　　6　　7

7　　0　　1　　 2　　4　　5　　6

6　　7　　0　　 1　　2　　4　　5

5　　6　　7　　 0　　1　　2　　4

4　　5　　6　　7　　0　　1　　2

2　　4　　5　　6　　7　　0　　1

1　　2　　4　　5　　6　　7　　0


*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)return -1;
		int i = 0, j = nums.size() - 1;
		while (i <= j) {
			int t = i + (j - i) / 2;//找到此时序列的中间位置
			if (target == nums[t])return t;
			if (nums[t] < nums[j]) {	//此时右边为升序
				if (nums[t] < target&&target <= nums[j])//目标函数位于右边
					i = t + 1;
				else
					j = t - 1;
			}
			else {
				if (nums[i] < target && nums[t]>target)
					j = t - 1;
				else
					i = t + 1;
			}
		}
		return -1;
	}
};


class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)return -1;
		for (int i = 0; i < nums.size(); ++i) {
			if (target == nums[i])
				return i;
		}
		return -1;



	}
};

void T033() {
	Solution s;
	vector<int>n;
	n = { 3,1 };
	cout << s.search(n, 1) << endl;
	n = { 4,5,6,7,0,1,2 };
	cout << s.search(n, 4) << endl;
	n = { 4,5,6,7,0,1,2 };
	cout << s.search(n, 7) << endl;
	n = { 4,5,6,7,0,1,2 };
	cout << s.search(n, 2) << endl;
	n = { 4,5,6,7,0,1,2 };
	cout << s.search(n, 0) << endl;

}