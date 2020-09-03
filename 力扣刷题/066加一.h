#include "_000�⺯��.h"

//��Ҫ����ȡ������ֱ�������һλ�����ж�
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int a = 1;//��������
		int p = digits.size() - 1;//��λ����λ��
		while (p >= 0 && a) {
			a = digits[p] + a;
			digits[p] = a % 10;
			a = a / 10;//�Ƿ��н�λ
			--p;
		}
		if (a) //���н�λ
			digits.insert(digits.begin(), a);
		return digits;
	}
};

//���ǽ�carry��ʼ��Ϊ1��Ȼ���൱��digits����һ��0��
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.empty()) return digits;
		int carry = 1, n = digits.size();
		for (int i = n - 1; i >= 0; --i) {
			if (carry == 0) return digits;
			int sum = digits[i] + carry;
			digits[i] = sum % 10;
			carry = sum / 10;
		}
		if (carry == 1) digits.insert(digits.begin(), 1);
		return digits;
	}
};

void T066() {
	Solution s;
	vector<int>v;
	v = { 9,9,9 };
	v = s.plusOne(v);
	for (auto i : v)
		cout << i;
	cout << endl;
	v = { 1,2,3 };
	v = s.plusOne(v);
	for (auto i : v)
		cout << i;
	cout << endl;
	v = { 1,9,9 };
	v = s.plusOne(v);
	for (auto i : v)
		cout << i;
	cout << endl;

}