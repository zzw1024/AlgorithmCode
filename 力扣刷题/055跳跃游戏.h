#include "000�⺯��.h"

//����ǰ�����Ծ��Ϸ����
//ÿ����Ծ�ҳ���Ծ��Զ��λ�ӣ�������������һ��������
//���гɹ�16ms
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int left=0, right=nums[0]+0;
		while (right < n-1) {		
			int maxN = right;
			for (int k = left + 1; k <= right; ++k)//��֮��������������Զλ��
				maxN = maxN > (nums[k] + k) ? maxN : (nums[k] + k);
			left = right;
			right = maxN;
			if (left >= right)
				return false;
		}	
		return true;
	}

};

//���������ƣ��������
//ֻ������������Զ��λ��
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size(), reach = 0;
		for (int i = 0; i < n; ++i) {
			if (i > reach || reach >= n - 1) break;
			reach = max(reach, i + nums[i]);
		}
		return reach >= n - 1;
	}
};

//ʹ�ö�̬�滮
//���ﵱǰλ�õ�ʣ�ಽ����ʲô�й��أ���ʵ�Ǹ���һ��λ�õ�ʣ�ಽ������һ��λ�õ������йأ�
//�������������ԭ������ÿ��λ�õ����֣���Ϊ��������Ե�ǰλ��Ϊ����ܵ������Զλ�á�
//���Ե�ǰλ�õ�ʣ�ಽ����dpֵ���͵�ǰλ�õ������еĽϴ��Ǹ��������˵�ǰ�ܵ�����Զ���룬
//����һ��λ�õ�ʣ�ಽ����dpֵ���͵��ڵ�ǰ������ϴ�ֵ��ȥ1����Ϊ��Ҫ��һ������������һ��λ�ã�
//�������Ǿ���״̬ת�Ʒ����ˣ�dp[i] = max(dp[i - 1], nums[i - 1]) - 1��
//�����ĳһ��ʱ��dp�����ֵΪ���ˣ�˵���޷��ִﵱǰλ�ã���ֱ�ӷ���false��
//���ѭ��������ֱ�ӷ���true���ɣ��������£�
class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		for (int i = 1; i < nums.size(); ++i) {
			dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
			if (dp[i] < 0) return false;
		}
		return true;
	}
};



void T055() {
	Solution s;
	vector<int>v;
	v = { 0,1 };
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.canJump(v) << endl;
	v = { 3,4,0,1,0,0,3,0 };
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.canJump(v) << endl;
	v = { 3,4,2,1,0,7,5,2,8 };
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.canJump(v) << endl;
	v = { 2,3,1,1,4 };
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.canJump(v) << endl;
	v = { 3,2,1,8,4};
	for (auto a : v)
		cout << a << "  ";
	cout << endl << s.canJump(v) << endl;
}
