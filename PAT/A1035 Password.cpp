////#include <iostream>
////#include <string>
////#include <vector>
////using namespace std;
////int N;
////int main()
////{
////	cin >> N;
////	vector<pair<string, string>>res;
////	for (int i = 0; i < N; ++i)
////	{
////		bool flag = false;
////		string name, password;
////		cin >> name >> password;
////		for (int j = 0; j < password.length(); ++j)
////		{
////			if (password[j] == '1')
////			{
////				flag = true;
////				password[j] = '@';
////			}
////			else if (password[j] == '0')
////			{
////				flag = true;
////				password[j] = '%';
////			}
////			else if (password[j] == 'l')
////			{
////				flag = true;
////				password[j] = 'L';
////			}
////			else if (password[j] == 'O')
////			{
////				flag = true;
////				password[j] = 'o';
////			}			
////		}
////		if (flag)
////			res.push_back(make_pair(name, password));
////	}
////	if (res.size() == 0)
////	{
////		if (N > 1)
////			cout << "There are " << N << " accounts and no account is modified" << endl;
////		else
////			cout << "There is " << N << " account and no account is modified" << endl;
////	}		
////	else
////	{
////		cout << res.size() << endl;
////		for (auto ptr : res)
////			cout << ptr.first << " " << ptr.second << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	unordered_map<char, char>map;
//	vector<pair<string, string>>res;
//	map['1'] = '@';
//	map['l'] = 'L';
//	map['0'] = '%';
//	map['O'] = 'o';
//	for (int i = 0; i < n; ++i)
//	{
//		string s, str;
//		cin >> s >> str;
//		string temp = str;
//		for (int j = 0; j < str.length(); ++j)
//			if (map.find(str[j]) != map.end())
//				str[j] = map[str[j]];
//		if (temp != str)
//			res.push_back(make_pair(s, str));
//	}
//	if (res.size() == 0 && n == 1)
//		printf("There is 1 account and no account is modified\n");
//	else if (res.size() == 0 && n > 1)
//		printf("There are %d accounts and no account is modified\n", n);
//	else
//	{
//		printf("%d\n", res.size());
//		for (int i = 0; i < res.size(); ++i)
//			cout << res[i].first << " " << res[i].second << endl;
//	}
//	return 0;
//}