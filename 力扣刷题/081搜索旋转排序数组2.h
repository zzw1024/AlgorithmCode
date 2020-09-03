#include "_000�⺯��.h"

//mmp,û������Ŀ������ת�а�ëǮ��ϵѽ��
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty())return false;
		for (auto a : nums)
			if (target == a)return true;
		return false;
	}
};

//���˲��Ͳ�֪������ν����ת��������ȷ����תλ�ú�ʹ�ö��ַ����в���
//��Ϊʹ����ͨ�ı������Ӷ�̫��
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty())return false;
		//����ʹ�ö��ַ��ҵ���ת�㣬
		//��ʹ�ö��ַ��������ֲ���
		int left = 0, right = nums.size(), mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] == target)return true;
			if (nums[mid] < nums[right]) {
				if (nums[mid] < target && nums[right] >= target)left = mid + 1;
				else right = mid - 1;
			}
			else if (nums[mid] > nums[right]) {
				if (nums[left] <= target && nums[mid] > target)right = mid - 1;
				else left = mid + 1;
			}
			else --right;
		}

	}
};
