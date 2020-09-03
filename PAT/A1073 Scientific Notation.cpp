////#include <iostream>
////#include <string>
////using namespace std;
////int main()
////{
////	string str, f1, num1, num2, f2, num3, res = "";
////	cin >> str;
////	int nDot, E, Exp = 0;
////	f1 = str[0];
////	nDot = str.find('.');
////	num1 = str[nDot - 1];//第一位数字
////	E = str.find('E');
////	num2.assign(str.begin() + nDot + 1, str.begin() + E);//小数点后面的数字
////	f2 = str[E + 1];
////	num3.assign(str.begin() + E + 2, str.end());//指数
////	for (int i = 0; i < num3.length(); ++i)//计算指数
////		Exp = Exp * 10 + num3[i] - '0';
////	if (f1 == "-")
////		res += "-";
////	if (f2 == "-")
////	{
////		res += "0.";
////		res.insert(res.end(), Exp - 1, '0');//中间插入0
////	}
////	else if (f2 == "+")
////	{
////		if (num2.length() <= Exp)//小数位不足，则直接末尾加0；
////			num2.insert(num2.end(), Exp - num2.length(), '0');
////		else//小数位多余幂次，则小数点后移
////			num2.insert(num2.begin() + Exp, 1, '.');
////	}
////	res += num1 + num2;
////	cout << res << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str, num1, num2;
//	cin >> str;
//	int pot = str.find('E');
//	num1.assign(str.begin(), str.begin() + pot);
//	num2.assign(str.begin() + pot + 1, str.end());
//	if (num1[0] == '-')
//		printf("-");
//	num1.erase(0, 1);	
//	int p = atoi(num2.c_str());
//	pot = num1.find('.');
//	int L = 0;
//	if (pot != -1)
//	{
//		L = num1.length() - pot - 1;
//		num1.erase(pot, 1);
//	}
//	if (p < 0)
//	{
//		printf("0.");
//		for (int i = 1; i < (-p); ++i)
//			printf("0");
//		cout << num1;
//	}
//	else
//	{	
//		if (p - L < 0)
//		{
//			if (num1[0] == '0')
//				num1.erase(0, 1);
//			num1.insert(num1.begin() + p, '.');
//		}	
//		cout << num1;
//		for (int i = 0; i < p - L; ++i)
//			printf("0");
//	}
//	return 0;
//}