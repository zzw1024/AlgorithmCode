////#include <iostream>
////#include <string>
////using namespace std;
////string sell, buy;
////int nums[130] = { 0 }, res = 0;//ASCALL表
////int main()
////{
////	cin >> sell >> buy;
////	for (auto s : sell)
////		nums[s]++;
////	for (auto s : buy)
////	{
////		if (nums[s] == 0)
////			res++;
////		else
////			nums[s]--;
////	}
////	if (res == 0)
////		cout << "Yes" << " " << (sell.size() - buy.size()) << endl;
////	else
////		cout << "No" << " " << res << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//	string  str, s;
//	cin >> str >> s;
//	unordered_map<char, int>colors;
//	for (auto v : str)
//		colors[v]++;
//	int lessN = 0;
//	for (auto v : s)
//	{
//		if (colors[v] == 0)
//			lessN++;
//		else
//			colors[v]--;
//	}
//	if (lessN > 0)
//		cout << "No " << lessN << endl;
//	else
//		cout << "Yes " << str.length() - s.length() << endl;
//	return 0;
//}