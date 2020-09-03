////#include <iostream>
////#include <string>
////#include <algorithm>
////using namespace std;
////int main()
////{
////	int k = 0;
////	string str1, str2, str;
////	cin >> str;
////	while (k < 10)
////	{
////		int c = 0;
////		str1 = str2 = str;
////		reverse(str2.begin(), str2.end());
////		if (str1 == str2)
////			break;
////		cout << str1 << " + " << str2 << " = ";
////		for (int i = str1.length()-1; i>=0; --i)
////		{
////			str[i] = (str1[i] - '0' + str2[i] - '0' + c) % 10 + '0';
////			c = (str1[i] - '0' + str2[i] - '0' + c) / 10;
////		}
////		if (c > 0)
////			str.insert(str.begin(), 1, c + '0');
////		cout << str << endl;
////		k++;
////	}
////	if (k == 10)
////		cout << "Not found in 10 iterations." << endl;
////	else
////		cout << str1 << " is a palindromic number." << endl;
////	return 0;
////}
//
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string nums;
//	cin >> nums;
//	int k = 1;
//	while (k <= 10)
//	{
//		k++;
//		string s1, s2;
//		s1 = s2 = nums;
//		reverse(s2.begin(), s2.end());
//		if (s1 == s2)break;
//		int c = 0;
//		for (int i = nums.length() - 1; i >= 0; --i)
//		{
//			nums[i] = (s1[i] - '0' + s2[i] - '0' + c) % 10 + '0';
//			c = (s1[i] - '0' + s2[i] - '0' + c) / 10;
//		}
//		if (c > 0)
//			nums.insert(nums.begin(), c + '0');
//		cout << s1 << " + " << s2 << " = " << nums << endl;
//	}
//	if (k <= 10)
//		cout << nums << " is a palindromic number." << endl;
//	else
//		cout << "Not found in 10 iterations." << endl;
//	return 0;
//}