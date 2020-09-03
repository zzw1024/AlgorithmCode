#include "000�⺯��.h"

//��һ�ۣ��о�ûʲô�����㷨�ģ�����ͨ���ͺ���
//����Ϊ������ �ģ���ʹ�ö��ַ�����ˡ�����̫�氮�ñ�����ɵ�ӲŻ�һ�����ͱ�����    12ms
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0 || target < nums[0])return 0;//Ϊ�ջ�����̫С��������λ����
		if (target > nums[nums.size() - 1])return nums.size();//̫����β������
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)return mid;
			if (nums[mid] < target) left = mid + 1;//ʹ�������жϣ����ҵ�����ߵ�Ŀ��ֵ
			else right = mid;
		}		
		return right;
	}
};

void T035() {
	Solution s;
	vector<int> nums = { 1,3,5,5,6 };
	cout << "*********************************" << endl;
	cout << s.searchInsert(nums, 4) << endl;
	cout << s.searchInsert(nums, 3) << endl;
	cout << s.searchInsert(nums, 5) << endl;
	cout << s.searchInsert(nums, 6) << endl;
	cout << s.searchInsert(nums, 7) << endl;

}


[[".", ".", ".", ".", "5", ".", ".", "1", "."],
[".", "4", ".", "3", ".", ".", ".", ".", "."],
[".", ".", ".", ".", ".", "3", ".", ".", "1"],
["8", ".", ".", ".", ".", ".", ".", "2", "."],
[".", ".", "2", ".", "7", ".", ".", ".", "."],
[".", "1", "5", ".", ".", ".", ".", ".", "."],
[".", ".", ".", ".", ".", "2", ".", ".", "."],
[".", "2", ".", "9", ".", ".", ".", ".", "."],
[".", ".", "4", ".", ".", ".", ".", ".", "."]]