#include "_000�⺯��.h"

//����ʹ��sort�������ޱ�
//������ĿҪ����ʹ��������

//�ⷨһ�����������ɡ�����ɨ�衿

//class Solution {
//public:
//	void sortColors(vector<int>& nums) {
//		int r = 0, w = 0, b = 0;//������ɫ���ִ�������
//		for (auto a : nums)
//			if (a == 0)++r;
//			else if (a == 1)++w;
//			else ++b;
//		nums.clear();//����
//		nums.insert(nums.end(), r, 0);
//		nums.insert(nums.end(), w, 1);
//		nums.insert(nums.end(), b, 2);
//	}
//};

//�ⷨ����ʹ��һ��ɨ�跨
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0;i<n;){
			vector<int>::iterator p = nums.begin() + i;
			if (nums[i] == 0) {
				nums.erase(p, p + 1);//ɾ��
				nums.insert(nums.begin(), 1, 0);//ǰ��
				++i;
			}
			else if (nums[i] == 2) {
				nums.erase(p, p + 1);//ɾ��
				nums.insert(nums.end(), 1, 2);//���
				--n;
			}
			else//��1������ԭλ
				++i;
		}
	}
};


void T075() {
	Solution s;
	vector<int>v;
	v = { 2,0,2,1,1,0 };
	s.sortColors(v);
	for (auto a : v)
		cout << a << "�� ";
	cout << endl;
}