#include "000�⺯��.h"

////////////�Խ�1�����ɸѡ�ڸ�ֵ,ʱ�����36ms
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)return nums.size();
		vector<int>v;
		v.push_back(nums[0]);		
		for (int i = 1, j = 0; i < nums.size(); ++i)
			if (nums[i] != nums[i - 1])
				v.push_back(nums[i]);
		nums = v;
		return nums.size();		
	}
};

//////////////�Խ�2��ʹ��set�Զ�ȥ��48ms
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)return nums.size();
		set<int>v;
		v.insert(nums.begin(), nums.end());
		nums.assign(v.begin(), v.end());
		return nums.size();
	}
};

//////////�Խ�3 ʹ���㷨  60ms
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		return std::unique(nums.begin(), nums.end()) - nums.begin();
	}
};

////////////���ͽⷨ1  56ms
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int pre = 0, cur = 0, n = nums.size();
		while (cur < n) {
			if (nums[pre] == nums[cur]) ++cur;
			else nums[++pre] = nums[cur++];
		}
		return pre + 1;
	}
};
//////////////////���ͽⷨ1  56ms
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int j = 0, n = nums.size();
		for (int i = 0; i < n; ++i) {
			if (nums[i] != nums[j]) nums[++j] = nums[i];
		}
		return j + 1;
	}
};

void T026() {
	vector<int>nums = { 0,0,1,1,1,2,2,3,3,4 };
	Solution S;
	cout << S.removeDuplicates(nums) << endl;
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << '\t';
	cout << endl;
}