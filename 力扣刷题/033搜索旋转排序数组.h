#include "_000�⺯��.h"

//�Խ�  68ms  ������
//���ҵ����ֵ��Ȼ��ȷ��Ŀ��ֵ�����ֵ����߻����ұ�
//���ʹ������Ѱ�ҷ����ҵ�Ŀ��ֵ��λ��,�˷���Ӧ�����㸴�ӶȲ�����logn��Ҫ��
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)return -1;

		int maxValue = *max_element(nums.begin(), nums.end());//���ֵ
		int maxPosition = max_element(nums.begin(), nums.end()) - nums.begin();//���ֵ��λ�� 
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

//�����Ĺؼ����룬�ҵ���һ�����������
//��ת�����и��ص㣬�м���������������һ��һ��������ģ���һ�߾Ͳ�һ����
//���ֽⷨ���㸴�Ӷ�logn��Ҫ��  20ms
/*

0����1����2���� 4����5����6����7

7����0����1���� 2����4����5����6

6����7����0���� 1����2����4����5

5����6����7���� 0����1����2����4

4����5����6����7����0����1����2

2����4����5����6����7����0����1

1����2����4����5����6����7����0


*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)return -1;
		int i = 0, j = nums.size() - 1;
		while (i <= j) {
			int t = i + (j - i) / 2;//�ҵ���ʱ���е��м�λ��
			if (target == nums[t])return t;
			if (nums[t] < nums[j]) {	//��ʱ�ұ�Ϊ����
				if (nums[t] < target&&target <= nums[j])//Ŀ�꺯��λ���ұ�
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