////#include <iostream>
////#include <string>
////using namespace std;
////int main()
////{
////	string date[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
////	string s1, s2, s3, s4;
////	cin >> s1 >> s2 >> s3 >> s4;
////	int flag = 0;
////	for (int i = 0; i < s1.length() && i<s2.length(); ++i)
////	{
////		if (flag == 0 && s1[i] >= 'A' && s1[i] <= 'Z' && s1[i] == s2[i])
////		{
////			cout << date[s1[i] - 'A'] << " ";
////			flag = 1;
////		}
////		else if(flag == 1 && s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] >= '0' && s1[i] <= '9')))
////		{
////			if (s1[i] >= '0'&& s1[i] <= '9')
////				cout << "0" << s1[i] - '0' << ":";
////			else
////				cout << (s1[i] - 'A' + 10) << ":";
////			break;
////		}
////	}
////	int k = 0;
////	for (int i = 0; i < s3.length() && i < s4.length(); ++i)
////	{
////		if (((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z')) && s3[i] == s4[i])
////		{
////			k = i;
////			break;
////		}
////	}
////	cout << (k > 9 ? "" : "0") << k << endl;
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
//	string s1, s2, s3, s4;
//	cin >> s1 >> s2 >> s3 >> s4;
//	string date[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
//	bool flag = false;
//	for(int i=0;i<min(s1.length(),s2.length());++i)
//		if (s1[i] == s2[i])
//		{
//			if (!flag && s1[i]>='A'&&s1[i]<='G')//一定得是大写字母
//			{
//				cout << date[s1[i] - 'A'] << " ";
//				flag = true;
//			}
//			else if (flag && ((isdigit(s1[i]) || s1[i]>='A'&&s1[i]<='N')))
//			{
//				printf("%02d:", (isdigit(s1[i]) ? (s1[i] - '0') : (s1[i] - 'A' + 10)));
//				break;
//			}
//		}
//	for (int i = 0; i < min(s3.length(), s4.length()); ++i)
//		if (s3[i] == s4[i] && isalpha(s3[i]))
//		{
//			printf("%02d\n", i);
//			break;
//		}
//	return 0;
//}