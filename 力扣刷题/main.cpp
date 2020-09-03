//#include <iostream>
//using namespace std;
//
//double helper(int n, int m)
//{
//	if (n <= 0)return 0;
//	if (m <= 0)return 1;
//	double res = double(n) / double(n + m);//直接赢的概率
//	if (m < 2)return res;
//	res += double(m) / double(n + m) * double(m - 1) / double(n + m - 1) *  //没中奖，但B也应该摸不中奖
//		(double(n) / double(n + m - 2)*helper(n - 1, m - 2) + double(m - 2) / double(n + m - 2)*helper(n, m - 3));
//	return res;
//}
//
//int main()
//{
//	int n, m;
//	while (cin >> n >> m)
//	{
//		double res = 0.0;
//		res = helper(n, m);
//		printf("%.4f\n", res);
//	}
//}
//
