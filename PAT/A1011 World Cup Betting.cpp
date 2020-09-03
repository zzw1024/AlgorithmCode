////#include <iostream>
////using namespace std;
//////我只能说是弱智题，找到每场必赛的最大赔率就行
////int main()
////{
////	double a, b, c, p[3];
////	char res[3];
////	for (int i = 0; i < 3; ++i)
////	{
////		cin >> a >> b >> c;
////		if (a > b && a > c)
////		{
////			p[i] = a;
////			res[i] = 'W';
////
////		}
////		else if (b > a && b > c)
////		{
////			p[i] = b;
////			res[i] = 'T';
////		}
////		else
////		{
////			p[i] = c;
////			res[i] = 'L';
////		}	
////	}
////	a = 1.0;
////	for (int i = 0; i < 3; ++i)
////	{
////		cout << res[i] << " ";
////		a *= p[i];
////	}
////	printf("%.2f\n", (a * 0.65 - 1) * 2 + 0.0000005);//由于double存在精度问题，所以加一位
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	char res[3];
//	double num[3];
//	double w, t, l, maxV;
//	for (int i = 0; i < 3; ++i)
//	{
//		cin >> w >> t >> l;
//		if (w >= t&& w >= l)
//		{
//			res[i] = 'W';
//			num[i] = w;
//		}
//		else if (t >= l && t >= w)
//		{
//			res[i] = 'T';
//			num[i] = t;
//		}
//		else
//		{
//			res[i] = 'L';
//			num[i] = l;
//		}		
//	}
//	printf("%c %c %c %.2f", res[0], res[1], res[2], (num[0] * num[1] * num[2] * 0.65 - 1) * 2);
//	return 0;
//}
