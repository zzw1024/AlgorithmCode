#include "_000�⺯��.h"


//����ĿҪ������ʹ�ö�����ڴ�ռ�
//ֻ����ԭ�����϶���
//����Ϊ�������������飬�ʼ򵥵�
//������ŷ��֣���Ŀ�����㽫�������������ƣ���̨������ �������鳤�ȴ�ӡ����
//ԭ�����Ƿ��س�����ô��

//����һ��ʹ��ɾ��
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2)return nums.size();
		int n = 0, res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			n = 1;
			while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {				
				++n;
				++i;
			}		
			if (n > 2) {
				vector<int>::iterator pt = nums.begin() + res+1;
				nums.erase(pt, pt + n - 2);//ɾ�������Ԫ��
				i -= n - 2;
			}
			res += n > 2 ? 2 : n;
		}
		return res;
	}
};


void T080() {
	Solution s;
	vector<int>v;
	v = { 1, 1, 1, 2, 2, 3 };
	cout << s.removeDuplicates(v) << endl;
	for (auto a : v)
		cout << a << " ";
	cout << endl;
	v = { 0,0,1,1,1,1,2,3,3 };
	cout << s.removeDuplicates(v) << endl;
	for (auto a : v)
		cout << a << " ";
	cout << endl;
}