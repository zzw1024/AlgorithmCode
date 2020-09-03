//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//int main()
//{
//	string str, s = "", res;
//	map<string, int>words;
//	int maxN = -1;
//	getline(cin, str);
//	for (int i = 0; i < str.length(); ++i)
//	{
//		if(isalnum(str[i])!=0)//数字也算
//			s += tolower(str[i]);
//		else if(s.length()>0)
//		{
//			words[s]++;
//			s = "";
//		}
//	}
//	//注意，不要漏了最后一个单词
//	if (!s.empty())
//		words[s]++;
//	for (auto ptr = words.begin(); ptr != words.end(); ++ptr)
//	{
//		if (maxN < ptr->second)
//		{
//			maxN = ptr->second;
//			res = ptr->first;
//		}
//	}
//	cout << res << " " << maxN << endl;
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <sstream>
//#include <map>
//using namespace std;
//int main()
//{
//	string str, s = "";
//	getline(cin, str);
//	for (int i = 0; i < str.length(); ++i)
//	{
//		if (isdigit(str[i]) || isalpha(str[i]) || str[i] == ' ')
//			s += tolower(str[i]);
//	}
//	istringstream is(s);
//	map<string, int>res;
//	while (!is.eof())
//	{
//		is >> str;
//		res[str]++;
//	}
//	int maxN = -1;
//	for (auto ptr = res.begin(); ptr != res.end(); ++ptr)
//	{
//		if (maxN < ptr->second)
//		{
//			maxN = ptr->second;
//			s = ptr->first;
//		}
//	}
//	cout << s << " " << maxN << endl;
//	return 0;
//}