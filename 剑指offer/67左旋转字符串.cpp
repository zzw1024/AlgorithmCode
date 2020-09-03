//#include "head.h"
//
//class Solution01 {
//public:
//	string LeftRotateString(string str, int n) {
//		if (str.length() < 2 || n % str.length() == 0)return str;
//		n %= str.length();
//		string a;
//		a.assign(str.begin(), str.begin() + n);
//		str.assign(str.begin() + n, str.end());
//		return str+a;	
//	}
//};
//
//class Solution02 {
//public:
//	string LeftRotateString(string str, int n) {
//		int size = str.length();
//		if (size < 2 || n % size == 0)return str;
//		n %= size;
//		Reverse(str, 0, n - 1);
//		Reverse(str, n, size - 1);
//		Reverse(str, 0, size - 1);
//		return str;
//	}
//private:
//	void Reverse(string &str,int L, int R)
//	{
//		while (L < R) {
//			swap(str[L], str[R]);
//			++L, --R;
//		}
//	}
//};
//
//int main()
//{
//	Solution02 s;
//	cout << s.LeftRotateString("abcdefg", 2) << endl;
//	return 0;
//}