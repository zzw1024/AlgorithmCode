////#include <iostream>
////#include <cmath>
////const int maxn = 100010;
////bool isprime(int n)
////{//判断n是否为素数
////	if (n == 1)
////		return false;
////	int sqr = (int)sqrt(1.0*n);
////	for (int i = 2; i <= sqr; i++)
////	{
////		if (n % i == 0)
////			return false;
////	}
////	return true;
////}
////int prime[maxn], pNum = 0;
////void FindPrime()
////{//求素数表
////	for (int i = 1; i < maxn; i++)
////	{
////		if (isprime(i) == true)
////			prime[pNum++] = i;
////	}
////}
////struct factor 
////{
////	int x,cnt;//x为质因子，cnt为其个数
////}fac[10];
////
////int main()
////{
////	FindPrime();//此句必须记得写
////	int n, num = 0;//num为n的不同质因子的个数
////	scanf("%d", &n);
////	if (n == 1)
////		printf("1=1");//特判1的情况
////	else
////	{
////		printf("%d=", n);
////		int sqr = (int)sqrt(1.0*n);//n的根号
////		//枚举根号n以内的质因子
////		for (int i = 0; i < pNum&&prime[i] <= sqr; i++)
////		{
////			if (n%prime[i] == 0)//如果prime[i]是n的因子
////			{
////				fac[num].x = prime[i];//记录该因子
////				fac[num].cnt = 0;
////				while (n%prime[i] == 0)
////				{//计算出质因子prime[i]的个数
////					fac[num].cnt++;
////					n /= prime[i];
////				}
////				num++;//不同质因子个数加1
////			}
////			if (n == 1)
////				break;//及时退出循环，节省点时间
////		}
////		if (n != 1)
////		{//如果无法被根号n以内的质因子除尽
////			fac[num].x = n;//那么一定有一个大于根号n的质因子
////			fac[num++].cnt = 1;
////		}
////		//按格式输出结果
////		for (int i = 0; i < num; i++)
////		{
////			if (i > 0)
////				printf("*");
////			printf("%d", fac[i].x);
////			if (fac[i].cnt > 1)
////				printf("^%d", fac[i].cnt);
////		}
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//long long int n;
//vector<int>prime;
//void getPrime(vector<bool>&isPrime)
//{
//	for (int i = 2; i <= n; ++i)
//	{
//		if (isPrime[i] == false)
//		{
//			prime.push_back(i);
//			for (int j = i + i; j <= n; j += i)
//				isPrime[j] = true;
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	printf("%ld=", n);
//	vector<bool>isPrime(n+1, false);
//	getPrime(isPrime);
//	for (int i = 0; i < prime.size(); ++i)
//	{
//		int m = 0;
//		while (n%prime[i] == 0)
//		{
//			m++;
//			n /= prime[i];
//		}
//		if (n == 1)
//			break;
//		else if (isPrime[n] == false)
//		{
//			printf("%d", n);
//			break;
//		}
//		if (m > 0)
//			if (m > 1)
//				printf("%d^%d*", prime[i], m);
//			else
//				printf("%d*", m);
//	}
//	return 0;
//}