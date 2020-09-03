////#include <iostream>
////using namespace std;
////long long N, A, B, C, sum;
////int main()
////{
////	cin >> N;
////	for (int i = 1; i <= N; ++i)
////	{
////		cin >> A >> B >> C;
////		sum = A + B;
////		if (A > 0 && B > 0 && sum < 0)//正溢出
////			cout << "Case #" << i << ": " << "true" << endl;
////		else if (A < 0 && B < 0 && sum >= 0)//负溢出
////			cout << "Case #" << i << ": " << "false" << endl;
////		else if(sum>C)
////			cout << "Case #" << i << ": " << "true" << endl;
////		else
////			cout << "Case #" << i << ": " << "false" << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//int main()
//{
//	long long A, B, C, sum;
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> A >> B >> C;
//		sum = A + B;
//		if ((sum<0 && A>0 &&B>0)||(sum>C && !(A<0 && B<0 && sum>=0)))//是正溢出,或者不是负溢出
//			printf("Case #%d: true\n", i);
//		else
//			printf("Case #%d: false\n", i);
//	}
//	return 0;
//}