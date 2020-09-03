//////#include "head.h"
//////
//////class Solution01 {
//////public:
//////	int  NumberOf1(int n) {
//////		int cnt = 0;
//////		while (n)
//////		{
//////			if (n & 1)cnt++;
//////			n = n >> 1;
//////		}
//////		return cnt;
//////	}
//////};
//////
//////class Solution02 {
//////public:
//////	int  NumberOf1(int n) {
//////		int cnt = 0;
//////		unsigned num = 1;//一定是无符号的！！！
//////		while (num)
//////		{
//////			if (n & num)cnt++;
//////			num = num << 1;//num<<1不能改变num的
//////		}
//////		return cnt;
//////	}
//////};
//////
//////class Solution03 {
//////public:
//////	int  NumberOf1(int n) {
//////		int cnt = 0;
//////		while (n)
//////		{
//////			++cnt;
//////			n = (n - 1)&n;
//////		}
//////		return cnt;
//////	}
//////};#include "head.h"
//////
//////class Solution01 {
//////public:
//////	int  NumberOf1(int n) {
//////		int cnt = 0;
//////		while (n)
//////		{
//////			if (n & 1)cnt++;
//////			n = n >> 1;
//////		}
//////		return cnt;
//////	}
//////};
//////
//////class Solution02 {
//////public:
//////	int  NumberOf1(int n) {
//////		int cnt = 0;
//////		unsigned num = 1;//一定是无符号的！！！
//////		while (num)
//////		{
//////			if (n & num)cnt++;
//////			num = num << 1;//num<<1不能改变num的
//////		}
//////		return cnt;
//////	}
//////};
//////
//////class Solution03 {
//////public:
//////	int  NumberOf1(int n) {
//////		int cnt = 0;
//////		while (n)
//////		{
//////			++cnt;
//////			n = (n - 1)&n;
//////		}
//////		return cnt;
//////	}
//////};
////
////#include "head.h"
////class Solution {
////public:
////	int hammingWeight(uint32_t n) {
////		int res = 0;
////		while (n > 0)
////		{
////			++res;
////			n &= n - 1;
////		}
////		return res;
////	}
////};
////
////
////int main()
////{
////	Solution s;
////	cout << s.hammingWeight(01000000000000000000000000001011)<< endl;
////	return 0;
////}
//
//
//
//#include "head.h"
//
//class Base
//{
//public:
//	void print() { cout << "hello" << endl; }
//};
//
//Base temp()
//{
//	return Base();
//}
//
//int main()
//{
//	Base a = temp();
//	return 0;
//}