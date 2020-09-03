////#include <iostream>
////#include <string>
////using namespace std;
////int main()
////{
////	int n;
////	string str, res = "", bad = "", temp = "";
////	int key[128] = { 0 };
////	cin >> n;
////	getchar();
////	getline(cin, str);
////	for (int i = 0; i < str.length();)
////	{
////		int j = i + 1;
////		while (j < str.length() && str[j] == str[i])//重复字符
////			++j;
////		if (key[str[i]] >= 0)//不是坏键
////			key[str[i]] = (j - i) % n == 0 ? 1 : -1;//重复n次是坏键
////		i = j;
////	}		
////	bool out[128] = { false };//表示是否输出过
////	for (int i = 0; i < str.length();)
////	{
////		res += str[i];
////		if (key[str[i]] == 1)//为坏键
////		{
////			if (out[str[i]] == false)//还为输出过
////				bad += str[i];
////			out[str[i]] = true;//输出过
////			i += n;//跳过重复键
////		}
////		else
////			++i;//继续遍历
////	}
////	cout << bad << endl << res << endl;
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	int k;
//	cin >> k;
//	string str, res = "";
//	cin >> str;
//	bool isExit[128] = { false }, isFail[128] = { false };
//	for (int i = 0; i < str.length(); ++i)
//	{
//		int n = 0;
//		isFail[str[i]] = false;
//		while (i < str.length() - 1 && str[i] == str[i + 1])
//		{
//			n++;
//			i++;
//		}
//		if ((n + 1) % k == 0 && isFail[str[i - 1]] == false)
//		{
//			isFail[str[i - 1]] = true;
//			res += str[i-1];
//		}
//	}
//	for (auto a : res)
//	{
//		if (isFail[a] == true && isExit[a] == false)
//		{
//			isExit[a] = true;
//			cout << a;
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < str.length(); ++i)
//		if (isFail[str[i]] == true)
//			str.erase(i, k - 1);
//	cout << str << endl;
//	return 0;
//}