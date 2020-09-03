#include "_000库函数.h"

//从末尾一位一位的相加
class Solution {
public:
	string addBinary(string a, string b) {
		if (a.empty())return b;
		if (b.empty())return a;
		int p1 = a.size() - 1,p2=b.size()-1;
		string res = p1 > p2 ? a : b;//选用较长的二进制做基
		int p = p1 > p2 ? p1 : p2;
		int s = 0;//进位
		while (p>=0) {
			if (min(p1, p2) >= 0)//两数相加
				s = a[p1--] - '0' + b[p2--] - '0' + s;
			else
				s = res[p] - '0' + s;//进位想加
			
			res[p--] = s % 2 + '0';
			s = s / 2;
		}
		if (s) {//进位
			a = "1";
			res = a + res;
		}
		return res;
	}
};

//下面这种写法又巧妙又简洁，用了两个指针分别指向a和b的末尾，
//然后每次取出一个字符，转为数字，若无法取出字符则按0处理，
//然后定义进位carry，初始化为0，将三者加起来，对2取余即为当前位的数字，
//对2取商即为当前进位的值，记得最后还要判断下carry，如果为1的话，要
//在结果最前面加上一个1，参见代码如下：
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