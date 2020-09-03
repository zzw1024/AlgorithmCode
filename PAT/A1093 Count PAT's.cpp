////#include <iostream>
////#include <vector>
////#include <string>
////using namespace std;
////string str;
////vector<int>P, A, T;
////int main()
////{
////	cin >> str;
////	int dp[100100] = { 0 };
////	for (int i = 1; i < str.length(); ++i)
////	{
////		dp[i] = dp[i - 1];
////		if (str[i - 1] == 'P')
////			dp[i]++;
////	}
////	long long int res = 0;
////	int n = 0;
////	for (int i = str.size() - 1; i >= 0; --i)
////	{
////		if (str[i] == 'T')
////			n++;
////		else if (str[i] == 'A')
////			res = (res + dp[i] * n) % 1000000007;
////	}
////	cout << res << endl;
////	return 0;
////}
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	cin >> str;
//	vector<int>PN(str.length(),0), TN(str.length(),0);
//	int numP = 0, numT = 0;
//	for (int i = 0; i < str.length(); ++i)
//	{
//		if (str[i] == 'P')
//			numP++;
//		else if (str[i] == 'A')
//			PN[i] = numP;
//	}
//	for (int i = str.length()-1; i>=0; --i)
//	{
//		if (str[i] == 'T')
//			numT++;
//		else if (str[i] == 'A')
//			TN[i] = numT;
//	}
//	long long int res = 0;
//	for (int i = 0; i < str.length(); ++i)
//		res += PN[i] * TN[i];
//	cout << res % 1000000007;
//	return 0;
//}