////#include <iostream>
////#include <vector>
////using namespace std;
//////此处11进制中的10就是10，而不是a
////int main()
////{
////	int N, b;
////	cin >> N >> b;
////	vector<int>v1, v2;
////	while (N)
////	{
////		v1.push_back(N%b);
////		N /= b;
////	}
////	v2.assign(v1.rbegin(), v1.rend());
////	if (v1 == v2)
////		cout << "Yes" << endl;
////	else
////		cout << "No" << endl;
////	if (v2.size() == 0)
////		cout << 0;
////	else
////	{
////		cout << v2[0];
////		for (int i = 1; i < v2.size(); ++i)
////			cout << " " << v2[i];
////	}
////	cout << endl;
////	return 0;
////}
//
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int N, B;
//vector<string> getString()
//{
//	vector<string>res;
//	while (N > 0)
//	{
//		res.push_back(to_string(N%B));//防止余数为75，56，
//		N /= B;
//	}
//	return res;
//}
//int main()
//{
//	cin >> N >> B;
//	vector<string>s1, s2;
//	s1 = s2 = getString();
//	reverse(s1.begin(), s1.end());
//	if (s1 == s2)
//		cout << "Yes" << endl;
//	else
//		cout << "No" << endl;
//	if (s1.size() == 0)
//		cout << 0 << endl;
//	else
//		for (int i = 0; i < s1.size(); ++i)
//			cout << (i == 0 ? "" : " ") << s1[i];
//	return 0;
//}