//#include <iostream>
//using namespace std;
//bool isPrime(int x)//�ж��ǲ�������
//{
//	if (x < 3)
//		return x >= 1;
//	for (int i = 2; i*i <= x; ++i)
//		if (x%i == 0)
//			return false;
//	return true;
//}
//int isSexyPrimes(int x)//�ж�����������ĿҪ��
//{
//	if (isPrime(x))
//	{
//		bool fL = isPrime(x - 6), fR = isPrime(x + 6);
//		if (fL || fR)
//			return fL ? x - 6 : x + 6;
//	}
//	return -1;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int res = isSexyPrimes(n);
//	if (res > 0)
//	{
//		printf("Yes\n");
//		printf("%d\n", res);
//	}
//	else
//	{
//		printf("No\n");
//		for (int i = n + 1; i < INT32_MAX; ++i)//��Ѱ�Ҵ�����ֱ������Ҫ��
//		{
//			if (isSexyPrimes(i) > 0)
//			{
//				printf("%d\n", i);
//				break;
//			}
//		}
//	}
//	return 0;
//}