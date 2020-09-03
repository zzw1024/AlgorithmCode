#include "000�⺯��.h"


//������Ȼ����ֵ
//�Լ��Ľⷨ 12ms
//class Solution {
//public:
//	int firstMissingPositive(vector<int>& nums) {
//		sort(nums.rbegin(),nums.rend());//�����������������
//		for (int i = nums.size() - 1; i >= 0; --i)
//			if (nums[i] < 1)nums.pop_back();//��С��1����ɾ��
//		if (nums.size() == 0 || nums[nums.size()-1] > 1)return 1;//������Ϊ�ջ�����Сֵ����1���򷵻�1
//		if (nums.size() == 1)return nums[0] == 1 ? 2 : 1;//����ֻ��1��Ԫ��ʱ������1���ͷ���2���򷵻�1
//		for (int i = nums.size() - 2; i >= 0; --i) {
//			if (nums[i] - nums[i + 1] > 1)//�ҵ��������1������������
//				return nums[i + 1] + 1;//���ؽ�С��+1
//		}		
//		return nums[0] + 1;//���������+1
//	}
//};


//�ڶ��ֽⷨ������
//�����򣬽�С��1����ɾ����Ȼ�����ʣ�µ������������½Ǳ겻�Ǹ�ֵ���򷵻ظ���
//����Ϊ��ܿ죬������12ms,�����Ӻܺã�������أ�
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());//����
		vector<int>v;
		v.push_back(0);//��0���±�Ϊ0��λ��ռ��
		for (int i = 0, j = 0; i < nums.size(); ++i) {
			if (nums[i] < 1 || nums[i] == v.back())continue;//�ų�С��1������ȥ���ظ�����
			v.push_back(nums[i]);
			++j;
			if (j != nums[i])return j;//С�Ǳ�δ��ô������ֶ�Ӧ
		}	
		return v.back() + 1;//ԭ�����������ģ����������+1��
	}
};


//���͵Ľ��
//����ô�о�����һ����
//�����������Լ����ģ�ԭ��һ�������½Ǳ�
//ͬ��12ms
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) return i + 1;
		}
		return n + 1;
	}
};

void T041() {
	Solution s;
	vector<int>n;
	n = {2,1 };
	cout << s.firstMissingPositive(n) << endl;
	n = { 3,4,-1,1 };
	cout << s.firstMissingPositive(n) << endl;
	n = { 7,8,9,11,12 };
	cout << s.firstMissingPositive(n) << endl;
	n = {100,-9};
	cout << s.firstMissingPositive(n) << endl;
	n = { 0,2,2,1,1 };
	cout << s.firstMissingPositive(n) << endl;
}