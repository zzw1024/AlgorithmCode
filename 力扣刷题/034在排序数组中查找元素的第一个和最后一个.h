#include "000库函数.h"

//使用二分法查找到目标值的位置，然后分两边再查找出起始位置和终止位置
//16ms  不是严格意义上的logn的复杂度
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int>v = { -1,-1 };
		int i = 0, j = nums.size() - 1;
		int m = -1;
		while (i <= j) {
			int t = (i + j) / 2;
			if (nums[t] == target) {
				m = t;
				break;
			}
			if (nums[t] > target)	j = t - 1;
			else i = t + 1;
		}
		if (m == -1) return v;	
		int t = m;
		while (t >= 0 && nums[t] == target) --t; 
		v[0] = (t + 1);
		t = m;
		while (t < nums.size() && nums[t] == target) ++t;
		v[1] = (t - 1);
		return v;
	}
};

//复杂度满足logn   
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {		
		vector<int> res(2, -1);
		if (nums.size() == 0)return res;
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) left = mid + 1;//使用这种判断，会找到最左边的目标值
			else right = mid;
		}
		if (nums[right] != target) return res;

		res[0] = right;
		right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] <= target) left = mid + 1;//使用这种判断，会找到最右边的目标值
			else right = mid;
		}
		res[1] = left - 1;
		return res;
	}
};
void T034() {
	Solution s;
	vector<int >n;
	n = { 8 };
	n = s.searchRange(n, 8);
	cout << n[0] << "  " << n[1] << endl;
	n = { 5,7,7,8,8,10 };
	n = s.searchRange(n, 9);
	cout << n[0] << "  " << n[1] << endl;
	n = { 5,7,7,8,8,8,10 };
	n = s.searchRange(n, 8);
	cout << n[0] << "  " << n[1] << endl;
	n = { 1,1,1,1,1,1};
	n = s.searchRange(n,1);
	cout << n[0] << "  " << n[1] << endl;

}