////#include <iostream>
////#include <string>
////using namespace std;
////string str1, str2;
////int main()
////{
////	cin >> str1 >> str2;
////	string res="";
////	char c;
////	for (int i = 0, j = 0; i < str1.length(); ++i)
////	{
////		while (j < str2.length() && str1[i] == str2[j])
////		{
////			++i;
////			++j;
////		}
////		c = toupper(str1[i]);
////		if (res.find(c) == -1)
////			res += c;
////	}
////	cout << res << endl;
////	return 0;	
////}
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	vector<char>res;
//	int word[128] = { 0 };
//	for (int i = 0, j = 0; i < s1.length(); ++i)
//	{
//		while (i < s1.length() && j < s2.length() && s1[i]== s2[j])
//		{
//			++j;
//			++i;
//		}
//		if (word[toupper(s1[i])] == 0)
//		{
//			res.push_back(toupper(s1[i]));
//			word[toupper(s1[i])] = 1;
//		}
//	}
//	for (auto v : res)
//		cout << v;
//	return 0;
//}