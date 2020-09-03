#include "_000�⺯��.h"

//��ĩβһλһλ�����
class Solution {
public:
	string addBinary(string a, string b) {
		if (a.empty())return b;
		if (b.empty())return a;
		int p1 = a.size() - 1,p2=b.size()-1;
		string res = p1 > p2 ? a : b;//ѡ�ýϳ��Ķ���������
		int p = p1 > p2 ? p1 : p2;
		int s = 0;//��λ
		while (p>=0) {
			if (min(p1, p2) >= 0)//�������
				s = a[p1--] - '0' + b[p2--] - '0' + s;
			else
				s = res[p] - '0' + s;//��λ���
			
			res[p--] = s % 2 + '0';
			s = s / 2;
		}
		if (s) {//��λ
			a = "1";
			res = a + res;
		}
		return res;
	}
};

//��������д���������ּ�࣬��������ָ��ֱ�ָ��a��b��ĩβ��
//Ȼ��ÿ��ȡ��һ���ַ���תΪ���֣����޷�ȡ���ַ���0����
//Ȼ�����λcarry����ʼ��Ϊ0�������߼���������2ȡ�༴Ϊ��ǰλ�����֣�
//��2ȡ�̼�Ϊ��ǰ��λ��ֵ���ǵ����Ҫ�ж���carry�����Ϊ1�Ļ���Ҫ
//�ڽ����ǰ�����һ��1���μ��������£�
class Solution {
public:
	string addBinary(string a, string b) {
		string res = "";
		int m = a.size() - 1, n = b.size() - 1, carry = 0;
		while (m >= 0 || n >= 0) {
			int p = m >= 0 ? a[m--] - '0' : 0;
			int q = n >= 0 ? b[n--] - '0' : 0;
			int sum = p + q + carry;
			res = to_string(sum % 2) + res;
			carry = sum / 2;
		}
		return carry == 1 ? "1" + res : res;
	}
};
void T067() {
	Solution s;
	string a, b;
	a = "11";
	b = "1";
	cout << s.addBinary(a, b) << endl;
	a = "1010";
	b = "1011";
	cout << s.addBinary(a, b) << endl;
	a = "11010";
	b = "";
	cout << s.addBinary(a, b) << endl;


}