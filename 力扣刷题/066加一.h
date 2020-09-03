#include "_000库函数.h"

//不要将其取出来，直接在最后一位进行判断
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int a = 1;//保留余数
		int p = digits.size() - 1;//个位数的位置
		while (p >= 0 && a) {
			a = digits[p] + a;
			digits[p] = a % 10;
			a = a / 10;//是否有进位
			--p;
		}
		if (a) //仍有进位
			digits.insert(digits.begin(), a);
		return digits;
	}
};

//我们将carry初始化为1，然后相当于digits加了一个0，
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