#include "000库函数.h"

//这道题很简单，将两个字符串变为整数，再相乘后变为字符串即是答案
//但是，由于输入是字符串，长度不限，故无法装换成数字再相乘！！！！！！！会溢出，存不下
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


//标准答案Java版
//class Solution {
//	public String multiply(String num1, String num2) {
//		/**
//		num1的第i位(高位从0开始)和num2的第j位相乘的结果在乘积中的位置是[i+j, i+j+1]
//		例: 123 * 45,  123的第1位 2 和45的第0位 4 乘积 08 存放在结果的第[1, 2]位中
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
//		这样我们就可以单独都对每一位进行相乘计算把结果存入相应的index中
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
//				bitmul += mul[i + j + 1]; // 先加低位判断是否有新的进位
//
//				mul[i + j] += bitmul / 10;
//				mul[i + j + 1] = bitmul % 10;
//			}
//		}
//
//		StringBuilder sb = new StringBuilder();
//		int i = 0;
//		// 去掉前导0
//		while (i < mul.length - 1 && mul[i] == 0)
//			i++;
//		for (; i < mul.length; ++i)
//			sb.append(mul[i]);
//		return sb.toString();
//	}
//}


//只能用容器来计算了,这样数据再长也不怕
//好吧，没想出来怎么乘，并不是辣么简单
//这是参考标准答案改的
/*
				  4   5     6
				* 1   2     3
			——————————
				 12   15   18
			 8   10	  12
		 4   5    6
	————————————
	v _  _   _    _    _    _
	v 0  4   13   28   27   18
	进位处理即得答案
*/

class Solution {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.length();
		int len2 = num2.length();
		vector<int>v(len1 + len2, 0); //用来存放乘积，最后的结果的位数不可能超过len1+len2
		
		for (int i = len1 - 1; i >= 0; i--) {
			for (int j = len2 - 1; j >= 0; j--) {
				v[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');  //此处很巧妙，对应位乘完后相加，并始终不进位
			}
		}

		// 处理进位
		int carry = 0;
		for (int i = len1 + len2 - 1; i >= 0; i--) {
			v[i] += carry;
			carry = v[i] / 10;
			v[i] %= 10;
		}

		string re = "";
		int flag = 1;
		for (int i = 0; i < len1 + len2; ++i) {
			if (v[i] == 0 && flag)continue;//去除前位是0的数
			re += v[i] + '0';
			flag = 0;
		}
		if (flag)
			re += '0';//若全为0即得0
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