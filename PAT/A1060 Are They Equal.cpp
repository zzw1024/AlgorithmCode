//#include <iostream>
//#include <string>
//using namespace std;
//string A, B;//注意，10^100超出double的范围，只能使用字符串来存取
//int N;
//int dealString(string &str)//数据预处理,返回数据位数
//{
//	int k = str.find('.');//找到小数点
//	if (k != -1)
//	{
//		str.erase(k, 1);//删除小数点
//		if (str[0] == '0')
//		{
//			k = 0;
//			str.erase(0, 1);//删除第一个0
//		}
//	}
//	else//没有小数
//	{
//		if (str != "0")
//			k = str.length();
//		else
//		{
//			k = 0;
//			str.erase(0, 1);//删除第一个0
//		}
//	}
//	while (!str.empty() && str[0] == '0')
//	{
//		str.erase(0, 1);//输出前面的0
//		k--;//比如0.000128 = 0.128*10^-3
//	}
//	if (str.empty())//这个数就是0
//		k = 0;
//	while (str.length() < N)
//		str += "0";//位数不够0来凑
//	return k;
//}
//
//int main()
//{
//	cin >> N >> A >> B;
//	//使用k1,k2来得到A,B的位数
//	int k1, k2;
//	k1 = dealString(A);
//	k2 = dealString(B);
//	A.assign(A.begin(), A.begin() + N);//取前N位
//	B.assign(B.begin(), B.begin() + N);
//	if (A == B && k1 == k2)
//	{
//		cout << "YES ";
//		cout << "0." << A << "*10^" << k1 << endl;
//	}
//	else
//	{
//		cout << "NO ";
//		cout << "0." << A << "*10^" << k1 << " ";
//		cout << "0." << B << "*10^" << k2 << endl;
//	}
//	return 0;	
//}
//
//
//#include <iostream>
//#include <string>
//using namespace std;
//int k;
//void getNum(string &str,int &m)
//{
//	if (str.length() == 1 && str[0] == '0')//str==0
//		return;
//	int t = str.find('.');
//	if (t != -1)//12.54
//	{
//		m = t;
//		str.erase(k, 1);
//	}
//	else//12345
//		m = str.length();
//	while (str.length() > 0 && str[0] == '0')//0.0038
//	{
//		m--;
//		str.erase(0, 1);
//	}
//	while (str.length() < k)
//		str += '0';
//	str.assign(str.begin(), str.begin() + k);
//}
//int main()
//{
//	string s1, s2, s;
//	int m1 = 0, m2 = 0;
//	cin >> k >> s1 >> s2;
//	getNum(s1, m1);
//	getNum(s2, m2);
//	if (s1 == s2 && m1 == m2)
//		cout << "YES 0." << s1 << "*10^" << m1;
//	else
//		cout << "NO 0." << s1 << "*10^" << m1 << " 0." << s2 << "*10^" << m2;
//	return 0;
//}