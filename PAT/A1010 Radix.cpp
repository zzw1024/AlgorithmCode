////#include <iostream>
////#include <string>
////#include<math.h>
////#include <cctype>
////#include <algorithm>
////using namespace std;
////
//////最简单的一种一种格式试
////int main()
////{
////	string N1, N2;
////	long long int tag,radix;//防止溢出
////	cin >> N1 >> N2 >> tag >> radix;
////	if (tag == 2)
////	{
////		string N = N2;
////		N2 = N1;
////		N1 = N;
////	}
////	long long int aim = 0, n = 0;//防止化为10制止时溢出
////	for (int i = N1.length() - 1, j = 0; i >= 0; ++j, --i)//将N1划为10进制
////	{
////		n = isdigit(N1[i]) ? (N1[i] - '0') : (N1[i] - 'a' + 10);
////		aim += n * pow(radix, j);
////	}
////	long long int l, r, m;
////	char it = *max_element(N2.begin(), N2.end());//找出最大的元素
////	l = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;//找到N2形成的最小进制	
////	r = max(aim, l);
////	while (l <= r)
////	{
////		m = l + (r - l) / 2;
////		long long int res = 0, n;
////		for (int i = N2.length() - 1, j = 0; i >= 0; ++j, --i)
////		{
////			n = isdigit(N2[i]) ? (N2[i] - '0') : (N2[i] - 'a' + 10);	
////			res += n * pow(m, j);
////		}
////		if (res == aim)
////			break;
////		else if (res<0 || res>aim)
////			r = m - 1;
////		else
////			l = m + 1;
////	}
////	if (l > r)
////		cout << "Impossible" << endl;
////	else
////		cout << m << endl;
////	
////	return 0;
////
////}
//
//#include <iostream>
//#include <string>
//using namespace std;
//long long num1, num2;
//long long func1(string s, long long radix)
//{
//	long long res = 0, index = 1;
//	for (int i = s.length() - 1; i >= 0; --i)
//	{
//		if (s[i] >= 'a' && s[i] <= 'z')
//			res += (s[i] - 'a' + 10) * index;
//		else
//			res += (s[i] - '0') * index;
//		index *= radix;
//	}
//	return res;
//}
//
//long long func2(string s)
//{
//	long long l = 0, r = 36 > num1 ? 36 : num1, mid, res = 0;//切记r的取值
//	while (l <= r)
//	{
//		mid = (l + r) / 2;
//		num2 = func1(s, mid);
//		if (num2 == num1)
//			return mid;
//		else if (num2 < 0 || num2 > num1) //num2<0表示溢出
//			r = mid - 1;
//		else
//			l = mid+1;
//	}
//	return -1;
//}
//
//int main()
//{
//	string a, b;
//	long long tag, radix, res;
//	cin >> a >> b >> tag >> radix;
//	if (tag = 1)
//	{
//		num1 = func1(a, radix);
//	}
//	else
//	{
//		num1 = func1(b, radix);
//		b = a;
//	}	
//	res = func2(b);
//	if (res != -1)
//		cout << res;
//	else
//		cout << "Impossible";
//	return 0;	
//}
//


//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//string n, m;
//int t, k;
////根据进制计算十进制数值
//long long calValue(string x, long long r)
//{
//	if (r == 10)return atoi(x.c_str());
//	long long sum = 0, k = 1;
//	for (int i = x.length()-1;i>=0;--i)
//	{
//		sum += k * (isalpha(x[i]) ? (x[i] - 'a' + 10) : (x[i] - '0'));
//		k *= r;
//	}
//	return sum;
//}
//
//long long calRadix(string x)
//{
//	//首先计算x中的最大数值
//	int maxV = 0;
//	for (auto a : x)
//		maxV = max(maxV, isalpha(a) ? (a - 'a' + 10) : (a - '0'));
//	long long nV = calValue(n, k);//计算n的十进制数
//	long long L = maxV + 1, R = nV, mid;//一定得使用二分法
//	while (L <= R)
//	{
//		mid = L + (R - L) / 2;
//		long long mV = calValue(x, mid);
//		if (nV == mV)
//			return mid;
//		if (mV > nV || mV<0)//mV<0表示溢出，进制太大了
//			R = mid - 1;
//		else
//			L = mid + 1;
//	}
//	return -1;
//}
//int main()
//{
//	cin >> n >> m >> t >> k;
//	if (t == 2)
//		swap(n, m);//记住n为已知的进制数
//	long long res = calRadix(m);
//	if(res>-1)
//		cout << res << endl;
//	else
//		printf("Impossible");
//	return 0;
//}