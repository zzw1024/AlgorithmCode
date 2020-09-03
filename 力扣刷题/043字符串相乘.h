#include "000�⺯��.h"

//�����ܼ򵥣��������ַ�����Ϊ����������˺��Ϊ�ַ������Ǵ�
//���ǣ������������ַ��������Ȳ��ޣ����޷�װ������������ˣ���������������������治��
//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		if (num1.empty() || num2.empty())return "";
//		string Res ;
//		deque<char> d;
//		long int ans = 0, n1 = 0, n2 = 0;
//		int size = num1.size() > num2.size() ? num1.size() : num2.size();
//		for (int i = 0; i < size; ++i) {
//			if (i < num1.size())n1 = n1 * 10 + (num1[i] - '0');
//			if (i < num2.size())n2 = n2 * 10 + (num2[i] - '0');
//		}
//		ans = n1 * n2;
//		while (ans) {
//			d.push_front(ans % 10 + '0');
//			ans = ans / 10;
//		}
//		Res.assign(d.begin(), d.end());
//		return Res;		
//	}
//};


//��׼��Java��
//class Solution {
//	public String multiply(String num1, String num2) {
//		/**
//		num1�ĵ�iλ(��λ��0��ʼ)��num2�ĵ�jλ��˵Ľ���ڳ˻��е�λ����[i+j, i+j+1]
//		��: 123 * 45,  123�ĵ�1λ 2 ��45�ĵ�0λ 4 �˻� 08 ����ڽ���ĵ�[1, 2]λ��
//		  index:    0 1 2 3 4
//
//						1 2 3
//					*     4 5
//					---------
//						  1 5
//						1 0
//					  0 5
//					---------
//					  0 6 1 5
//						1 2
//					  0 8
//					0 4
//					---------
//					0 5 5 3 5
//		�������ǾͿ��Ե�������ÿһλ������˼���ѽ��������Ӧ��index��
//		**/
//
//		int n1 = num1.length() - 1;
//		int n2 = num2.length() - 1;
//		if (n1 < 0 || n2 < 0) return "";
//		int[] mul = new int[n1 + n2 + 2];
//
//		for (int i = n1; i >= 0; --i) {
//			for (int j = n2; j >= 0; --j) {
//				int bitmul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
//				bitmul += mul[i + j + 1]; // �ȼӵ�λ�ж��Ƿ����µĽ�λ
//
//				mul[i + j] += bitmul / 10;
//				mul[i + j + 1] = bitmul % 10;
//			}
//		}
//
//		StringBuilder sb = new StringBuilder();
//		int i = 0;
//		// ȥ��ǰ��0
//		while (i < mul.length - 1 && mul[i] == 0)
//			i++;
//		for (; i < mul.length; ++i)
//			sb.append(mul[i]);
//		return sb.toString();
//	}
//}


//ֻ����������������,���������ٳ�Ҳ����
//�ðɣ�û�������ô�ˣ���������ô��
//���ǲο���׼�𰸸ĵ�
/*
				  4   5     6
				* 1   2     3
			��������������������
				 12   15   18
			 8   10	  12
		 4   5    6
	������������������������
	v _  _   _    _    _    _
	v 0  4   13   28   27   18
	��λ�����ô�
*/

class Solution {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.length();
		int len2 = num2.length();
		vector<int>v(len1 + len2, 0); //������ų˻������Ľ����λ�������ܳ���len1+len2
		
		for (int i = len1 - 1; i >= 0; i--) {
			for (int j = len2 - 1; j >= 0; j--) {
				v[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');  //�˴��������Ӧλ�������ӣ���ʼ�ղ���λ
			}
		}

		// �����λ
		int carry = 0;
		for (int i = len1 + len2 - 1; i >= 0; i--) {
			v[i] += carry;
			carry = v[i] / 10;
			v[i] %= 10;
		}

		string re = "";
		int flag = 1;
		for (int i = 0; i < len1 + len2; ++i) {
			if (v[i] == 0 && flag)continue;//ȥ��ǰλ��0����
			re += v[i] + '0';
			flag = 0;
		}
		if (flag)
			re += '0';//��ȫΪ0����0
		return re;
	}
};


void T043() {
	Solution s;
	string num1;
	string num2;
	num1 = "2";
	num2 = "3";
	cout << s.multiply(num1, num2) << endl;
	num1 = "123";
	num2 = "456";
	cout << s.multiply(num1, num2) << endl;
	num1 = "0";
	num2 = "456";
	cout << s.multiply(num1, num2) << endl;
}