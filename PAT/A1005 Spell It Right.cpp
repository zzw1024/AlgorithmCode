////#include <iostream>
////#include <string>
////#include <vector>
////
////using namespace std;
////
////int main()
////{
////	vector<string>words = { "zero","one","two","three","four","five","six","seven","eight","nine","ten" };
////	string num;//不能用数字类型存储，会导致溢出的
////	cin >> num;
////	int sum = 0;
////	for (auto a : num)
////		sum += a - '0';
////	num = to_string(sum);
////	cout << words[num[0] - '0'];
////	for (int i = 1; i < num.length(); ++i)
////		cout << " " << words[num[i] - '0'];
////	cout << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str,res="";
//	string words[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
//	cin >> str;
//	long long int s = 0;
//	for (auto c : str)
//		s += c - '0';
//	str = to_string(s);
//	for (int i = 0; i < str.length(); ++i)
//		cout << (i > 0 ? " " : "") << words[str[i] - '0'];
//	return 0;
//}

