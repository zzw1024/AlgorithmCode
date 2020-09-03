////#include <iostream>
////#include <string>
////using namespace std;
////int main()
////{
////	string N, str;
////	int K, i = 0;
////	cin >> N >> K;
////	if (N == str.assign(N.rbegin(), N.rend()))
////		K = 0;
////	for (i = 1; i <= K; ++i)
////	{
////		str = "";
////		int s = 0;
////		for (int j = 0; j < N.length(); ++j)
////		{
////			str += (s + N[j] - '0' + N[N.length() - j - 1] - '0') % 10 + '0';
////			s = (s + N[j] - '0' + N[N.length() - j - 1] - '0') / 10;			
////		}
////		if (s > 0)
////			str += s + '0';
////		N.assign(str.rbegin(), str.rend());
////		if (N == str)
////			break;
////	}
////	cout << N << endl;
////	cout << (i > K ? K : i) << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string s1, s2, s3;
//	int m = 0, k;
//	cin >> s1 >> k;
//	do
//	{
//		int index = 0, temp;
//		s2 = s1;
//		reverse(s2.begin(), s2.end());
//		if (s1 == s2)
//			break;
//		for (int i = s1.length()-1; i >= 0; --i)
//		{
//			temp = s1[i] - '0' + s2[i] - '0' + index;
//			s1[i] = temp % 10 + '0';
//			index = temp / 10;
//		}
//		if (index > 0)
//			s1.insert(s1.begin(), index + '0');
//		m++;
//	} while (m < k);
//	cout << s1 << endl << m << endl;
//	return 0;
//}
