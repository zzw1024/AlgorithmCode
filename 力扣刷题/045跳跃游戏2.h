#include "000�⺯��.h"


//���ǵ�ǰ��Զ�ܵ�ʲô�ط�������2, 3, 1, 1, 4��
//����ֻ����a[0] = 2������Զ���Ե�a[2]��Ȼ���1��2������һ���ɵ�����Զ�㣬
//��a[1]���Ե���a[4]����ʱ�ҵ������������¼Ϊ2�������ſ��ǣ�
//��һ��Ӧ�ô�3 - 4������һ����Զ��a[4]�ɴ�a[8]��4 + 4��, 
//����һ�δ�5 - 8������Զ
//20ms
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() < 2)return 0;
		int min = 0;
		int a = 0, b = 0 + nums[0];//��һ������һ��������
		while (a < nums.size() - 1) {
			min++;	
			int s = MAX(nums, a + 1, b);	//��a,b���ҵ���Զ����
			a = b;
			b = s;
		}
		return min;
	}
	int MAX(vector<int>& nums, int s, int t) {
		int max = s + nums[s];
		for (; s < nums.size() && s <= t; ++s) {
			if (max < s + nums[s])
				max = s + nums[s];
		}
		return max;
	}
};

//���ͽⷨ  20ms
//�ⷨ��˼��һ�����ҵ�������Զ���Ǹ�
class Solution {
public:
	int jump(vector<int>& nums) {
		int res = 0, n = nums.size(), i = 0, cur = 0;
		while (cur < n - 1) {
			++res;
			int pre = cur;
			for (; i <= pre; ++i) {
				cur = max(cur, i + nums[i]);
			}
			if (pre == cur) return -1; // May not need this
		}
		return res;
	}
};


class Solution {
public:
	int jump(vector<int>& nums) {
		int res = 0, n = nums.size(), last = 0, cur = 0;
		for (int i = 0; i < n - 1; ++i) {
			cur = max(cur, i + nums[i]);
			if (i == last) {
				last = cur;
				++res;
				if (cur >= n - 1) break;
			}
		}
		return res;
	}
};
void T045() {
	Solution s;
	vector<int>v;
	v = { 5,5,3,2,1,0,2,3,3,10,0,0 };
	cout << s.jump(v) << endl << "**************" << endl;
	v = { 2,0,2,4,6,0,0,3};
	cout << s.jump(v) << endl << "**************" << endl;
	v = { 2,3,0,1,4 };
	cout << s.jump(v) << endl << "**************" << endl;
	v = { 2,3,1,1,4 };
	cout << s.jump(v) << endl << "**************" << endl;
}