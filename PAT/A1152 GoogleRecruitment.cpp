//#include <iostream>
//#include <vector>
//#include <string>
//#include <cmath>
//using namespace std;
//int n, k;
//string str, res = "";
////void getPrimeTable(int inf, vector<bool>&notPrime)//创建素数表
////{
////	notPrime[0] = notPrime[1] = true;
////	for (int i = 2; i <= inf; ++i)
////		if (notPrime[i] == false)//从2这个素数开始
////			for (int j = 2; j*i <= inf; ++j)
////				notPrime[j*i] = true;//剔除素数的所有倍数
////}
//
//bool isPrime(int x)//判断是不是素数
//{
//	if (x < 3)
//		return true;
//	for (int i = 2; i*i <= x; ++i)
//		if (x%i == 0)
//			return false;
//	return true;
//}
//int main()
//{
//	cin >> n >> k;
//	cin >> str;
//	//int size = (int)pow(10, k);
//	//vector<bool>notPrime(size+1, false);//防止内存太大，我这里是动态建立数组的
//	//getPrimeTable(size, notPrime);//创建素数表
//	for (int i = 0; i + k <= n; ++i)
//	{
//
//		string s = str.substr(i, k);
//		int num = atoi(s.c_str());
//		if (isPrime(num))//notPrime[num]==false)//使用的代码简单的素数判断，注释的代码是使用素数表
//		{
//			res = s;
//			break;
//		}
//	}
//	if (res.size() > 0)
//		cout<<res;
//	else
//		cout << "404";
//	return 0;
//}
